#include "clause.h"
#include <stdlib.h>
#include <string.h>

Clause* allocateClauses(unsigned int num) {
	Clause* allocation = (Clause*) malloc(sizeof(Clause)*num);
	memset(allocation, 0, sizeof(Clause)*num);
	return allocation;
}


