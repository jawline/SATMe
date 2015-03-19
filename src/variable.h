#ifndef _VARIABLE_DEF_H_
#define _VARIABLE_DEF_H_
#include <stdbool.h>

typedef struct {
	char const* name;
	bool state;
} Variable;

Variable* allocateVariables(unsigned int num);
void initialiseVariable(Variable* variable, char const* name);

#endif //_VARIABLE_DEF_H_
