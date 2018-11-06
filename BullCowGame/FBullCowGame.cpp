#include "FBullCowGame.h"

FBullCowGame::FBullCowGame() { Reset(); }
unsigned short FBullCowGame::GetMaxTries() const { return MyMaxTries; }
unsigned short FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

void FBullCowGame::Reset()
{
	constexpr unsigned short MAX_TRIES = 6;
	MyMaxTries = MAX_TRIES;
	MyCurrentTry = 1;
	return;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

bool FBullCowGame::CheckGuessValidity(std::string)
{
	return false;
}

bool FBullCowGame::IsIsogram(std::string)
{
	return false;
}
