#include <stdlib.h>
#include <stdio.h>
#include "uthash.h"

typedef struct _Hash{
	char* name;
	void* value;
	UT_hash_handle hh;
} Hash;

void insert_symbol(Hash **hash, char* name, void* value);

void delete_symbol(Hash **hash, char* name);

void* find_symbol(Hash **hash, char* name);

void clear_symbols(Hash **hash);


