#include <iostream>
#include <string>

void PrintIntro();
std::string GetGuess();

// the entry point for our application
int main()
{
	PrintIntro(); // introduce the game

	// loop for the number of turns asking for guesses
	std::string Guess = "";
	constexpr unsigned short NUMBER_OF_TURNS = 5;
	for (unsigned short count = 1; count <= NUMBER_OF_TURNS; count++)
	{
		Guess = GetGuess(); // get a guess from the player

		// repeat the guess back to them
		std::cout << "Your guess was: '" << Guess << "'" << std::endl;
		std::cout << std::endl;
	}

	std::cin.get();

	return 0;
}

void PrintIntro()
{
	constexpr short WORD_LENGTH = 5;
	std::cout << "Welcome to Bulls and Cows, a fun word game!" << std::endl;
	std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?" << std::endl;
	std::cout << std::endl;

	return;
}

std::string GetGuess()
{
	std::string Guess = "";
	std::cout << "Enter your guess: ";
	std::getline(std::cin, Guess);
	return Guess;
}
