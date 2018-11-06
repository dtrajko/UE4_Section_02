#pragma once

#include <string>

class FBullCowGame
{
public:
	FBullCowGame(); // constructor
	unsigned short GetMaxTries() const;
	unsigned short GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset(); // TODO Reset make a more rich return value
	bool CheckGuessValidity(std::string); // TODO CheckGuessValidity make a more rich return value
	// TODO provide a method for counting bulls and cows, and increasing turn #

// ^^ Please try and ignore this and focus on the interface above ^^
private:
	// see constructor for initialization
	unsigned short MyCurrentTry;
	unsigned short MyMaxTries;
	bool IsIsogram(std::string);
	// TODO SomeNewType SubmitValidGuess(std::string);
};
