#include "conta.h"

void criarConta(Conta *conta, int num){
	conta->num_c = num;
	conta->saldo = 0;
}

void depositaConta(Conta *conta, float valor){
	conta->saldo += valor;

}

void retiraConta(Conta *conta, float valor){
	conta->saldo -= valor;
}

float obtemSaldo(Conta *conta){
	printf("%.2f\n", conta->saldo);
	return conta->saldo;
}
