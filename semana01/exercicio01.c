#include <stdio.h>
#include <stdlib.h>

/*Exercicio: 1.1
Escreva um programa em C para ler um valor Q que representa a quantidade de alunos de uma turma.
A seguir ler Q pares de dados contendo, cada um, a altura e um código para masculino (1) e feminino (2) de cada aluno.
Calcular e escrever:
-A altura do "ALUNO" mais alto da turma.
-A média de altura das "ALUNAS".
*/

int main(){
	int q, i, cont, opt;
	float alt, med_alt = 0.0, alt_men = 0.0, med_men = 0.0, bestHeight = 0.0;
	printf("Informe a quantidade de alunos:\n");
	scanf("%d", &q);
	for (i = 0; i < q; i++){
		printf("Informe o sexo do(a) aluno(a): 1-masculino 2-feminino\n");
		scanf("%d", &opt);
		if(opt == 1){
			printf("Informe a altura do aluno:\n");
			scanf("%f", &alt);
			if(alt > bestHeight){
				bestHeight = alt;
			}
		} else{
			printf("Informe a altura da aluna:\n");
			scanf("%f", &alt_men);
			cont++;
			med_men = med_men + alt_men;
		}
	}//fim do laço for
	med_alt = med_men / cont;
	printf("med fem: %.2f\n", med_alt);
	printf("Best height: %.2f\n", bestHeight);
	return 0;
}
