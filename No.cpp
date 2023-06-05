#include "No.h"
#include <stdio.h>

No::No(const int chave) :
	chave(chave),
	pai(NULL),
	esq(NULL),
	dir(NULL) {
}

void No::escreve(const char* sep) {
	printf("%2d%s", chave, sep);
}