// Highscore Entry

#ifndef _HighscoreEntry
#define _HighscoreEntry

struct HighscoreEntry
{
	HighscoreEntry(int score, std::string name);
	bool operator <(const HighscoreEntry& h) const;

	int score;
	std::string name;
};

#endif _HighscoreEntry