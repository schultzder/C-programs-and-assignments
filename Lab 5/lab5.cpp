//---------------------------------------------------------------------
// 
// DO_1: Fill in your name and section
// Name:                   
//
// Course:  CS 1430,  Section X, Spring 2017
//
// Purpose: This program reads integers and prints out all the divisors
//          of the input number, except 1 and the number itself, 
//          followed by the count of divisors.  If a number is only 
//          divisible by one and itself it is prime. 
//          The program quits when the end of file is reached.
//
// Inputs:  A sequence of integers until end of file.
//
// Output:  For each input number
//              Print all divisors of the input number
//              Print the count of the divisors
//
//---------------------------------------------------------------------

#include <iostream>
#include <iomanip>

using namespace std;

const int FIRST_DIVISOR = 2;
const int WIDTH = 7;

int main()
{
   int number;
   int divisor;
   int divisorCount;       // count of the number of divisors of number

   cout << "Enter a number: ";
   cin >> number;   // Priming read of the EOF loop

   // DO_2: Fill in the condition that will exit the loop 
   //       after the end of file has been reached
   while (cin)
   {
      // DO_3: Initialize divisorCount to 0 
      //       and divisor to FIRST_DIVISOR 
      divisorCount = 0;
      divisor = FIRST_DIVISOR;


      // DO_4: Fill in the condition that will stop 
      //       looking for more divisors.
      // HINT: A divisor can NOT be larger than half of the number.
      while (divisor < (number / 2)) 
      {
         // DO_5: Fill in the condition that determines if the 
         //       divisor divides number evenly.        
         if (number % divisor = 0)  
         {  
             // DO_6: Display divisor with a width of 7, use the const WIDTH 
            cout << setw(WIDTH) << divisor;
            divisorCount = divisorCount + 1; 


    
             // DO_7: Update divisorCount


         
         }

         // DO_8: Update divisor to look for the next divisor
         cin >> number; 
      
      }

      cout << endl;
      cout << "Number " << number << " has "
)           << divisorCount << " divisors.";

      // DO_9:  Complete the condition that checks whether the number is prime.     
      if (divisorCount = 0)
         cout << "  This number is prime."; 

      cout << endl << endl;
      cout << "Enter a number: ";
      cin >> number;
   }

   cout << endl;
   cout << "End of file detected.";

   return 0;
}
