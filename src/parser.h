#ifndef _SAT_PARSER_DEF_H_
#define _SAT_PARSER_DEF_H_
#include <stdbool.h>
#include "sat.h"

/**
 * Parses a string into a SAT data structure
 */
bool parseSat(SAT* sat, char const* input);

#endif //_SAT_PARSER_DEF_H_
