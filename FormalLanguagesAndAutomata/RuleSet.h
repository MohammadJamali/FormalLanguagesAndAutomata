#ifndef RULESET_H
#define RULESET_H

#include <vector>
#include "Rule.h"

using namespace std;

class RuleSet
{
	public:
		RuleSet(){}
		RuleSet(rsize_t size, Rule *Rules)
		{
			for (size_t i = 0; i < size; i++)
				arr.push_back(Rules[i]);
		}

		void addNewRule(Rule rule)
		{
			arr.push_back(rule);
		}

		rsize_t getRuleCount(){ return arr.size(); }
		Rule getRule(int index){ return arr.at(index); }

	private:
		vector<Rule> arr;
};

#endif // RULESET_H
