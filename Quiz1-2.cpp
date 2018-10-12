//-------------------------------------------------
// Course  : CS1430, Spring 2017
//
// DO_01: Your name and section
// Section : 2
//
// Name    : Derek Schultz
//
// Quiz 1-2: 1 Point
//           Due 5 pm, Wednesday, February 8 at 5 pm
//-------------------------------------------------

// DO_02: Include the header file for Input/Output
#include <iostream>
#include <iomanip>
using namespace std;

const int COUNT = 3;

int main()
{
   int num1, num2, num3;

   // DO_03: Declare an integer variable total
   int total;

   // DO_04: Declare a float variable avg
   float avg;
   cout << fixed << showpoint << setprecision(2);
   // DO_05: Output string "Enter three integers: "
   cout << "Enter three integers: ";

   // DO_06: Read in three integers to num1, num2 and num3
   cin >> num1; cin >> num2; cin >> num3;

   // D0_7: output a blank line
   cout << endl;

   // DO_07: Compute the total of the three input integers 
   //        and store the result in variable total
   total = num1 + num2 + num3;

   cout << "The total is " << total << '.' << endl;

   // DO_08: Compute the FLOAT average of the three integers 
   //        and store the value in  variable avg. You will need
   //        to typecast.
   avg = (float(num1) + float(num2) + float(num3)) / float(3);

      // DO_09: Display the value of avg with a message
      //        at the beginning of the next line.
      //        Assuming the value of avg is 3.5, then the display should be
      //
      // The average is 3.5.
   cout << "The average is " << avg << ".";

   return 0;
}   
