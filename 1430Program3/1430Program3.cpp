//------------------------------------------------------------------------
//
// Name:   Derek Schultz and Sam Shay 
//
// Course:  CS 1430, Section 2
//
// Purpose: Create the Wumpus game. 
//
// Input:   There are data for multiple games which terminates when the number of arrows is entered as a 0.  
// The data for one game starts with the number of arrows.
// Following that is the player's start row and start column.  After that, there are two commands:  M = Move and S = Shoot.
// The command is followed by a direction, U, D, L, R for Up, Down, Left, Right.There can be 0 or more spaces between the command and the direction.

//
// Output:  The output corrispondis with hints as to where the player 
// is on the board and where the wumpus is to the player. 
// If the wupus is shot the program outputs a win for the player. If the wumpus is in the same square as the player, 
// the program ouputs a loss for the player. 

//------------------------------------------------------------------------
// 
// TODO1: Right-click to the right of the last dash above, select 
//   Guidelines, and then select Add Guideline.  This will place a 
//   Guideline at the end of column 74.  Do not go past it!
//   You can also change the color of the Guideline by right-clicking.
// TODO2: To reformat, click Edit -> Advanced -> Format Document.
//   This will clean up the formatting if you have issues.
//   Then recheck to make sure line lengths are inside the Guidelines.
// The above TODO's assume templates were properly installed as per
// Step 4 of the Visual_Studio_2015_Installation document at:
//     K:\Academic\CSSE\Software\VisualStudo2015_Installation

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
using namespace std;
const int MIN_ROW = 1;
const int MIN_COL = 1;
const int NUM_ROWS = 4;
const int NUM_COLS = 5;
const int MOVE_CHANCES = 6;
const char DOWN = 'D';
const char UP = 'U';
const char RIGHT = 'R';
const char LEFT = 'L';
const char MOVE = 'M';
const char SHOOT = 'S'; 

void PlayOneGame(int numArrows);
void GetCellInDirection(char direction, int curRow, int curCol, 
   int & newRow, int & newCol);
void GetShootPosition(char direction, int curRow, int curCol, int & arrowRow, int & arrowCol);
bool WumpusCheck(int playerRow, int playerCol, int wumpusRow, int wumpusCol);
bool ArrowCheck(int arrowRow, int arrowCol, int wumpusRow, int wumpusCol);

int main()
{
   srand(1);
   int curRow;
   int curCol;
   int numArrows; 
   
   cin >> numArrows;
   while (numArrows > 0)
   {
      cin >> curRow >> curCol;
      PlayOneGame(numArrows);
      cin >> numArrows;

   }
   cout << "Normal Termination of Wumpus Program.";
   return 0;
}

void PlayOneGame(int numArrows)
{
   int wumpusRow;
   int wumpusCol;
   char command; 
   char direction;
   int curRow;
   int curCol;
   int newRow;
   int newCol;
   int arrowRow;
   int arrowCol;
   int playerRow;
   int playerCol;


   wumpusRow = 1 + rand() % NUM_ROWS;
   wumpusCol = 1 + rand() % NUM_COLS;
   
   cin >> command;
   while (numArrows > 0 && WumpusCheck(playerRow, playerCol, wumpusCol, wumpusRow) == false 
      && ArrowCheck(arrowRow, arrowCol, wumpusCol, wumpusRow) == false)
   {
      if (command == 'M')
      {
         GetCellInDirection(direction, curRow, curCol, newRow, newCol);
         curCol = newCol;
         curRow = newRow;
         WumpusCheck(playerRow, playerCol, wumpusCol, wumpusRow);
      }
      else if (command == 'S')
      {
         GetShootPosition(direction, curRow, curCol, arrowRow, arrowCol);
         ArrowCheck(arrowRow, arrowCol, wumpusCol, wumpusRow);
      }
      
      cin >> command;

   }
   
   cout << "Game over - you are out of arrows." << endl;

}

void GetCellInDirection(char direction, int curRow, int curCol, int & newRow, int & newCol)
{
   cin >> direction;

   if (direction == 'U')
   {
      newRow = curRow - 1;
      newCol = curCol;
   }
   else if (direction == 'D')
   {
      newRow = curRow + 1;
      newCol = curCol;
   }
   else if (direction = 'L')
   {
      newCol = curCol - 1;
      newRow = curRow;
   }
   else if (direction = 'R')
   {
      newCol = curCol + 1;
      newRow = curRow;
   }


   if (curRow < MIN_ROW)
   {
      newRow = MIN_ROW;
   }
   if (curRow > NUM_ROWS)
   {
      newRow = NUM_ROWS;
   }
   if (curCol < MIN_COL)
   {
      newCol = MIN_COL;
   }
   if (curCol > NUM_COLS)
   {

   }


}
void GetShootPosition(char direction, int curRow, int curCol, int & arrowRow, int & arrowCol)
{
   cin >> direction;

   if (direction == 'U')
   {
      arrowRow = curRow - 1;
      arrowCol = curCol;
   }
   else if (direction == 'D')
   {
      arrowRow = curRow + 1;
      arrowCol = curCol;
   }
   else if (direction == 'R')
   {
      arrowCol = curCol + 1;
      arrowRow = curRow;
   }
   else if (direction == 'L')
   {
      arrowCol = curCol - 1;
      arrowRow = curRow;
   }
}

bool WumpusCheck(int playerRow, int playerCol, int wumpusRow, int wumpusCol)
{   
   
   if (abs(playerRow - wumpusRow) == 0 && (abs(playerCol - wumpusCol) == 0))
   {
      return true;
   }
   else if ((abs(playerRow - wumpusRow) == 1 && (abs(playerCol - wumpusCol) == 1)))
   {
      return false;
      cout << "The Wumpus is close by." << endl;
   }
   else return false;
   
}

bool ArrowCheck(int arrowRow, int arrowCol, int wumpusRow, int wumpusCol)
{
   if (abs(arrowRow - wumpusRow) == 0 && (abs(arrowCol - wumpusCol) == 0))
   {
      return true;
   }
   else return false;
}