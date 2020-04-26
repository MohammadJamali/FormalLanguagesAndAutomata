#ifndef ALPHABET_H
#define ALPHABET_H

#include <iostream>

using namespace std;

class Alphabet
{
public:
    friend istream &operator>>(istream  &input, Alphabet &alphabet)
    {
        input >> alphabet.alpha;
        return input;
    }

    friend bool operator==(Alphabet f, Alphabet s)
    {
        return f.alpha == s.alpha ? true : false;
    }

    Alphabet(char c = '0') : alpha(c){}

	bool isVariable()
	{
		return	'A' <= alpha && 'Z' >= alpha ? true : false;
	}

    char getCharCode(){ return alpha; }
    void setChar(char c){ alpha = c; }

private:
    char alpha;
};

class Variable : public Alphabet {};


#endif // ALPHABET_H
