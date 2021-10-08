#include "Horario.h"

int convertTime(Horario *dados){
	int timeConverted = 0;

	timeConverted += dados->hh * 3600;
	timeConverted += dados->mm * 60;
	timeConverted += dados->ss;

	return timeConverted;
}
