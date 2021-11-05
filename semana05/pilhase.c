#include <stdio.h>
#include "pilhase.h"

void criaPilha(Pilha *pl){
	pl->topo = NULL;
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
		pl->topo = pNodo
		return SUCESSO;
	}
}
