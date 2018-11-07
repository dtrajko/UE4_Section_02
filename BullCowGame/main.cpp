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
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();

FBullCowGame BCGame; // instantiate a new game

// the entry point for our application
int main()
{
	bool bPlayAgain = false;
	do
	{
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	}
	while (bPlayAgain);

	// std::cin.get();
	return 0;
}

void PrintIntro()
{
	// introduce the game
	std::cout << "Welcome to Bulls and Cows, a fun word game!" << std::endl;
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength() << " letter isogram I'm thinking of?" << std::endl;
	std::cout << std::endl;
	return;
}

void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();
	std::cout << "MaxTries: " << MaxTries << std::endl;

	// loop for the number of turns asking for guesses
	// TODO change from FOR to WHILE loop once we are validating tries
	for (int32 count = 1; count <= MaxTries; count++)
	{
		FText Guess = GetValidGuess();

		// submit valid guess to the game and receive counts
		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);

		// TODO print number of bulls and cows
		BCGame.PrintBullsAndCows(BullCowCount);

		std::cout << "Your guess was: '" << Guess << "'" << std::endl;
		std::cout << std::endl;

		bool bGuessCorrect = BCGame.IsGuessCorrect(BullCowCount);
		if (bGuessCorrect)
		{
			std::cout << "Your guess is correct! The hidden word is '" << BCGame.GetHiddenWord() << "'." << std::endl;
			std::cout << std::endl;
			break;
		}
	}

	// TODO PlayGame add a game summary
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
		std::cout << "Try " << CurrentTry << ". Enter your guess: ";
		Guess = "";
		std::getline(std::cin, Guess);

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
			break;
		}
	}
	while (GuessStatus != EGuessStatus::OK); // keep looping until we get no errors
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again (y/n)? ";
	FText Response = "";
	std::getline(std::cin, Response);
	return Response[0] == 'y' || Response[0] == 'Y';
}
