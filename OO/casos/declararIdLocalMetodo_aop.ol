main {

	class AA {

		// Metodos
		function int mA1 (int p1) { printf 0;} 	// CASO 60: SE BUSCA PARA DECLARAR UN PARÁMETRO (p1) NO DECLARADO
						// DEBE DEVOLVER ERR, NO ESTÁ Y SE PUEDE DECLARAR
		function int mA2 (int p1, int p1) {  printf p1;}	 // CASO 61: SE BUSCA PARA DECLARAR UN PARÁMETRO (p1) YA DECLARADO
						// DEBE DEVOLVER OK, YA ESTÁ Y NO SE PUEDE DECLARAR
		function int mA3 (int p1; boolean mA3) { printf p1;}  // CASO 	62: SE BUSCA PARA DECLARAR UN PARAMETRO (mA3) 
						// YA DECLARADO COMO FUNCIÓN, SE DELEGA ESTE CASO A LA COINCIDENCIA DE NOMBRE INTERNO
						// ES DECIR, EN ESTE CASO, LA FUNCIÓN TIENE COMO NOMBRE mA3@1@3 Y EL PARÁMETRO SIMPLEMENTE
						// ma3 POR LO QUE NO ES EL MISMO SÍMBOLO Y DARÍA ERROR, NO ESTÁ DECLARADA Y SE PUEDE PUEDE DECLARAR
		function int mA4 () { int v2; printf v2;}  // CASO 63: SE BUSCA PARA DECLARAR UNA VARIABLE LOCAL(v2) NO DECLARADA
						// DEBE DEVOLVER ERR, NO ESTÁ DECLARADA Y SE PUEDE DECLARAR
		function int mA5 (int v1) {int v1;  printf v1;} // CASO 64: SE BUSCA PARA DECLARAR UNA VARIABLE LOCAL(v1) DECLARADA
						// PREVIAMENTE COMO ARGUMENTO, DEBE DEVOLVER OK, ESTÁ YA DECLARADO Y NO SE PUEDE DECLARAR
		function int mA6 () {int v1; boolean v1; printf v1;} // CASO 65: SE BUSCA PARA DECLARAR UNA VARIABLE LOCAL(v1) DECLARADA
						// PREVIAMENTE COMO LOCAL, DEBE DEVOLVER OK, ESTÁ YA DECLARADO Y NO SE PUEDE DECLARAR
		function int mA7(int p1) {int mA7;} // CASO 66: SE BUSCA PARA DECLARAR UNA VARIABLE LOCAL(mA7) DECLARADA
						// PREVIAMENTE COMO FUNCIÓN, Y ADEMÁS EL MÉTODO TIENE ARGUMENTOS, EN ESTE CASO 
						// COMO TIENE ARGUMENTOS EL NOMBRE DE LA FUNCIÓN TENDRA @s Y NO COLISIONARÁ CON EL DE
						// LA VARIABLE, DEBE DEVOLVER ERR, NO ESTÁ DECLARADA Y SE PUEDE DECLARAR
		function int mA8() {int mA8} 	// CASO 67: SE BUSCA PARA DECLARAR UNA VARIABLE LOCAL(mA8) DECLARADA
						// PREVIAMENTE COMO FUNCION, AUNQUE EL MÉTODO NO TIENE ARGUMENTOS,NO COLISIONARÁ CON EL DE
						// LA VARIABLE, YA QUE EL PREFIJO DE LA FUNCIÓN ES EL DE LA CLASE Y EL DE LA VARIABLE ES EL DEL
						// METODO. DEBE DEVOLVER ERROR, NO ESTÁ DECLARADA Y  SE PUEDE DECLARAR
	};
	
	printf 0;
}
