#ifndef Cheque_H
#define Cheque_H

typedef struct{
	int numC;
	float value;
	int status;
} Cheque;

void criarCheque(Cheque *cheque, int num);

int exibeCheque(Cheque *cheque);

int obtemStatus(Cheque *cheque);

float obtemValor(Cheque *cheque);

int obtemNum(Cheque *cheque);

int compensaCheque(Cheque *cheque);

int emiteCheque(Cheque *cheque, float value);


#endif
