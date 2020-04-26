#include <iostream>
#include <string>
#include <algorithm>

#include "Grammer.h"

using namespace std;

void remove_nullable(Grammer objGrammer)
{
	// Remove nullables

	bool changeFlag = false;
	VariableSet nullVariable;

	// find all variables that have landa(*)
	for (size_t i = 0; i < objGrammer.getRuleSet().getRuleCount(); i++)
		if (objGrammer.getRuleSet().getRule(i).getAlphabetSet().getSize() == 1)
			if (objGrammer.getRuleSet().getRule(i).getAlphabetSet()[0] == '*')
				nullVariable.addNewAlpha(objGrammer.getRuleSet().getRule(i).getVariable().getCharCode());

	while (!changeFlag)
	{
		changeFlag = true;
		for (size_t i = 0; i < objGrammer.getRuleSet().getRuleCount(); i++)
		{
			int counter = 0;
			for (size_t j = 0; j < nullVariable.getSize(); j++)
				for (size_t k = 0; k < objGrammer.getRuleSet().getRule(i).getAlphabetSet().getSize(); k++)
					if (objGrammer.getRuleSet().getRule(i).getAlphabetSet()[k].getCharCode() == nullVariable[j].getCharCode())
						counter++;

			if (objGrammer.getRuleSet().getRule(i).getAlphabetSet().getSize() == counter)
				if (nullVariable.addNewAlpha(objGrammer.getRuleSet().getRule(i).getVariable()))
					changeFlag = false;
		}
	}

	cout << endl << endl << " nullable set {";
	for (size_t i = 0; i < nullVariable.getSize(); i++)
	{
		cout << nullVariable[i].getCharCode();

		if (i < nullVariable.getSize() - 1)
			cout << ", ";
	}
	cout << "}";

}

void useless(Grammer objGrammmer)
{
	VariableSet PT;

	// get those who will create terminal
	for (size_t i = 0; i < objGrammmer.getRuleSet().getRuleCount(); i++)
	{
		bool isValid = true;
		for (size_t j = 0; j < objGrammmer.getRuleSet().getRule(i).getAlphabetSet().getSize(); j++)
			if (objGrammmer.getRuleSet().getRule(i).getAlphabetSet()[j].isVariable())
				isValid = false;

		if (isValid)
			PT.addNewAlpha(objGrammmer.getRuleSet().getRule(i).getVariable());
	}

	bool changeFlag = false;
	while (!changeFlag)
	{
		changeFlag = true;

		for (size_t i = 0; i < objGrammmer.getRuleSet().getRuleCount(); i++)
		{
			int counter = 0;
			for (size_t j = 0; j < objGrammmer.getRuleSet().getRule(i).getAlphabetSet().getSize(); j++)
				if (objGrammmer.getRuleSet().getRule(i).getAlphabetSet()[j].isVariable())
					for (size_t k = 0; k < PT.getSize(); k++)
						if (objGrammmer.getRuleSet().getRule(i).getAlphabetSet()[j].getCharCode() == PT[k].getCharCode())
							counter++;

			if (counter == objGrammmer.getRuleSet().getRule(i).getAlphabetSet().getSize())
				if (PT.addNewAlpha(objGrammmer.getRuleSet().getRule(i).getVariable()))
					changeFlag = false;
		}
	}

	cout << endl << endl << " PT set {";
	for (size_t i = 0; i < PT.getSize(); i++)
	{
		cout << PT[i].getCharCode();

		if (i < PT.getSize() - 1)
			cout << ", ";
	}
	cout << "}";
}

int main()
{
    VariableSet grammerVariables;
    AlphabetSet grammerAlphabet;
    RuleSet grammerRuleSet;
    int startPoint = 0;

    cout << endl << " Please enter grammer alphabets ( Enter ! at end ) : ";

    Alphabet alpha;
	cin >> alpha;
	while (alpha.getCharCode() != '!'){
		grammerAlphabet.addNewAlpha(alpha);
		cin >> alpha;
	}

    cout << " Plase enter grammer variables  ( Enter ! at end ) : ";

	cin >> alpha;
	while (alpha.getCharCode() != '!'){
		grammerVariables.addNewAlpha(alpha);
		cin >> alpha;
	}

    cout << " Please enter start variable index : ";
    cin >> startPoint;

	cout << " Plase enter grammer rules  ( like : S -> aA | bB - Enter ! at end ) :\n" << endl;

	fflush(stdin);
	char inputRuleChar[256];
	string inputRule;

	do{
		cout << "\t";
		cin.getline(inputRuleChar, 256, '\n');

		inputRule.assign(inputRuleChar);

		rsize_t index = 0;
        while (!(inputRule[index] >= 'A' && inputRule[index] <= 'Z') && index < inputRule.size())
            index++;

        Variable var;

        var.setChar(toupper(inputRule[index]));

        if (grammerVariables.find(toupper(inputRule[index++])) == -1)
        {
            cout << " -Sorry, but there is an un-known variable in this rule !" << endl << "  Please try agian ... " << endl;
            continue;
        }

        while (index < inputRule.size())
        {
			bool flag = true;
            VariableSet rule;

            while (inputRule[index] != '|' && index < inputRule.size())
            {
				if (isalpha(inputRule[index]) || inputRule[index] == '*')
					rule.addNewAlpha(inputRule[index], false);

				index++;
            }

			index++;

            grammerRuleSet.addNewRule(*(new Rule(var, rule)));
        }

	} while (inputRule.at(inputRule.size() - 1) != '!');

    Grammer objGrammer(grammerVariables, grammerAlphabet, startPoint, grammerRuleSet);

	int choise = 0;
	cout << endl <<" Please choose what you want to do : \n\t1)nullables\n\t2)useless" << endl << "\t-> ";
	cin >> choise;

	if (choise == 1)
		remove_nullable(objGrammer);
	else
		useless(objGrammer);
	
	fflush(stdin);
	getchar();

    return EXIT_SUCCESS;
}