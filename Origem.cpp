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
No* minimum(No* root); //ok
No* maximum(No* root); // ok
No* sucessor(No* root, int value); //ok
No* predecessor(No* root, int value); //ok
No* search(No*& root, int value); //ok
bool remove(No* root, int value); //ok
void clean(No*& root); //ok
void copy(No* original, No*& rootCopy); //ok

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
		else{
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

bool remove(No* root, int value) {
	No* current = root;
	No* parent = nullptr;

	// Localiza o nó a ser removido
	while (current != nullptr && current->value != value) {
		parent = current;
		if (value < current->value) {
			current = current->left;
		}
		else {
			current = current->right;
		}
	}

	// Verifica se o nó foi encontrado
	if (current == nullptr) {
		return false; // Nó não encontrado, retorna false
	}

	// Caso 1: Nó folha
	if (current->left == nullptr && current->right == nullptr) {
		if (parent == nullptr) {
			delete current; // Nó raiz
		}
		else if (current == parent->left) {
			parent->left = nullptr; // Nó filho esquerdo
		}
		else {
			parent->right = nullptr; // Nó filho direito
		}
		delete current;
	}
	// Caso 2: Nó com apenas um filho
	else if (current->left == nullptr) {
		if (parent == nullptr) {
			root = current->right; // Nó raiz
		}
		else if (current == parent->left) {
			parent->left = current->right; // Nó filho esquerdo
		}
		else {
			parent->right = current->right; // Nó filho direito
		}
		delete current;
	}
	else if (current->right == nullptr) {
		if (parent == nullptr) {
			root = current->left; // Nó raiz
		}
		else if (current == parent->left) {
			parent->left = current->left; // Nó filho esquerdo
		}
		else {
			parent->right = current->left; // Nó filho direito
		}
		delete current;
	}
	// Caso 3: Nó com dois filhos
	else {
		No* successor = current->right;
		No* successorParent = current;

		// Encontra o nó sucessor (o menor nó na subárvore direita)
		while (successor->left != nullptr) {
			successorParent = successor;
			successor = successor->left;
		}

		// Atualiza os ponteiros
		current->value = successor->value;

		if (successor == successorParent->left) {
			successorParent->left = successor->right;
		}
		else {
			successorParent->right = successor->right;
		}

		delete successor;
	}

	return true;
}
