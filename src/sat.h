#ifndef _SAT_STRUCTURE_DEF_H_
#define _SAT_STRUCTURE_DEF_H_
#include <stdbool.h>
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

/**
 * Initialise a SAT instance with the given values
 */
void initialiseSat(SAT* sat, Variable* variables, unsigned int numVariables, Clause* clauses, unsigned int numClauses);

/**
 * Print the SAT structure
 */
void printSat(SAT* sat);

/**
 * Prints a warning if a defined variable is not referenced in any clauses
 */
void warnUnusedVariables(SAT* sat);

/**
 * Returns true if a SAT problem is satisfiable, and false otherwise
 */
bool satIsSatisfiable(SAT* sat);

#endif //_SAT_STRUCTURE_DEF_H_
