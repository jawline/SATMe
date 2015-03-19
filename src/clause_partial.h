#ifndef _CLAUSE_PARTIAL_DEF_H_
#define _CLAUSE_PARTIAL_DEF_H_
#include <stdbool.h>
#include "variable.h"

/**
 * Clause partials represent a single variable reference or ¬ within a predicate clause
 */
typedef struct {

	/**
	 * The variable this partial references
	 */
	Variable* variable;

	/**
	 * Whether to negate the state of the variable
	 */
	bool negate;

} ClausePartial;

#endif //_CLAUSE_PARTIAL_DEF_H_
