// preprocessor directives
#include "Intro.h"
// function to display contents to console
void Intro::intro()
{
	cout << "\n\t\t  [][][] Song Seeker [][][]\n\n";
	cout << "  This application lists files available in a music directory.\n";
	cout << "  Song Seeker prints to display a list of all songs in the dir-\n";
	cout << "  ectory, displays songs by a particular artist, displays an\n";
	cout << "  author based on a song name and allows the user to rate songs.\n";
	cout << "  Music play is represented by a proxy audio file.\n\n";

	system("pause >nul | echo. Continue...");				// WinOS specific pause 
	system("CLS");								// WinOS specific clear console
}
