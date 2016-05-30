
void remove(char *w)
{
    struct nlist* np = hashtab[hash(w)];
    struct nlist* prev;

    if( np != NULL && strcmp(w, np->name) == 0 )
    {
        hastab[hash(w)] = np->next;
        free(np->name);
        free(np->defn);
        free(np);
    }
    else
    {
        do
        {
            prev = np;            
            np = np->next;
        }
        while( np != NULL && strcmp(w, np->name) != 0 )
        
        if( np != NULL )
        {
            prev->next = np->next;
            free(np->name);
            free(np->defn);
            free(np);
        }
    }
}
