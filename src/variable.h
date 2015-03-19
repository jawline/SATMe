#ifndef _VARIABLE_DEF_H_
#define _VARIABLE_DEF_H_

typedef enum { VAR_FALSE = 0, VAR_TRUE, VAR_UNSET} VariableState;

typedef struct {
	char const* name;
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

#endif //_VARIABLE_DEF_H_
