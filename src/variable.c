#include "variable.h"
#include <string.h>
#include <stdlib.h>

Variable* allocateVariables(unsigned int num) {
	Variable* allocation = (Variable*) malloc(sizeof(Variable) * num);
	memset(allocation, 0, sizeof(Variable) * num);
	return allocation;
}

void initialiseVariable(Variable* variable, char const* name) {
	variable->name = malloc(strlen(name)+1);
	strcpy(variable->name, name);
}

void freeVariable(Variable* variable) {
	free(variable->name);
	free(variable);
}