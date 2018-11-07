/********************************
Fichero: prueba_TS.c
Autores: Francisco de Vicente Lana, Miguel García Moya, Manuel Suárez y Ricardo Riol González
Descripcion: programa principal de la tabla de símbolos
*********************************/
#include "prueba_TS.h"

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

int main(int argc, char *argv) {
  FILE *f_in, *f_out;
  char *linea;

  /* Comprobacion argumentos de entrada */
  if (argc != 3) {
    printf("./prueba_TS <fichero_de_lectura> <fichero_de_escritura>\n");
    return EXIT_FAILURE;
  }

  /* Apertura dichero entrada */
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
  fclose(yyin);
  fclose(fout);

  return EXIT_SUCCESS;
}

int procesar_linea(char *linea) {
  char *palabra1, *ambito, *categoria;
  char token[MAX];

  token = strtok(linea, " \n\t");
  palabra1 = (char*)malloc(sizeof(char) * (1 + strlen(token)));
  strcpy(palabra1, token);

  if (!strcmp(palabra1, TOK_OP_INICIA_TSA_MAIN)) {
    gestiona_INICIA_TSA_MAIN();
  } else if (!strcmp(palabra1, TOK_OP_ABRIR_AMBITO_PPAL_MAIN)) {
    gestiona_ABRIR_AMBITO_PPAL_MAIN();
  } else if (!strcmp(palabra1, TOK_OP_BUSCAR)) {
    gestiona_BUSCAR();
  } else if (!strcmp(palabra1, TOK_OP_INSERTAR_TSA_MAIN)) {
    gestiona_INSERTAR_TSA_MAIN();
  } else if (!strcmp(palabra1, TOK_OP_ABRIR_AMBITO_TSA_MAIN)) {
    gestiona_ABRIR_AMBITO_TSA_MAIN();
  } else if (!strcmp(palabra1, TOK_OP_CERRAR_AMBITO_TSA_MAIN)) {
    gestiona_CERRAR_AMBITO_TSA_MAIN();
  } else if (!strcmp(palabra1, TOK_OP_INICIA_TSC)) {
    gestiona_INICIA_TSC();
  } 
  //...
  else if (!strcmp(palabra1, TOK_OP_CERRAR_CLASE)) {

  } else if (!strcmp(palabra1, TOK_OP_CERRAR_TSA_MAIN)) {

  } else if (!strcmp(palabra1, TOK_OP_CERRAR_TSC)) {

  } else if (!strcmp(palabra1, )) {

  } else if (!strcmp(palabra1, )) {

  } else if (!strcmp(palabra1, )) {

  } else if (!strcmp(palabra1, ))

  while (token != NULL) {
    token = strtok(NULL," \n\t");
    ambito = (char*)malloc(sizeof(char) * (1 + strlen(token)));
    strcpy(ambito, token);
    categoria = atoi(strtok(NULL," \n\t"));
  }



}
