#pragma once

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
No* minimum(No* root); //ok
No* maximum(No* root); // ok
No* sucessor(No* root, int value); //ok
No* predecessor(No* root, int value); //ok
No* search(No*& root, int value); //ok
bool remove(No*& root, int value); //ok
void clean(No*& root); //ok
void copy(No* original, No*& rootCopy); //ok

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
		std::cout << "N�o encontrado";
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

No* minimum(No* root) {
	if (!root->left) {
		return root;
	}

	return minimum(root->left);
}

No* maximum(No* root) {
	if (!root->right) {
		return root;
	}

	return maximum(root->right);
}

No* sucessor(No* root, int value) {
	No* current = search(root, value);

	if (current->right) {
		return minimum(current->right);
	}

	No* sucessor = NULL;

	while (current->parent) {
		if (current->parent->value < value) {
			current = current->parent;
		}
		else {
			return current->parent;
		}
	}
	return NULL;
}

No* predecessor(No* root, int value) {
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
			return current->parent;
		}
	}

	return NULL;
}

void writeInOrder(No*& root) {
	if (root != nullptr) {
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

void copy(No* original, No*& rootCopy) {
	if (original) {
		rootCopy = (No*)calloc(1, sizeof(No));
		rootCopy->left = original->left;
		rootCopy->right = original->right;
		rootCopy->parent = original->parent;
		rootCopy->value = original->value;

		copy(original->left, rootCopy->left);
		copy(original->right, rootCopy->right);
	}
}

bool remove(No*& root, int value) {
	No* nodeToRemove = search(root, value);

	if (!nodeToRemove) {
		return false; // N� n�o encontrado, retorna false
	}

	No* parent = nodeToRemove->parent;

	// Caso 1: N� folha
	if (!nodeToRemove->left && !nodeToRemove->right) {
		if (!parent) {
			root = nullptr; // N� raiz
		}
		else if (nodeToRemove == parent->left) {
			parent->left = nullptr; // N� filho esquerdo
		}
		else {
			parent->right = nullptr; // N� filho direito
		}
		delete nodeToRemove;
		return true;
	}

	// Caso 2: N� com apenas um filho

	if (!nodeToRemove->left) {
		if (!parent) {
			root = nodeToRemove->right; // N� raiz
		}
		else if (nodeToRemove == parent->left) {
			parent->left = nodeToRemove->right; // N� filho esquerdo
		}
		else {
			parent->right = nodeToRemove->right; // N� filho direito
		}
		delete nodeToRemove;
		return true;
	}

	if (!nodeToRemove->right) {
		if (!parent) {
			root = nodeToRemove->left; // N� raiz
		}
		else if (nodeToRemove == parent->left) {
			parent->left = nodeToRemove->left; // N� filho esquerdo
		}
		else {
			parent->right = nodeToRemove->left; // N� filho direito
		}
		delete nodeToRemove;
		return true;
	}

	// Caso 3: N� com dois filhos
	No* successor = nodeToRemove->right;
	No* successorParent = nodeToRemove;

	// Encontra o n� sucessor (o menor n� na sub�rvore direita)
	while (successor->left) {
		successorParent = successor;
		successor = successor->left;
	}

	// Atualiza os ponteiros
	nodeToRemove->value = successor->value;

	if (successor == successorParent->left) {
		successorParent->left = successor->right;
	}
	else {
		successorParent->right = successor->right;
	}

	delete successor;


	return true;
}