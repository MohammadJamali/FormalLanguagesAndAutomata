#ifndef ALPHABETSET_H
#define ALPHABETSET_H

#include <vector>
#include "Alphabet.h"

using namespace std;

class AlphabetSet
{
public:
    Alphabet operator[](int index)
    {
        return arr[index];
    }

    AlphabetSet(){}

	AlphabetSet(rsize_t size, Alphabet *alpha)
    {
        for (size_t i = 0; i < size; i++)
            arr.push_back(alpha[i]);
    }

    int find(Alphabet alpha)
    {
        for (size_t i = 0; i < arr.size(); i++)
        if (arr.at(i) == alpha)
            return i;

        return -1;
    }

    bool addNewAlpha(Alphabet alpha, bool Repeat = true)
    {
		if (Repeat)
			for (size_t i = 0; i < arr.size(); i++)
				if (arr.at(i) == alpha)
					return false;

        arr.push_back(alpha);
		return true;
    }

    rsize_t getSize(){ return arr.size(); }

private:
    vector<Alphabet> arr;
};

class VariableSet : public AlphabetSet {};

#endif // ALPHABETSET_H
