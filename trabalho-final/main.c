#include <stdio.h>
#include "voo.c"

int main(){
	Filase fl;
	Voo v;
	int op;

	criaFila(&fl);

	do{
		printf("Menu:\n");
		printf("0. Fim             3. Consulta existência de voo\n");
		printf("1. Insere um voo   4. Quantidade de avioes\n");
		printf("2. Retira um voo   5. Exibe todos os voos\n");
		scanf("%d", &op);
		switch(op){
			case 0:
				exit(0);
				break;
		}
	}while(op != 0);
	return 0;
}
