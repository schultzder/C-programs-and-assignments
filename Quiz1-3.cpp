//-------------------------------------------------
// Course  : CS1430, Spring 2017
//
// DO_01: 
// Name    : Derek Schultz
// Section : 2
// Purpose : Determines the average of ten numbers.
// Input   : a list of 10 integers  
// Output  : The average of the ten numbers. 
// Quiz 1-2: 1 Point
// Due     : Monday, February 20 at 8 am
//-------------------------------------------------

#include <iostream>
#include <iomanip>
using namespace std;

const int NUMBER_DIVISOR = 10;

int main()
{
   // DO_01: Declare an integer variable named num.
   int num;

      // DO_02: Declare an integer variable named count and set it to 0.
   int count = 0;
   int sum = 0;
   float average = 0;
 
   cout << fixed << showpoint << setprecision(2);
   cout << "Enter a list of ten numbers, and I will calculate the average: " << endl;
   
   // DO_03: Prompt the user to enter the first number, "Enter the first number: "
   cout << "Enter the first number: ";
   
   // D0_04: Read in the first number into the variable num.
   cin >> num;
   count = count + 1;
   // DO_05: Complete the while test, using the count variable, stop when you
   //       have read the 10 numbers.
   while (count <= NUMBER_DIVISOR)
   {   
      cout << endl;
      // DO_06: Add num to the variable sum and store it in sum.
      sum = num + sum;
     
      // DO_07: Prompt the user to enter the next number, "Enter the next number: "
      cout << "Enter the next number: ";
      // DO_08: Read in the next number, reusing the variable num to 
      //       store the next value.
      cin >> num;
      // DO_09: increment the counter
      count = count + 1;
   }
   
   cout << endl;
 
   // DO_10: Calculate the average of the numbers, storing it in the variable
   //        average. Use the constant NUMBER_DIVISOR. You will need to typecast.
   average = float(sum) / NUMBER_DIVISOR;
   
   // DO_11: print the average of the numbers with the text, "The average is: ",
   //        with a new line after it. 
   
   cout << "The average is: " << average << endl;
      
   
   return 0;
}   
