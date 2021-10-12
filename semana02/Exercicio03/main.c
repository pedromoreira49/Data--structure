#include <stdio.h>
#include <stdlib.h>
#include "conta.c"

int printMenu(int op);

int main(){

	Conta cc, cp;
	float value;
	int num, nump, op;

	printf("Informe o numero da conta corrente:\n");
	scanf("%d", &num);
	criarConta(&cc, num);
	printf("Informe o numero da conta poupanca:\n");
	scanf("%d", &nump);
	criarConta(&cp, nump);

	while(op != 5){
		printf("O que deseja fazer:\n1-Deposito conta corrente\n2-Deposito conta poupanca\n3-Retirada conta corrente\n4-Retirada conta poupanca\n5-Fim\n");
		scanf("%d", &op);
		switch(op){
			case 1:
				printf("Escolhido: Deposito conta corrente\n");
				printf("Insira o valor:\n");
				scanf("%f", &value);
				depositaConta(&cc, value);
				printf("Saldo atual: R$ %.2f\n", obtemSaldo(&cc));
				break;
			case 2:
				printf("Escolhido: Deposito conta poupanca\n");
				printf("Insira o valor:\n");
				scanf("%f", &value);
				depositaConta(&cp, value);
				printf("Saldo atual: R$ %.2f\n", obtemSaldo(&cp));
				break;
			case 3:
				printf("Escolhido: Retirada conta corrente\n");
				printf("Insira o valor:\n");
				scanf("%f", &value);
				if(obtemSaldo(&cc) >= value){
					retiraConta(&cc, value);
				}else if(obtemSaldo(&cp) >= value){
					retiraConta(&cp, value);
				}else{
					printf("Saldo insuficiente");
				}
				break;
			case 4:
				printf("Escolhido: Retirada conta poupanca\n");
				printf("Insira o valor:\n");
				scanf("%f", &value);
				if(obtemSaldo(&cp) >= value){
					retiraConta(&cp, value);
				}else{
					printf("Saldo insuficiente");
				}
				break;
			case 5:
				printf("Escolhido: Sair.\n");
				exit(0);
				break;
		}
	}
	return 0;

}
