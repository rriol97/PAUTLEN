/********************************
Fichero: prueba_TS.c
Autores: Francisco de Vicente Lana, Miguel García Moya, Manuel Suárez y Ricardo Riol González
Descripcion: programa principal de la tabla de símbolos
*********************************/
#include "prueba_TS.h"
#include "tabla.h"

FILE *f_in, *f_out;

TablaAmbito* tablaMain = NULL;
TablaSimbolosClases* tsc = NULL;

int num_at_c = 0;
int num_at_i = 0;
int num_met_s = 0;
int num_met_ns = 0;
int num_acumulado_at_i = 0;
int num_acumulado_met_s = 0;

int procesar_linea(char *linea);

void gestiona_INICIA_TSA_MAIN();
void gestiona_ABRIR_AMBITO_PPAL_MAIN();
void gestiona_BUSCAR();
void gestiona_INSERTAR_TSA_MAIN ();
void gestiona_ABRIR_AMBITO_TSA_MAIN();
void gestiona_CERRAR_AMBITO_TSA_MAIN();
void gestiona_INICIA_TSC();
void gestiona_ABRIR_CLASE();
void gestiona_ABRIR_CLASE_HEREDA();
void gestiona_INSERTAR_TSC();
void gestiona_ABRIR_AMBITO_TSC();
void gestiona_CERRAR_AMBITO_TSC();
void gestiona_CERRAR_CLASE();
void gestiona_CERRAR_TSA_MAIN();
void gestiona_CERRAR_TSC();

int main(int argc, char *argv[]) {
  char linea[MAX];

  /* Comprobacion argumentos de entrada */
  if (argc != 3) {
    printf("./prueba_TS <fichero_de_lectura> <fichero_de_escritura>\n");
    return EXIT_FAILURE;
  }

  /* Apertura fichero entrada */
  f_in = fopen(argv[1], "r");
  if (!f_in)
  {
      printf("Apertura fichero entrada fallida\n");
      return EXIT_FAILURE;
  }

  /* Apertura fichero salida */
  f_out = fopen(argv[2], "w");
  if (!f_out)
  {
      printf("Apertura fichero salida fallida\n");
      return EXIT_FAILURE;
  }

  while (fgets(linea, MAX, f_in) != NULL) {
    procesar_linea(linea);
  }

  /* Cierre de ficheros */
  fclose(f_in);
  fclose(f_out);
  if(tablaMain != NULL){
      tablaFree(tablaMain);
  }
  if(tsc != NULL){
      liberarTablaSimbolosClases(tsc);
  }
  return EXIT_SUCCESS;
}

int procesar_linea(char *linea) {
  char *token;

  token = strtok(linea, " \r\n\t");

  if (!strcmp(token, TOK_OP_INICIA_TSA_MAIN)) {
    gestiona_INICIA_TSA_MAIN();
  } else if (!strcmp(token, TOK_OP_ABRIR_AMBITO_PPAL_MAIN)) {
    gestiona_ABRIR_AMBITO_PPAL_MAIN();
  } else if (!strcmp(token, TOK_OP_BUSCAR)) {
    gestiona_BUSCAR();
  } else if (!strcmp(token, TOK_OP_INSERTAR_TSA_MAIN)) {
    gestiona_INSERTAR_TSA_MAIN();
  } else if (!strcmp(token, TOK_OP_ABRIR_AMBITO_TSA_MAIN)) {
    gestiona_ABRIR_AMBITO_TSA_MAIN();
  } else if (!strcmp(token, TOK_OP_CERRAR_AMBITO_TSA_MAIN)) {
    gestiona_CERRAR_AMBITO_TSA_MAIN();
  } else if (!strcmp(token, TOK_OP_INICIA_TSC)) {
    gestiona_INICIA_TSC();
  } else if (!strcmp(token, TOK_OP_ABRIR_CLASE)) {
    gestiona_ABRIR_CLASE();
  } else if (!strcmp(token, TOK_OP_ABRIR_CLASE_HEREDA)) {
    gestiona_ABRIR_CLASE_HEREDA();
  } else if (!strcmp(token, TOK_OP_INSERTAR_TSC)) {
    gestiona_INSERTAR_TSC();
  } else if (!strcmp(token, TOK_OP_ABRIR_AMBITO_TSC)) {
    gestiona_ABRIR_AMBITO_TSC();
  } else if (!strcmp(token, TOK_OP_CERRAR_AMBITO_TSC)) {
    gestiona_CERRAR_AMBITO_TSC();
  } else if (!strcmp(token, TOK_OP_CERRAR_CLASE)) {
    gestiona_CERRAR_CLASE();
  } else if (!strcmp(token, TOK_OP_CERRAR_TSA_MAIN)) {
    gestiona_CERRAR_TSA_MAIN();
  } else if (!strcmp(token, TOK_OP_CERRAR_TSC)) {
    gestiona_CERRAR_TSC();
  }
  
  return 0;
}

void gestiona_INICIA_TSA_MAIN() {
    tablaMain = tablaInit("main");
    fprintf(f_out, "inicia tsa main\n");
}

void gestiona_ABRIR_AMBITO_PPAL_MAIN() {
    fprintf(f_out, "abrir ambito ppal main\n");
    return; /*nuestra funcion de abrir ambito solo inicializa la tabla, ya hecho antes*/
}

void gestiona_BUSCAR() {
    char* token;
    char* clase;
    char* instancia;
    char nombre_og[MAX_NAME];
    elementoTablaSimbolos* e;
    char nombre_ambito_encontrado[MAX_NAME];
    int result = ERR;
    
    token = strtok(NULL, " \r\n\t");
    if(!strcmp(token, TOK_DECLARAR_MAIN)) {
        fprintf(f_out, "buscar declarar main\n");
        token = strtok(NULL, " \r\n\t");
        result = buscarParaDeclararIdTablaSimbolosAmbitos(tablaMain, token, &e, "main", nombre_ambito_encontrado);
        if(result == OK) {
            fprintf(f_out, "Existe el id (%s): no se puede declarar\n", token);
        } else {
            fprintf(f_out, "No existe el id (%s): se puede declarar\n", token);
        }
    } else if(!strcmp(token, TOK_DECLARAR_MIEMBRO_CLASE)) {
        fprintf(f_out, "buscar declarar miembro clase\n");
        clase = strtok(NULL, " \r\n\t");
        token = strtok(NULL, " \r\n\t");
        /*quitamos el prefijo*/
        strcpy(nombre_og, token);
        strtok(token, "_");
        instancia = strtok(NULL, "_");
        result = buscarParaDeclararMiembroClase(tsc, clase, instancia, &e, nombre_ambito_encontrado);
        if(result == OK) {
            fprintf(f_out, "Existe el id (%s): no se puede declarar\n", nombre_og);
        } else {
            fprintf(f_out, "No existe el id (%s): se puede declarar\n", nombre_og);
        }
    } else if(!strcmp(token, TOK_DECLARAR_MIEMBRO_INSTANCIA)) {
        fprintf(f_out, "buscar declarar miembro instancia\n");
        clase = strtok(NULL, " \r\n\t");
        token = strtok(NULL, " \r\n\t");
        /*quitamos el prefijo*/
        strcpy(nombre_og, token);
        instancia = strtok(token, "_");
        instancia = strtok(NULL, "_");
        result = buscarParaDeclararMiembroInstancia(tsc, clase, instancia, &e, nombre_ambito_encontrado);
        if(result == OK) {
            fprintf(f_out, "Existe el id (%s): no se puede declarar\n", nombre_og);
        } else {
            fprintf(f_out, "No existe el id (%s): se puede declarar\n", nombre_og);
        }
    } else if(!strcmp(token, TOK_DECLARAR_ID_LOCAL_METODO)) {
        fprintf(f_out, "buscar declarar id local metodo\n");
        clase = strtok(NULL, " \r\n\t");
        token = strtok(NULL, " \r\n\t");
        result = buscarParaDeclararIdLocalEnMetodo(tsc, clase, token, &e, nombre_ambito_encontrado);
        if(result == OK) {
            fprintf(f_out, "Existe el id (%s): no se puede declarar\n", token);
        } else {
            fprintf(f_out, "No existe el id (%s): se puede declarar\n", token);
        }
    } else if(!strcmp(token, TOK_JERARQUIA)) {
        fprintf(f_out, "buscar jararquia\n");
        token = strtok(NULL, " \r\n\t");
        clase = strtok(NULL, " \r\n\t");
        result = buscarIdEnJerarquiaDesdeClase(tsc, token, clase, &e, nombre_ambito_encontrado);
        if(result == OK) {
            fprintf(f_out, "Existe el id (%s) en la jerarquía\n", token);
        } else {
            fprintf(f_out, "No existe el id (%s) en la jerarquía\n", token);
        }
    } else if(!strcmp(token, TOK_ID_NO_CUALIFICADO)) {
        fprintf(f_out, "buscar id no cualificado\n");
        token = strtok(NULL, " \r\n\t");
        clase = strtok(NULL, " \r\n\t");
        result = buscarIdNoCualificado(tsc, tablaMain, token, clase, &e, nombre_ambito_encontrado);
        if(result == OK) {
            fprintf(f_out, "Existe el id no cualificado (%s)\n", token);
        } else {
            fprintf(f_out, "No existe el id no cualificado (%s)\n", token);
        }
    } else if(!strcmp(token, TOK_ID_CUALIFICADO_INSTANCIA)) {
        fprintf(f_out, "buscar id cualificado instancia\n");
        instancia = strtok(NULL, " \r\n\t");
        token = strtok(NULL, " \r\n\t");
        clase = strtok(NULL, " \r\n\t");
        result = buscarIdCualificadoInstancia(tsc, tablaMain, instancia, token, clase, &e, nombre_ambito_encontrado);
        if(result == OK) {
            fprintf(f_out, "Existe el id (%s) cualificado por (%s)\n", token, instancia);
        } else {
            fprintf(f_out, "No existe el id (%s) cualificado por (%s)\n", token, instancia);
        }
    } else if(!strcmp(token, TOK_ID_CUALIFICADO_CLASE)) {
        fprintf(f_out, "buscar id cualificado clase\n");
        instancia = strtok(NULL, " \r\n\t");
        token = strtok(NULL, " \r\n\t");
        clase = strtok(NULL, " \r\n\t");
        result = buscarIdCualificadoClase(tsc, instancia, token, clase, &e, nombre_ambito_encontrado);
        if(result == OK) {
            fprintf(f_out, "Existe el id (%s) cualificado por (%s)\n", token, instancia);
        } else {
            fprintf(f_out, "No existe el id (%s) cualificado por (%s)\n", token, instancia);
        }
    }

}

void gestiona_INSERTAR_TSA_MAIN () {
    char* token;
    int categoria, tipo_basico, estructura, tipo_acceso, tipo_miembro;
    
    fprintf(f_out, "insertar tsa main\n");
    
    token = strtok(NULL, " \r\n\t");
    categoria = atoi(strtok(NULL, " \r\n\t"));
    tipo_basico = atoi(strtok(NULL, " \r\n\t"));
    estructura = atoi(strtok(NULL, " \r\n\t"));
    tipo_acceso = atoi(strtok(NULL, " \r\n\t"));
    tipo_miembro = atoi(strtok(NULL, " \r\n\t"));
    
    /*TODO: que cojones son todo eso*/
    insertarTablaSimbolosAmbitos(tablaMain, "main",
        token, categoria,
        tipo_basico, estructura,
        1, 0,
        0, 1,
        1,
        1,
        0, 0,
        0, 0,
        tipo_acceso, tipo_miembro,
        0, 0,
        0, 0,
        0,
        0,
        NULL);
}

void gestiona_ABRIR_AMBITO_TSA_MAIN() {
    char* token, *no_prefijo;
    int tipo_basico;
    
    fprintf(f_out, "abrir ambito tsa main\n");
    
    token = strtok(NULL, " \r\n\t");
    tipo_basico = atoi(strtok(NULL, " \r\n\t"));
    insertarTablaSimbolosAmbitos(tablaMain, "main",
        token, ESCALAR,
        tipo_basico, FUNCION,
        1, 0,
        0, 1,
        1,
        1,
        0, 0,
        0, 0,
        ACCESO_TODOS, MIEMBRO_UNICO,
        0, 0,
        0, 0,
        0,
        0,
        NULL);
        
    /*quitamos el prefijo*/
    strtok(token, "_");
    no_prefijo = strtok(NULL, "_");
    AbrirAmbitoPrefijos(tablaMain, "main", no_prefijo, FUNCION, ACCESO_TODOS, MIEMBRO_UNICO, 0, 1);
}

void gestiona_CERRAR_AMBITO_TSA_MAIN() {
    fprintf(f_out, "cerrar ambito tsa main\n");
    cerrarAmbitoPrefijos(tablaMain);
}

void gestiona_INICIA_TSC() {
    fprintf(f_out, "inicia tsc\n");
    iniciarTablaSimbolosClases(&tsc, "grafo");
}

void gestiona_ABRIR_CLASE() {
    char* token;
    
    fprintf(f_out, "abrir clase\n");

    token = strtok(NULL, " \r\n\t");
    abrirClase(tsc, token);
}

void gestiona_ABRIR_CLASE_HEREDA() {
    char* token;
    char* padre;
    int num_padres = 0, i;
    char** padres = NULL;
    
    fprintf(f_out, "abrir clase hereda\n");

    token = strtok(NULL, " \r\n\t");
    while( (padre=strtok(NULL, " \r\n\t")) != NULL ) {
        num_padres++;
        padres = realloc(padres, sizeof(char*)*num_padres);
        padres[num_padres-1] = malloc((strlen(padre) + 1) * sizeof(char));
        strcpy(padres[num_padres-1], padre);
    }
    abrirClaseHeredaN(tsc, token, padres, num_padres);
    for(i = 0; i < num_padres; i++) {
        free(padres[i]);
    }
    free(padres);
}

void gestiona_INSERTAR_TSC() {
    char* token, *simbolo;
    int categoria, tipo_basico, estructura, tipo_acceso, tipo_miembro;
    
    fprintf(f_out, "insertar tsc\n");
    
    token = strtok(NULL, " \r\n\t");
    simbolo = strtok(NULL, " \r\n\t");
    categoria = atoi(strtok(NULL, " \r\n\t"));
    tipo_basico = atoi(strtok(NULL, " \r\n\t"));
    estructura = atoi(strtok(NULL, " \r\n\t"));
    tipo_acceso = atoi(strtok(NULL, " \r\n\t"));
    tipo_miembro = atoi(strtok(NULL, " \r\n\t"));
    
    /*TODO: que cojones son todo eso*/
    insertarTablaSimbolosClases(tsc, token,
        simbolo, categoria,
        tipo_basico, estructura,
        1, 0,
        0, 1,
        1,
        1,
        num_at_c, num_at_i,
        num_met_s, num_met_ns,
        tipo_acceso, tipo_miembro,
        num_at_i*4, num_met_s*4,
        num_acumulado_at_i, num_acumulado_met_s,
        num_acumulado_at_i*4,
        num_acumulado_met_s*4,
        NULL);
        
    if(categoria == METODO_NO_SOBREESCRIBIBLE) {
        num_met_ns++;
    } else if (categoria == METODO_SOBREESCRIBIBLE) {
        num_met_ns++;
        num_acumulado_met_s++;
    } else if (categoria == ATRIBUTO_CLASE) {
        num_at_c++;
    } else if (categoria == ATRIBUTO_INSTANCIA){
        num_at_i++;
        num_acumulado_at_i++;
    }
    
}

void gestiona_ABRIR_AMBITO_TSC() {
    char* token, *simbolo, *no_prefijo;
    int categoria, tipo_basico, tipo_acceso, tipo_miembro;
    
    fprintf(f_out, "abrir ambito tsc\n");
    
    token = strtok(NULL, " \r\n\t");
    simbolo = strtok(NULL, " \r\n\t");
    categoria = atoi(strtok(NULL, " \r\n\t"));
    tipo_basico = atoi(strtok(NULL, " \r\n\t"));
    tipo_acceso = atoi(strtok(NULL, " \r\n\t"));
    tipo_miembro = atoi(strtok(NULL, " \r\n\t"));
    
    insertarTablaSimbolosClases(tsc, token,
        simbolo, ESCALAR,
        tipo_basico, FUNCION,
        1, 0,
        0, 1,
        1,
        1,
        0, 0,
        0, 0,
        tipo_acceso, tipo_miembro,
        0, 0,
        0, 0,
        0,
        0,
        NULL);
        
    /*quitamos el prefijo*/
    strtok(simbolo, "_");
    no_prefijo = strtok(NULL, "_");
    abrirAmbitoEnClase(tsc, token, no_prefijo, categoria, tipo_acceso, tipo_miembro, 0, 1);
    
}

void gestiona_CERRAR_AMBITO_TSC() {
    char* token;
    
    fprintf(f_out, "cerrar ambito tsc\n");
    
    token = strtok(NULL, " \r\n\t");
    cerrarAmbitoEnClase(tsc, token);
}

void gestiona_CERRAR_CLASE() {
    char* token;
    
    fprintf(f_out, "cerrar clase\n");
    
    token = strtok(NULL, " \r\n\t");
    
    cerrarClase(tsc, token, num_at_c, num_at_i, num_met_s, num_met_ns);
    num_at_c = 0;
    num_at_i = 0;
    num_met_ns = 0;
    num_met_ns = 0;
    
}


void gestiona_CERRAR_TSA_MAIN() {
    fprintf(f_out, "cerrar tsa main\n");
    
    cerrarAmbito(tablaMain);
}

void gestiona_CERRAR_TSC() {
    FILE* dot;
    
    fprintf(f_out, "cerrar tsc\n");
    
    cerrarTablaSimbolosClases(tsc);
    dot = fopen("tsc.dot", "w");
    if(dot != NULL) {
        tablaSimbolosClasesToDot(tsc, dot);
        fclose(dot);
    }
}

