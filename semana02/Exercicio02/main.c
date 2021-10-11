#include "aluno.c"
#include <stdio.h>
#include <stdlib.h>

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
