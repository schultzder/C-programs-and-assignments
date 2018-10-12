//---------------------------------------------------------------------
//
// Name:   <Derek Schultz> 
//
// Course:  CS 1430, <DO_02: Section 2>, Spring 2017. 
//
// Purpose: This program computes the car insurance premium based 
//          on the driver's gender, age, and number of traffic tickets 
//          she/he has received.
//
// Input:  Gender, age, and the number of traffic tickets.
//              gender           -  a  char
//              age              -  an integer
//              tickNum          -  an integer 
//
// Output:  The insurance premium based on gender, age, and the 
//          number of traffic tickets.
//              premium           -  as an integer
//---------------------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Constant Declaration , see lab3.txt
const int ADULT_AGE = 21;
const int MALE_ADULT_AGE_BASE = 1000;
const int FEMALE_ADULT_AGE_BASE = 900;
const int MALE_UNDER_ADULT_AGE_BASE = 1200;
const int ADULT_AGE_TICKET_MULTIPLIER = 100;
const int UNDER_ADULT_AGE_TICKET_MULTIPLIER = 200;

// DO_3: Declare the  constant FEMALE_UNDER_ADULT_AGE_BASE , which 
//       represents the base  for females with age < 21
//       Hint: see lab3.txt for the value.
const int FEMALE_UNDER_ADULT_AGE_BASE = 1000;



int main()
{
   char gender;  // M = Male , F = Female
   int age;      // The Driver's age
   int tickNum;  // Number of tickets the driver has

   // DO_4: Declare the  integer variable premium , which 
   //       represents the driver's insurance premium

   int premium;

   cout << "Enter your gender (M/F): ";
   cin >> gender;
   cout << endl;

   // DO_5: Prompt "Enter your age as an integer: " and read the age

   cout << "Enter your age as an integer: ";
   cin >> age;
   cout << endl;


   cout << "How many tickets do you have: ";
   cin >> tickNum;
   cout << endl;

   // ******* COMPUTATION ******
   // Using nested if statements to calculate the insurance premium
   // based on formulas that are given in lab3.txt

   // DO_6: Complete the remaining nested if statement to cover the remaining 
   //       premium formulas that are mentioned in lab3.txt
   //       Note : You must use the declared constants

   if (gender == 'M')
   {
      if (age < ADULT_AGE)

         premium = MALE_UNDER_ADULT_AGE_BASE +
         UNDER_ADULT_AGE_TICKET_MULTIPLIER * tickNum;

      else if (age >= ADULT_AGE)

         premium = MALE_ADULT_AGE_BASE +
         ADULT_AGE_TICKET_MULTIPLIER * tickNum;
   }

  
   else if (gender == 'F')

      {
         if (age < ADULT_AGE)

            premium = FEMALE_UNDER_ADULT_AGE_BASE +
            UNDER_ADULT_AGE_TICKET_MULTIPLIER * tickNum;

         else if (age >= ADULT_AGE)

            premium = FEMALE_ADULT_AGE_BASE +
            ADULT_AGE_TICKET_MULTIPLIER * tickNum;
      }





   // The end of  IF STRUCTURE
         
   // DO_7: Finish the cout statement
   // Print the calculated premium

         cout << "Your premium is $"; cout << premium << endl;
            
   // Debugger Exercise
   // DO_8: Set a break point right after the second cin statement 
   //       where you read in the tickNum.
   //       Start Debugging run 1: enter male, age 18, and tickNum 3 
   //       Start Debugging run 2: enter female, age 25, and tickNum 25
   //       Write down the value of partial_premium in the Debug ->
   //       Windows -> Locals and complete the following cout statements. 
   int partial_premium = UNDER_ADULT_AGE_TICKET_MULTIPLIER * tickNum;
   cout << "Start Debugging run 1, the value of partial_premium: "
        << 600 << endl;
   cout << "Start Debugging run 2, the value of partial_premium: "
        << 5000 << endl;

   return 0;
}