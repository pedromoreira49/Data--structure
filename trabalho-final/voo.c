#include <stdio.h>
#include <stdlib.h>
#include "voo.h"

void criaFila(Filase *fl){
	fl->frente = NULL;
	fl->re = NULL;
}

void exibeFila(Filase fl){
	Nodo *pNodo;
	pNodo = fl.frente;
	while(pNodo != NULL){
		printf("EndNodo: %x - num: %d - cia: %s - proxEnd: %x\n", pNodo, pNodo->voo.num, pNodo->voo.cia, pNodo->prox);
		pNodo = pNodo->prox;
	}
}

int quantidadeDeNodos(Filase fl){
	int cont = 0;
	Nodo *pNodo;
	pNodo = fl.frente;
	while(pNodo != NULL){
		cont++;
		pNodo = pNodo->prox;
	}
	return(cont);
}

int insere(Filase *fl, Voo v){
	Nodo *pNodo;
	Nodo *pAux;
	pNodo = (Nodo *) malloc(sizeof(Nodo));
	if(pNodo == NULL){
		return FALTOU_MEMORIA;
	}else if(fl->frente == NULL){
		pNodo->v = v;
		pNodo->prox = NULL;
		fl->frente = pNodo;
		fl->re = pNodo;
		return SUCESSO;
	}else{
		pNodo->v = v;
		pNodo->prox = NULL;
		pAux = fl->frente;
		while(pAux->prox != NULL){
			pAux = pAux->prox;
		}
		pAux->prox = pNodo;
		fl->re = pNodo;
		return SUCESSO;
	}
}

int retira(Filase *fl, Voo *v){
	Nodo *pNodo;
	Nodo *pTemp;
	pTemp = fl->frente;
	if(pTemp == NULL){
		return FILA_VAZIA;
	}else{
		pNodo = pTemp->prox;
		*v = pTemp->v;
		fl->frente = pNodo;
		free(pTemp);
		return SUCESSO;
	}
}
