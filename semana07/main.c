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
			case 5:
				if(excluiDoInicio(&lt, &d) == LISTA_VAZIA){
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
