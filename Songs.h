// preprocessor directives
#pragma once
#include <string>
#include <vector>

using namespace std;

class Songs
{
public:	// public access modifier
	vector<string> artistList;				// public variable
	
	void getPlaylist();					// lists artist.song
	void extractArtists();					// list artists
	void collateArtists();					// list artists
	void removeRedund();					// list artists
	void getArtists();						// list artists
	void extractSongs();					// list songs

	void chooseArtist();					// find songs by artist
	void findArtistSongs(const string*);			// find songs by artist	*** const ptr parameter
	string getChosenArtist();				// find songs by artist
	void setChosenArtist(string);				// find songs by artist

	void chooseSong();					// find artist by song
	void findSongs(const string*);				// find artist by song  *** const ptr parameter
	string getChosenSong();					// find artist by song
	void setChosenSong(string);				// find artist by song


private: // private access modifier
	string m_chosenArtist;
	string m_chosenSong;
	
};
