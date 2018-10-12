//---------------------------------------------------------------------
// DO_1: Insert your name and section
// Name:_______Derek Schultz______________________
//
// Course:  CS 1430, Section _2_,  Spring 2017
//
// Purpose: This program computes the perimeter, the semiperimeter and 
//          area of a triangle, given the lengths of the 3 sides.
//
// Input :  This program accepts the following prompted input
//          for the three sides of a given triangle:
//              first side - as a float
//              second side - as a float
//              third side - as a float
//
// Output:  This program provides the calculations for the perimeter, 
//          the semiperimeter, and the area of a triangle
//               perimeter - as a float
//               semiperimeter - as a float
//               area of triangle - as a float
//---------------------------------------------------------------------

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
   // ***** INPUT Variables *****
   float side1, side2, side3;

   // DO_2: Declare more variables for perimeter, semiperimeter, 
   //       and area
   //       Hint: see Program Header for Outputs.
   float perimeter, semiperimeter, area;

   // ***** PROMPTED INPUTS *****
   // Prompt "Enter first side" and Input the first side
   cout << "Enter first side: " << endl;
   cin >> side1;

   // Start the output on a new line
  

   // DO_3: Prompt "Enter second side: " and Input second side;
   cout << "Enter second side: " << endl;
   cin >> side2;

   // Start the output on a new line
  

   // DO_4: Prompt ""Enter third side: " and input third side
   cout << "Enter third side: " << endl;
   cin >> side3;
   // Start the output on a new line
   

   // ***** COMPUTATIONS *****
   // DO_5: Compute the values
   //       Hint: see Program Header for Outputs and the lab2.txt for formulas.
   perimeter = (side1 + side2 + side3);
   semiperimeter = perimeter / 2;
   area = sqrt(semiperimeter * (semiperimeter - side1) * (semiperimeter - side2) * (semiperimeter - side3));


   // Start the output on a new line
  
   cout << endl;

   // ***** OUTPUTS *****
   // DO_6: Output values with messages
   //       Hint: see the example output in the lab2.txt, matching punctuation and line spacing.
   cout << "The perimeter is "; cout << perimeter; cout << ". " << endl;
   cout << "The semiperimeter is "; cout << semiperimeter; cout << ". " << endl;
   cout << "The area of the triangle is "; cout << area; cout << ". " << endl;

   //---------  Debugger Exercise ---------------------------
   // DO_7: Replace the 99 with the answer to the debugger exercise.
   // areaSquared variables for the debugger exercise
   // Hypotenuse variables for the debugger exercise
   int leg1 = 13;
   int leg2 = 8;
   int intermediatehypotenuse;
   float hypotenuse;

   intermediatehypotenuse = ( leg1 * leg1 ) + ( leg2 * leg2);
   hypotenuse = (sqrt (float(intermediatehypotenuse)));
   cout << hypotenuse << endl;
   //Replace the following output of 99 with the result from the intermediatehypotenuse value above using the debugger.
   cout << 233 << endl;
   //----------------------  End Debugger Exercise --------------------------

   return 0;
}

