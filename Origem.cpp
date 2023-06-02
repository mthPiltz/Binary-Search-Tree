﻿/* Estruturas de Dados - Trabalho pratico

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

void insert(No*& root, int value); //ok
void escreve_ordenado(); // escreve em percurso em-ordem
int minimum(No* root); //ok
int maximum(No* root); // ok
int sucessor(No* root, int value);
int procecessor(No* root, int value);
int search(No*& root, int value); // ok
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
	
	minimum(root);
	maximum(root);
}

void insert(No*& tree, int value) {
	if (!tree) {
		tree = (No*)calloc(1, sizeof(No));
		tree->value = value;
		tree->right = NULL;
		tree->left = NULL;

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

int minimum(No* root) {
	if (!root->left) {
		std::cout << root->value;
		std::cout << "\n";
		return root->value;
	}

	return minimum(root->left);
}

int maximum(No* root) {
	if (!root->right) {
		std::cout << root->value;
		std::cout << "\n";
		return root->value;
	}

	return maximum(root->right);
}