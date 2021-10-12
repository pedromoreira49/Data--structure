#include <stdio.h>
#include "cheque.h"

void criarCheque(Cheque *cheque, int num){
	cheque->numC = num;
	cheque->value = 0;
	cheque->status = 0;
}

int obtemStatus(Cheque *cheque){
	if(cheque->status == 0){
		printf("Em branco\n");
	}else if(cheque->status == 1){
		printf("Emitido\n");
	}else{
		printf("Compensado\n");
	}
	return cheque->status;
}

int exibeCheque(Cheque *cheque){
	printf("Num: %d    Valor: %.2f    Status:", cheque->numC, cheque->value);

	if(obtemStatus(cheque) == 0){
		printf(" Em branco\n");
	}else if(obtemStatus(cheque) == 1){
		printf(" Emitido\n");
	}else{
		printf(" Compensado\n");
	}
}

float obtemValor(Cheque *cheque){
	return cheque->value;
}

int obtemNum(Cheque *cheque){
	return cheque->numC;
}

int compensaCheque(Cheque *cheque){
	if(obtemStatus(cheque) == 1){
		cheque->status = 2;
		return 0;
	}else{
		return 1;
	}
}

int emiteCheque(Cheque *cheque, float value){
	if(obtemStatus(cheque) == 0){
		cheque->status = 1;
		cheque->value = value;
		return 0;
	}else{
		return 1;
	}
}
