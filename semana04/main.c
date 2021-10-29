#include <stdio.h>
#include <stdlib.h>
#include "listase.c"

int main(){
	Dado d;
	ListaSE lt;
	criaLista(&lt);
	int chose;
	do {
		printf("MENU:\n");
		printf("0.Fim                       5.Exclui do inicio    10.Exclui nodo\n");
		printf("1.Inclui no inicio          6.Inclui no fim\n");
		printf("2.Exibe lista	            7.Exclui do fim\n");
		printf("3.Quantidade de nodos	    8.Consulta por codigo\n");
		printf("4.Exibe situacao da lista   9.Inclui depois\n");
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
