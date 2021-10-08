#include <stdio.h>
#include "Horario.c"

/*Exercicio: 2.1
Definir um tipo chamado Horario para armazenar um horário composto de: hora, minuto, segundo.
Escreva um programa em C para ler dois horários. Escreva o menor horário no formato HH:MM:SS. No caso de igualdade escrever a mensagem "Horários iguais".
*/

int main(void) {
	Horario hor[2], *p;
	int h1, h2;

	for(int i = 0; i < 2; i++){
		printf("Informe o horario: HH:MM:SS\n");
		scanf("%d %d %d", &hor[i].hh, &hor[i].mm, &hor[i].ss);
	}

	h1 = convertTime(&hor[0]);
	h2 = convertTime(&hor[1]);

	if(h1 > h2){
		p = &hor[1];
		printf("%d:%d:%d\n", p->hh, p->mm, p->ss);
	}else if(h1 == h2){
		printf("Horarios iguais\n");
	}else{
		p = &hor[0];
		printf("%d:%d:%d\n", p->hh, p->mm, p->ss);
	}

	return 0;
}

