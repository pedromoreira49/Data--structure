#include <stdio.h>
#include "listade.h"

void criaLista(Listade *lt){
	lt->inicio = NULL;
	lt->fim = NULL;
	lt->n = 0;
}

void exibeLista(Listade lt){
	Nodo *pAux;
	pAux = lt.inicio;
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
