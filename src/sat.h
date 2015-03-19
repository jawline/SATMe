#ifndef _SAT_STRUCTURE_DEF_H_
#define _SAT_STRUCTURE_DEF_H_
#include "variable.h"
#include "clause.h"

/**
 * The SAT data structure represents a boolean satisfaction problem as a C data structure
 */
typedef struct {
	Variable* variables;
	unsigned int numVariables;

	Clause* clauses;
	unsigned int numClauses;
} SAT;

void initialiseSat(SAT* sat, Variable* variables, unsigned int numVariables, Clause* clauses, unsigned int numClauses);

#endif //_SAT_STRUCTURE_DEF_H_
