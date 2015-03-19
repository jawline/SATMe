#ifndef _VARIABLE_DEF_H_
#define _VARIABLE_DEF_H_
#include <stdbool.h>

typedef struct {
	char const* name;
	bool state;
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
