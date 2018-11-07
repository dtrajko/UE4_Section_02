/* The game logic (no view code or direct user interaction)
The game is a simple guess the word game based on Mastermind
*/

#pragma once

#include <string>
#include <iostream>
#include <map>
#include <cctype>
#include <algorithm>

// to make syntax Unreal friendly
#define TMap std::map
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
	void SetCurrentTry(int32);
	FString GetHiddenWord() const;
	int32 GetHiddenWordLength() const;
	bool IsGameWon() const;
	EGuessStatus CheckGuessValidity(FString) const;

	void Reset();
	FBullCowCount SubmitValidGuess(FString);
	void PrintBullsAndCows(FBullCowCount);
	bool IsGuessCorrect(FBullCowCount);

// ^^ Please try and ignore this and focus on the interface above ^^
private:
	// see constructor for initialization
	int32 MyCurrentTry;
	FString MyHiddenWord;
	bool bGameIsWon;

	bool IsIsogram(FString) const;
	bool IsLowercase(FString) const;
};
