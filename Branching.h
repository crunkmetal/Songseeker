#pragma once
#include "Songs.h"

class Branching : public Songs
{
public:
	void choices();
	void branchChoice(const int*);

	int getUserChoice();
	void setUserChoice(const int);

private:
	int m_user_choice = 0;
};

/*
	menu of choices
		- list all songs(author.songname)		-> getPlaylist()
		- list all authors(authors)
		- list all songs(songnames)
		- find songs by author(search for song, display author.songname)
		- find author by song name(search for song name, display author.songname)
 */