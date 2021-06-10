#pragma once
#include <string>
#include <vector>

using namespace std;

class Songs
{
public:
	vector<string> artistList;
	
	void getPlaylist();		
	void extractArtists();	// list artists
	void collateArtists();	// list artists
	void removeRedund();	// list artists
	void getArtists();		// list artists
	void extractSongs();	// list songs

	void chooseArtist();	// find songs by artist
	void findArtistSongs(string);	// find songs by artist
	string getChosenArtist();
	void setChosenArtist(string);

	void chooseSong();
	void findSongs(string);
	string getChosenSong();
	void setChosenSong(string);


private:
	string m_chosenArtist;
	string m_chosenSong;
	
};

/*
	menu of choices
				- list all songs(author.songname)		-> getPlaylist()
				- list all authors(authors)
				- list all songs(songnames)
		- find songs by author(search for song, display author.songname)
		- find author by song name(search for song name, display author.songname)
 */

