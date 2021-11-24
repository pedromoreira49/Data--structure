#include <stdio.h>
#include "listade.h"

void criaLista(Listade *lt){
	lt->inicio = NULL;
	lt->fim = NULL;
	lt->n = 0;
}

void exibeLista(Listade lt){
	Nodo *pAux;
	Nodo *_pAux;
	int __pAux;
	pAux = lt.inicio;
	_pAux = lt.fim;
	__pAux = lt.n;
	printf("Inicio: %x - N: %d - Fim: %x\n", pAux, __pAux, _pAux);
	while(pAux != NULL){
		printf("EndNodo: %x - EndAnt: %x -  cod: %3d - peso: %.2f - ProxEnd: %x\n", pAux, pAux->ant, pAux->info.cod, pAux->info.peso, pAux->prox);
		pAux = pAux->prox;
	}
}

int incluiNoInicio(Listade *lt, Dado d){
	Nodo *pNodo;
	pNodo = (Nodo *) malloc (sizeof (Nodo));
	if(pNodo == NULL){
		return FALTOU_MEMORIA;
	}else{
		pNodo->info = d;
		pNodo->ant = NULL;
		pNodo->prox = lt->inicio;
		if(lt->n == 0){
			lt->fim = pNodo;
		}else{
			lt->inicio->ant = pNodo;
		}
		lt->inicio = pNodo;
		lt->n++;
		return SUCESSO;
	}
}

int excluiDoInicio(Listade *lt, Dado *d){
	Nodo *pNodo;
	if(lt->n == 0){
		return LISTA_VAZIA;
	}else{
		*d = lt->inicio->info;
		pNodo = lt->inicio;
		lt->inicio = lt->inicio->prox;
		if(lt->n == 1){
			lt->fim = NULL;
		}else{
			lt->inicio->ant = NULL;
		}
		lt->n--;
		free(pNodo);
		return SUCESSO;
	}
}

int quantidadeDeNodos(Listade lt){
	return lt.n;
}

int estaVazia(Listade lt){
	if(lt.inicio == NULL && lt.fim == NULL){
		return LISTA_VAZIA;
	}else{
		return SUCESSO;
	}
}

int incluiNoFim(Listade *lt, Dado d){
	Nodo *pNodo;
	pNodo = (Nodo *) malloc(sizeof(Nodo));
	if(pNodo == NULL){
		return FALTOU_MEMORIA;
	}else{
		pNodo->info = d;
		pNodo->prox = NULL;
		if(lt->n == 0){
			pNodo->ant = NULL;
			lt->inicio = pNodo;
		}else{
			lt->fim->prox = pNodo;
			pNodo->ant = lt->fim;
		}
		lt->fim = pNodo;
		lt->n++;
		return SUCESSO;
	}
}

int excluiDoFim(Listade *lt, Dado *d){
	Nodo *pNodo;
	if(lt->n == 0){
		return LISTA_VAZIA;
	}else{
		*d = lt->fim->info;
		pNodo = lt->fim;
		lt->fim = lt->fim->ant;
		if(lt->n == 1){
			lt->inicio = NULL;
		}else{
			lt->inicio->prox = NULL;
		}
		lt->n--;
		free(pNodo);
		return SUCESSO;
	}
}

int consultaPorCodigo(Listade lt, int cod, Dado *d){
	Nodo *pNodo;

	pNodo = lt.inicio;
	while(pNodo->info.cod != cod){
		if(pNodo->prox == NULL){
			return CODIGO_INEXISTENTE;
		}
		pNodo = pNodo->prox;
	}
	*d = pNodo->info;
	return SUCESSO;
}
