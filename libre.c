// libre.c
#include "libre.h"
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<string.h>

float normalizacao(float x, float Xmin, float Xmax)
{

	float Xn = 0;

	Xn = (x - Xmin)/(Xmax - Xmin);
	printf("O valor normalizado de x é: %f\n", Xn);

	return Xn;

}

int sorteio(int vetor[], int n)
{
	int i = 0;
	int j;
	int repeticao;

	do
	{
		vetor[i] = rand() % n;
		repeticao = 0;

		for(j = 0; j < i; j++)
		{
			if(vetor[j] == vetor[i])
				repeticao = 1;
		}

		if(repeticao == 0)
		{
			vetor[n] = vetor[i];
			i++;
		}

	}while(i < n);

	for(i = 0; i < n; i++)
	{
		printf("%d", vetor[i]);
	    printf("\n");
	}

	return vetor[n];
}

void inverter(char vetor[])
{
	int i, aux, fim, size;

	size = strlen(vetor);
	fim = size - 1;

	for(i = 0; i < size/2; i++)
	{
		aux = vetor[i];
		vetor[i] = vetor[fim];
		vetor[fim] = aux;
		fim--;
	}

}

void inverter2(char vetor[])
{
	int i, size;
	char aux;
	size = strlen(vetor);

	for(i = 0; i < size/2; i++)
	{
		aux = vetor[i];
		vetor[i] = vetor[size - i - 1];
		vetor[size - i - 1] = aux;
	}


}

void prefixo(char string[], int n)
{
	int i = 0;
	int j = 0;

	printf("Possíveis prefixos da palavra: \n");

	do
	{

		for(j = 0; j < i; j++)
		{
			printf("%c", string[j]);
		}

		printf("\n");

		i++;

	}while(i < n+1);

	printf("\n");

}

void sufixo(char string[], int n)
{
	int i = 0;
  	int j = 0;

	printf("Possíveis sufixos da palavra: \n");

	do
	{

	  	for(i = n-1; i >= n-j; i--)
	  	{
	  		printf("%c", string[i]);
		}

		printf("\n");
	
		j++;

	}while(j < n + 1);

	printf("\n");

}

char concatenar(char string1[], int i1, char string2[], int i2, char string3[])
{
	int i;
	int j;

	for(i = 0; i < i1; i++)
	{
		string3[i] = string1[i];
	}

	for(j = 0; j < i2; j++)
	{
		string3[i2 + j] = string2[j];
	}

	return string3[i1+i2];
}
/* funcoes relacionadas a listas */

// Algoritmo de inclusao ao final

void inserir(lista **cabeca, int x)
{
	lista *p = *cabeca;
	lista *novo = NULL;
	while(p != NULL)
	{
		novo = p;
		p = p->prox;
	}
	p = malloc(sizeof(lista));
	p->dado = x;
	p->prox = NULL;
	if(novo != NULL)
		novo->prox = p;
	else
		*cabeca = p;
}

lista *empilhar(lista *topo, int n)
{
	lista *novo = malloc(sizeof(lista));

	if(novo)
	{
		novo->dado = n;
		novo->prox = topo;
		return novo;
	}
	else
		printf("Erro ao alocar memoria\n");
	return NULL;
		
}

// Algoritmo imprimir uma lista completa

void imprimir(lista *cabeca)
{
	lista *p = cabeca;
	while(p != NULL)
	{
		printf("%d ", p->dado);
		p = p->prox;
	}
	printf("NULL\n");
}

// Algoritmo de busca de um elemento dentro de uma lista

lista *buscar(lista *cabeca, int x)
{
	lista *p = cabeca;

	while(p != NULL)
	{
		if(p->dado == x)
			return p;
		
		p = p->prox;
	}

	return NULL;
}

// Algoritmo sorteio sem repeticao

void sorteio_lista(lista *l1, int k, int n)
{
	srand(time(NULL));
	lista *p = NULL;
	int i = 0, j = 0, repeticao = 0, sorteio = 0;

	do
	{
		sorteio = rand() % n; // sorteia um numero entre 0 e n onde n é o maior numero da lista
		p = buscar(l1, sorteio);

		repeticao = 0;

		for(j = 0; j < i; j++)
		{
			if(p->prox->dado == p->dado)
			{
				printf("DEBUG\n");
				repeticao = 1;
			}
		}
		
		if(repeticao == 0)
		{
			p = p->prox;
			i++;
		}
		printf("numero sorteado: %d\n", p->dado); 

	}while(i < k);

}

arvore *inserir_arvore(arvore *raiz, int valor)
{
	if(raiz == NULL)
	{
		arvore *aux = malloc(sizeof(arvore));
		aux->num = valor;
		aux->esquerda = NULL;
		aux->direita = NULL;
		return aux;
	}
	else
	{
		if(valor < raiz->num)
			raiz->esquerda = inserir_arvore(raiz->esquerda, valor);
		else
			raiz->direita = inserir_arvore(raiz->direita, valor);
		return raiz;
	}
}

void preorder(arvore *raiz)
{
	if(raiz != NULL)
	{
		printf("%d; ", raiz->num);
		preorder(raiz->esquerda);
		preorder(raiz->direita);
	}
}

void inorder(arvore *raiz)
{
	if(raiz != NULL)
	{
		inorder(raiz->esquerda);
		printf("%d; ", raiz->num);
		inorder(raiz->direita);
	}
}

void posorder(arvore *raiz)
{
	if(raiz != NULL)
	{
		posorder(raiz->esquerda);
		posorder(raiz->direita);
		printf("%d; ", raiz->num);
	}
}

void limpar_arvore(arvore *raiz)
{
	if(raiz != NULL)
	{
		limpar_arvore(raiz->direita);
		limpar_arvore(raiz->esquerda);
		free(raiz);
	}
}

