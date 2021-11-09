#include <stdio.h>
#include "pilhase.c"
#include <stdlib.h>

int main(){

	Pilha pl;
	Dado d;
	int op;
	criaPilha(&pl);

	do{
		printf("MENU:\n");
		printf("0.Fim        3.Quantidade de nodos\n");
		printf("1.Empilha    4.Exibe situação da lista\n");
		printf("2.Desempilha 5.Consulta topo\n");
		scanf("%d", &op);
		switch(op){
			case 0:
				exit(0);
				break;
			case 1:
				printf("Informe o codigo:\n");
				scanf("%d", &d.cod);
				printf("Informe o peso:\n");
				scanf("%f", &d.peso);
				if(empilha(&pl, d)==FALTOU_MEMORIA){
					printf("ERRO: Faltou memoria\n");
				}else{
					printf("SUCESSO\n");
					exibe(pl);
				}
				break;
			case 2:
				if(desempilha(&pl, &d)==PILHA_VAZIA){
					printf("ERRO: Pilha vazia\n");
				}else{
					printf("SUCESSO\n");
					exibe(pl);
				}
				break;
			case 3:
				printf("Quantidade no nodos: %d\n", quantidadeDeNodos(pl));
				break;
			case 4:
				if(estaVazia(pl)==PILHA_VAZIA){
					printf("Pilha vazia\n");
				}else{
					printf("Pilha possui um ou mais nodos\n");
				}
				break;
			case 5:
				if(consultaTopo(pl)==PILHA_VAZIA){
					printf("Pilha vazia\n");
				}else{
					printf("SUCESSO\n");
				}
				break;
		}

	}while(op != 0);

	return 0;
}
