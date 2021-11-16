#include <stdio.h>
#include <stdlib.h>
#include "filase.h"

void criaFila(Fila *fl){
	fl->frente = NULL;
	fl->re = NULL;
}

int insere(Fila *fl, Dado d){
	Nodo *pNodo;
	Nodo *pAux;
	pNodo = (Nodo *) malloc (sizeof(Nodo));
	if(pNodo == NULL){
		return FALTOU_MEMORIA;
	}else if(fl.frente == NULL){
		pNodo->info = d;
		pNodo->prox = NULL;
		fl.frente = pNodo;
		fl.re = pNodo;
		return SUCESSO;
	}else{
		pNodo->info = d;
		pNodo->prox = NULL;
		pAux = fl.frente;
		while(pAux->prox != NULL){
			pAux = pAux->prox;
		}
		pAux->prox = pNodo;
		fl.re = pNodo;
		return SUCESSO;
	}
}

int retira(Fila *f, Dado *d){
	Nodo *pNodo;
	Nodo *pTemp;
	pTemp = fl->frente;
	if(pTemp == NULL){
		return FILA_VAZIA;
	}else{
		pNodo = pTemp->prox;
		*d = pTemp->info;
		fl->frente = pNodo;
		free(pTemp);
		return SUCESSO;
	}

}
