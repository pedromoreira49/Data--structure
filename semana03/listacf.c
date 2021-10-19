#include <stdio.h>
#include "listacf.h"

void criaLista(ListaCF *lt){
	lt->n = 0;
}

int incluiNoFim(ListaCF *lt, Dado d){
	if(lt->n == MAX_NODOS){
		return LISTA_CHEIA;
	}else{
		lt->v[lt->n] = d;
		lt->n++;
		return SUCESSO;
	}
}


void exibe(ListaCF lt){
	int i;
	printf("Exibindo...\n");
	for(i = 0; i < lt.n; i++){
		printf(" %d %.2f\n", lt.v[i].cod, lt.v[i].peso);
	}
}

int quantidadeDeNodos(ListaCF lt){
	return lt.n;
}

int estaCheia(ListaCF lt){
	if(lt.n == MAX_NODOS){
		return 1;
	}else{
		return 0;
	}
}

int estaVazia(ListaCF lt){
	if(lt.n == 0){
		return 1;
	}else{
		return 0;
	}
}

int excluiDoFim(ListaCF *lt, Dado *d){
	*d = lt->v[lt->n-1];
	if(lt->n == 0){
		return LISTA_VAZIA;
	}else{
		lt->n--;
		return SUCESSO;
	}
}

int incluiNoInicio(ListaCF *lt, Dado d){
	if(lt->n == MAX_NODOS){
		return LISTA_CHEIA;
	}
	for(int i = 0; i < lt->n; i++){
		lt->v[i + 1] = lt->v[i];
	}
	lt->v[0] = d;
	lt->n++;
	return SUCESSO;
}

int excluiDoInicio(ListaCF *lt, Dado *d){
	*d = lt->v[0];
	if(lt->n == 0){
		return LISTA_VAZIA;
	}
	for(int i = 0; i < lt->n; i++){
		lt->v[i - 1] = lt->v[i];
	}
	lt->n--;
	return SUCESSO;
}

int consultaPorCodigo(ListaCF lt, Dado *d, int cod){
	for(int i = 0; i < lt.n; i++){
		if(lt.v[i].cod == cod){
			*d = lt.v[i];
			return SUCESSO;
		}
	}
	return CODIGO_INEXISTENTE;
}

int incluiAntes(ListaCF *lt, Dado d, int cod){
	if(lt->n == MAX_NODOS){
		return LISTA_CHEIA;
	}
	int i = 0;
	while((lt->v[i].cod) != cod && (i <= MAX_NODOS)){
		i++;
	}
	if(i > lt->n){
		return CODIGO_INEXISTENTE;
	}

	for(int j = lt->n; j >= i; j++){
		lt->v[j] = lt->v[j - 1];
	}
	lt->v[i] = d;
	lt->n++;
	return SUCESSO;
}

int excluiNodo(ListaCF *lt, Dado *d, int cod){
	if(lt->n == 0){
		return LISTA_VAZIA;
	}

	int i = 0;
	while((lt->v[i].cod) != cod && (i <= MAX_NODOS)){
		i++;
	}

	if(i > lt->n){
		return CODIGO_INEXISTENTE;
	}

	*d = lt->v[i];
	for(int j = i; j <= lt->n; j++){
		lt->v[j] = lt->v[j + 1];
	}
	lt->n--;
	return SUCESSO;
}
