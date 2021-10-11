#include "aluno.h"

int verificaIdade(Date *hoje, Date *dta_nasc){
	if((hoje->ano - dta_nasc->ano) >= 18){
		return 1;
	}else{
		return 0;
	}
}



