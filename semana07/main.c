#include <stdio.h>
#include <stdlib.h>
#include "listade.c"

int main(){
	Listade lt;
	Dado d;
	int op, cod;
	criaLista(&lt);

	do{
		printf("MENU:\n");
		printf("0.Fim                       5.Exclui do inicio     10.Exclui nodo\n");
		printf("1.Inclui no inicio          6.Inclui no fim\n");
		printf("2.Exibe lista               7.Exclui do fim\n");
		printf("3.Quantidade de nodos       8.Consulta por codigo\n");
		printf("4.Exibe situação da lista   9.Inclui depois\n");
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
				if(incluiNoInicio(&lt, d)== FALTOU_MEMORIA){
					printf("Erro: Faltou memoria\n");
				}else{
					printf("SUCESSO\n");
				}
				exibeLista(lt);
				break;
			case 2:
				exibeLista(lt);
				break;
			case 3:
				printf("Quantidade de nodos: %d\n", quantidadeDeNodos(lt));
				break;
			case 4:
				if(estaVazia(lt) == LISTA_VAZIA){
					printf("A lista esta vazia\n");
				}else{
					printf("A lista possui um ou mais nodos\n");
				}
				break;
			case 5:
				if(excluiDoInicio(&lt, &d) == LISTA_VAZIA){
					printf("Erro: Lista vazia\n");
				}else{
					printf("SUCESSO\n");
				}
				exibeLista(lt);
				break;
			case 6:
				printf("Informe o codigo:\n");
				scanf("%d", &d.cod);
				printf("Informe o peso:\n");
				scanf("%f", &d.peso);
				if(incluiNoFim(&lt, d) == FALTOU_MEMORIA){
					printf("Erro: Faltou memoria\n");
				}else{
					printf("SUCESSO\n");
				}
				exibeLista(lt);
				break;
			case 7:
				if(excluiDoFim(&lt, &d)==LISTA_VAZIA){
					printf("Erro: Lista vazia\n");
				}else{
					printf("SUCESSO\n");
				}
				exibeLista(lt);
				break;
			case 8:
				printf("Informe o codigo:\n");
				scanf("%d", &cod);
				if(consultaPorCodigo(lt, cod, &d)==CODIGO_INEXISTENTE){
					printf("Erro: codigo inexistente\n");
				}else{
					printf("SUCESSO\n");
					printf("Codigo: %d - Peso: %.2f\n", d.cod, d.peso);
				}
				break;
			case 9:
				printf("Informe o codigo:\n");
				scanf("%d", &d.cod);
				printf("Informe o peso:\n");
				scanf("%f", &d.peso);
				printf("Informe o codigo a ser procurado\n");
				scanf("%d", &cod);
				if(incluiDepois(&lt, d, cod)==FALTOU_MEMORIA){
					printf("Erro: Faltou memoria\n");
				}else{
					printf("SUCESSO\n");
				}
				exibeLista(lt);
				break;
			case 10:
				printf("Informe o codigo a ser excluido:\n");
				scanf("%d", &cod);
				if(excluiNodo(&lt, &d, cod) == LISTA_VAZIA){
					printf("Erro: Lista vazia\n");
				}else{
					printf("SUCESSO\n");
				}
				exibeLista(lt);
				break;
		}
	}while(op != 0);
	return 0;
}
