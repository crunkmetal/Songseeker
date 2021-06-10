// preprocessor directives
#include "Intro.h"
#include "Branching.h"
// using standard template library
using namespace std;
// the one and only main function, expects an int return value
int main()
{
	Intro intro;								// instantiate an object of Intro Class
	intro.intro();								// invoke function to display intro;
	Branching direction;							// instantiating an object of Branching class
	
	do
	{
		direction.choices();						// invoking choices function from Branching class
		const int usersChoice = direction.getUserChoice(); 		// assigning the value of the result of function into a constant int variable
		direction.branchChoice(&usersChoice);				// invoke branchChoice function from Branching class (passing value by reference)
		system("CLS");							// clear the console (WinOS specific)
	} while ((direction.getUserChoice()) != 6);				// game loop continues unless user's choice is '6'

    return 0;									// returning int value to main
}
