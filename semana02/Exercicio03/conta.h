#ifndef Conta_H
#define Conta_H

typedef struct {
	int num_c;
	float saldo;
} Conta;


void criarConta(Conta *conta, int num);

void depositaConta(Conta *conta, float valor);

void retiraConta(Conta *conta, float valor);

float obtemSaldo(Conta *conta);


#endif
