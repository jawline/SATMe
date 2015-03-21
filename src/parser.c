#include "parser.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

/**
 * Grammar explanation
 * | - Or
 * [Rule] - Optional rule
 * `x` - Expect x character
 * Hello: `a` - Define the grammar rule Hello which is satisfied by the input string `a`
 */

/**
 * Skip whitespace until the end of the input or the next character is found
 */
char const* nextToken(char const* input) {
  for (; *input && isspace(*input); input++) {}
  return input;
}

/**
 * Alpha: Any alphabet character
 * Variable: Alpha | '¬' Alpha
 */
char const* parseVariable(SAT* sat, ClausePartial* partial, char const* input) {
  bool negate = false;
  char name = '\0';

  //If the first character is a negation then we expect the ¬A 
  //Test -62 and -84 as ¬ is a multibyte character comprised of -62 and -84
  if (*input && *input == -62 && *(input+1) == -84) {
    negate = true;
    input = nextToken(input+2);
  }
  
  if (isalpha(*input)) {
    name = *input;
    input = nextToken(input+1);
  } else {
    printf("Expected alphabet variable name. Recieved %c\n", *input);
    return 0;
  }
  
  char nameBuffer[2];
  nameBuffer[0] = name;
  nameBuffer[1] = '\0';

  //Set the clause partial from the parsed information
  Variable* v = satFindVariable(sat, nameBuffer);
  if (!v) {
    v = satAddVariable(sat, nameBuffer);
  }

  *partial = clausePartial(v, negate);
  return input;
}

bool parseVariableExpected(char const* input) {
  if (isalpha(*input)) {
    return true;
  }
  if (*input && *input == -62 && *(input+1) == -84) {
    return true;
  }
  return false;
}

/**
 * ClauseBody: Variable 'v' Variable 'v' Variable
 */
char const* parseClauseBody(SAT* sat, char const* input) {

  ClausePartial a, b, c;
  
  //Parse the first variable in clause
  input = parseVariable(sat, &a, input);
  if (!input) {
    return 0;
  }

  if (*input == ')') {
    satAddClause(sat, a, a, a);
    return input;
  } else if (*input == 'v') {
    input = nextToken(input+1);
  } else {
    printf("Unexpected %c\n", *input);
    return 0;
  }
  
  //Parse the second variable in clause
  input = parseVariable(sat, &b, input);
  if (!input) {
    return 0;
  }

  if (*input == ')') {
    satAddClause(sat, a, a, b);
    return input;
  } else if (*input == 'v') {
    input = nextToken(input+1);
  } else {
    printf("Unexpected %c\n", *input);
    return 0;
  }
  
  //Parse the last variable in clause
  input = parseVariable(sat, &c, input);
  if (!input) {
    return 0;
  }

  satAddClause(sat, a, b, c);
  
  return input;
}

/**
 * Clause: '(' ClauseBody ')' ['^' Clause]
 */
char const* parseCnfClause(SAT* sat, char const* input) {

  //If the next token is a ( then it is the start of a 3-sat clause
  if (*input == '(') {

    //Parse the variables
    input = parseClauseBody(sat, nextToken(input+1));
    if (!input) {
      return 0;
    }
    //Check that it is closed
    if (*input == ')') {
      input = nextToken(input+1);
    } else {
      printf("ERROR: Expecting )\n");
      return 0;
    }
  } else if (parseVariableExpected(input)) { //If the next token is a ¬ 
    ClausePartial a;
    input = parseVariable(sat, &a, input);
    satAddClause(sat, a, a, a);
    if (!input) {
      return 0;
    }
  } else {
    printf("ERROR: Expected a single variable condition (A or ¬A) or a 3-sat clause (AvBvC)");
    return 0;
  }

  //If the next terminal is a ^ then repeat for the next cnf clause  
  if (*input == '^') {
    return parseCnfClause(sat, nextToken(input+1));
  } else if (!*input) {
    //If its the end of the parsing then return input (Anything other than 0 is ok - 0 indicates error)
    return input;
  } else {
    //Any other characters cause an error
    printf("ERROR: Unexpected %c\n", *input);
    return 0;
  }
}

bool parseSat(SAT* sat, char const* input) {
  return parseCnfClause(sat, input) != 0;
}
