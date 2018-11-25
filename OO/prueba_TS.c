/********************************
Fichero: prueba_TS.c
Autores: Francisco de Vicente Lana, Miguel García Moya, Manuel Suárez y Ricardo Riol González
Descripcion: programa principal de la tabla de símbolos
*********************************/
#include "prueba_TS.h"
#include "tabla.h"

TablaAmbito* tablaMain = NULL;
TablaSimbolosClases* tsc = NULL;

int procesar_linea(char *linea);

void gestiona_INICIA_TSA_MAIN();
void gestiona_ABRIR_AMBITO_PPAL_MAIN();
void gestiona_BUSCAR();

void gestiona_INSERTAR_TSA_MAIN ();
void gestiona_ABRIR_AMBITO_TSA_MAIN();
void gestiona_CERRAR_AMBITO_TSA_MAIN();
void gestiona_INICIA_TSC();
void gestiona_ABRIR_CLASE();
void gestiona_ABRIR_CLASE_HEREDA ();
void gestiona_INSERTAR_TSC();
void gestiona_ABRIR_AMBITO_TSC();
void gestiona_CERRAR_AMBITO_TSC ();
void gestiona_CERRAR_CLASE ();
void gestiona_CERRAR_TSA_MAIN();
void gestiona_CERRAR_TSC();

int main(int argc, char *argv[]) {
  FILE *f_in, *f_out;
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
  printf("llega");
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
  } /*else if (!strcmp(token, TOK_OP_ABRIR_AMBITO_TSA_MAIN)) {
    gestiona_ABRIR_AMBITO_TSA_MAIN();
  } else if (!strcmp(token, TOK_OP_CERRAR_AMBITO_TSA_MAIN)) {
    gestiona_CERRAR_AMBITO_TSA_MAIN();
  } else if (!strcmp(token, TOK_OP_INICIA_TSC)) {
    gestiona_INICIA_TSC();
  } */
  /*...
  else if (!strcmp(token, TOK_OP_CERRAR_CLASE)) {
    gestiona_CERRAR_CLASE ();
  } else if (!strcmp(token, TOK_OP_CERRAR_TSA_MAIN)) {
    gestiona_CERRAR_TSA_MAIN();
  } else if (!strcmp(token, TOK_OP_CERRAR_TSC)) {
    gestiona_CERRAR_TSC();
  } else if (!strcmp(token, TOK_DECLARAR_MAIN)) {

  } else if (!strcmp(token, TOK_DECLARAR_MIEMBRO_CLASE)) {

  } else if (!strcmp(token, TOK_DECLARAR_MIEMBRO_INSTANCIA)) {

  } else if (!strcmp(token, TOK_ID_CUALIFICADO_INSTANCIA)) {
      
  } else if (!strcmp(token, TOK_ID_CUALIFICADO_CLASE)) {
      
  }*/
  /*
      void gestiona_ABRIR_CLASE();
void gestiona_ABRIR_CLASE_HEREDA ();
void gestiona_INSERTAR_TSC();
void gestiona_ABRIR_AMBITO_TSC();


void gestiona_CERRAR_AMBITO_TSC();*/

  /*while (token != NULL) {
    token = strtok(NULL," \n\t");
    printf("%s\n", token);
    //ambito = (char*)malloc(sizeof(char) * (1 + strlen(token)));
    //strcpy(ambito, token);
    //categoria = atoi(strtok(NULL," \n\t"));
  //}*/


    return 0;
}

void gestiona_INICIA_TSA_MAIN() {
    tablaMain = tablaInit("main");
}

void gestiona_ABRIR_AMBITO_PPAL_MAIN() {
    return; /*nuestra funcion de abrir ambito solo inicializa la tabla, ya hecho antes*/
}

void gestiona_BUSCAR() {
    char* token;
    char* clase;
    char* instancia;
    elementoTablaSimbolos* e;
    char nombre_ambito_encontrado[MAX_NAME];
    
    token = strtok(NULL, " \r\n\t");
    if(!strcmp(token, TOK_DECLARAR_MAIN)) {
        token = strtok(NULL, " \r\n\t");
        buscarParaDeclararIdTablaSimbolosAmbitos(tablaMain, token, &e, "main", nombre_ambito_encontrado);
    } else if(!strcmp(token, TOK_DECLARAR_MIEMBRO_CLASE)) {
        clase = strtok(NULL, " \r\n\t");
        token = strtok(NULL, " \r\n\t");
        /*aun no funciona: falta abrir clase*/
        /*buscarParaDeclararMiembroClase(tsc, clase, token, &e, nombre_ambito_encontrado);*/
    } else if(!strcmp(token, TOK_DECLARAR_MIEMBRO_INSTANCIA)) {
        clase = strtok(NULL, " \r\n\t");
        token = strtok(NULL, " \r\n\t");
        /*aun no funciona: falta abrir clase*/
        /*buscarParaDeclararMiembroInstancia(tsc, clase, token, &e, nombre_ambito_encontrado);*/
    } else if(!strcmp(token, TOK_DECLARAR_ID_LOCAL_METODO)) {
        clase = strtok(NULL, " \r\n\t");
        token = strtok(NULL, " \r\n\t");
        /*aun no funciona: falta abrir clase*/
        /*buscarParaDeclararIdLocalEnMetodo(tsc, clase, token, &e, nombre_ambito_encontrado);*/
    } else if(!strcmp(token, TOK_JERARQUIA)) {
        token = strtok(NULL, " \r\n\t");
        clase = strtok(NULL, " \r\n\t");
        /*aun no funciona: falta abrir clase*/
        /*buscarIdEnJerarquiaDesdeClase(tsc, token, clase, &e, nombre_ambito_encontrado);*/
    } else if(!strcmp(token, TOK_ID_NO_CUALIFICADO)) {
        token = strtok(NULL, " \r\n\t");
        clase = strtok(NULL, " \r\n\t");
        /*aun no funciona: falta abrir clase*/
        /*buscarIdNoCualificado(tsc, tablaMain, token, clase, &e, nombre_ambito_encontrado);*/
    } else if(!strcmp(token, TOK_ID_CUALIFICADO_INSTANCIA)) {
        instancia = strtok(NULL, " \r\n\t");
        token = strtok(NULL, " \r\n\t");
        clase = strtok(NULL, " \r\n\t");
        /*aun no funciona: falta abrir clase*/
        /*buscarIdCualificadoInstancia(tsc, tablaMain, instancia, token, clase, &e, nombre_ambito_encontrado);*/
    } else if(!strcmp(token, TOK_ID_CUALIFICADO_CLASE)) {
        instancia = strtok(NULL, " \r\n\t");
        token = strtok(NULL, " \r\n\t");
        clase = strtok(NULL, " \r\n\t");
        /*aun no funciona: falta abrir clase*/
        /*buscarIdCualificadoClase(tsc, instancia, token, clase, &e, nombre_ambito_encontrado);*/
    }

}

void gestiona_INSERTAR_TSA_MAIN () {
    char* token;
    int categoria, tipo_basico, estructura, tipo_acceso, tipo_miembro;
    
    token = strtok(NULL, " \r\n\t");
    categoria = atoi(strtok(NULL, " \r\n\t"));
    tipo_basico = atoi(strtok(NULL, " \r\n\t"));
    estructura = atoi(strtok(NULL, " \r\n\t"));
    tipo_acceso = atoi(strtok(NULL, " \r\n\t"));
    tipo_miembro = atoi(strtok(NULL, " \r\n\t"));
    
    /*TODO: que cojones son todo eso*/
    /*also cosa importante: los ficheros suyos incluyen el prefijo ya en la llamada a insertar: deberiamos cambiarlo para que funcionen sus ficheros*/
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
    printf("finally");
}
