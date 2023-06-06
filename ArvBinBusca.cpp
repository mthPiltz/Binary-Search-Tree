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
        cout << root->chave;
        cout << " ";
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

No* ArvBinBusca::busca(No* x, int k) {
    if (x) {
        if (x->chave == k){
            return x;
        }

        if (x->chave < k){
            return busca(x->dir, k);
        }
        else {
            return busca(x->esq, k);
        }
    }    
    
    return NULL;
}

No* ArvBinBusca::minimo() {
    return raiz ? minimo(raiz) : NULL;
}

No* ArvBinBusca::minimo(No* x) {
    No* temp = x;

    while (temp->esq)
    {
        temp = temp->esq;
    }

    return temp;
}

No* ArvBinBusca::maximo() {
    return raiz ? maximo(raiz) : NULL;
}

No* ArvBinBusca::maximo(No* x) {
    No* temp = x;

    while (temp->dir)
    {
        temp = temp->dir;
    }

    return temp;
}

No* ArvBinBusca::sucessor(No* x) {
    No* temp = x;

    if (temp->dir) {
        return minimo(temp->dir);
    }

    No* sucessor = NULL;

    while (temp->pai) {
        if (temp->pai->chave < x->chave) {
            temp = temp->pai;
        }
        else {
            return temp->pai;
        }
    }
    return NULL;

    return NULL;
}

No* ArvBinBusca::predecessor(No* x) {
    No* temp = x;

    if (temp->esq) {
        return maximo(temp->esq);
    }

    while (temp->pai)
    {
        if (temp->pai->chave > x->chave) {
            temp = temp->pai;
        }
        else {
            return temp->pai;
        }
    }

    return NULL;
}

void ArvBinBusca::insere(int chave) {
    No* z = new No(chave);
    insere(z);
}

void ArvBinBusca::insere(No* z) {
    if (!raiz) {
        raiz = z;
        return;
    }

    No* atual = raiz;
    No* pai = NULL;

    while (atual)
    {
        pai = atual;

        if (atual->chave < z->chave) {
            atual = atual->dir;
        }
        else {
            atual = atual->esq;
        }
    }

    if (pai->chave < z->chave) {
        z->pai = pai;
        pai->dir = z;
    }
    else {
        pai->esq = z;
        z->pai = pai;
    }
}

void ArvBinBusca::transplante(No* u, No* v) {
    //TODO: implementar
}

bool ArvBinBusca::remove(int chave) {
    No* z = busca(raiz, chave);
    if (z == NULL)
        return false;

    remove(z);
    delete z;
    return true;
}

void ArvBinBusca::remove(No* z) {
    if (z->esq == nullptr && z->dir == nullptr) {
        No* pai = z->pai;
        if (pai == nullptr) {
            raiz = nullptr;  
        }
        else if (pai->esq == z) {
            pai->esq = nullptr; 
        }
        else {
            pai->dir = nullptr; 
        }
    }
    else if (z->esq == nullptr || z->dir == nullptr) {
        No* filho = (z->esq != nullptr) ? z->esq : z->dir;  
        No* pai = z->pai;
        if (pai == nullptr) {
            raiz = filho;  
        }
        else if (pai->esq == z) {
            pai->esq = filho; 
        }
        else {
            pai->dir = filho; 
        }
    }
    else {
        No* no_sucessor = sucessor(z->dir); 
        No* paiSucessor = no_sucessor->pai;

        if (paiSucessor != z) {
            paiSucessor->esq = no_sucessor->dir;
            no_sucessor->dir = z->dir; 
        }

        no_sucessor->esq = z->esq;  

        No* pai = z->pai;
        if (pai == nullptr) {
            raiz = no_sucessor;  
        }
        else if (pai->esq == z) {
            pai->esq = no_sucessor;
        }
        else {
            pai->dir = no_sucessor; 
        }
    }
}

void ArvBinBusca::limpa() {
    limpa(raiz);
    raiz = NULL;
}

void ArvBinBusca::limpa(No* x) {
    //TODO: implementar
}

void ArvBinBusca::copia(const ArvBinBusca& T) {
    if (T.raiz == NULL)
        raiz = NULL;
    else {
        raiz = new No(T.raiz->chave);
        copia(raiz, T.raiz);
    }
}

void ArvBinBusca::copia(No* dest, No* orig) {
    //TODO: implementar
}
