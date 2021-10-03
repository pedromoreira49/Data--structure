#include <stdio.h>
#include <stdlib.h>

/*Exercicio: 1.5
Escreva um função em C chamada duplaCrescente que classifique 2 valores inteiros passados como argumento em ordem crescente.
Entrada: Dois números inteiros
Saída: Os dois inteiros em ordem crescente.
Retorno: Nenhum
Escreva um programa em C para ler uma quantidade indeterminada de duplas de inteiros.
Escrever cada dupla em ordem crescente. Os valores em ordem crescente devem ser obtidos através da chamada à função duplaCrescente.
O programa termina quando os dois valores informados forem iguais (nesta situação os valores não devem ser impressos).
*/

void duplaCrescente(int *a, int *b);

int main(){
	int a, b;
	while(1){
		printf("Informe 2 numeros:\n");
		scanf("%d %d", &a, &b);
		if(a != b){
			duplaCrescente(&a, &b);
			printf("%d %d\n", a, b);
		} else{
			exit(0);
		}
	}
	return 0;
}

void duplaCrescente(int *a, int *b){
	int aux;

	if(*a > *b){
		aux = *a;
		*a = *b;
		*b = aux;
	}
}
