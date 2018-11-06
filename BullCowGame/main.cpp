#include <iostream>
#include <string>
#include "FBullCowGame.h"

void PrintIntro();
void PlayGame();
std::string GetGuess();
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
	constexpr short WORD_LENGTH = 5;
	std::cout << "Welcome to Bulls and Cows, a fun word game!" << std::endl;
	std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?" << std::endl;
	std::cout << std::endl;
	return;
}

void PlayGame()
{
	BCGame.Reset();
	unsigned short MaxTries = BCGame.GetMaxTries();
	std::cout << "MaxTries: " << MaxTries << std::endl;

	// loop for the number of turns asking for guesses
	// TODO change from FOR to WHILE loop once we are validating tries
	for (unsigned short count = 1; count <= MaxTries; count++)
	{
		std::string Guess = GetGuess(); // TODO make check for valid guesses

		// TODO submit valid guess to the game
		// TODO print number of bulls and cows

		std::cout << "Your guess was: '" << Guess << "'" << std::endl;
		std::cout << std::endl;
	}

	// TODO PlayGame add a game summary
}

std::string GetGuess()
{
	unsigned short CurrentTry = BCGame.GetCurrentTry();
	std::string Guess = "";
	std::cout << "Try " << CurrentTry << ". Enter your guess: ";
	std::getline(std::cin, Guess);
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again (y/n)? ";
	std::string Response = "";
	std::getline(std::cin, Response);
	return Response[0] == 'y' || Response[0] == 'Y';
}
