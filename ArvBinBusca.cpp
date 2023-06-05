#include "ArvBinBusca.h"

ArvBinBusca::ArvBinBusca() {
    raiz = NULL;
}

ArvBinBusca::ArvBinBusca(const ArvBinBusca& outro) {
    copia(outro);
}

ArvBinBusca::~ArvBinBusca() {
    limpa();
}

ArvBinBusca& ArvBinBusca::operator=(const ArvBinBusca& outro) {
    limpa();
    copia(outro);
    return *this;
}

void ArvBinBusca::escreve_ordenado() {
    escreve_ordenado(raiz);
    putchar('\n');
}

void ArvBinBusca::escreve_ordenado(No* root) {
    if (root != nullptr) {
        escreve_ordenado(root->esq);
        std::cout << root->chave;
        std::cout << " ";
        escreve_ordenado(root->dir);
    }
}

void ArvBinBusca::escreve() {
    escreve("", raiz);
}

void ArvBinBusca::escreve(const std::string& prefixo, No* x) {
    if (x == NULL)
        return;

    bool ehDireito = x->pai and x->pai->dir == x;
    bool temIrmaoEsq = x->pai and x->pai->esq;

    printf(prefixo.c_str());
    printf(ehDireito and temIrmaoEsq ? "├──" : "└──");

    if (x->pai == NULL) // raiz
        x->escreve("\n");
    else
        x->escreve(ehDireito ? "d\n" : "e\n");

    escreve(prefixo + (ehDireito and temIrmaoEsq ? "│   " : "    "), x->dir);
    escreve(prefixo + (ehDireito and temIrmaoEsq ? "│   " : "    "), x->esq);
}

No* ArvBinBusca::get_raiz() {
    return raiz;
}

No* ArvBinBusca::busca(int k) {
    return busca(raiz, k);
}

//No* ArvBinBusca::busca(No* x, int k) {
//    //TODO: implementar
//}
//
//No* ArvBinBusca::minimo() {
//    return raiz ? minimo(raiz) : NULL;
//}
//
//No* ArvBinBusca::minimo(No* x) {
//    //TODO: implementar
//}
//
//No* ArvBinBusca::maximo() {
//    return raiz ? maximo(raiz) : NULL;
//}
//
//No* ArvBinBusca::maximo(No* x) {
//    //TODO: implementar
//}
//
//No* ArvBinBusca::sucessor(No* x) {
//    //TODO: implementar
//}
//
//No* ArvBinBusca::predecessor(No* x) {
//    //TODO: implementar
//}

//void ArvBinBusca::insere(int chave) {
//    No* z = new No(chave);
//    insere(z);
//}
//
//void ArvBinBusca::insere(No* z) {
//    //TODO: implementar
//}

//void ArvBinBusca::transplante(No* u, No* v) {
//    //TODO: implementar
//}

bool ArvBinBusca::remove(int chave) {
    No* z = busca(raiz, chave);
    if (z == NULL)
        return false;

    remove(z);
    delete z;
    return true;
}

//void ArvBinBusca::remove(No* z) {
//    //TODO: implementar
//}

void ArvBinBusca::limpa() {
    limpa(raiz);
    raiz = NULL;
}

//void ArvBinBusca::limpa(No* x) {
//    //TODO: implementar
//}

void ArvBinBusca::copia(const ArvBinBusca& T) {
    if (T.raiz == NULL)
        raiz = NULL;
    else {
        raiz = new No(T.raiz->chave);
        copia(raiz, T.raiz);
    }
}

//void ArvBinBusca::copia(No* dest, No* orig) {
//    //TODO: implementar
//}
