#include "clause_partial.h"

ClausePartial clausePartial(Variable* v, bool negate) {
	ClausePartial P = {v, negate};
	return P;
}