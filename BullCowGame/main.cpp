/* This is the console executable that makes use of the FBullCowGame class
This acts as a view in a MVC pattern, and is responsible for all 
user interaction. For game logic see the FBullCowGame class
*/

#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
bool PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();
void PrintGameSummary();

FBullCowGame BCGame; // instantiate a new game

// the entry point for our application
int main()
{
	bool bPlayAgain = false;
	bool bStillPlaying = true;
	do
	{
		PrintIntro();
		bStillPlaying = PlayGame();
		if (bStillPlaying)
		{
			bPlayAgain = AskToPlayAgain();
		}
		else
		{
			bPlayAgain = false;
		}
	}
	while (bPlayAgain);

	// std::cin.get();
	return 0;
}

void PrintIntro()
{
	printf("\033c");
	std::cout << "Welcome to Bulls and Cows, a fun word game." << std::endl;;
	std::cout << std::endl;
	std::cout << "          }   {         ___            " << std::endl;
	std::cout << "          (o o)        (o o)           " << std::endl;
	std::cout << "   /-------\\ /          \\ /-------\\ " << std::endl;
	std::cout << "  / | BULL |O            O| COW  | \\  " << std::endl;
	std::cout << " *  |-,--- |              |------|  *  " << std::endl;
	std::cout << "    ^      ^              ^      ^     " << std::endl;
	std::cout << std::endl;
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
	std::cout << " letter isogram I'm thinking of?" << std::endl;
	std::cout << std::endl;
	return;
}

bool PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();
	// std::cout << "MaxTries: " << MaxTries << std::endl;

	// loop for the number of turns asking for guesses
	// TODO change from FOR to WHILE loop once we are validating tries
	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries)
	{
		FText Guess = GetValidGuess();
		if (Guess == "exit") break;

		// submit valid guess to the game and receive counts
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);

		// TODO print number of bulls and cows
		BCGame.PrintBullsAndCows(BullCowCount);

		bool bGuessCorrect = BCGame.IsGuessCorrect(BullCowCount);
		if (bGuessCorrect)
		{
			std::cout << "Your guess is correct! The hidden word is '" << BCGame.GetHiddenWord() << "'." << std::endl;
			std::cout << std::endl;
			break;
		}
	}

	PrintGameSummary();
	return true;
}

// loop continually until the user gives a valid guess
FText GetValidGuess()
{
	EGuessStatus GuessStatus = EGuessStatus::Invalid;
	FText Guess;

	do
	{
		// get a guess from the player
		int32 CurrentTry = BCGame.GetCurrentTry();
		std::cout << "Try " << CurrentTry << " of " << BCGame.GetMaxTries() << ". Enter your guess ('exit' to abort): ";
		Guess = "";
		std::getline(std::cin, Guess);

		if (Guess == "exit")
		{
			BCGame.SetCurrentTry(BCGame.GetMaxTries());
			std::cout << "Game aborted." << std::endl;
			std::cout << std::endl;
			return Guess;
		}

		GuessStatus = BCGame.CheckGuessValidity(Guess);
		switch (GuessStatus)
		{
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word." << std::endl;
			std::cout << std::endl;
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter a word without repeating letters." << std::endl;
			std::cout << std::endl;
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter all lowercase letters." << std::endl;
			std::cout << std::endl;
			break;
		case EGuessStatus::OK:
			break;
		default:
			// assume the guess is valid
			break;
		}
	}
	while (GuessStatus != EGuessStatus::OK); // keep looping until we get no errors
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again with the same hidden word (y/n)? ";
	FText Response = "";
	std::getline(std::cin, Response);
	return Response[0] == 'y' || Response[0] == 'Y';
}

void PrintGameSummary()
{
	if (BCGame.IsGameWon())
	{
		std::cout << "WELL DONE - YOU WIN!" << std::endl;
	}
	else
	{
		std::cout << "Better luck next time!" << std::endl;
	}
}
