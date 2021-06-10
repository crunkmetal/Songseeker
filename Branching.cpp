#include "Branching.h"
#include <iostream>

using namespace std;

void Branching::choices()
{
	int tentativeChoice = 0;
	
	cout << "\n\t\t  [][][] Song Seeker [][][]\n\n";
	cout << "  Please make a choice:\n";
	cout << "\t1) List Directory Contents.\n";
	cout << "\t2) List all Artists.\n";
	cout << "\t3) List all Songs.\n";
	cout << "\t4) Find Songs by Artist.\n";
	cout << "\t5) Find Artist by Song.\n";
	cout << "\t6) Exit Song Seeker.\n\n";
	
	cin >> tentativeChoice;

	// TODO: fix issue -> user enters char other than int 
	// verify user input is an integer

	if (tentativeChoice == 1 || tentativeChoice == 2 || tentativeChoice == 3 || tentativeChoice == 4 || tentativeChoice == 5)
	{
		setUserChoice(tentativeChoice);
		system("CLS");
	}
	else if (tentativeChoice == 6)
	{
		system("CLS");
		cout << "\n\n\tExiting Song Seeker...\n\n";
		exit(0);
	}
	else
	{
		system("CLS");
		cout << "\n\n";
		cout << "  [][][][][][][][][][][][][][][][][][][][][][][][][]\n";
		cout << "  You have entered invalid output, please try again...\n";
		cout << "  [][][][][][][][][][][][][][][][][][][][][][][][][]\n\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		tentativeChoice = 0;
		system("pause");
	}
}

void Branching::branchChoice(const int* user_choice)	// switch case here
{
	switch(*user_choice)
	{
		case 1:
		{
			system("CLS");
			cout << "\n\n\tPLAYLIST DIRECTORY\n\n";
			getPlaylist();
			cout << "\n\n";
			cout << "  [][][][][][][][][][][][][][][][][][][][][][][][][]\n";
			cout << "  END OF DIRECTORY CONTENTS...\n";
			cout << "  [][][][][][][][][][][][][][][][][][][][][][][][][]\n\n";

			system("pause");
			system("CLS");
			break;
		}
		case 2:
		{
			system("CLS");
			cout << "\n\n\t ARTISTS DIRECTORY\n\n";
			extractArtists();
			collateArtists();
			removeRedund();
			getArtists();
			cout << "\n\n";
			cout << "  [][][][][][][][][][][][][][][][][][][][][][][][][]\n";
			cout << "  END OF DIRECTORY CONTENTS...\n";
			cout << "  [][][][][][][][][][][][][][][][][][][][][][][][][]\n\n";
			system("pause");
			system("CLS");
			break;
		}
		case 3:
		{
			system("CLS");
			cout << "\n\n\tSONGS DIRECTORY\n\n";
			extractSongs();
			cout << "\n\n";
			cout << "  [][][][][][][][][][][][][][][][][][][][][][][][][]\n";
			cout << "  END OF DIRECTORY CONTENTS...\n";
			cout << "  [][][][][][][][][][][][][][][][][][][][][][][][][]\n\n";
			system("pause");
			system("CLS");
			break;
		}
		case 4:
		{
			system("CLS");
			cout << "\n\n\tSONG SEARCH DIRECTORY\n\n";
			chooseArtist();
			findArtistSongs(getChosenArtist());
			cout << "\n\n";
			cout << "  [][][][][][][][][][][][][][][][][][][][][][][][][]\n";
			cout << "  END OF DIRECTORY CONTENTS...\n";
			cout << "  [][][][][][][][][][][][][][][][][][][][][][][][][]\n\n";
			system("pause");
			system("CLS");
			break;
		}
		case 5:
		{
			system("CLS");
			cout << "\n\n\tARTIST SEARCH DIRECTORY\n\n";
			chooseSong();
			findSongs(getChosenSong());
			cout << "\n\n";
			cout << "  [][][][][][][][][][][][][][][][][][][][][][][][][]\n";
			cout << "  END OF SEARCH...\n";
			cout << "  [][][][][][][][][][][][][][][][][][][][][][][][][]\n\n";
			system("pause");
			system("CLS");
			break;
		}

		default:
		{
			system("CLS");
			cout << "\n\n";
			cout << "  [][][][][][][][][][][][][][][][][][][][][][][][][]\n\n";
			cout << "\n\tYou have entered invalid output, please try again...\n\n";
			cout << "  [][][][][][][][][][][][][][][][][][][][][][][][][]\n\n";
			setUserChoice(0);
			cout << "The value of user Choice now: " << getUserChoice();
			//choices();
			break;
		}
	}
}

// public member function to retrieve the value of a private property
int Branching::getUserChoice()
{
	return m_user_choice;  // returns the value of the private property
}
// public member function to assign the value of an input parameter to a private property
void Branching::setUserChoice(int tentativeChoice)
{
	m_user_choice = tentativeChoice;
}
