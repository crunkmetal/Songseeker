// preprocessor directives
#pragma once
#include "Songs.h"
// class Branching is derived from Songs class
class Branching : public Songs
{
public:
	void choices();
	void branchChoice(const int*);		// const pointer parameter

	int getUserChoice();
	void setUserChoice(const int*);		// const pointer parameter

private:
	int m_user_choice = 0;
};
