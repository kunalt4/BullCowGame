#include "FBullCowGame.h"
#include <map>
#define TMap std::map
using int32 = int;

int32 FBullCowGame::GetMaxTries() const {
	return MyMaxTries;
}

int32 FBullCowGame::GetCurrentTry() const {
	return MyCurrentTry;
}

int32 FBullCowGame::GetHiddenWordLength() const {
	return MyHiddenWord.length();
}

bool FBullCowGame::IsGameWon() const {
	return bGameIsWon;
}

FBullCowGame::FBullCowGame() {
	Reset();
}

void FBullCowGame::Reset() {

	constexpr int32 MAX_TRIES = 5;
	MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "kunal";

	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	bGameIsWon = false;
	return;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const{

	if (!IsIsogram(Guess)) {					//TODO If not isogram 
		return EGuessStatus::Not_Isogram;		//return error
	}

	else if (false) {							//TODO write func If not lowercase 
		return EGuessStatus::Not_Lowercase;		//return error
	}

	else if (Guess.length() != GetHiddenWordLength()) {	//If guess length wrong
		return EGuessStatus::Wrong_Length;		//return error
	}

	else if (false) {							//TODO If not alphabet
		return EGuessStatus::Not_alphabet;		//return error
	}
	
	else {
		return EGuessStatus::OK;				//Ok //TODO Make actual error
	}




	
}

//receives a valid guess, increments turn and returns count
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess) {

	MyCurrentTry++;
	FBullCowCount BullCowCount;
	int32 WordLength = MyHiddenWord.length(); //assume same length as guess
	
	//loop through hidden word
	for (int32 MHWChar = 0; MHWChar < WordLength; MHWChar++) {
		//compare letters with words
		for (int32 GChar = 0; GChar < WordLength; GChar++) {

			if (Guess[MHWChar] == MyHiddenWord[GChar]) {
				if (MHWChar == GChar) {				//if match
					BullCowCount.Bulls++;	//increment bulls if in same place
				}
				else
					BullCowCount.Cows++;	//increment cows if not
			}
		
		}
			
	}

	if (BullCowCount.Bulls == WordLength) {
		bGameIsWon = true;
	}

	return BullCowCount;
}

bool FBullCowGame::IsIsogram(FString Guess) const {

	//consider blank string as isogram
	if (Guess.length < 1) {
		return true;
	}

	//TMap
	//setup map
	//Go through the word and increment hash value for each letter
	//If any value reaches 2, return false
	//else
	//return true

	return true;
}


