#ifndef listade_h
#define listade_h

#define SUCESSO 0
#define LISTA_VAZIA 1
#define FALTOU_MEMORIA 2
#define CODIGO_INEXISTENTE 3

typedef struct {
	int cod;
	float peso;
} Dado;

typedef struct nodo Nodo;

struct nodo {
	Dado info;
	Nodo *ant;
	Nodo *prox;
};

typedef struct {
	Nodo *inicio;
	Nodo *fim;
	int n;
} Listade;

void criaLista(Listade *lt);
void exibeLista(Listade lt);
int estaVazia(Listade lt);
int quantidadeDeNodos(Listade lt);
int incluiNoInicio(Listade *lt, Dado d);
int excluiDoInicio(Listade *lt, Dado *d);
int incluiNoFim(Listade *lt, Dado d);
int excluiDoFim(Listade *lt, Dado *d);


#endif
