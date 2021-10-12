#include <stdio.h>
#include <stdlib.h>
#include "conta.c"

/*Exercicio: 2.3
Defina o tipo Conta para armazenar o numero de uma conta e seu respectivo saldo.
Escreva um programa para controlar a conta corrente e a conta poupança do sr.Silva. As contas são integradas de forma que quando não houver saldo suficiente na conta corrente uma transferência automática da conta poupança cobrirá um evental saldo (o valor da transferência deve ser igual ao valor necessário para cobrir o saldo negativo).
O programa deve ler o número e o saldo inicial da conta corrente e da poupança criando duas variáveis do tipo Conta (cada uma representa uma conta). A seguir ler uma quantidade indeterminada de duplas de dados representando respectivamente o código da operação (1.Depósito conta corrente 2.Depósito conta poupança 3.Retirada conta corrente 4.Retirada conta poupança 5.Fim) e o valor do movimento. O programa termina ao ser informado um código igual a 5 (nesta situação o valor do movimento não deve ser lido).
*/

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
			default:
				printf("Opcao invalida\n");
				break;
		}
	}
	return 0;

}
