#include <stdio.h>
#include "listacf.c"

int main(){
	ListaCF lt;
	Dado data;
	int cod, pesq, op, forFunc;

	criaLista(&lt);

	do{
		printf("MENU:\n");
		printf("1. Inclui no fim		6.Inclui no inicio	11.Fim\n");
		printf("2. Exibe lista 			7.Exclui do inicio\n");
		printf("3. Quantidade de nodos		8.Consulta por codigo\n");
		printf("4. Exibe situacao da lista	9.Inclui antes\n");
		printf("5. Exclui do fim		10.Exclui nodo\n");
		scanf("%d", &op);

		switch(op){
			case 1:
				printf("Informe o codigo:\n");
				scanf("%d", &data.cod);
				printf("Informe o peso:\n");
				scanf("%f", &data.peso);
				if(incluiNoFim(&lt, data) == LISTA_CHEIA){
					printf("ERROR: A Lista esta cheia\n");
				}else{
					printf("SUCESSO\n");
				}
				break;
			case 2:
				exibe(lt);
				break;
			case 3:
				printf("%d\n", quantidadeDeNodos(lt));
				break;
			case 4:
				if(estaCheia(lt) == 1){
					printf("A lista esta cheia\n");
				}else if(estaVazia(lt) == 1){
					printf("A lista esta vazia\n");
				}
				break;
			case 5:
				if(excluiDoFim(&lt, &data) == LISTA_VAZIA){
					printf("ERROR: A lista esta vazia\n");
				}else{
					printf("Dado %d excluido com SUCESSO\n", data.cod);
				}
				break;
			case 6:
				printf("Informe o codigo:\n");
				scanf("%d", &data.cod);
				printf("Informe o peso:\n");
				scanf("%f", &data.peso);
				if(incluiNoInicio(&lt, data) == LISTA_CHEIA){
					printf("ERROR: A lista esta cheia\n");
				} else {
					printf("SUCESSO\n");
				}
				break;
			case 7:
				if(excluiDoInicio(&lt,&data) == LISTA_VAZIA){
					printf("ERROR: A lista esta vazia\n");
				}else{
					printf("SUCESSO\n");
				}
				break;
			case 8:
				printf("Informe o codigo\n");
				scanf("%d",&pesq);
				if(consultaPorCodigo(lt, &data, pesq) == CODIGO_INEXISTENTE){
					printf("ERROR: Codigo inexistente\n");
				}else{
					printf("Codigo: %d Peso: %.2f\n", data.cod, data.peso);
				}
				break;
			case 9:
				printf("Informe o codigo:\n");
				scanf("%d", &data.cod);
				printf("Inform o peso:\n");
				scanf("%f", &data.peso);
				printf("Informe o codigo para pesquisa\n");
				scanf("%d", &pesq);
				forFunc = incluiAntes(&lt, data, pesq);
				if(forFunc == LISTA_CHEIA){
					printf("ERROR: A lista esta cheia\n");
				} else if(forFunc == CODIGO_INEXISTENTE){
					printf("ERROR: Codigo inexistente\n");
				} else{
					printf("SUCESSO\n");
				}
				break;
			case 10:
				printf("Informe o codigo:\n");
				scanf("%d", &pesq);
				forFunc = excluiNodo(&lt, &data, pesq);
				if(forFunc == LISTA_VAZIA){
					printf("ERROR: A lista esta vazia\n");
				} else if(forFunc == CODIGO_INEXISTENTE){
					printf("ERROR: Codigo inexistente\n");
				} else{
					printf("Dado do codigo %d foi excluido com SUCESSO\n", data.cod);
				}
				break;
			case 11:
				printf("Saindo...\n");
				break;
			default:
				printf("Informe uma opcao valida\n");
				break;
		}

			if(op != 2){
				exibe(lt);
			}
	}while(op != 11);

	return 0;

}

