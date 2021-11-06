#include <stdio.h>
#include "pilhase.h"
#include <stdlib.h>

void criaPilha(Pilha *pl){
	pl->topo = NULL;
}

void exibe(Pilha pl){
	Nodo *pNodo;
	pNodo = pl.topo;
	while(pNodo != NULL){
		printf("EndNodo: %p - cod: %d - peso: %.2f - proxEnd: %p\n", pNodo, pNodo->info.cod, pNodo->info.peso, pNodo->prox);
		pNodo = pNodo->prox;
	}
}

int empilha(Pilha *pl, Dado d){
	Nodo *pNodo;
	pNodo = (Nodo *) malloc (sizeof(Nodo));
	if(pNodo == NULL){
		return FALTOU_MEMORIA;
	}else if(pl->topo == NULL){
		pNodo->info = d;
		pNodo->prox = NULL;
		pl->topo = pNodo;
		return SUCESSO;
	}else {
		pNodo->info = d;
		pNodo->prox = pl->topo;
		pl->topo = pNodo;
		return SUCESSO;
	}
}


int desempilha(Pilha *pl, Dado *d){
	Nodo *pNodo;
	Nodo *pTemp;
	pTemp = pl->topo;
	if(pTemp == NULL){
		return PILHA_VAZIA;
	}else{
		pNodo = pTemp->prox;
		*d = pTemp->info;
		pl->topo = pNodo;
		free(pTemp);
		return SUCESSO;
	}
}
