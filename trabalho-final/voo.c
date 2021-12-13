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
