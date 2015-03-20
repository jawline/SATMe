#include "sat.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initialiseSat(SAT* sat, Variable* variables, unsigned int numVariables, Clause* clauses, unsigned int numClauses) {
	sat->variables = variables;
	sat->numVariables = numVariables;
	sat->clauses = clauses;
	sat->numClauses = numClauses;
}

void freeSat(SAT* sat) {
	if (sat->variables) {
		for (unsigned int i = 0; i < sat->numVariables; i++) {
			freeVariable(sat->variables+i);
		}
		free(sat->variables);
		sat->variables = 0;
		sat->numVariables = 0;
	}
	if (sat->clauses) {
		free(sat->clauses);
		sat->clauses = 0;
		sat->numClauses = 0;
	}
}

Variable* satAddVariable(SAT* sat, char const* name) {
  unsigned int numCurrent = sat->numVariables;

  Variable* newAllocation = (Variable*) malloc(sizeof(Variable) * (numCurrent + 1));
  memset(newAllocation, 0, sizeof(Variable) * (numCurrent + 1));

  if (sat->numVariables) {
  	memcpy(newAllocation, sat->variables, sizeof(Variable) * sat->numVariables);
  }

  initialiseVariable(newAllocation + numCurrent, name);
  Variable* createdVariable = newAllocation + numCurrent;

  sat->variables = newAllocation;
  sat->numVariables++;
  
  return createdVariable;
}

Variable* satFindVariable(SAT* sat, char const* name) {
  for (unsigned int i = 0; i < sat->numVariables; i++) {
    if (strcmp((sat->variables+i)->name, name) == 0) {
      return sat->variables+i;
    }
  }
  return 0;
}

void printSat(SAT* sat) {
	printf("Variables: ");
	for (unsigned int i = 0; i < sat->numVariables; i++) {
		printf("%s%s", (sat->variables+i)->name, i == 4 ? "\n":" ");	
	}
	printf("Clauses: ");
	for (unsigned int i = 0; i < sat->numClauses; i++) {
		printClause(sat->clauses+i);
		printf(i == (sat->numClauses-1) ? "\n" : "^");
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
			printf("Warning: Variable %s is unused (This could slow down execution)\n", (sat->variables+i)->name);
		}
	}
}


void printSatAllocation(SAT* sat) {
	printf("Variables: ");
	for (unsigned int i = 0; i < sat->numVariables; i++) {
		printf("%s: %s\n", (sat->variables+i)->name, ((sat->variables+i)->state == VAR_TRUE) ? "true" : "false");	
	}
}

bool satSatisfied(SAT* sat) {
	for (unsigned int i = 0; i < sat->numClauses; i++) {
		if (!clauseSatisfied(sat->clauses+i)) {
			return false;
		}
	}
	return true;
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

	//If all variables are allocated then check if the SAT is satisfied
	if (!unset) {
		return satSatisfied(sat);
	}

	//Recurse and test satisfiability with this variable set to true
	unset->state = VAR_TRUE;
	if (satRecursiveSatisfy(sat)) {
		return true;
	}

	//Recurse and test satisfiability with this variable set to false
	unset->state = VAR_FALSE;
	if (satRecursiveSatisfy(sat)) {
		return true;
	}

	//If no solution was found then cleanup the changes and backtrack
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
