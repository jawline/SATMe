#include <stdio.h>
#include "sat.h"

int main(int argc, char** argv) {
	Variable* v = allocateVariables(5);

	initialiseVariable(v, "A");
	initialiseVariable(v+1, "B");
	initialiseVariable(v+2, "C");
	initialiseVariable(v+3, "D");
	initialiseVariable(v+4, "E");

	Clause* c = allocateClauses(3);
	initialiseClause(c, clausePartial(v, false), clausePartial(v+1, false), clausePartial(v, true));
	initialiseClause(c+1, clausePartial(v, false), clausePartial(v+1, false), clausePartial(v, true));
	initialiseClause(c+2, clausePartial(v, false), clausePartial(v+1, false), clausePartial(v, true));

	SAT s;
	initialiseSat(&s, v, 5, c, 3);
	printSat(&s);
	warnUnusedVariables(&s);

	return 0;
}
