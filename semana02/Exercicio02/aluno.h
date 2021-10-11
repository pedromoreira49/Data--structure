#ifndef Aluno_H
#define Aluno_H

typedef struct {
	int dia, mes, ano;

} Date;

typedef struct {
	int matricula;
	Date dt_nasc;
} Aluno;

int verificaIdade(Date *hoje, Date *dta_nasc);

#endif
