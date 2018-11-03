#include <iostream>
#include <string>

int main()
{
	// introduce the game
	constexpr short WORD_LENGTH = 5;
	std::cout << "Welcome to Bulls and Cows, a fun word game!" << std::endl;
	std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?" << std::endl;
	std::cout << std::endl;

	// get a guess from the player
	std::cout << "Enter your guess: ";
	std::string Guess = "";
	std::getline(std::cin, Guess);

	// repeat the guess back to them
	std::cout << "Your guess was: '" << Guess << "'" << std::endl;

	std::cin.get();

	std::cout << std::endl;
	return 0;
}
