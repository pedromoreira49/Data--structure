#include <stdio.h>
#include "listaSE.h"

void criaLista(ListaSE *lt){
	lt->inicio = NULL;
}

void exibe(ListaSE lt){
	Nodo *pAux;

	pAux = lt.inicio;
	while(pAux != NULL){
		printf("%d %f\n", pAux->info.cod, pAux->info.peso);
		pAux = pAux->prox;
	}
}

int estaVazia(ListaSE lt){
	if(lt->inicio == NULL)
		return LISTA_VAZIA;
	else
		return 0;
}

int incluiNoFim(ListaSE *lt, Dado d){
	Nodo *pNodo;
	Nodo *pAux;
	pNodo = (Nodo *) malloc (sizeof(Nodo));
	if(pNodo == NULL)
		return FALTOU_MEMORIA;
	else {
		pAux = lt.inicio;
		while(pAux != NULL){
			pAux = pAux->prox;
		}
		pAux->prox = pNodo;
		pNodo->info = d;
		pNodo->prox = NULL; 
		return SUCESSO;
	}

}

int incluiNoInicio(ListaSE *lt, Dado d){
	Nodo *pNodo;

	pNodo = (Nodo *) malloc (sizeof(Nodo));
	if(pNodo == NULL)
		return FALTOU_MEMORIA;
	else{
		pNodo->info = d;
		pNodo->prox = lt->inicio;
		lt->inicio = pNodo;
		return SUCESSO;
	}
}

