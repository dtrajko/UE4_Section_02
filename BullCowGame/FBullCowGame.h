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

enum class EGuessStatus
{
	Invalid,
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase,
};

enum class EResetStatus
{
	OK,
	No_Hidden_Word,
};

class FBullCowGame
{
public:
	FBullCowGame(); // constructor
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	FString GetHiddenWord() const;
	int32 GetHiddenWordLength() const;
	bool IsGameWon() const;
	EGuessStatus CheckGuessValidity(FString) const; // TODO CheckGuessValidity make a more rich return value

	void Reset(); // TODO Reset make a more rich return value
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
