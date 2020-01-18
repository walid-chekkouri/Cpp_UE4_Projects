#pragma once
#include "FBullCowGame.h"
#include<map>
#define TMap std::map

FBullCowGame::FBullCowGame() { Reset(); }//default constructor


int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const{ return MyHiddenWord.length();}
bool FBullCowGame::IsGameWon() const { return bGameIsWon; }


int32 FBullCowGame::GetMaxTries() const
{ 
	TMap<int32, int32> WordLengthToMaxTries{ {3,4}, {4,7}, {5,10}, {6,15}, {7,20} };
	return WordLengthToMaxTries[MyHiddenWord.length()];
}



void FBullCowGame::Reset()
{

	const FString HIDDEN_WORD = "plane";
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;
	bGameIsWon = false;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	
	if (!IsIsogram(Guess))// if the guess isn't an isogram
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (!IsLowerCase(Guess))// if the guess isn't all lowercase
	{
		return EGuessStatus::Not_Lowercase; 
	}
	else if (Guess.length() != GetHiddenWordLength()) //if the guess length is wrong
	{
		return EGuessStatus::Wrong_Length;
	}
	else
	{
		return EGuessStatus::Ok;
	}


}


//receives a VALID guess, increments turn, and returns count
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;
	int32 WordLength = MyHiddenWord.length();//asumming same length as guess

	//loop through all letters in the hidden word
	for (int32 i = 0; i < WordLength; i++)
	{	
		//compate letters against the guess
		for (int32 j = 0; j < WordLength; j++)
		{
			if (Guess[j] == MyHiddenWord[i])
			{
				if (i == j)
				{
					BullCowCount.Bulls++;//Bull
				}
				else
				{
					BullCowCount.Cows++;//Cow
				}
			}
		}


	}

	if (BullCowCount.Bulls == WordLength)
	{
		bGameIsWon = true;
	}
	else
	{
		bGameIsWon = false;
	}

	return BullCowCount;
}

bool FBullCowGame::IsIsogram(FString Word) const
{
	// treat 0 and 1 letter words as isograms
	if (Word.length() <= 1) { return true; }

	TMap<char, bool> LetterSeen;  //setup our map
	for (auto Letter : Word)	//for all letters of the word
	{
		Letter = tolower(Letter); //handle mixed case
		if (LetterSeen[Letter]) {
			return false; //we do NOT have an isogram
		} else {
			LetterSeen[Letter] = true;
		}

	}		
	

	return true;
}

bool FBullCowGame::IsLowerCase(FString Word) const
{
	for (auto Letter : Word)
	{
		if (!islower(Letter))
		{
			// if not lowercase
			return false;
		}

	}

	return true;
}
