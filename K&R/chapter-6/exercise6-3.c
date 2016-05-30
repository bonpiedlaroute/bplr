#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define BUFSIZE 100
#define MAXWORD 100

struct tline
{
    int num;
    int count;
    struct tline* next;
};

struct tnode
{
    char *word;
    struct tline *lines;
    struct tnode *left;
    struct tnode *right;
};

char buf[BUFSIZE];
int bufp = 0;
int numline = 1;

int getch()
{
    return( bufp > 0 ) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if( bufp >= BUFSIZE )
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}


struct tline *addlines(struct tline *p, int l)
{
    struct tline *tmp, *node;    
    if( p == NULL )
    {
        p = (struct tline *) malloc(sizeof(struct tline));
        p->num = l;
        p->count = 1;
        p->next = NULL;
    }
    else
    {
        tmp = p;
        while( tmp->next != NULL && tmp->num != l )
            tmp = tmp->next;
        if( tmp->num != l )
        {
            node = (struct tline *) malloc(sizeof(struct tline));
            node->num = l;
            node->count = 1;
            node->next = NULL;

            tmp->next = node;
        }
        else
            tmp->count++;
    }

    return p;
}
void removelines(struct tline *p, int l)
{
    struct tline *tmp, *prev;

    if( p == NULL )
        return;
    else
    {        
        if( p->num == l ) /* delete at head */
        {
            tmp = p;            
            p = p->next;
            free(tmp);
        }
        else
        {
            prev = p;
            tmp = p->next;

            while( tmp != NULL && tmp->num != l )
            {
                prev = tmp;         
                tmp = tmp->next;
            }

            if( tmp != NULL )
            {
                if( tmp->num == l )
                {
                    prev->next = tmp->next;
                    free(tmp);
                }
            }
        }
    }
}

void printline(struct tline *p)
{
    struct tline *tmp = p;

    printf(" ");
    while( tmp != NULL )
    {
        printf("%d ",tmp->num);
        tmp = tmp->next;
    }
}

struct tnode* addtree(struct tnode *p, char *w, int l)
{
    int cond;
    
    struct tnode *prev = NULL, *tmp = NULL, *n;

    tmp = p;

    while( tmp != NULL && (cond = strcmp(w, tmp->word)) != 0 )
    {
        prev = tmp;

        if( cond < 0 )
            tmp = tmp->left;
        else
            tmp = tmp->right;
    }

    if( tmp != NULL )
    {
        tmp->lines = addlines(tmp->lines, l);        
        return p;
    }
    else
    {
        n = (struct tnode *) malloc(sizeof(struct tnode));
        n->word = strdup(w);
        n->lines = NULL;
        n->lines = addlines(n->lines, l);
        n->left = n->right = NULL;        

        if( prev == NULL )
            return n;
        else
        {
            if( cond < 0 )
                prev->left = n;
            else
                prev->right = n;
    
            return p;
        }

    }


}

/* getword get next word or character from input */

int getword(char *word, int lim)
{
    int c;
    char *w = word;
    
    while( isspace(c = getch()))
    {
        if( c == '\n' )
            numline++;
    }
    if( c != EOF )
        *w++ = c;

    if( !isalpha(c) && c != '_'  && c != '#')
    {
        *w = '\0';
        return c;
    }

    for(; --lim > 0; w++)
    {
        if( !isalnum(*w = getch()) && *w != '_' )
        {
            ungetch(*w);
            break;
        }
    }
    *w = '\0';
    
    return word[0];
}

void treeprint(struct tnode *p)
{
    if( p != NULL )
    {
        treeprint(p->left);
        printf("%s:",p->word);
        printline(p->lines);
        printf("\n");
        treeprint(p->right);
    }
    
}

int main(int argc, char *argv[])
{
    struct tnode *root;
    char word[MAXWORD];

    root = NULL;

    while( getword(word, MAXWORD) != EOF )
    {
        if( isalpha(word[0]) || word[0] == '_' || word[0] == '#' )
            root = addtree(root, word, numline);
    }
    treeprint(root);
    return 0;
}
