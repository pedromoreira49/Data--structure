#include <stdio.h>
#include <stdlib.h>
#include "cheque.c"

int main(){
	Cheque c1, c2;
	int num;
	float value;

	printf("Informe o primeiro cheque:\n");
	scanf("%d", &num);
	criarCheque(&c1, num);

	printf("Informe o segundo cheque:\n");
	scanf("%d", &num);
	criarCheque(&c2, num);

	printf("Informe o valor do primeiro cheque:\n");
	scanf("%f", &value);
	emiteCheque(&c1, value);

	printf("Informe o valor do segundo cheque:\n");
	scanf("%f", &value);
	emiteCheque(&c2, value);

	exibeCheque(&c1);
	exibeCheque(&c2);

	if(obtemValor(&c1) > obtemValor(&c2)){
		compensaCheque(&c1);
	}else{
		compensaCheque(&c2);
	}

	printf("O status do cheque um e: ", obtemStatus(&c1));
	printf("\n");
	printf("O status do cheque dois e: ", obtemStatus(&c2));
	printf("\n");

	printf("O num do cheque um e: %d", obtemNum(&c1));
	printf("\n");
	printf("O num do cheque dois e: %d", obtemNum(&c2));
	printf("\n");

	return 0;
}
