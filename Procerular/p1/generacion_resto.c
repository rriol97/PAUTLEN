#include "generacion.h"

void resto(FILE* fpasm, int es_variable_1, int es_variable_2) {

	if (!fpasm) {
		printf("Error del fichero (dividir)\n");
	}

	else {
		fprintf(fpasm, "\tpop ecx\n\tpop eax\n");

		if (es_variable_1) {
			fprintf(fpasm, "\tmov eax, [eax]\n");
		} 

		if (es_variable_2) {
			fprintf(fpasm, "\tmov ecx, [ecx]\n");
		} 

		fprintf(fpasm, "\tidiv ecx\n\tpush edx\n");
	}
	
	return;
}
