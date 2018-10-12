//-----------------------------------------------------------------------
//
//  DO_1: Your Name and Section
//  Name:    Derek Schultz 
//
//  Course:  CS1430, Section 2, Spring 2017
//
//  Purpose: This program uses a while loop to process the output of
//           a coin sorter to determine how many of each type of coin
//           is sorted - pennies, nickels, dimes, quarters, and unknown.
//
//  Inputs:  The inputs will be characters associated
//           with each coin. These include:
//
//               'p' for penny
//               'n' for a nickel
//               'd' for a dime
//               'q' for a quarter
//
//           All other coins need to go into the unknown bucket, as 
//           they will require manual sorting.
//
//           The program stops counting when 'x' is encountered OR
//           there are more than 10 unknown coins (those with symbols
//           not in the above table).
//               
//  Outputs: The output for this program include the labelled 
//           counts for each of the coin types, the total value of the
//           coinage sorted, and the number of unidentified coins.
//
//-----------------------------------------------------------------------

#include <iostream>
#include <iomanip>

using namespace std;

// coin values
const int PENNY_VAL   =  1;
const int NICKEL_VAL  =  5;
const int DIME_VAL    = 10;
//---------------------------------------------------------
// DO_2 Declare constant for QUARTER_VAL with value 25
//--------------------------------------------------------- 
const int QUARTER_VAL = 25;


// maximum number of bad coins before exiting
const int MAX_BAD_COINS = 10;
// value of a dollar - used for printing results
const int DOLLAR_VAL = 100;

// terminating character is 'x'
const char TERMINATING_CHAR = 'x';

int main()
{
   //------------------------------------------------------------
   // DO_3 declare variable total_value and initialize it to 0
   //------------------------------------------------------------ 
   int total_value = 0;

   //----coin counters------
   int pennies  = 0;
   int nickels  = 0;
   int dimes    = 0;  
   int quarters = 0;
   int unknown_coins = 0;
   int cents;

   char coin;

   cout << "Enter the coin codes:" << endl;
   cin >> coin;   // Priming read for While loop

   //-------------------------------------------------------------------
   // count coins until we get an 'x' to eXit or more than 10 unknown
   //-------------------------------------------------------------------

   //-------------------------------------------------------------------
   // DO_4 Fill in the condition so the loop exits when coin is 'x'
   //      or there are more than 10 coins of unknown type
   // HINT:  Use one of DeMorgan's laws
   //-------------------------------------------------------------------
   while (coin != TERMINATING_CHAR && unknown_coins <= 10)
   {                          
      if ( coin == 'p' )
      {
         pennies++;
         total_value += PENNY_VAL;
      }
      else if ( coin == 'n' )
      {
         nickels++;
         total_value += NICKEL_VAL;
      }
      //-----------------------------------------------------------------
      // DO_5 Write code to process dimes, quarters, and unknown coins
      // HINT: Complete the nested if started above   
      //-----------------------------------------------------------------
      else if (coin == 'd')
      {
         dimes++;
         total_value += DIME_VAL;
      }
      
      else if (coin == 'q')
      {
         quarters++;
         total_value += QUARTER_VAL;
      }
      
      else
      {
         unknown_coins++;
      }
	  
      // read next coin code
      cin >> coin;  

   } // end while counting coins

   // Output the counts and total value
   cout << "Coin counts:" << endl;
   cout << "---------------" << endl;
   cout << " Pennies:  " << pennies   << endl;
   cout << " Nickels:  " << nickels   << endl;
   cout << " Dimes:    " << dimes     << endl; 

   //-------------------------------
   // DO_6 Write output for quarters
   //-------------------------------
   cout << " Quarters: " << quarters  << endl;
   

   cout << "---------------" << endl;

   //---------------------------------------------------
   // Now print total value in $x.yy form.
   //---------------------------------------------------

   cout << "TOTAL VALUE: $";
   //----------------------------------------------------------------
   // DO_7 Print the number of dollars followed by the decimal point.
   //      Hint: use / and DOLLAR_VAL to figure out how many whole
   //      dollars there are.
   //---------------------------------------------------
   cout << (total_value / DOLLAR_VAL) << ".";

   //---------------------------------------------------
   // DO_8 Compute the number of cents (using %).
   //---------------------------------------------------
   cents = (total_value % DOLLAR_VAL);

   //----------------------------------------------------------------
   // DO_9 Write out the cents.  Note that if cents < DIME_VAL,
   //      you will need to write a 0 before cents.  Otherwise,
   //      just write cents by itself.  This way you cover
   //      (for example) $0.03 and $0.82.
   //----------------------------------------------------------------
   if (cents < DIME_VAL) cout << "0" << cents;
   else (cout << cents);
   
   

   cout << endl;

   cout << "Number of unidentified coins: "
        << unknown_coins << endl;

   return 0;
} 
