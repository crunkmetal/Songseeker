// preprocessor directives
#include "Songs.h"
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;					// using standard template library

// function to get a list of Artists.Songs
void Songs::getPlaylist()
{
	string line;					// declare a local string variable
	int songsDisplayed = 0;				// declare/define a counter variable
	ifstream library("library.txt", ios::in);	// Combining object construction and stream opening in a single statement
	if (library.is_open())				// verify stream is actually open
	{
		while (getline(library, line)) 		// while loop to read contents of file, assign value of each line to a variable
		{
			// if loop used to display 25 lines at a time
			if (songsDisplayed % 25 == 0 && songsDisplayed > 0)
			{
				cout << "\n";
				system("pause >nul | echo. Continue...");	// system pause (winOS specific)
				system("CLS");
				cout << "\n\n\tPLAYLIST DIRECTORY\n\n";
			}
			
			cout << setw(3) << " " << line << endl;
			
			songsDisplayed++;		// increment counter
		}
		library.close();			// close the open document
	}
	else						// if file does not open, print info to console
	{
		cout << "Unable to open input file.\n" << endl;
		system("pause");
		system("CLS");
	}
} // end of getPlaylist()

// function to extract the artists name from the Playlist
void Songs::extractArtists()
{
	string line;
	ifstream library("library.txt", ios::in);			// Combining object construction and instream opening in a single statement
	ofstream artists("Artists.txt", ios::trunc);			// combining object construction and outstream opening in a single statement
	if (library.is_open())						// verify input stream file is open
	{
		if (artists.is_open())					// verify output stream file is open
		{
			while (getline(library, line))			// read each line in file and assign value to variable
			{
				size_t pos = line.find(".");		// search for '.' in each line, assign it's position to a size_t var
				string artist = line.substr(0, pos); 	// assign to variable the contents of line var up to the location of 'pos' var

				artists << artist << endl;		// send parsed data to file
			}
			artists.close();				// close the open document
		}							// end of Artists output stream
		library.close();					// close the open document
	}
	else								// if file does not open, print this to console
	{
		cout << "Unable to open input file.\n" << endl;
		system("pause");
		system("CLS");
	}
}
// function to put artists into a vector (for future use)
void Songs::collateArtists()
{
	string line;
	ifstream artists("Artists.txt", ios::in);

	if (artists.is_open())
	{
		while(getline(artists, line))				// read each line in a file and assign value to a var
		{
			if (!line.empty())				// if the read line is not empty...
			{
			artistList.push_back(line);			// assign string value of line to a vector element
			}
		}
		artists.close();					// close open file
		removeRedund();						// invoke function to remove redundancies		
	}
	else  // if file does not open, print to console
	{
		cout << "Unable to open input file.\n" << endl;
		system("pause");
		system("CLS");
	}
}

// function to remove redundancies from vector
void Songs::removeRedund()
{
	// for loop to erase duplicate entries in artistList vector
	for (unsigned int i = 1; i < artistList.size(); i++)
	{
		if (artistList[i].size() == artistList[i - 1].size())	// compare elements by size
		{
			artistList[i - 1].erase();			// if they are the same, erase this element
		}
	}

	ofstream artists("Artists.txt", ios::trunc);			// open file stream 
	if (artists.is_open())						// verify file is open
	{
		for (unsigned int i = 0; i < artistList.size(); i++)	// loop thru vector
		{
			if (!artistList[i].empty())			// if line has content...
			{
				artists << artistList[i] << "\n";	// send content to file
			}
		}
		artists.close();					// close the file stream
	}
	else  // if file does not open, print to console
	{
		cout << "Unable to open input file.\n" << endl;
		system("pause");
		system("CLS");
	}
}

// function to get Artist names
void Songs::getArtists()
{
	string line;
	int artistsDisplayed = 0;
	ifstream artists("artists.txt", ios::in);				// open an input filestream
	
	if(artists.is_open())							// if file is open...
	{	
		while (getline(artists, line))					// read each line, assign value to a var
		{
			// if statement limiting display to 25 lines
			if (artistsDisplayed % 25 == 0 && artistsDisplayed > 0)	
			{
				cout << "\n";
				system("pause >nul | echo. Continue...");
				system("CLS");
				cout << "\n\n\t ARTISTS DIRECTORY\n\n";
			}
			cout << line << "\n";
			artistsDisplayed++;					// increment counter
		}
	}
	else  // if file does not open, display to console
	{
		cout << "Unable to open input file.\n" << endl;
		system("pause");
		system("CLS");
	}
}

// function to parse only songs from playlist
void Songs::extractSongs()
{
	int songsDisplayed = 0;
	string line;
	ifstream library("library.txt", ios::in);					// Combining object construction and in stream opening in a single statement
	ofstream songslist("songs.txt", ios::trunc);					// combining object construction and out stream opening in a single statement
	if (library.is_open())								// verify in file is open
	{
		if (songslist.is_open())						// verify out file is open
		{
			while (getline(library, line))					// read each line in file, assign the value to var
			{
				auto pos = line.find(".");				// search for '.' in each line, assign it's position to an auto var
				string song = line.substr(pos + 1, line.length());	// assign to variable the contents of the substring

				songslist << song << endl;				// send to file
				// if loop to limit display of output to 25 lines
				if (songsDisplayed % 25 == 0 && songsDisplayed > 0)
				{
					cout << "\n";
					system("pause >nul | echo. Continue...");
					system("CLS");
					cout << "\n\n\tSONGS DIRECTORY\n\n";
				}
				cout << "  " << song << "\n";
				songsDisplayed++;					// increment counter
			}
			songslist.close();						// close the open document
		}									// end of Artists output stream
		library.close();							// close the open document
	}
	else
	{
		cout << "Unable to open input file.\n" << endl;
		system("pause");
		system("CLS");
	}
}

// function to get user input (enter Artist, to find songs)
void Songs::chooseArtist()
{
	string chosenArtist;
	cout << "  FIND ALL SONGS BY SEARCHING AN ARTIST\n\n";
	cout << "  Format: uppercase.  Enter Artist:\t";
	
	ws(cin);									// skipping whitespace
	getline (cin, chosenArtist);							// get user input and assign val to var
	setChosenArtist(chosenArtist);							// invoke function to set the value of a private member	
}

// function to output to console, all songs by a given artist
void Songs::findArtistSongs(const string* chosenArtist)					// const ptr parameter
{
	string line;
	cout << "\n\n  Search results for: " << *chosenArtist << "...\n\n";
	
	fstream songSearch("library.txt", ios::in);					// open an input file stream
	
	if (songSearch.is_open())							// verify file is open, if so...
	{
		while (getline(songSearch, line))					// read each line in file, assign value to line var
		{
			if (line.rfind(*chosenArtist, 0) != string::npos)		// rfind seeks a string at 0 location (beginning of string), if content found...
			{
				cout << "  " << line << "\n";				// print to console that value
			}			
		}
		songSearch.close();							// close the open file
	}
	else										// if file not open, print to console...
	{
		cout << "Unable to open input file.\n" << endl;
		system("pause");
		system("CLS");
	}
}

// function to get value of private class variable
string Songs::getChosenArtist()
{
	return m_chosenArtist;
}
// function to set value of private class variable
void Songs::setChosenArtist(string chosenArtist)
{
	m_chosenArtist = chosenArtist;
}

// function to gather user input (a song title)
void Songs::chooseSong()
{
	string chosenSong;
	cout << "\n\n\t  FIND ARTISTS BY SEARCHING A SONG\n\n";
	cout << "  What is the name of the song?\n";
	cout << "  Format: uppercase.  Enter song title:\t";

	ws(cin);								// skipping whitespace
	getline(cin, chosenSong);						// get user input and assign the value to var
	setChosenSong(chosenSong);						// set this value to a private class var
}
// function to print to console, songs relevant to user's choice (based on an Artist name)
void Songs::findSongs(const string* chosenSong)					// const ptr parameter
{
	string line;
	system("CLS");

	fstream songSearch("library.txt", ios::in);				// open an input file stream
	cout << "\n\n\t  Finding artist by song...\n\n";

	if (songSearch.is_open())						// verify file is open, if so...
	{
		while (getline(songSearch, line))				// read each line in file
		{
			auto pos = line.find(".");				// search for '.' in each line, assign it's position to a size_t var
			string song = line.substr(pos + 1, line.length()); 	// assign to variable the contents of the substring
			
			if (song.rfind(*chosenSong, 0) != string::npos) 	// rfind seeks a string at 0 location (beginning of string)
			{
				cout << "  " << *chosenSong << " found.\n\n";	// print the de-referenced value of pointer 
				cout << "  " << line << "\n";			// print song to console (each loop iteration)
			}
		}
		songSearch.close();						// close this file
	}
	else									// if file will not open...
	{
		cout << "Unable to open input file.\n" << endl;
		system("pause");
		system("CLS");
	}
}

// function to get the value of private class variable
string Songs::getChosenSong()
{
	return m_chosenSong;
}
// function to set the value of private class variable
void Songs::setChosenSong(string chosenSong)
{
	m_chosenSong = chosenSong;
}
