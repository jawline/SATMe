#ifndef _VARIABLE_DEF_H_
#define _VARIABLE_DEF_H_

/**
 * Variable states in the SAT solver can have three states, TRUE, FALSE or UNSET.
 * TRUE and FALSE map to boolean true and false, UNSET indicates that this variable does
 * not have a mapping in the current allocation
 */
typedef enum { 
	VAR_FALSE = 0,
	VAR_TRUE,
	VAR_UNSET
} VariableState;

/**
 * A Variable in the SAT solver has a name (for debugging and output) and a current allocation state
 */
typedef struct {
	char* name;
	VariableState state;
} Variable;

/**
 * Allocate memory for num variables
 */
Variable* allocateVariables(unsigned int num);

/**
 * Initialise the specified variable with a given name
 */
void initialiseVariable(Variable* variable, char const* name);

/**
 * Free any memory allocated to a variable
 */
void freeVariable(Variable* variable);

#endif //_VARIABLE_DEF_H_
