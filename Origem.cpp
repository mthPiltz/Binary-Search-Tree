/* Estruturas de Dados - Trabalho pratico

Professor: Diego P. Rubert
Aluno(s): Matheus Piltz Scariot

*/
#include <string>
#include "tree.h"

int main() {
	No* root = NULL;
	No* rootCopy = NULL;

	insert(root, 10);
	insert(root, 5);
	insert(root, 20);
	insert(root, 3);
	insert(root, 7);
	insert(root, 12);
	insert(root, 22);
	insert(root, 1);
	insert(root, 4);
	insert(root, 6);
	insert(root, 9);
	insert(root, 11);
	insert(root, 13);
	insert(root, 21);
	insert(root, 23);
	
	writeInOrder(root);
	std::cout << "\n";
	remove(root, 20);
	remove(root, 21);
	remove(root, 1);
	writeInOrder(root);
}

