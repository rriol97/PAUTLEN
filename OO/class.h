#include <stdlib.h>
#include <stdio.h>
#include "hash.h"

#define MAX_NAME 100

typedef struct {
    char name[MAX_NAME];
    Hash** th_ppal;
    Hash** th_func;
} TablaAmbito;

typedef struct {
    int index;
    char name[MAX_NAME];
    TablaAmbito tabla;
} Class;
