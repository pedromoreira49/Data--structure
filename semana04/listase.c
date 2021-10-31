#include <stdio.h>
#include "listase.h"

void criaLista(ListaSE *lt){
	lt->inicio = NULL;
}

void exibe(ListaSE lt){
	Nodo *pAux;

	pAux = lt.inicio;
	while(pAux != NULL){
		printf("EndNodo:%p - cod:%3d - peso:%.2f - ProxEnd:%p\n", pAux, pAux->info.cod, pAux->info.peso, pAux->prox);
		pAux = pAux->prox;
	}
}

int estaVazia(ListaSE lt){
	if(lt.inicio == NULL)
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
	else if(lt->inicio == NULL){
		pNodo->info = d;
		pNodo->prox = NULL;
		lt->inicio = pNodo;
		SUCESSO;
	}else {
		pAux = lt->inicio;
		while(pAux->prox != NULL){
			pAux = pAux->prox;
		}
		pNodo->info = d;
		pNodo->prox = NULL;
		pAux->prox = pNodo;
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

int quantidadeDeNodos(ListaSE lt){
	int conta = 0;
	Nodo *pAux;

	pAux = lt.inicio;
	while(pAux != NULL){
		conta++;
		pAux = pAux->prox;
	}
	return(conta);
}

int excluiDoInicio(ListaSE *lt, Dado *d){
	Nodo *pTemp;
	if(lt->inicio==NULL){
		return LISTA_VAZIA;
	}else{
		*d = lt->inicio->info;
		pTemp = lt->inicio;
		lt->inicio = lt->inicio->prox;
		free(pTemp);
		return SUCESSO;
	}
}
