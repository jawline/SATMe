#include "sat.h"
#include <stdio.h>

void initialiseSat(SAT* sat, Variable* variables, unsigned int numVariables, Clause* clauses, unsigned int numClauses) {
	sat->variables = variables;
	sat->numVariables = numVariables;
	sat->clauses = clauses;
	sat->numClauses = numClauses;
}

void printSat(SAT* sat) {
	printf("Variables: ");
	for (unsigned int i = 0; i < sat->numVariables; i++) {
		printf("%s%s", (sat->variables+i)->name, i == 4 ? "\n":" ");	
	}

	printf("Clauses: ");
	for (unsigned int i = 0; i < sat->numClauses; i++) {
		printClause(sat->clauses+i);
		printf(i == 2 ? "\n" : " ");
	}
}

void warnUnusedVariables(SAT* sat) {
	for (unsigned int i = 0; i < sat->numVariables; i++) {
		(sat->variables+i)->state = VAR_FALSE;
	}
	for (unsigned int i = 0; i < sat->numClauses; i++) {
		(sat->clauses+i)->A.variable->state = VAR_TRUE;
		(sat->clauses+i)->B.variable->state = VAR_TRUE;
		(sat->clauses+i)->C.variable->state = VAR_TRUE;
	}
	for (unsigned int i = 0; i < sat->numVariables; i++) {
		if (!(sat->variables+i)->state) {
			printf("Warning: Variable %s is unused\n", (sat->variables+i)->name);
		}
	}
}

bool satRecursiveSatisfy(SAT* sat) {

	//Find the next unset state
	Variable* unset = 0;

	for (unsigned int i = 0; i < sat->numVariables; i++) {
		if ((sat->variables+i)->state == VAR_UNSET) {
			unset = sat->variables+i;
			break;
		}
	}

	if (!unset) {
		printf("TEST SATISFIABLE\n");
		return false;
	} else {
		printf("Next unset %s\n", unset->name);
	}

	unset->state = VAR_TRUE;
	if (satRecursiveSatisfy(sat)) {
		return true;
	}

	unset->state = VAR_FALSE;
	if (satRecursiveSatisfy(sat)) {
		return true;
	}

	unset->state = VAR_UNSET;

	return false;
}

bool satIsSatisfiable(SAT* sat) {
	
	//Reset all states to VAR_UNSET before attempting to satisfy recursively
	for (unsigned int i = 0; i < sat->numVariables; i++) {
		(sat->variables+i)->state = VAR_UNSET;
	}

	return satRecursiveSatisfy(sat);
}