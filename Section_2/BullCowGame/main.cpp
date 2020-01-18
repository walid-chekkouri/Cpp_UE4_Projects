#pragma once

#include<iostream>
#include<string>
#include"FBullCowGame.h"

//Unreal friendly syntax
using FText = std::string;
using int32 =int;


//Function prototypes
void PrintIntro();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();
void PrintGameSummary();

FBullCowGame BCGame; //Instantiation of a new game

//MAIN FUNCTION
int32 main(){

	bool bPlayAgain = false;
	do {
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
		
	} while (bPlayAgain);

	system("pause");
	return 0; //exit
}

//Introduce the game
void PrintIntro()
{
	std::cout <<
		R"(
 .-=-.                .-=-.            .=     ,        =.
  `) )              ( (`      _  _   /'/    )\,/,/(_   \ \
 .' /                \ '.      `//-.|  (  ,\\)\//\)\/_  ) |
(  (   _.-'`::`'-._   )  )     //___\   `\\\/\\/\/\\///'  /
 \  `'`    .::.    `'`  /   ,-"~`-._ `"--'_   `"""`  _ \`'"~-,_
  `-._\`~`      `~`/_.-'    \       `-.  '_`.      .'_` \ ,-"~`/
 _,=` /            \ `=,_    `.__.-'`/   (-\        /-) |-.__,'
(    ,(^\        /^),    )     ||   |     \O)  /^\ (O/  |
 `~~` \0)\      /(0/ `~~`      `\\  |         /   `\    /
       | /`    '\ |              \\  \       /      `\ /
       |          |               `\\ `-.  /' .---.--.\
       |          |                 `\\/`~(, '()      ('
       |          |                  /(O) \\   _,.-.,_)
       /          \                 //  \\ `\'`      /
       \()      ()/               / |  ||   `""""~"`
        `._-==-_.'               /'  |__||
           `""`                        `o
           BULLS         AND                COWS
                    A fun word game

)";

	std::cout << "\n Bulls & Cows game \n";
	std::cout << "can u guess the " << BCGame.GetHiddenWordLength() << " letter isogram I'm thinking of? \n";

}

//Playing the Game
void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();

	//loop asking for guesses while the game is NOT won
	//and there are still tries remaining
	while(! BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries)
	{
		FText Guess = GetValidGuess();

		//Submit valid guess to the game
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);


		//Print number of bulls and cows
		std::cout << "Bulls: " << BullCowCount.Bulls<< " Cows: " << BullCowCount.Cows<<std::endl;

	}

	PrintGameSummary();
}

// loop contianually until the user enters a valid guess
FText GetValidGuess()
{
	FText Guess = "";
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	do {
		int32 CurrentTry = BCGame.GetCurrentTry();

		std::cout << "Try " << CurrentTry << " Of "<<BCGame.GetMaxTries()<<"| Enter your guess: ";
		
		std::getline(std::cin, Guess);

		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status)
		{
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word. \n\n";
			break;

		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter a word without repeating letters \n\n";
			break;

		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter all lowercase letters \n\n";
			break;

		default:
			//assume the guess is valid
			break;
		}
		
	} while (Status != EGuessStatus::Ok); //keep looping until getting valid input

	return Guess;
	
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play with the same hidden word y/n ? ";
	FText Response;

	std::getline(std::cin, Response);

	

	return (Response[0] == 'y') || (Response[0] == 'Y');
}

void PrintGameSummary()
{
	if (BCGame.IsGameWon())
	{

		std::cout <<
			R"(


     _______________
    |@@@@|     |####|
    |@@@@|     |####|
    |@@@@|     |####|
    \@@@@|     |####/
     \@@@|     |###/
      `@@|_____|##'
           (O)
        .-'''''-.
      .'  * * *  `.
     :  *       *  :
    : ~	 Winner ~ :
    : ~ A W A R D ~ :
     :  *       *  :
  `.  * * *  .'
        `-.....-'


)";


		std::cout << "WELL DONE - YOU WIN \n";
	}
	else
	{
		

			std::cout << "		_______________________________________________________\n";

			std::cout << "/                                                       \\ \n" ;

			std::cout << "|                 Ha ha, you're dead                    | \n";

			std::cout << "\_________              _______________________________/ \n";

			std::cout << "          \_         __/    ___---------__              \n";

			std::cout << "            \      _/      /              \_            \n";

			std::cout << "             \    /       /                 \           \n";

			std::cout << "              |  /       | _    _ \          \          \n";

			std::cout << "             | |       / / \  / \ |          \          \n";

			std::cout << "              | |       ||   ||   ||           |        \n";

			std::cout << "              | |       | \_//\\_/ |           |        \n";

		    std::cout << "              | |       |_| (||)   |_______|   |        \n";

			std::cout << "              | |         |  ||     | _  / /   |        \n";

			std::cout << "               \ \        |_________|| \/ /   /         \n";

			std::cout << "                \ \_       |_|_|_|_|/|  _/___/          \n";

			std::cout << "                 \__>       _ _/_ _ /  |                \n";

			std::cout << "                          .|_|_|_|_|   |                \n";

			std::cout << "                          |           /                 \n";

			std::cout << "                         |__________/   ";


			std::cout << "Better Luck Next Time ! \n";


	}
}
