#ifndef RULE_H
#define RULE_H

#include "Alphabet.h"
#include "AlphabetSet.h"

class Rule{
public:
    Rule(Variable var, AlphabetSet alphaSet){
        objVariable = new Variable(var);
        objAlphabetSet = new AlphabetSet(alphaSet);
    }

    Variable getVariable(){ return *objVariable; }
    AlphabetSet getAlphabetSet(){ return *objAlphabetSet; }

private:
    Variable *objVariable;
    AlphabetSet *objAlphabetSet;
};


#endif // RULE_H
