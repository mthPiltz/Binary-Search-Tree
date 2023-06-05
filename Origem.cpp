/* Estruturas de Dados - Trabalho pratico

Professor: Diego P. Rubert
Aluno(s): Matheus Piltz Scariot

*/
#include <iostream>
#include <cstdio>
#include <string>

struct No {
	No* parent;
	No* left;
	No* right;
	int value;
};

void insertRecursive(No*& root, int value, No* nodeParent = NULL); //ok
void insert(No*& tree, int value);
void escreve_ordenado(); // escreve em percurso em-ordem
int minimum(No* root); //ok
int maximum(No* root); // ok
int sucessor(No* root, int value); //ok
int predecessor(No* root, int value);
No* search(No*& root, int value); // ok
char remove(No* root, int value);
void limpa(No* root);
void copia(No* original, No* copy);

int main() {
	No* root = NULL;

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
	
	int a = sucessor(root, 23);
	std::cout << a;
}

void insert(No*& tree, int value) {
	insertRecursive(tree, value, NULL);
}

void insertRecursive(No*& tree, int value, No* nodeParent) {
	if (!tree) {
		tree = (No*)calloc(1, sizeof(No));
		tree->parent = nodeParent;
		tree->value = value;
		tree->right = NULL;
		tree->left = NULL;

		return;
	}

	if (tree->value < value) {
		insertRecursive(tree->right, value, tree);
	}
	else {
		insertRecursive(tree->left, value, tree);
	}
}

No* search(No*& tree, int value) {
	if (!tree) {
		std::cout << "Não encontrado";
		return NULL;
	}

	if (tree->value == value) {
		return tree;
	}

	if (tree->value < value) {
		return search(tree->right, value);
	}
	else {
		return search(tree->left, value);
	}
}

int minimum(No* root) {
	if (!root->left) {
		return root->value;
	}

	return minimum(root->left);
}

int maximum(No* root) {
	if (!root->right) {
		return root->value;
	}

	return maximum(root->right);
}

int sucessor(No* root, int value) {
	No* atual = search(root, value);
	
	if (atual->right) {
		return minimum(atual->right);
	}

	No* sucessor = NULL;

	while (atual->parent) {
		if (atual->parent->value < value) {
			atual = atual->parent;
		}
		else
		{
			return atual->parent->value;		}
	}
	return -1;
}