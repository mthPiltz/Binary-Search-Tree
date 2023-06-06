/* Estruturas de Dados - Trabalho pratico

Professor: Diego P. Rubert
Aluno(s): Matheus Piltz Scariot

*/
#include <string>
#include "ArvBinBusca.h"



int main(void)
{
  ArvBinBusca T; // construtor ArvBinBusca()
  int v[] = {10, 25, 0, 16, 20, 9, 15, 6, 14, 7, 18, 12, 22, 19, 3, 13};
  
  for (const auto &x : v)
    T.insere(x); 
  
  printf("T:\n");
  T.escreve();
  printf("Valores de T em ordem crescente: ");
  T.escreve_ordenado(); 

  No *raiz = T.get_raiz();
  printf("Raiz: ");
  raiz->escreve("\n");

  return 0;

  No *pre = T.predecessor(raiz);
  printf("Predecessor da raiz: ");
  pre->escreve("\n");
  No *suc = T.sucessor(raiz);
  printf("Sucessor da raiz: ");
  suc->escreve("\n");

  printf("Sucessor do predecessor da raiz (== raiz): ");
  T.sucessor(pre)->escreve("\n");
  printf("Predecessor do sucessor da raiz (== raiz): ");
  T.predecessor(suc)->escreve("\n");

  No *minimo = T.minimo();
  No *maximo = T.maximo();
  printf("Mínimo: ");
  minimo->escreve("\n");
  printf("Máximo: ");
  maximo->escreve("\n");

  return 0; //TODO: remover após implementar remoção

  T.remove(0); // Caso 1
  T.remove(13); // Caso 2
  T.remove(10); // Caso 3b + 3a

  printf("T:\n");
  T.escreve();

  return 0; //TODO: remover após implementar construtor de cópia e operador de atribuição
  
  ArvBinBusca T2(T); // construtor de cópia
  T2.insere(30);
  printf("T:\n");
  T.escreve();
  printf("T2:\n");
  T2.escreve();

  ArvBinBusca T3 = T; // construtor de cópia
  T3.insere(-8);
  printf("T:\n");
  T.escreve();
  printf("T3:\n");
  T3.escreve();

  T3 = T; // operador de atribuição
  T3.insere(100);
  printf("T:\n");
  T.escreve();
  printf("T3:\n");
  T3.escreve();
  
  return 0;
}