#pragma once
#include <stdio.h>
#include <iostream>
#include <string>
#include "../trabalho-base-professor/No.h"

class ArvBinBusca
{
public:
	ArvBinBusca();
	ArvBinBusca(const ArvBinBusca& outro); // construtor de c�pia
	~ArvBinBusca();
	ArvBinBusca& operator=(const ArvBinBusca& outro); // operador de atribui��o

	void escreve_ordenado(); // escreve em percurso em-ordem
	void escreve();

	No* get_raiz(); // devolve a raiz
	No* busca(int k); // devolve o ponteiro para um elemento, se achar, ou NULL
	No* minimo(); // devolve o menor elemento da �rvore
	No* maximo(); // devolve o maior elemento da �rvore
	No* sucessor(No* x); // devolve o sucessor de um elemento
	No* predecessor(No* x); // devolve o predecessor de um elemento

	void insere(int chave); // insere um elemento
	bool remove(int chave); // busca e remove um elemento

	void limpa(); // remove todos elementos da �rvore, liberando a memoria

private:
	No* raiz;

	void escreve_ordenado(No* x); // escreve em percurso em-ordem
	void escreve(const std::string& prefixo, No* x);

	No* busca(No* x, int k); // Parte recursiva da busca
	No* minimo(No* x); // Parte recursiva de minimo
	No* maximo(No* x); // Parte recursiva de maximo

	void insere(No* z); // Insercao, mas ja recebe pronto o no (nao a chave) a ser inserido
	void transplante(No* u, No* v); // Transplante
	void remove(No* z); // Recebe o no a ser removido (deve tratar todos os casos e fazer transplante, se necessario)

	void limpa(No* x); // dado um n� x, remove recursivamente elementos abaixo e deleta x

	void copia(const ArvBinBusca& T); // copia uma �rvore T para a atual a partir da raiz,
									  // usada no construtor de c�pia e no operador de atribui��o
	void copia(No* dest, No* orig);   // copia um n� e os descendentes recursivamente
};

