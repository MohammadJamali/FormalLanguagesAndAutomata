#ifndef GRAMMER_H
#define GRAMMER_H

#include "RuleSet.h"
#include "AlphabetSet.h"

class Grammer
{
public:
    Grammer(VariableSet variables, AlphabetSet alphaSet, int startVar, RuleSet ruleSet)
    {
        objVariables = new VariableSet(variables);
        objAlphabetSet = new AlphabetSet(alphaSet);
        objRuleSet = new RuleSet(ruleSet);
        startVariable = startVar;
    }
    ~Grammer()
    {
		if (objVariables->getSize() > 0)
			delete objVariables;
		if (objAlphabetSet->getSize() >0)
			delete objAlphabetSet;
		if (objRuleSet->getRuleCount() >0)
			delete objRuleSet;
    }

    VariableSet getVariableSet()	{ return *objVariables; }
    AlphabetSet getAlphabetSet()	{ return *objAlphabetSet; }
    RuleSet		getRuleSet()		{ return *objRuleSet; }

private:
    VariableSet *objVariables;
    AlphabetSet *objAlphabetSet;
    RuleSet *objRuleSet;
    int startVariable;
};


#endif // GRAMMER_H
