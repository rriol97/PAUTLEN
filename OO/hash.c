#include <stdlib.h>
#include <stdio.h>
#include "uthash.h"
#include "hash.h"


void insert_symbol(Hash **hash, char* name, void* value) {
    Hash *s, *point;

    HASH_FIND_STR( *hash, name, point );
    if(point != NULL)
        return;

    s = malloc(sizeof(Hash));
    if(s == NULL) {
        fprintf(stderr, "Error while allocating memory");
        return;
    }
    s->value = value;
    s->name = malloc(sizeof(char)*(strlen(name)+1));
    if(s->name == NULL) {
        fprintf(stderr, "Error while allocating memory");
        free(s);
        return;
    }
    strcpy(s->name, name);
    HASH_ADD_KEYPTR(hh, *hash, s->name, strlen(s->name), s);
}

void delete_symbol(Hash **hash, char* name){
    Hash *point = NULL;

    HASH_FIND_STR( *hash, name, point );
    if(point == NULL)
        return;
    HASH_DEL(*hash, point);
    free(point->name);
    free(point);             
}

void* find_symbol(Hash **hash, char* name){
    Hash *point = NULL;

    HASH_FIND_STR( *hash, name, point );
    if(point == NULL)
        return NULL;
    return point->value;

}

void clear_symbols(Hash **hash){
    Hash *point, *tmp;

    HASH_ITER(hh, *hash, point, tmp) {
        HASH_DEL(*hash,point);  
        free(point->name);
        free(point->value);
        free(point);            
    }
}


