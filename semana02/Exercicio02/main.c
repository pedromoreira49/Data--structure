#include "aluno.c"
#include <stdio.h>
#include <stdlib.h>

/*Exercicio: 2.2
Definir um tipo chamado Aluno para armazenar os seguintes dados de um aluno: número de matrı́cula e data de nascimento (tipo Data). Escrever um programa em C para ler a data de hoje armazenando-a em uma variável do tipo Data. A seguir ler uma quantidade indeterminada de dados de alunos (Aluno). Para cada aluno lido escrever se ele já completou 18 anos até a data informada. O programa termina ao ser informado um valor negativo para a matrı́cula. Nesta situação a data de nascimento não deve ser lida.
*/


int main(){
	Date hoje, *p, *q;
	Aluno aluno;

	printf("Informe a data de hoje:\n");
	scanf("%d %d %d", &hoje.dia, &hoje.mes, &hoje.ano);
	p = &hoje;
	do{
		printf("Informe a matricula do aluno:\n");
		scanf("%d", &aluno.matricula);
		if(aluno.matricula < 0){
			exit(0);
		}
		printf("Informe a data de nascimento do aluno:\n");
		scanf("%d %d %d", &aluno.dt_nasc.dia, &aluno.dt_nasc.mes, &aluno.dt_nasc.ano);
		q = &aluno.dt_nasc;
		if(verificaIdade(p, q)){
			printf("18 anos :D\n");
		}else{
			printf("Nao tem 18 anos\n");
		}

	}while(aluno.matricula > 0);
	return 0;
}
