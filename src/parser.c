#include "parser.h"
#include <ctype.h>

char const* skipWhitespace(char const* satString) {
  for (; *satString && isspace(*satString); satString++) {}
  return satString;
}

char const* nextTerminal(char const* satString) {
  return skipWhitespace(satString+1);
}

bool parseSat(SAT* sat, char const* satString) {
  for (satString = skipWhitespace(satString); *satString; satString = nextTerminal(satString)) {
  }
}
