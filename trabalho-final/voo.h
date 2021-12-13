#ifndef voo_h
#define voo_h

#define SUCESSO 0
#define FILA_VAZIA 1
#define FALTOU_MEMORIA 2
#define NUMERO_INEXISTENTE 3

typedef struct {
	int num;
	char cia[10];
} Voo;

typedef struct nodo Nodo;

struct nodo{
	Voo v;
	Nodo *prox;
}

typedef struct {
	Nodo *frente;
	Nodo *re;
} Filase;

void criaFila(Filase *fl);

#endif
