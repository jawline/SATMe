#include <stdio.h>
#include "parser.h"
#include "sat.h"

void executeSat(SAT* s) {
	printSat(s);
	warnUnusedVariables(s);
	bool isSatisfiable = satIsSatisfiable(s);
	printf("Satisfiable: %s\n", isSatisfiable ? "true" : "false");
	if (isSatisfiable) {
		printSatAllocation(s);
	}	
}

int main(int argc, char** argv) {
	
	SAT s;
	Variable* v = 0;
	Clause* c = 0;

	initialiseSat(&s, 0, 0, 0, 0);
	parseSat(&s, "(Av¬BvC) ^ (¬AvBv¬C) ^ (AvCvD)");
	executeSat(&s);
	freeSat(&s);

	return 0;
}
