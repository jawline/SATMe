#include "clause_partial.h"

ClausePartial clausePartial(Variable* v, bool negate) {
	ClausePartial P = {v, negate};
	return P;
}

bool clausePartialSatisfied(ClausePartial* p) {
	bool cur = p->variable->state == VAR_TRUE;
	return p->negate ? !cur : cur;
}