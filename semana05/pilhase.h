#ifndef pilhase.h
#define pilhase.h

#define SUCESSO 0
#define PILHA_VAZIA 1
#define FALTOU_MEMORIA 2

typedef struct {
	int cod;
	float peso;
} Dado;

typedef struct nodo Nodo;

struct Nodo {
	Dado info;
	Nodo *prox;
};

typedef struct {
	Nodo *topo;
} Pilha;

#endif
