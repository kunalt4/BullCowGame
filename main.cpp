/* This is the console executaable, that uses BullCow class. Acts as the view in MVC 
pattern, and is responsible for for User Interaction. Check FBullCowGame for logic
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
void PrintGameSummary();


FBullCowGame BCGame;	//To instantiate a new game


int main() {
	
	do {
		PrintIntro();
		PlayGame();
	} while (AskToPlayAgain()); //While AsktoPlayAgain returns true

	return 0;	//Exit
}


void PrintIntro() {

	//Game description and intro
	std::cout << "Welcome to the Bulls and Cows game!" << std::endl;
	std::cout << "Guess the " << BCGame.GetHiddenWordLength() << " letter isogram, and win.\n\n";
	return;
}

void PlayGame() {

	BCGame.Reset();

	int32 MaxTries =  BCGame.GetMaxTries();

	//Loop asking guesses while game is not won and there are tries remaining
	
	//TODO change to while loop 
	while(!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries) {

		FText Guess = GetValidGuess();		

		//Submit valid guess to game
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);

		//Print number of bulls and cows
		std::cout << "Bulls: " << BullCowCount.Bulls << ", ";
		std::cout << "Cows: " << BullCowCount.Cows << "\n\n";
	}

	//summarise game
	PrintGameSummary();
	return;
}

//loop until user gives valid guess
FText GetValidGuess() {	

	FText Guess = "";
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	
	do {
		int32 CurrentTry = BCGame.GetCurrentTry();

		//Take guess from user
		std::cout << "Try " << CurrentTry << ". Enter your guess: ";
		std::getline(std::cin, Guess);

		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status)
		{
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word." << std::endl;
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter an isogram - a word without repeating letters." << std::endl;
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter the word in lowercase." << std::endl;
			break;
		case EGuessStatus::Not_alphabet:
			std::cout << "Please use alphabets only." << std::endl;
			break;
		default:
			//assuming guess valid
			return Guess;
		}
		std::cout << std::endl;
	} while (Status != EGuessStatus::OK);

	return Guess;
}

bool AskToPlayAgain() {

	std::cout << "Do you want to play again? (Y/N): ";
	FText Response = "";
	
	std::getline(std::cin, Response);
	std::cout << std::endl;


	if (toupper(Response[0]) == 'Y') {
		return true;
	}
	else if (toupper(Response[0]) == 'N') {
		return false;
	}
	else {
		std::cout << "Please input Y or N." << std::endl;
		return AskToPlayAgain();
	}
}

void PrintGameSummary() {
	
	if (BCGame.IsGameWon()) {
		std::cout << "Congratulations, you've guessed the isogram. Good innit? \n\n";
	}
	else {
		std::cout << "Bad luck eh! Better luck next time mate.\n\n";
	}

}


