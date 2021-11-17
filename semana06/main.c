#include <stdio.h>
#include "filase.c"

int main(){
	Fila fl;
	Dado d;
	int op;

	criaFila(&fl);

	do{
		printf("Menu:\n");
		printf("0.Fim     3.Quantidade de nodos\n");
		printf("1.Insere  4.Exibe situação da fila\n");
		printf("2.Retira  5.Consulta frente\n");
		scanf("%d", &op);
		switch(op){
			case 0:
				exit(0);
				break;
			case 1:
				printf("Informe o cod:\n");
				scanf("%d", &d.cod);
				printf("Informe o peso:\n");
				scanf("%f", &d.peso);
				if(insere(&fl, d)==FALTOU_MEMORIA){
					printf("Erro:Faltou memoria\n");
				}else{
					printf("SUCESSO\n");
				}
				exibeFila(fl);
				break;
			case 2:
				if(retira(&fl, &d)==FILA_VAZIA){
					printf("ERRO: Fila vazia\n");
				}else{
					printf("SUCESSO\n");
				}
				exibeFila(fl);
				break;
			case 3:
				printf("Quantidade de nodos: %d\n", quantidadeDeNodos(fl));
				break;
		}
	}while(op != 0);

	return 0;
}
