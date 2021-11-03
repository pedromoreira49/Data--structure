#include <stdio.h>
#include <stdlib.h>
#include "listase.c"

int main(){
	Dado d;
	ListaSE lt;
	criaLista(&lt);
	int chose, cod;
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
			case 2:
				exibe(lt);
				break;
			case 3:
				quantidadeDeNodos(lt);
				break;
			case 4:
				if(estaVazia(lt)==LISTA_VAZIA){
					printf("Lista vazia\n");
				}else{
					printf("Lista possui conteudo\n");
				}
				break;
			case 5:
				if(excluiDoInicio(&lt, &d)==LISTA_VAZIA){
					printf("Lista vazia\n");
				}else{
					printf("SUCESSO\n");
				}
				break;
			case 6:
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
			case 7:
				if(excluiDoFim(&lt, &d)==LISTA_VAZIA){
					printf("Memoria vazia\n");
				}else{
					printf("SUCESSO\n");
				}
				break;
			case 8:
				printf("Informe o codigo:\n");
				scanf("%d", &cod);
				if(consultaPorCodigo(lt, cod)==LISTA_VAZIA){
					printf("Lista vazia\n");
				}else{
					printf("SUCESSO\n");
				}
				break;
			case 9:
				printf("Informe o codigo:\n");
				scanf("%d", &d.cod);
				printf("Informe o peso:\n");
				scanf("%f", &d.peso);
				printf("Informe o codigo anterior:\n");
				scanf("%d", &cod);
				if(incluiDepois(&lt, d, cod)==FALTOU_MEMORIA){
					printf("ERRO: Memoria insuficiente\n");
				}else{
					printf("SUCESSO\n");
				}
				break;
			case 10:
				printf("Informe o codigo do nodo a ser excluido:\n");
				scanf("%d", &cod);
				if(excluiNodo(&lt, &d, cod)==LISTA_VAZIA){
					printf("Lista vazia\n");
				}else{
					printf("SUCESSO\n");
				}
				break;
		}
			if(chose != 2 && chose != 8){
				exibe(lt);
			}
	}while(chose != 0);

	return 0;
}
