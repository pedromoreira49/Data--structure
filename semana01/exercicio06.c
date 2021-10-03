#include <stdio.h>
#include <stdlib.h>

/*Exercicio: 1.6
Escreva uma função chamada duplaClassificada que classifique 2 valores inteiros conforme o código passado como argumento (0 - ordem crescente 1- ordem decrescente).
Escreva um programa para ler uma quantidade indeterminada de duplas de valores. Escrever cada dupla em ordem crescente se a soma dos elementos da dupla for par e em ordem decrescente se a soma for impar. Os valores em ordem devem ser obtidos através da função duplaClassificada. O programa termina quando os dois valores informados forem iguais.
*/

void duplaClassificada(int *a, int *b);

int main(){
	int a, b;
	while(1){
		printf("Informe o valor de dois numeros:\n");
		scanf("%d %d", &a, &b);
		if(a != b){
			duplaClassificada(&a, &b);
			printf("%d %d\n", a, b);
		} else{
			exit(0);
		}
	}
	return 0;
}

void duplaClassificada(int *a, int *b){
	int aux;

	if(((*a + *b) % 2) == 0){
		if(*a > *b){
			aux = *a;
			*a = *b;
			*b = aux;
		}
	} else{
		if(*b > *a){
			aux = *b;
			*b = *a;
			*a = aux;
		}
	}
}
