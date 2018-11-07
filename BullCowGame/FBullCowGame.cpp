#include "FBullCowGame.h"

FBullCowGame::FBullCowGame() { Reset(); }
int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
FString FBullCowGame::GetHiddenWord() const { return MyHiddenWord; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }

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

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	// if the guess isn't an isogram
	if (false)
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (false)
	{
		return EGuessStatus::Not_Lowercase;
	}
	else if (Guess.length() != GetHiddenWordLength())
	{
		return EGuessStatus::Wrong_Length;
	}
	else
	{
		return EGuessStatus::OK;
	}
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
	int32 GuessLength = Guess.length();
	for (int32 indHW = 0; indHW < HiddenWordLength; indHW++)
	{
		for (int32 indG = 0; indG < GuessLength; indG++)
		{
			if (Guess[indG] == MyHiddenWord[indHW])
			{
				if (indG == indHW)
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
