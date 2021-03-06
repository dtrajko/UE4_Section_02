#include "FBullCowGame.h"

FBullCowGame::FBullCowGame() { Reset(); }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
FString FBullCowGame::GetHiddenWord() const { return MyHiddenWord; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const { return bGameIsWon; }
bool FBullCowGame::IsGuessCorrect(FBullCowCount BullCowCount) { return BullCowCount.Bulls == GetHiddenWordLength(); }
void FBullCowGame::SetCurrentTry(int32 NewTryValue) { MyCurrentTry = NewTryValue; }

void FBullCowGame::Reset()
{
	const FString HIDDEN_WORD = "sky"; // this must be an isogram (no duplicate letters)
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	bGameIsWon = false;
	return;
}

int32 FBullCowGame::GetMaxTries() const
{
	TMap<int32, int32> WordLengthToMaxTries =
	{
		{3, 4},
		{4, 8},
		{5, 10},
		{6, 18},
		{7, 28},
		{8, 32},
	};
	return WordLengthToMaxTries[GetHiddenWordLength()];
}

bool FBullCowGame::IsIsogram(FString Word) const
{
	// consider 0 and 1 letter words as isograms
	if (Word.length() <= 1) return true;
	TMap<char, bool> LetterSeen;
	for (auto Letter : Word)
	{
		Letter = tolower(Letter);
		if (LetterSeen[Letter])
		{
			return false;
		}
		else
		{
			LetterSeen[Letter] = true;
		}
	}
	return true;
}

bool FBullCowGame::IsLowercase(FString Word) const
{
	for (auto Letter : Word)
	{
		if (!islower(Letter)) return false;
	}
	return true;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (Guess.length() != GetHiddenWordLength())
	{
		return EGuessStatus::Wrong_Length;
	}
	else if (!IsLowercase(Guess))
	{
		return EGuessStatus::Not_Lowercase;
	}
	else if (!IsIsogram(Guess))
	{
		return EGuessStatus::Not_Isogram;
	}
	else
	{
		return EGuessStatus::OK;
	}
}

// v1 counts bulls and cows, and increases try number, assuming valid guess
// v2 receives a VALID guess, increments turns, and returns count
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++;
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

	bGameIsWon = IsGuessCorrect(BullCowCount);

	return BullCowCount;
}

void FBullCowGame::PrintBullsAndCows(FBullCowCount BullCowCount)
{
	std::cout << "Bulls: " << BullCowCount.Bulls << ". Cows: " << BullCowCount.Cows << "." << std::endl;
	std::cout << std::endl;
}
