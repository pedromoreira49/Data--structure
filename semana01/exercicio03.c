#include <stdio.h>
#include <stdlib.h>

/*Exercicio: 1.3
Escreva uma função chamada maiorNumero que receba como entrada dois inteiros positivos e retorne o maior deles ou o valor -1 se eles forem iguais.
Considere que os valores de entrada são sempre positivos.
Escreva um programa em C para ler um valor A. A seguir ler N duplas de inteiros.
Para cada dupla informada exibir o maior elemento ou a frase "Eles são iguais".
Para obter o maior elemento deve ser utilizada a função maiorNumero.
*/

int maiorNumero(int a, int b);

int main(){
	int i,q, a, b;
	printf("Informe a quantidade de numero:\n");
	scanf("%d", &q);
	for(i = 1; i <= q; i++){
		printf("Informe o primeiro numero\n");
		scanf("%d", &a);
		printf("Informe o segundo numero:\n");
		scanf("%d", &b);
		if((maiorNumero(a, b) > 0)){
			printf("%d\n", maiorNumero(a, b));
		} else {
			printf("Eles são iguais\n");
		}
	}
	return 0;
}

int maiorNumero(int a, int b){
	if(a > b){
		return a;
	} else if(b > a) {
		return b;
	} else {
		return -1;
	}
}


