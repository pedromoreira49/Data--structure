#include <stdio.h>
#include <stdlib.h>

/*Exercicio: 1.2
Escreva uma função chamada exibeDivisores que exiba na tela os divisores do inteiro passado com argumento.
Escreva um programa em C para imprimir os números de 1 a 20 com seus respectivos divisores.
Cada conjunto de divisores deve ser impresso com a função exibeDivisores.
*/

void exibeDivisores(int num);

int main(){
	int num;
	printf("Informe um numero:\n");
	scanf("%d", &num);
	for(int i = 1; i <= num; i++){
		printf("%d: ", i);
		exibeDivisores(i);
		printf("\n");
	}
	return 0;
}

void exibeDivisores(int num){
	for(int i = 1; i <= num; i++){
		if((num % i) == 0){
			printf("%d ", i);
		}
	}
}
