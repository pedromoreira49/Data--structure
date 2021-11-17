#ifndef filase_h
#define filase_h

#define SUCESSO 0
#define FILA_VAZIA 1
#define FALTOU_MEMORIA 2

typedef struct {
	int cod;
	float peso;
} Dado;

typedef struct nodo Nodo;

struct nodo {
	Dado info;
	Nodo *prox;
};

typedef struct {
	Nodo *frente;
	Nodo *re;
} Fila;

void criaFila(Fila *fl);
int insere(Fila *fl, Dado d);
int retira(Fila *fl, Dado *d);
int estaVazia(Fila fl);
int quantidadeDeNodos(Fila fl);
int consultaFrente(Fila fl);
void exibeFila(Fila fl);

#endif
