#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define BUFSIZE 100
#define MAXWORD 100

struct tword
{
    char *word;
    int count;
    struct tword* next;
};

struct tnode
{
    char *word;
    int count;
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


struct tword *add(struct tword *p, char *w)
{
    struct tword *tmp, *node;    
    if( p == NULL )
    {
        p = (struct tword *) malloc(sizeof(struct tword));
        p->word = strdup(w);
        p->count = 1;
        p->next = NULL;
    }
    else
    {
        tmp = p;
        while( tmp->next != NULL && strcmp(tmp->word, w) != 0 )
            tmp = tmp->next;
        if( strcmp(tmp->word, w) != 0 )
        {
            node = (struct tword *) malloc(sizeof(struct tword));
            node->word = strdup(w);
            node->count = 1;
            node->next = NULL;

            tmp->next = node;
        }
        else
            tmp->count++;
    }

    return p;
}


struct tnode* addtree(struct tnode *p, char *w, int freq)
{
    int cond;
    
    if( p == NULL )
    {
        p = (struct tnode *)malloc(sizeof(struct tnode));
        p->word = strdup(w);
        p->count = freq;
        p->left = p->right = NULL;
    }
    else
    {
        if( p->count <= freq )
            p->left = addtree(p->left, w, freq) ;
        else
            p->right = addtree(p->right, w, freq);
    }

    return p;
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
        printf("%s:%d\n",p->word, p->count);
        treeprint(p->right);
    }
    
}

int main(int argc, char *argv[])
{
    struct tword *root, *tmp;
    char word[MAXWORD];
    struct tnode *tree = NULL;

    root = NULL;

    while( getword(word, MAXWORD) != EOF )
    {
        if( isalpha(word[0]) || word[0] == '_' || word[0] == '#' )
            root = add(root, word);
    }

    tmp = root;

    while( tmp != NULL )
    {
        tree = addtree(tree, tmp->word, tmp->count);
        tmp = tmp->next;
    }
    
    treeprint(tree);
    return 0;
}
