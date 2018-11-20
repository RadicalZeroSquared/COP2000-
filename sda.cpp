#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <ctime>

using namespace std;

//The purpose of this program is to create a 3 round game where you guess a missing value
// Marcos Dos Santos
// September 19th, 2018
// COP2000
//HW #5
//Actually doing notes because this assignment was the most frustrating

void displayBoard (int GameBoard[4][3]);
void instructions();
int beginGame (int UsedBoards[3]);
bool testWinner (int answers, int BoardNumber, int AnswerBoard[3]);
int EnterAnswer (int BoardNumber, int answer[3]);
int GameDecider (int BoardNumber, int Board0[4][3], int answers[3], int UsedBoards[3], int Board1[4][3], int Board2[4][3]);

int main()
{
    int GameBoard [4][3];
    int UsedBoards [3] = {0, 1, 2};
    int answers[3] = {8, 13, 10};
    int BoardNumber = 1;
    //Boards are number 0-2 because it took me way too long to figure out how to make it 1-3 with the random cstdlib library
    int Board0[4][3] = { { 11, 2, 20 },
	                                           { 22, 4 , 40 },
	                                           { 33, 6 , 60 },
	                                           { 44, 0 , 80 } };
	                                           
    int Board1[4][3] = { { 12, 3, 21 },
	                                           { 98, 17 , 89 },
	                                           { 24, 6 , 15 },
	                                           { 85, 0 , 49 } };
	                                           
    int Board2[4][3] = { { 77, 14, 95 },
	                                           { 51, 6 , 42 },
	                                           { 91, 10 , 73 },
	                                           { 46, 0 , 55 } };
	                                           
    //The whole main function is just calling the required functions.
    instructions();
    //the cout copy past
    beginGame(UsedBoards);
    //draws a random number between 0 and 2
    BoardNumber = beginGame(UsedBoards);
    //asigns the number given at random to it's own variable. I could shorten it, but I thought have to use the function as a variable and it constantly gave problems with "real randomness", so I just made a seperate variable
    GameDecider(BoardNumber, Board0, answers, UsedBoards, Board1, Board2);
    //Program picks one of the 3 boards, plays it, marks it as used, and picks another board.
    beginGame(UsedBoards);
    BoardNumber = beginGame(UsedBoards);
    GameDecider(BoardNumber, Board0, answers, UsedBoards, Board1, Board2);
    beginGame(UsedBoards);
    BoardNumber = beginGame(UsedBoards);
    GameDecider(BoardNumber, Board0, answers, UsedBoards, Board1, Board2);
    //The final board. All 3 boards are marked.
    beginGame(UsedBoards);
    //If statement triggers where all boards are marked, so it gives a cout.

}




void instructions()
    {
    cout<<"*****************************************************************" << endl;
    cout<<"MISSING NUMBERS GAME" << endl;
    cout<<"A fun brain game…" << endl;
    cout<<"Please Enter a whole number to guess the missing number…" << endl;
    cout<<"Program Developed by: Marcos Dos Santos" << endl;
    cout<<"*****************************************************************" << endl;
    }
//obligatory
	                                           
bool testWinner (int UserInput, int BoardNumber, int answers[])
    {
        if (UserInput == answers[BoardNumber])
        {
            cout << "Nice Job!" << endl;
            return true;
        }
            
        else
        {
             cout << "Sorry, that is incorrect" << endl;
            return false;
        }
    }
//Basic array answer check. I would of much rather have made a funtion that checks the answer input and dont all the verifications, but this is a bool.


int beginGame (int UsedBoards[3])
{
    int RandomNumber;
    
    srand(time(0));
    RandomNumber = rand() % 3;
    //This rand funtion isnt random, but gives a string of numbers in a set order (like how pie is random, but has a set string of numbers). Maybe the hint would of worked, but I messed with it for so long that I just got another library and google gave me the srand funtion that allows real randomness.
    if((UsedBoards[0] == -1) && (UsedBoards[1] == -1) && (UsedBoards[2]) == -1)
    //The usedboards array is given the number of a board. After a board is played, the value of the usedboards variable assigned to it is set to one (later in the code).
    //Here I first check to see if all of the usedboards variables are changed to -1.
    {
        cout << "There are no more boards!" << endl;
        cout << "You are the word genius! Congratulations!" << endl;
        exit(0);
        //Since user cleared all boards, cout congrats are given.
    }
    
    if ((RandomNumber == 0) && (UsedBoards[0] == -1)) 
    //I couldn't figure out how to make the program check if a random number has the associated board used up. I decided to do if statements to see what the random number is and if the board associated is used already or not
    {
        do 
        {
            srand(time(0));
            RandomNumber = rand() % 3;
            //If it's used, RandomNumber is assigned a new variable.
        }
        while ((RandomNumber == 0) && (UsedBoards[0] == -1)); 
        //and just to check my bases, the variable is assigned a new variable until it isn't 0
    }
    
    if ((RandomNumber == 1) && (UsedBoards[1] == -1)) 
    {
        do 
        {
            srand(time(0));
            RandomNumber = rand() % 3;
        }
        while ((RandomNumber == 1) && (UsedBoards[1] == -1));
    }
    
    if ((RandomNumber == 2) && (UsedBoards[2] == -1)) 
    {
        do 
        {
            srand(time(0));
            RandomNumber = rand() % 3;
        }
        while ((RandomNumber == 2) && (UsedBoards[2] == -1));
    }
    //Any cominations of variables used will be filted out by now and only return an unused board variable.

    return RandomNumber;
}
    
void displayBoard (int GameBoard[4][3])
    {
        for (int x = 0; x < 4; x++)
        {
            for (int q = 0; q < 3; q++)
            {
                cout << setw(4) << GameBoard[x][q] << " ";
            }
            cout << endl;
        }
    }
// a simple cout for loop that displays the table. 

int EnterAnswer (int BoardNumber, int answers[3])
{
    int UserInput = 1000;
    //Ridiculously large number so it doesn't happen to be the answer or exit number
    cout << "Enter guess or 0 to exit" << endl;
    cin >> UserInput;
    
    while (UserInput < 0)
    {
        cout << "Please enter a positive whole number" << endl;
        cin >> UserInput;
    }
    //Input validation
    if (UserInput == 0)
    {
        exit(0);
    }
    //exit option
    if ((testWinner (UserInput, BoardNumber, answers)) == true)
    {
        cout << "Do you wish to play again? Enter 0 to exit or any number to continue" << endl;
        cin >> UserInput;
        
        if (UserInput == 0)
        {
            exit(0);
        }
        //exit option
    }
    else 
    //Since I had to give the user 3 chances, I just made an if else statment to see if they were right and made the if else statement the same thing.
    {
        cout << "Enter guess or 0 to exit" << endl;
        cin >> UserInput;
        
        while (UserInput < 0)
        {
            cout << "Please enter a positive whole number" << endl;
            cin >> UserInput;
        }
    
        if (UserInput == 0)
        {
            exit(0);
        }
        
        if ((testWinner (UserInput, BoardNumber, answers)) == true)
        {
            cout << "Do you wish to play again? Enter 0 to exit or any number to continue" << endl;
            cin >> UserInput;
        
            if (UserInput == 0)
            {
                exit(0);
            }
        }
        else 
        //same thing
        {
            cout << "Enter guess or 0 to exit" << endl;
            cin >> UserInput;
            
            while (UserInput < 0)
            {
                cout << "Please enter a positive whole number" << endl;
                cin >> UserInput;
            }
        
            if (UserInput == 0)
            {
                exit(0);
            }
            
            if ((testWinner (UserInput, BoardNumber, answers)) == true)
            {
                cout << "Do you wish to play again? Enter 0 to exit or any number to continue" << endl;
                cin >> UserInput;
            
                if (UserInput == 0)
                {
                    exit(0);
                }
                else 
                {
                    cout << "Next board!" << endl;
                }
                // function ends and the whole thing loops again
            }
            else
            // 3rd failure means game over
            {
                cout << "Sorry... You're out of guesses" << endl;
                exit(0);
            }
        }
    }

}   

    
int GameDecider (int BoardNumber, int Board0[4][3], int answers[3], int UsedBoards[3], int Board1[4][3], int Board2[4][3])
{
switch (BoardNumber)
// I had to create a large switch function because I couldn't figure out how to make a second board appear. The only other way I could figure out was to make the program again in each case with 2 boards to choose from (randomly) and then another switch statement in both of those cases. If there was a way to go from one case to another in the same funtion, I didn't know about it (that can also make the case chosen at random).
    {
        case 0:
            {
                displayBoard (Board0);
                //shows first board
                EnterAnswer (BoardNumber, answers);
                //checks if the user is correct or not
                UsedBoards[0] = -1;
                // makes is so that the RandomNumber variable can't be 0
                
                break;
            }
                
            case 1:
            {
                displayBoard (Board1);
                //shows second board
                EnterAnswer (BoardNumber, answers);
                //checks if the user is correct or not
                UsedBoards[1] = -1;
                // makes is so that the RandomNumber variable can't be 1
                
                break;
            }
        
            case 2:
            {
                displayBoard (Board2);
                //shows third board
                EnterAnswer (BoardNumber, answers);
                //checks if the user is correct or not
                UsedBoards[2] = -1;
                // makes is so that the RandomNumber variable can't be 2

                break;
            }
            
            //As I'm creating this, I noticed that you copy and paste the main funtion into each case, but I know you like funtions and I know I'm too lazy to even clean up this code. My main problem is the messy EnterAnswer funtion. I could of probably added another funtion to deal with validation and multiple tries, but making functions within fuctions takes me a while. At least this works.
    }
}