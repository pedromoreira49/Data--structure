#ifndef LISTASE_H
#define ListaSE_H

#define SUCESSO 0
#define LISTA_VAZIA 1
#define FALTOU_MEMORIA 2
#define CODIGO_INEXISTENTE 3

typedef struct{
	int cod;
	float peso;
} Dado;

typedef struct nodo Nodo;

struct nodo{
	Dado info;
	Nodo *prox;
};

typedef struct{
	Nodo *inicio;
} ListaSE;

void criaLista(ListaSE *lt);
void exibe(ListaSE lt);
int estaVazia(ListaSE lt);
int incluiNoFim(ListaSE *lt, Dado d);
int incluiDepois(ListaSE *lt, Dado d, int cod);
int consultaPorCodigo(ListaSE lt, int cod);
int incluiNoInicio(ListaSE *lt, Dado d);
int quantidadeDeNodos(ListaSE lt);
int excluiDoInicio(ListaSE *lt, Dado *d);
int excluiDoFim(ListaSE *lt, Dado *d);
int excluiNodo(ListaSE *lt, Dado *d, int cod);

#endif
