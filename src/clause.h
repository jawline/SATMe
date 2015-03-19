#ifndef _CLAUSE_DEF_H_
#define _CLAUSE_DEF_H_
#include "clause_partial.h"

/**
 * In a 3-sat a clause is the the disjunction of 3 clause partials (Variable or ¬Variable)
 */
typedef struct Clause {
	ClausePartial A;
	ClausePartial B;
	ClausePartial C;
} Clause;

/**
 * Allocate memory for num clauses
 */
Clause* allocateClauses(unsigned int num);

/**
 * Initialise a given clause with some values
 */
void initialiseClause(Clause* clause, ClausePartial A, ClausePartial B, ClausePartial C);

/**
 * Print debug info about the clause
 */
void printClause(Clause* clause);

#endif //_CLAUSE_DEF_H_
