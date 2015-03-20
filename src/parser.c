#include "parser.h"
#include <ctype.h>

char const* skipWhitespace(char const* satString) {
  for (; *satString && isspace(*satString); satString++) {}
  return satString;
}

char const* parseClause(SAT* sat, char const* satString) {
  
}

bool parseSat(SAT* sat, char const* satString) {
  satString = skipWhitespace(satString);
  if (*satString == '(') {
    satString = parseClause(sat, satString+1);
    if (!satString) {
      return false;
    }
    if (*satString == ')') {
      satString++;
    } else {
      printf("ERROR: Expecting )\n");
      return false;
    }
  } else {
    printf("ERROR: Expecting (\n");
    return false;
  }
}
