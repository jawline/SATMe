#SAT Solving experiment

Dependancies: gcc, make

To build:
Invoke make from the repository directory

To test:
From the repository directory invoke
./bin/satme "3-SAT in CNF"
For example
./bin/satme "(AvBvC)^(¬Av¬Bv¬C)"

The parser is capable of expanding signle and double rules into 3 variable clauses
For example

./bin/satme "(A)"
./bin/satme "(AvB)"

should parse correctly.

In addition to thise single variable clauses (Such as "¬A") do not need parenthesis

so ./bin/satme "¬A^A" will parse correctly
