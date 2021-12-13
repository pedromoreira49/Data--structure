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
			case 1:
				printf("Informe o numero:\n");
				scanf("%d", &v.num);
				printf("Informe a cia:\n");
				scanf("%s", &v.cia);
				if(insere(&fl, v) == FALTOU_MEMORIA){
					printf("Erro: Faltou memoria\n");
				}else{
					printf("SUCESSO\n");
				}
				exibeFila(fl);
				break;
			case 2:
				if(retira(&fl, &v) == FILA_VAZIA){
					printf("Erro: Fila vazia\n");
				}else{
					printf("SUCESSO\n");
				}
				exibeFila(fl);
				break;
		}
	}while(op != 0);
	return 0;
}
