// TODO: When finished, write a file comment that describes the program.
// Write your name and date, and cite anyone who helped you.
/*
Sami Shibli January 15 2023
This program stimulates a simple version
of the webgame wordle
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <cstring>

using namespace std;

// program constants
const string FILENAME = "wordbank.txt";
const int NUM_LETTERS = 5;
const int NUM_GUESSES = 6;

// helper function declarations
string getWord();
string getGuess();
void processGuess(string guess, string secret);

// Main plays the game and report the outcome
int main()
{

	string secret = getWord();
	cout << "The secret word has been selected. Start guessing!" << endl;
	string guess;

	for (int i = 0; i < NUM_GUESSES; i++)
	{
		cout << "Guess # " << (i + 1) << ": " << endl;
		guess = getGuess();

		for (int j = 0; j < guess.length(); j++)
		{
			guess[j] = toupper(guess[j]);
		}

		if (guess == secret)
		{
			break;
		}
		processGuess(guess, secret);
	}

	if (guess == secret)
	{
		cout << "You guessed the word!" << endl;
	}
	else
	{
		cout << "You ran out of guesses before guessing the word: " << secret << endl; // for testing; remove before submitting

		/* TODO: write code to play the game and report the outcome here */

		return 0;
	}
}

// picks a random word from the specified file
string getWord()
{
	// open the file
	ifstream f(FILENAME);
	// read words line-by-line into a vector (array-like data structure)
	vector<string> allWords;
	string word;
	while (getline(f, word))
	{
		allWords.push_back(word);
	}
	// close the file
	f.close();
	// pick a random word from the vector and capitalize its letters
	srand(time(nullptr));
	word = allWords[rand() % allWords.size()];
	for (int i = 0; i < word.length(); i++)
	{
		word[i] = toupper(word[i]);
	}
	return word;
}

// solicit a guess from the user. Requires
string getGuess()
{
	string guess;
	cout << "Enter in a guess!" << endl;
	cin >> guess;
	while (guess.size() != NUM_LETTERS)
	{
		cout << "your guess must be 5 letters" << endl;
		cout << "Enter in another guess!";
		cin >> guess;
	}
	return guess;
}
// check to see letter by letter if its in the correct spot.
void processGuess(string guess, string secret)
{
	for (int i = 0; i < NUM_LETTERS; i++)
	{
		if (secret[i] == guess[i])
		{
			cout << guess[i] << " is in position " << i + 1 << endl;
		}
		else
		{
			bool in_word = false;
			for (int j = 0; j < NUM_LETTERS; j++)
			{
				if (secret[j] == guess[i])
				{
					in_word = true;
					break;
				}
			}
			if (in_word)
			{
				cout << guess[i] << " is in the word but not in position " << i + 1 << endl;
			}
			else
			{
				cout << guess[i] << " is not in the word" << endl;
			}
		}
	}
}
