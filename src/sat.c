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
		(sat->variables+i)->state = false;
	}
	for (unsigned int i = 0; i < sat->numClauses; i++) {
		(sat->clauses+i)->A.variable->state = true;
		(sat->clauses+i)->B.variable->state = true;
		(sat->clauses+i)->C.variable->state = true;
	}
	for (unsigned int i = 0; i < sat->numVariables; i++) {
		if (!(sat->variables+i)->state) {
			printf("Warning: Variable %s is unused\n", (sat->variables+i)->name);
		}
	}
}