#include <iostream>
#include <string>

void PrintIntro();
void PlayGame();
std::string GetGuess();
bool AskToPlayAgain();

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
	// loop for the number of turns asking for guesses
	constexpr unsigned short NUMBER_OF_TURNS = 5;
	for (unsigned short count = 1; count <= NUMBER_OF_TURNS; count++)
	{
		std::string Guess = GetGuess(); // get a guess from the player
		// repeat the guess back to them
		std::cout << "Your guess was: '" << Guess << "'" << std::endl;
		std::cout << std::endl;
	}
}

std::string GetGuess()
{
	std::string Guess = "";
	std::cout << "Enter your guess: ";
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
