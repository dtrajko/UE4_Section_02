#pragma once

#include <string>
#include <iostream>

using FString = std::string;
using int32 = int;

// all values initialized to zero
struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows  = 0;
};

class FBullCowGame
{
public:
	FBullCowGame(); // constructor
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	FString GetMyHiddenWord() const;
	bool IsGameWon() const;

	void Reset(); // TODO Reset make a more rich return value
	bool CheckGuessValidity(FString); // TODO CheckGuessValidity make a more rich return value
	FBullCowCount SubmitGuess(FString);
	void PrintBullsAndCows(FBullCowCount);
	bool IsGuessCorrect(FBullCowCount);

// ^^ Please try and ignore this and focus on the interface above ^^
private:
	// see constructor for initialization
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;

	bool IsIsogram(FString);
};
