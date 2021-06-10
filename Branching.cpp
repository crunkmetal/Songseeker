// preprocessor directives
#include "Branching.h"
#include <iostream>
// using standard template library
using namespace std;
// function to display/parse user input
void Branching::choices()
{
	int tentativeChoice = 0;							// declare/define local variable
	
	cout << "\n\t\t  [][][] Song Seeker [][][]\n\n";
	cout << "  Please make a choice:\n";
	cout << "\t1) List Directory Contents.\n";
	cout << "\t2) List all Artists.\n";
	cout << "\t3) List all Songs.\n";
	cout << "\t4) Find Songs by Artist.\n";
	cout << "\t5) Find Artist by Song.\n";
	cout << "\t6) Exit Song Seeker.\n\n";
	
	cin >> tentativeChoice;								// get user input and assign value to var
	// if user's choice is 1 - 5, do this...
	if (tentativeChoice == 1 || tentativeChoice == 2 || tentativeChoice == 3 || tentativeChoice == 4 || tentativeChoice == 5)
	{
		setUserChoice(&tentativeChoice);					// set value of var to private class var/pass by reference
		system("CLS");								// WinOS specific, clear console
	}
	// if user choice is '6', do this...
	else if (tentativeChoice == 6)
	{
		system("CLS");
		cout << "\n\n\tExiting Song Seeker...\n\n";
		exit(0);								// exit program
	}
	// if user input is any char other than '1 - 6', do this...
	else
	{
		system("CLS");
		cout << "\n\n";
		cout << "  [][][][][][][][][][][][][][][][][][][][][][][][][]\n";
		cout << "  You have entered invalid output, please try again...\n";
		cout << "  [][][][][][][][][][][][][][][][][][][][][][][][][]\n\n";
		cin.clear();								// clear buffer of any content
		cin.ignore(numeric_limits<streamsize>::max(), '\n');			// clear buffer of any content
		tentativeChoice = 0;							// reset value of var
		system("pause");
	}
}
// function to process user's choice from previous function
void Branching::branchChoice(const int* user_choice)				// const ptr parameter
{
	// switch case to control program flow
	switch(*user_choice)							// pass by reference
	{
		case 1:	// display artist.song
		{
			system("CLS");
			cout << "\n\n\tPLAYLIST DIRECTORY\n\n";
			getPlaylist();						// invoke function to display contents
			cout << "\n\n";
			cout << "  [][][][][][][][][][][][][][][][][][][][][][][][][]\n";
			cout << "  END OF DIRECTORY CONTENTS...\n";
			cout << "  [][][][][][][][][][][][][][][][][][][][][][][][][]\n\n";

			system("pause");
			system("CLS");
			break;
		}
		case 2:	// display artists
		{
			system("CLS");
			cout << "\n\n\t ARTISTS DIRECTORY\n\n";
			extractArtists();					// invoke function to extract artists from playlist data
			collateArtists();					// invoke function to push data to a vector
			removeRedund();						// invoke function to remove duplicates from vector
			getArtists();						// invoke function to display to console, artists
			cout << "\n\n";
			cout << "  [][][][][][][][][][][][][][][][][][][][][][][][][]\n";
			cout << "  END OF DIRECTORY CONTENTS...\n";
			cout << "  [][][][][][][][][][][][][][][][][][][][][][][][][]\n\n";
			system("pause");
			system("CLS");
			break;
		}
		case 3:	// display all songs
		{
			system("CLS");
			cout << "\n\n\tSONGS DIRECTORY\n\n";
			extractSongs();						// invoke function to display songs to console
			cout << "\n\n";
			cout << "  [][][][][][][][][][][][][][][][][][][][][][][][][]\n";
			cout << "  END OF DIRECTORY CONTENTS...\n";
			cout << "  [][][][][][][][][][][][][][][][][][][][][][][][][]\n\n";
			system("pause");
			system("CLS");
			break;
		}
		case 4:	// Find songs by artist
		{
			system("CLS");
			cout << "\n\n\tSONG SEARCH DIRECTORY\n\n";
			chooseArtist();	// invoke function to get user input (Artist: to find songs by)

			string tempArtist = getChosenArtist();			// assign value of private class member to local var				
			const string* chosenArtist = &tempArtist;		// assign address of local var to ptr
			findArtistSongs(chosenArtist);				// invoke function to search for songs(based on an Artist) const ptr parameter
			cout << "\n\n";
			cout << "  [][][][][][][][][][][][][][][][][][][][][][][][][]\n";
			cout << "  END OF DIRECTORY CONTENTS...\n";
			cout << "  [][][][][][][][][][][][][][][][][][][][][][][][][]\n\n";
			system("pause");
			system("CLS");
			break;
		}
		case 5:	// search for artists, based on a song query
		{
			system("CLS");
			cout << "\n\n\tARTIST SEARCH DIRECTORY\n\n";
			chooseSong();						// invoke function to gather user input

			const string bob = getChosenSong();			// assign value of private class var to local variable
			const string* p_bob = &bob;				// assign address of local var to pointer
			findSongs(p_bob);					// invoke function to search for artists (by song query)  const ptr parameter
			
			cout << "\n\n";
			cout << "  [][][][][][][][][][][][][][][][][][][][][][][][][]\n";
			cout << "  END OF SEARCH...\n";
			cout << "  [][][][][][][][][][][][][][][][][][][][][][][][][]\n\n";
			system("pause");
			system("CLS");
			break;
		}

		default:	// if user inputs inappropriate content, do this...
		{
			system("CLS");
			cout << "\n\n";
			cout << "  [][][][][][][][][][][][][][][][][][][][][][][][][]\n\n";
			cout << "\n\tYou have entered invalid output, please try again...\n\n";
			cout << "  [][][][][][][][][][][][][][][][][][][][][][][][][]\n\n";
			setUserChoice(0);							// reset value of private class var
			break;
		}
	}
}

// public member function to retrieve the value of a private property
int Branching::getUserChoice()
{
	return m_user_choice; 									// returns the value of the private property
}
// public member function to assign the value of an input parameter to a private property
void Branching::setUserChoice(const int* tentativeChoice)					// const pointer parameter
{
	m_user_choice = *tentativeChoice;							// assign dereferenced value of argument to private class var
}
