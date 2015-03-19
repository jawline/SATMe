#include "clause.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

Clause* allocateClauses(unsigned int num) {
	Clause* allocation = (Clause*) malloc(sizeof(Clause)*num);
	memset(allocation, 0, sizeof(Clause)*num);
	return allocation;
}

void initialiseClause(Clause* clause, ClausePartial A, ClausePartial B, ClausePartial C) {
	clause->A = A;
	clause->B = B;
	clause->C = C;
}

void printClause(Clause* clause) {
	printf("(%s%sv%s%sv%s%s)",
		clause->A.negate ? "¬" : "", clause->A.variable->name,
		clause->B.negate ? "¬" : "", clause->B.variable->name,
		clause->C.negate ? "¬" : "", clause->C.variable->name);
}