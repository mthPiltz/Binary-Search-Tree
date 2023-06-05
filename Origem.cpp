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
void insert(No*& tree, int value); //ok
void writeInOrder(No*& root); //ok
int minimum(No* root); //ok
int maximum(No* root); // ok
int sucessor(No* root, int value); //ok
int predecessor(No* root, int value); //ok
No* search(No*& root, int value); //ok
char remove(No* root, int value);
void clean(No*& root); //ok
void copy(No* original, No* copy);

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
	
	writeInOrder(root);
	clean(root);
	writeInOrder(root);
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
	No* current = search(root, value);
	
	if (current->right) {
		return minimum(current->right);
	}

	No* sucessor = NULL;

	while (current->parent) {
		if (current->parent->value < value) {
			current = current->parent;
		}
		else{
			return current->parent->value;		
		}
	}
	return -1;
}

int predecessor(No* root, int value) {
	No* current = search(root, value);

	if (current->left) {
		return maximum(current->left);
	}

	while (current->parent)
	{
		if (current->parent->value > value) {
			current = current->parent;
		}
		else {
			return current->parent->value;		
		}
	}

	return -1;
}

void writeInOrder(No*& root) {
	if (root) {
		writeInOrder(root->left);
		std::cout << root->value;
		std::cout << " ";
		writeInOrder(root->right);
	}
}

void clean(No*& root) {
	if (root) {
		clean(root->left);
		clean(root->right);
		memset(root, 0, sizeof(*root));
	}
}