// libre.h
#ifndef _LIBRE_H
#define _LIBRE_H

/* variaveis */
extern float x;
extern int vetor[];

typedef struct st_lista
{
	int dado;
	struct st_lista *prox;
}lista;

typedef struct st_arvore
{
	int num;
	struct st_arvore *direita, *esquerda;
}arvore;

/* funcoes */
float normalizacao(float x, float Xmin, float Xmax); /* normaliza um valor x, dado o seu máximo e mínimo */
int sorteio(int vetor[], int n); /* realiza um sorteio sem repeticao de um vetor */
char concatenar(char string1[], int i1, char string2[], int i2, char string3[]); /* junta(concatena) duas strings */
void prefixo(char string[], int n); /* printa os possíveis prefixos da palavra */
void sufixo(char string[], int n); /* printa os possíveis sufixos da palavra */
void inverter(char vetor[]); /* inverte a palavra */
void inverter2(char vetor[]);
void inserir(lista **cabeca, int x); /* insere um elemento à uma lista */
lista *empilhar(lista *topo, int n); /* empilha um numero no topo da pilha */
void imprimir(lista *cabeca); /* imprime todos os componentes de uma lista */
void sorteio_lista(lista *l1, int k,  int n); /* realiza um sorteio sem repeticao de uma lista */
arvore *inserir_arvore(arvore *raiz, int valor); /* insere numeros numa arvore binária */
void preorder(arvore *raiz); /*imprime os valores de uma arvore na ordem raiz, esquerda, direita) */
void inorder(arvore *raiz); /* imprime os valores de uma arvore na ordem esquerda, raiz, direita) */
void posorder(arvore *raiz); /* imprime os valores de uma arvore na ordem esquerda, direita, raiz */
void limpar_arvore(arvore *raiz); /* limpa a memoria utilizada pela arvore */

#endif

