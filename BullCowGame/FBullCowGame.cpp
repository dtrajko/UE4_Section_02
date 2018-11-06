#include "FBullCowGame.h"

FBullCowGame::FBullCowGame() { Reset(); }
int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

FString FBullCowGame::GetMyHiddenWord() const
{
	return MyHiddenWord;
}

void FBullCowGame::Reset()
{
	constexpr unsigned short MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;
	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	return;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

bool FBullCowGame::CheckGuessValidity(FString)
{
	return false;
}

// v1 counts bulls and cows, and increases try number, assuming valid guess
// v2 receives a VALID guess, increments turns, and returns count
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	// increment the turn number
	MyCurrentTry++;

	// setup a return value
	FBullCowCount BullCowCount;

	int32 HiddenWordLength = MyHiddenWord.length();
	for (int32 i = 0; i < HiddenWordLength; i++)
	{
		for (int32 j = 0; j < HiddenWordLength; j++)
		{
			if (Guess[i] == MyHiddenWord[j])
			{
				if (i == j)
				{
					BullCowCount.Bulls++;
				}
				else
				{
					BullCowCount.Cows++;
				}
			}
		}
	}

	return BullCowCount;
}

void FBullCowGame::PrintBullsAndCows(FBullCowCount BullCowCount)
{
	std::cout << "Bulls: " << BullCowCount.Bulls << std::endl;
	std::cout << "Cows: " << BullCowCount.Cows << std::endl;
}

bool FBullCowGame::IsIsogram(FString)
{
	return false;
}

bool FBullCowGame::IsGuessCorrect(FBullCowCount BullCowCount)
{
	return BullCowCount.Bulls == MyHiddenWord.length();
}
