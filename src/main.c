#include <stdio.h>
#include "sat.h"

int main(int argc, char** argv) {
	Variable* v = allocateVariables(5);

	initialiseVariable(v, "A");
	initialiseVariable(v+1, "B");
	initialiseVariable(v+2, "C");
	initialiseVariable(v+3, "D");
	initialiseVariable(v+4, "E");

	Clause* c = allocateClauses(2);
	initialiseClause(c, clausePartial(v, false), clausePartial(v, false), clausePartial(v, false));
	initialiseClause(c+1, clausePartial(v, true), clausePartial(v, true), clausePartial(v, true));

	SAT s;
	initialiseSat(&s, v, 5, c, 2);
	printSat(&s);
	warnUnusedVariables(&s);

	bool isSatisfiable = satIsSatisfiable(&s);
	printf("Satisfiable: %s\n", isSatisfiable ? "true" : "false");
	if (isSatisfiable) {
		printSatAllocation(&s);
	}

	return 0;
}
