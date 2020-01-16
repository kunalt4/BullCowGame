#pragma once
#include <string>

using FString = std::string;
using int32 = int;

struct FBullCowCount {

	int32 Bulls = 0;
	int32 Cows = 0;

};

enum class EGuessStatus {
	Invalid_Status,
	OK,
	Not_Isogram,
	Not_alphabet,
	Wrong_Length,
	Not_Lowercase
};



class FBullCowGame {
public:

	FBullCowGame();		//Constructor
	
	void Reset();		//TODO figure out a better return value

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	
	EGuessStatus CheckGuessValidity(FString) const;	
	bool IsGameWon() const;

	//counts bulls and cows and increment tries, assuming valid guess
	FBullCowCount SubmitValidGuess(FString);

private:

	bool IsIsogram(FString) const;

	//Initialisation in constructor
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
	bool bGameIsWon;
};

