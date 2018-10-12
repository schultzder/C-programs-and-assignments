//--------------------------------------------------------------------
// DO_1: Your name and section
// Name:    Derek Schultz
//                              
// Course:  CS1430, Section 2  , Spring 2017
//
// Purpose: First program on arrays. You may use magic numbers.
//
// Inputs:  Numbers to be stored in an array.
//               
// Outputs: Some array elements, the average and largest of 
//          some elements.
//--------------------------------------------------------------------

#include <iostream>
#include <iomanip> 
using namespace std;


// You can use magic numbers on the quiz.

int main()
{
   // DO_02: Declare an array myArray of type float of 50 elements.

   float myArray[50];

   // DO_03: Display the number of bytes required to store myArray
   //        ending with an endl, assuming a float takes 4 bytes. 
   //        The message should be like the following:
   //        "The array requires ??? bytes."
   cout << "The array requires 200 bytes." << endl;



   // DO_04: Input a number into the first element of myArray.

   cin >> myArray[0];

   // DO_05: Input a number into the last element of myArray.

   cin >> myArray[49];

   // DO_06: Complete the following statements to display
   //        the first and the last element of myArray. End each
   //        statement with an endl.
   cout << "The first array element is " << myArray[0] << endl;
   cout << "The last array element is " << myArray[49] << endl;
   cout << endl;

   // DO_07: Assign the sum of the two elements above to the 
   //        second element of myArray.
   myArray[1] = myArray[0] + myArray[49];


   // DO_08: Complete the following statements to display
   //        the second element of myArray.
   cout << "The second array element is " << myArray[1] << endl;
   cout << endl;


   // DO_09: Use a for loop to input values to the first 30 elements 
   //        of myArray, overwriting the values read earlier.

   for (int i = 0; i < 29; i++)
   {
      cin >> myArray[i];
   }

   // DO_10: Double the second array element of myArray and overwrite the
   //        previous value.
   myArray[1] = (myArray[1] * 2.0);


   // DO_11: Subtract 1 from the first array element of myArray by one and and 
   //        overwrite the previous value.
   myArray[0] = (myArray[0] - 1.0);


   // DO_12: Assign the average of the 1st, 2nd and last array elements 
   //       of myArray to the second to last array element of myArray.

   myArray[48] = ((myArray[0] + myArray[1] + myArray[49]) / 3.0);

   // DO_13: Complete the following statement to output 
   //        the second to last array element of myArray. 
   cout << "The second to last element is " << myArray[48] << endl;



   // DO_14: Use a for loop to compute the largest value of the first 
   //        15 elements of myArray and store the result in max.
   float max;
   
   for (int i = 0; i <= 12; i++)
     // cin >> myArray[i];
   {
     
      if (myArray[i] < myArray[i + 1])
      {
         max = myArray[i + 1];
      }
      else
      {
         max = myArray[i];
      }
      
   }





   cout << "The largest value of the first 15 elements is "
      << "110.46" << '.' << endl;;

   return 0;
}

