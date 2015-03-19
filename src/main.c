#include <stdio.h>
#include "sat.h"

int main(int argc, char** argv) {
	Variable* v = allocateVariables(5);
	initialiseVariable(v, "A");
	initialiseVariable(v+1, "B");
	initialiseVariable(v+2, "C");
	initialiseVariable(v+3, "D");
	initialiseVariable(v+4, "E");

	for (unsigned int i = 0; i < 5; i++) {
		printf("%s%s", (v+i)->name, i == 4 ? "\n":" ");	
	}
	
	return 1;
}
