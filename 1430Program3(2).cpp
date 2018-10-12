//------------------------------------------------------------------------
//
// Name:   Derek Schultz and Sam Shay. Work split: 50/50
//
// Course:  CS 1430, Section 2
//
// Purpose: Create the Wumpus game. 
//
// Input:   There are data for multiple games which terminates when the 
// number of arrows is entered as a 0. The data for one game starts with 
// the number of arrows.Following that is the player's start row and 
// start column.  After that, there are two commands:  M = Move 
// and S = Shoot. The command is followed by a direction, U, D, L, R for 
// Up, Down, Left, Right.There can be 0 or more spaces between the 
// command and the direction.

//
// Output:  The output corrispondis with hints as to where the player 
// is on the board and where the wumpus is to the player. 
// If the wupus is shot the program outputs a win for the player. If the 
// wumpus is in the same square as the player, the program ouputs a 
// loss for the player. 

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

// Delcare constants //

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

// Function prototypes //

void PlayOneGame(int numArrows);
void GetCellInDirection(char direction, int curRow, int curCol,
   int & newRow, int & newCol);
void GetShootPosition(char direction, int curRow, int curCol,
   int & arrowRow, int & arrowCol);
bool WumpusCheck(int playerRow, int playerCol, int wumpusRow,
   int wumpusCol);
bool ArrowCheck(int arrowRow, int arrowCol, int wumpusRow,
   int wumpusCol);
void GetRandWumpus(char direction, int wumpusRow, int wumpusCol,
   int & newWumpusRow, int & newWumpusCol, int playerRow, int playerCol);
void closeByCheck(int playerRow, int playerCol, int wumpusRow,
   int wumpusCol);

int main()
{
   srand(1);

   // Algorithm for main //

   int numArrows;
   cout << "Enter number of arrows (int)";
   cin >> numArrows;
   while (numArrows > 0)
   {
      cout << "Starting a new game.  ";
      PlayOneGame(numArrows);
      cout << "Enter number of arrows (int)";
      cin >> numArrows;
   }
   cout << "Normal Termination of Wumpus Program.";
   return 0;
}

void PlayOneGame(int numArrows)
{
   // Declare variables //

   int wumpusRow, curCol, curRow, newRow, newCol, arrowRow, arrowCol,
      playerRow, playerCol, newWumpusRow, newWumpusCol, wumpusCol;
   char command, direction;
   bool finished, done, outArrows;

   // Input row and column, display messeage. //
   cout << "Enter player row and column (int, int)";
   cin >> curRow >> curCol;
   cout << "Player at row " << curRow << " column " << curCol << endl;

   // Initialize variables //

   playerCol = curCol;
   playerRow = curRow;

   arrowCol = curCol;
   arrowRow = curRow;

   wumpusRow = 1 + rand() % NUM_ROWS;
   wumpusCol = 1 + rand() % NUM_COLS;

   finished = WumpusCheck(playerRow, playerCol, wumpusCol, wumpusRow);

   if (finished == true)
   {
      cout << "Game over. The Wumpus got you!" << endl;
      finished = true;
   }
   done = ArrowCheck(arrowRow, arrowCol, wumpusCol, wumpusRow);
   if (numArrows == 0)
   {
      outArrows = true;
   }
   else if (numArrows > 0)
   {
      outArrows = false;
   }
   closeByCheck(playerRow, playerCol, wumpusRow, wumpusCol);

   // Start of loop //

   while (outArrows == false && finished == false
      && done == false)
   {

      cin >> command >> direction;

      // Move command //

      if (command == 'M')
      {
         GetCellInDirection(direction, curRow, curCol, newRow, newCol);

         curCol = newCol;
         curRow = newRow;

         playerCol = curCol;
         playerRow = curRow;

         cout << "You are at row " << curRow << " column "
            << curCol << endl;

          finished = WumpusCheck(playerRow, playerCol, wumpusCol,
            wumpusRow);
         if (finished == false)
         {
            closeByCheck(playerRow, playerCol, wumpusRow, wumpusCol);
            GetRandWumpus(direction, wumpusRow, wumpusCol, newWumpusCol,
               newWumpusRow, playerRow, playerCol);
            wumpusCol = newWumpusCol;
            wumpusRow = newWumpusRow; 
            finished = WumpusCheck(playerRow, playerCol, wumpusCol,
               wumpusRow);
            if (finished == false)
            {
               finished = false;
            }
            else if (finished == true)
            {
               cout << "Game over. The Wumpus got you!" << endl;
               finished = true;
            }

            finished = false;
         }
         else if (finished == true)
         {
            cout << "Game over. The Wumpus got you!" << endl;
            finished = true;
         }

      }

      // Shoot command //

      else if (command == 'S')
      {


         GetShootPosition(direction, curRow, curCol, arrowRow, arrowCol);
         finished = ArrowCheck(arrowRow, arrowCol, wumpusCol, wumpusRow);
         if (finished == false)
         {
            cout << "You missed." << endl;
            numArrows = numArrows - 1;
            done = false;

         }
         else if (finished == true)
         {
            cout << "You win - you got the Wumpus!" << endl;
            numArrows = numArrows - 1;
            done = true;
         }

         if (done == false)
         {
            if (numArrows == 0)
            {
               cout << "Game over - you are out of arrows." << endl;
               outArrows = true;
            }
            else
               outArrows = false;
         }
      }
   }






}
// GetCellInDirection function //
void GetCellInDirection(char direction, int curRow, int curCol,
   int & newRow, int & newCol)
{

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
   else if (direction == 'L')
   {
      newCol = curCol - 1;
      newRow = curRow;
   }
   else if (direction == 'R')
   {
      newCol = curCol + 1;
      newRow = curRow;
   }
   if (newRow < MIN_ROW)
   {
      newRow = MIN_ROW;
   }
   if (newRow > NUM_ROWS)
   {
      newRow = NUM_ROWS;
   }
   if (newCol < MIN_COL)
   {
      newCol = MIN_COL;
   }
   if (newCol > NUM_COLS)
   {
      newCol = NUM_COLS;
   }


}
// GetShoot position function //
void GetShootPosition(char direction, int curRow, int curCol,
   int & arrowRow, int & arrowCol)
{
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
// WumpusCheck function //
bool WumpusCheck(int playerRow, int playerCol, int wumpusCol,
   int wumpusRow)
{

   if (abs(playerRow - wumpusRow) == 0 &&
      (abs(playerCol - wumpusCol) == 0))
   {
      return true;
   }

   else return false;

}
// ArrowCheck function //
bool ArrowCheck(int arrowRow, int arrowCol, int wumpusCol, int wumpusRow)
{
   if (abs(arrowRow - wumpusRow) == 0 &&
      (abs(arrowCol - wumpusCol) == 0))
   {
      return true;
   }
   else
   {
      return false;
   }
}
// GetRandWumpus function //
void GetRandWumpus(char direction, int wumpusRow, int wumpusCol,
   int & newWumpusCol, int & newWumpusRow, int playerRow, int playerCol)
{

   if (rand() % MOVE_CHANCES == 0)
   {
      if (direction == 'U')
      {
         newWumpusRow = wumpusRow - 1;
         newWumpusCol = wumpusCol;
         cout << "Wumpus may have moved." << endl;
      }
      else if (direction == 'D')
      {
         newWumpusRow = wumpusRow + 1;
         newWumpusCol = wumpusCol;
         cout << "Wumpus may have moved." << endl;
      }
      else if (direction == 'L')
      {
         newWumpusCol = wumpusCol - 1;
         newWumpusRow = wumpusRow;
         cout << "Wumpus may have moved." << endl;
      }
      else if (direction == 'R')
      {
         newWumpusCol = wumpusCol + 1;
         newWumpusRow = wumpusRow;
         cout << "Wumpus may have moved." << endl;
      }


      if (newWumpusRow < MIN_ROW)
      {
         newWumpusRow = MIN_ROW;
      }
      if (newWumpusRow > NUM_ROWS)
      {
         newWumpusRow = NUM_ROWS;
      }
      if (newWumpusCol < MIN_COL)
      {
         newWumpusCol = MIN_COL;
      }
      if (newWumpusCol > NUM_COLS)
      {
         newWumpusCol = NUM_COLS;
      }
      wumpusRow = newWumpusRow;
      wumpusCol = newWumpusCol;

      closeByCheck(playerRow, playerCol, wumpusRow, wumpusCol);
   }
   else
   {
      newWumpusCol = wumpusCol;
      newWumpusRow = wumpusRow;
   }

}
// CloseByCheck function //
void closeByCheck(int playerRow, int playerCol, int wumpusRow,
   int wumpusCol)
{
   if ((abs(playerRow - wumpusRow) <= 1 &&
      (abs(playerCol - wumpusCol) <= 1)))
   {
      if ((abs(playerRow - wumpusRow) == 0 &&
         (abs(playerCol - wumpusCol) == 0)))
      {

      }

      else cout << "The Wumpus is close by." << endl;

   }
}

