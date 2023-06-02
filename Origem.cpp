/* Estruturas de Dados - Trabalho pratico

Professor: Diego P. Rubert
Aluno(s): Matheus Piltz Scariot

*/
#include <iostream>
#include <cstdio>
#include <string>

struct No {
	No* left;
	No* right;
	int value;
};

void insert(No*& root, int value);
void escreve_ordenado(); // escreve em percurso em-ordem
int minimo(No* root);
int maximo(No* root);
int sucessor(No* root, int value);
int procecessor(No* root, int value);
int search(No*& root, int value);
char remove(No* root, int value);
void limpa(No* root);
void copia(No* original, No* copy);

int main() {
	No* root = NULL;

	insert(root, 5);
}

void insert(No*& tree, int value) {
	if (!tree) {
		tree = (No*)calloc(1, sizeof(No));
		tree->value = value;
		tree->right = (No*)calloc(1, sizeof(No));
		tree->left = (No*)calloc(1, sizeof(No));

		return;
	}

	if (tree->value < value) {
		insert(tree->right, value);
	}
	else {
		insert(tree->left, value);
	}
}

int search(No*& tree, int value) {
	if (!tree) {
		std::cout << "Não encontrado";
		return -1;
	}

	if (tree->value == value) {
		std::cout << tree->value;
		return tree->value;
	}

	if (tree->value < value) {
		return search(tree->right, value);
	}
	else {
		return search(tree->left, value);
	}
}