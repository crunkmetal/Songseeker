#include "Songs.h"
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <string>

using namespace std;

void Songs::getPlaylist()
{
	string line;
	int songsDisplayed = 0;
	ifstream library("library.txt", ios::in);	// Combining object construction and stream opening in a single statement
	if (library.is_open())
	{
		// cout << "\n\n\t  PLAYLIST\n";
		// cout << "\n  ALL records in the file, 25 at a time...\n\n";
		while (getline(library, line)) 
		{
			if (songsDisplayed % 25 == 0 && songsDisplayed > 0)
			{
				cout << "\n";
				system("pause >nul | echo. Continue...");
				system("CLS");
				cout << "\n\n\tPLAYLIST DIRECTORY\n\n";
			}
			
			// transform and toupper method used to change file content to uppercase
			// transform(line.begin(), line.end(), line.begin(), ::toupper);
			// setw() Sets the field width to be used on output operations.
			cout << setw(3) << " " << line << endl;
			// cout << line << endl;
			
			songsDisplayed++;
		}
		library.close();	// close the open document
	}
	else
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
	ifstream library("library.txt", ios::in);	// Combining object construction and instream opening in a single statement
	ofstream artists("Artists.txt", ios::trunc);// combining object construction and outstream opening in a single statement
	if (library.is_open())
	{
		if (artists.is_open())
		{
			while (getline(library, line))		// read each line in file
			{
				size_t pos = line.find(".");	// search for '.' in each line, assign it's position to a size_t var
				string artist = line.substr(0, pos); // assign to variable the contents of the substring

				// string str = artist;
				// transform(artist.begin(), artist.end(), artist.begin(), ::toupper);  // change values to uppercase

				artists << artist << endl;	// send to file
			}
			artists.close();	// close the open document
		}// end of Artists output stream
		library.close();	// close the open document
	}
	else
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
		while(getline(artists, line))	// read each line in a file
		{
			if (!line.empty())
			{
			artistList.push_back(line);	// assign string value of each line to a vector element
			}
		}
		artists.close();	// close open file
		removeRedund();	// invoke function to remove redundancies		
	}
	else  // if file does not open...
	{
		cout << "Unable to open input file.\n" << endl;
		system("pause");
		system("CLS");
	}
}

void Songs::removeRedund()
{
	// for loop to erase duplicate entries
	for (unsigned int i = 1; i < artistList.size(); i++)
	{
		if (artistList[i].size() == artistList[i - 1].size()) // .size() should be used
		{
			artistList[i - 1].erase();
		}
	}

	ofstream artists("Artists.txt", ios::trunc);
	if (artists.is_open())
	{
		for (unsigned int i = 0; i < artistList.size(); i++)
		{
			if (!artistList[i].empty())
			{
				artists << artistList[i] << "\n";
			}
		}
		artists.close();
	}
	else  // if file does not open...
	{
		cout << "Unable to open input file.\n" << endl;
		system("pause");
		system("CLS");
	}
}

void Songs::getArtists()
{
	string line;
	int artistsDisplayed = 0;
	ifstream artists("artists.txt", ios::in);
	
	if(artists.is_open())
	{
		while (getline(artists, line))
		{
			if (artistsDisplayed % 25 == 0 && artistsDisplayed > 0)
			{
				cout << "\n";
				system("pause >nul | echo. Continue...");
				system("CLS");
				cout << "\n\n\t ARTISTS DIRECTORY\n\n";
			}
			cout << line << "\n";
			artistsDisplayed++;
		}
	}
	else  // if file does not open...
	{
		cout << "Unable to open input file.\n" << endl;
		system("pause");
		system("CLS");
	}
}

// SHOW ALL SONGS...

void Songs::extractSongs()
{
	int songsDisplayed = 0;
	string line;
	ifstream library("library.txt", ios::in);	// Combining object construction and instream opening in a single statement
	ofstream songslist("songs.txt", ios::trunc);// combining object construction and outstream opening in a single statement
	if (library.is_open())
	{
		if (songslist.is_open())
		{
			while (getline(library, line))		// read each line in file
			{
				auto pos = line.find(".");	// search for '.' in each line, assign it's position to a size_t var
				string song = line.substr(pos + 1, line.length()); // assign to variable the contents of the substring

				// transform(song.begin(), song.end(), song.begin(), ::toupper);  // change values to uppercase

				songslist << song << endl;	// send to file

				if (songsDisplayed % 25 == 0 && songsDisplayed > 0)
				{
					cout << "\n";
					system("pause >nul | echo. Continue...");
					system("CLS");
					cout << "\n\n\tSONGS DIRECTORY\n\n";
				}
				
				cout << "  " << song << "\n";
				songsDisplayed++;
			}
			songslist.close();	// close the open document
		}// end of Artists output stream
		library.close();	// close the open document
	}
	else
	{
		cout << "Unable to open input file.\n" << endl;
		system("pause");
		system("CLS");
	}
}

void Songs::chooseArtist()
{
	string chosenArtist;

	cout << "\n\n\t  FIND SONGS BY SEARCHING AN ARTIST\n\n";
	cout << "  Format: uppercase for search functionality\n";
	
	ws(cin);	// skipping whitespace
	getline (cin, chosenArtist);
	setChosenArtist(chosenArtist);
}

void Songs::findArtistSongs(string chosenArtist)
{
	string line;
	cout << "\n\nSearch results for: " << chosenArtist << "...\n\n";
	
	fstream songSearch("library.txt", ios::in);
	
	if (songSearch.is_open())
	{
		while (getline(songSearch, line))		// read each line in file
		{
			if (line.rfind(chosenArtist, 0) != string::npos) // rfind seeks a string at 0 location (beginning of string)
			{
				cout << line << "\n";
			}			
		}
		songSearch.close();
	}
	else
	{
		cout << "Unable to open input file.\n" << endl;
		system("pause");
		system("CLS");
	}
}


string Songs::getChosenArtist()
{
	return m_chosenArtist;
}

void Songs::setChosenArtist(string chosenArtist)
{
	m_chosenArtist = chosenArtist;
}



void Songs::chooseSong()
{
	string chosenSong;

	cout << "\n\n\t  FIND ARTISTS BY SEARCHING A SONG\n\n";
	cout << "  What is the name of the song to search an Artist by?\n";
	cout << "  (Format: uppercase for search functionality)\t";

	ws(cin);	// skipping whitespace
	getline(cin, chosenSong);
	setChosenSong(chosenSong);
}

void Songs::findSongs(string chosenSong)
{
	string line;
	system("CLS");

	fstream songSearch("library.txt", ios::in);
	cout << "\n\n\t  Finding artist by song...\n\n";

	if (songSearch.is_open())
	{
		while (getline(songSearch, line))		// read each line in file
		{
			auto pos = line.find(".");	// search for '.' in each line, assign it's position to a size_t var
			string song = line.substr(pos + 1, line.length()); // assign to variable the contents of the substring
			
			if (song.rfind(chosenSong, 0) != string::npos) // rfind seeks a string at 0 location (beginning of string)
			{
				cout << "  " << chosenSong << " found.\n\n";
				cout << "  " << line << "\n";
			}
		}
		songSearch.close();
	}
	else
	{
		cout << "Unable to open input file.\n" << endl;
		system("pause");
		system("CLS");
	}
}


string Songs::getChosenSong()
{
	return m_chosenSong;
}

void Songs::setChosenSong(string chosenSong)
{
	m_chosenSong = chosenSong;
}