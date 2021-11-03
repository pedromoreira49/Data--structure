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

int excluiDoFim(ListaSE *lt, Dado *d){
	Nodo *pTemp;
	Nodo *pAux;
	Nodo *pNodo;
	if(lt->inicio==NULL){
		return LISTA_VAZIA;
	}else{
		pAux = lt->inicio;
		while(pAux->prox != NULL){
			pAux = pAux->prox;
		}
		pNodo = lt->inicio;
		while(pNodo->prox != pAux){
			pNodo = pNodo->prox;
		}
		*d = pAux->info;
		pTemp = pNodo->prox;
		pNodo->prox = NULL;
		free(pTemp);
		return SUCESSO;
	}
}

int excluiNodo(ListaSE *lt, Dado *d, int cod){
	Nodo *pNodo;
	Nodo *pAux;
	if(lt->inicio == NULL){
		return LISTA_VAZIA;
	}else{
		pNodo = lt->inicio;
		while(pNodo->info.cod != cod){
			pNodo = pNodo->prox;
		}
		pAux = lt->inicio;
		while(pAux->prox != pNodo){
			pAux = pAux->prox;
		}
		*d = pNodo->info;
		pAux->prox = pNodo->prox;
		free(pNodo);
		return SUCESSO;
	}
}

int consultaPorCodigo(ListaSE lt, int cod){
	Nodo *pNodo;
	if(lt.inicio == NULL){
		return LISTA_VAZIA;
	}else{
		pNodo = lt.inicio;
		while(pNodo->info.cod != cod){
			pNodo = pNodo->prox;
		}
		printf("EndNodo:%p - cod:%3d - peso:%.2f - ProxEnd:%p\n", pNodo, pNodo->info.cod, pNodo->info.peso, pNodo->prox);
		return SUCESSO;
	}
}

int incluiDepois(ListaSE *lt, Dado d, int cod){
	Nodo *pNodo;
	Nodo *pAux;
	pNodo = (Nodo *) malloc (sizeof(Nodo));
	if(pNodo == NULL){
		return FALTOU_MEMORIA;
	}else if(lt->inicio == NULL){
		return LISTA_VAZIA;
	}else{
		pAux = lt->inicio;
		while(pAux->info.cod != cod && pAux->prox != NULL){
			pAux = pAux->prox;
		}
		if(pAux->prox == NULL){
			free(pNodo);
			return CODIGO_INEXISTENTE;
		}else{
			pNodo->info = d;
			pNodo->prox = pAux->prox;
			pAux->prox = pNodo;
			return SUCESSO;
		}
	}
}
