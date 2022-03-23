#include "HighscoreEntry.h"

HighscoreEntry::HighscoreEntry(int score, std::string name)
{
	this->score = score;
	this->name = name;
}

bool HighscoreEntry::operator<(const HighscoreEntry& h) const
{
	return this->score > h.score;
}