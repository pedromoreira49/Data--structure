#include <stdio.h>
#include <stdlib.h>
#include "listase.c"

int main(){
	Dado d;
	ListaSE lt;
	criaLista(&lt);
	int chose;
	do {
		printf("MENU:\n1-exibe\n2-esta vazia\n3-Inclui no fim\n4-Inclui no inicio\n");
		scanf("%d", &chose);
		switch(chose){
			case 1:
				exibe(lt);
				break;
			case 2:
				if(estaVazia(lt)==LISTA_VAZIA){
					printf("Lista vazia\n");
				}else{
					printf("Lista possui conteudo\n");
				}
				break;
			case 3:
				printf("Informe o cod:\n");
				scanf("%d", &d.cod);
				printf("Informe o peso:\n");
				scanf("%f", &d.peso);
				if(incluiNoFim(&lt, d)== FALTOU_MEMORIA){
					printf("ERRO: Faltou memoria\n");
				} else{
					printf("SUCESSO\n");
				}
				break;
			case 4:
				printf("Informe o cod:\n");
				scanf("%d", &d.cod);
				printf("Informe o peso:\n");
				scanf("%f", &d.peso);
				if(incluiNoInicio(&lt, d)== FALTOU_MEMORIA){
					printf("ERRO: Faltou memoria\n");
				} else{
					printf("SUCESSO\n");
				}
				break;
		}
			if(chose != 1){
				exibe(lt);
			}
	}while(chose != 5);

	return 0;
}
