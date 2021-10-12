#include <stdio.h>
#include "conta.c"

int main(){

	Conta cc;
	float value;
	int num;

	printf("Informe o numero da conta:\n");
	scanf("%d", &num);
	criarConta(&cc, num);

	printf("Faca o primeiro deposito\n");
	scanf("%f", &value);
	depositaConta(&cc, value);

	printf("Faca uma retirada\n");
	scanf("%f", &value);
	retiraConta(&cc, value);

	printf("Veja seu saldo\n");
	obtemSaldo(&cc);

	return 0;

}
