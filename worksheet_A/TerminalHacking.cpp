// PartA_TerminalHacking.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "WordList.h"

const int wordLength = 5;
const int numberOfWords = 15;

int getlikeness(std::string playerguess, std::string secret)
{
	int result = 0;
	for (int check = 0; check < wordLength; check++)
	{
		if (playerguess.at(check) == secret.at(check)) {
			result++;
		}
	}

	return result;

}

int main()
{
	// Seed the random number generator with the current time,
	// to ensure different results each time the program is run
	srand(static_cast<unsigned int>(time(nullptr)));

	// Initialise word list
	WordList words(wordLength);

	// Choose secret word
	std::string secret = words.getRandomWord();

	// Create a set to hold the list of options
	std::set<std::string> options;

	// Put the secret word in the set
	options.insert(secret);

	// Fill the set with more words
	// Using a set for options guarantees that the elements are all different
	while (options.size() < numberOfWords)
	{
		std::string word = words.getRandomWord();
		options.insert(word);
	}

	// Display all words
	for each (std::string word in options)
	{
		std::cout << word << std::endl;
	}

	// TODO: implement the rest of the game
	std::string playerguess = "";
	int likescore = 0;
	int numguesses = 0;

	while (numguesses < 4)
	{
		std::cout << "\n Enter Your Guess \n";
		std::cin >> playerguess;
		std::set<std::string>::iterator counter = options.find(playerguess);
		if (counter == options.end())
		{
			std::cout << "Word Not Valid." << std::endl;
			continue;
		}
		else
		{
			likescore = getlikeness(playerguess, secret);
			std::cout << "\nYou Scored: " << likescore << " out of " << wordLength << "\n";
			if (likescore == wordLength)
			{
				std::cout << "\nCorrect! \n";
				exit(0);
			}
			else
			{
				numguesses++;
				std::cout << "\nYou Have " << 4 - numguesses << " Number Of Guesses Left. \n";
				likescore = 0;
			}
		}
	}

	std::cout << "\nYou Lose.\n";

    return 0;
}
