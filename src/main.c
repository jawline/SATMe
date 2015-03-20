#include <stdio.h>
#include "sat.h"

void executeSat(SAT* sat) {
	printSat(&s);
	warnUnusedVariables(&s);
	bool isSatisfiable = satIsSatisfiable(&s);
	printf("Satisfiable: %s\n", isSatisfiable ? "true" : "false");
	if (isSatisfiable) {
		printSatAllocation(&s);
	}	
}

int main(int argc, char** argv) {
	
	SAT s;
	Variable* v = 0;
	Clause* c = 0;
	
	v = allocateVariables(5);
	initialiseVariable(v, "A");
	initialiseVariable(v+1, "B");
	initialiseVariable(v+2, "C");
	initialiseVariable(v+3, "D");
	initialiseVariable(v+4, "E");

	c = allocateClauses(2);
	initialiseClause(c, clausePartial(v, false), clausePartial(v, false), clausePartial(v, false));
	initialiseClause(c+1, clausePartial(v, true), clausePartial(v, true), clausePartial(v, true));

	initialiseSat(&s, v, 5, c, 2);
	executeSat(&s);
	freeSat(&s);

	return 0;
}
