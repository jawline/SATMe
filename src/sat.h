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
 * Frees all memory attached to a SAT instance
 */
void freeSat(SAT* sat);

/**
 * Print the SAT structure
 */
void printSat(SAT* sat);

/**
 * Prints a warning if a defined variable is not referenced in any clauses
 */
void warnUnusedVariables(SAT* sat);

/**
 * Prints the current variable allocation
 */
void printSatAllocation(SAT* sat);

/**
 * Finds a variable in a SAT, return 0 if it doesnt exist
 */
Variable* satFindVariable(SAT* sat, char const* name);

/**
 * Add a variable to a SAT
 */
Variable* satAddVariable(SAT* sat, char const* name);

/**
 * Adds a new clause to the SAT
 */
void satAddClause(SAT* sat, ClausePartial a, ClausePartial b, ClausePartial c);

/**
 * Returns true if a SAT problem is satisfiable, and false otherwise
 */
bool satIsSatisfiable(SAT* sat);

#endif //_SAT_STRUCTURE_DEF_H_
