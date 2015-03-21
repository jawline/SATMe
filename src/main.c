#include <stdio.h>
#include "parser.h"
#include "sat.h"

void executeSat(SAT* s) {
	printSat(s);
	warnUnusedVariables(s);
	bool isSatisfiable = satIsSatisfiable(s);
	printf("Satisfiable: %s\n", isSatisfiable ? "true" : "false");
	if (isSatisfiable) {
		printSatAllocation(s);
	}	
}

int main(int argc, char** argv) {

	if (argc != 2) {
		printf("Error, incorrect number of arguments supplied");
		printf("Usage: %s 3-SatCnf", argv[0]);
		return -1;
	}
	
	SAT s;

	initialiseSat(&s, 0, 0, 0, 0);
	if (!parseSat(&s, argv[1])) {
		printf("Unable to parse %s\n", argv[1]);
		return 0;
	}
	executeSat(&s);
	freeSat(&s);

	return 0;
}
