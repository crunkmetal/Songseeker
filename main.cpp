#include <iostream>
#include <fstream>


#include "Intro.h"
#include "Songs.h"
#include "Branching.h"

using namespace std;



int main()
{
	Intro intro;	// instantiate an object of Intro Class
	intro.intro();	// invoke function to display intro;
	Branching direction;	// instantiating an object of Branching class
	
	do
	{
		direction.choices();
		// assigning the value of the result of function into a constant int variable
		const int usersChoice = direction.getUserChoice();
		// invoke a branching function using local parameter
		direction.branchChoice(&usersChoice);
		system("CLS");
	} while ((direction.getUserChoice()) != 6);

    return 0;
}

// pseudocode

/*
	- intro
		- about
		- menu of choices
			- list all songs
			- find songs by author
			- find author by song name
			- play a sound
				- if X found
				- if X not found
			- rate the song (1-5 stars)

	
 */

 // WinOS specific command to change CLI to read chinese characters
	 // system("chcp 936");