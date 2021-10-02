#include <stdio.h>
#include <stdlib.h>

/*Exercicio: 1.4
Escreva um programa em C para ler um inteiro Q (maximo 10). A seguir ler um vetor Z de Q elementos e um valor Y.
Copiar todos os elementos maiores que Y que estão no vetor Z para um vetor W (sem deixar elementos vazios entre os valores copiados). Escrever o vetor W após o término da cópia.
*/

int main() {
	int i, q, y, cont = 0, arrZ[10], arrW[10];
	printf("Informe a quantidade de elementos do vetor:\n");
	scanf("%d", &q);
	/*
	printf("Informe o valor para Y:\n");
	scanf("%d", &y);
	*/
	printf("Informe os elementos para o vetor Z:\n");
	for(i = 1; i <= q; i++){
		scanf("%d", &arrZ[i]);
	}
	printf("Informe o valor para Y:\n");
	scanf("%d", &y);
	for(i = 1; i <= q; i++){
		if(arrZ[i] > y){
			arrW[cont] = i;
			printf("%d ", arrW[cont]);
			cont++;
		}
	}
	return 0;
}
