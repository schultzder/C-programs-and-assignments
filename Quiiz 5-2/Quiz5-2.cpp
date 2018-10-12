//--------------------------------------------------------------------
//  DO_01: Your name and section.
//  Name:    Derek Schultz
//                              
//  Course:  CS1430, Section  2, Spring 2017
//
//  Purpose: Linear Search: Target Count. Reads in the number of students
//           and their test scores into Test2[].  Reads in a score to 
//           search for into target.  Counts the number of times
//			    that a target score appears in the list of scores. 
//           Repeats until EOF, and the user enters ctrl+Z [Enter].
//
//  Inputs:  int numStudents: the total number of students in the array
//           float Test2[]: array of students with scores (floats)
//           float target: the score that will be searched for in the 
//                         Test2[] array.
//               
//  Outputs: int count: The number of times the target score appears 
//           in the array.
//           Prints out the array.
//--------------------------------------------------------------------

#include <iostream>
#include <iomanip> 

using namespace std;
const int MAX_SIZE = 100;

void ReadArray(float s[], int& size);

// DO_05: Write the function prototypes for TargetCount() and DisplayArray() 
//        after completing the function definitions (DO_02 to DO_03)
int TargetCount(float s[], int size, float target);
void DisplayArray(const float s[], int size);



int main()
{
   int numStudents, count;
   float Test2[MAX_SIZE], target;

   // DO_06: Call ReadArray() to input numStudents and their scores
   //        on test2 to array Test2[]
   ReadArray(Test2, numStudents);

   cout << endl;
   cout << "Enter the score you are looking for: ";
   cin >> target;
   cout << endl;
   while (!cin.eof())
   {
      // DO_07: Call TargetCount() to find out how many times target
      //       occurs in array Test2[]. Store the result in count.
      count = TargetCount(Test2, numStudents, target);
     
      // DO_8: Fill in the condition 
      if (count >= 0)
         cout << "Target " << target << " is not in the array." << endl << endl;
      else
         cout << "Target " << target << " occurs in the array "
              << count << " times." << endl << endl;

      cout << "Enter the score you are looking for: ";
      cin >> target;
   }   
   
   cout << endl << endl;
   
   // DO_9: Call function DisplayArray to display 
   //        all array elements of Test2.
 
   DisplayArray(Test2, numStudents);

   return 0;
}

//--------------------------------------------------------------------
// Function TargetCount() has three parameters:
//     s[]   : array of type float
//     size  : integer, the number of elements of s[]
//     target: float
// The function returns the number of times target occurs in
//     array s[]
// Parameters: ( in  , in  ,  in )
// DO_02: Write the function definition. You MUST use one for or while
//        loop!
//--------------------------------------------------------------------
int TargetCount(float s[], int size, float target)
{
   int i;
   int count;
   count = 0;
   for (int i = 0; i < size; i++);
   {
      if (s[i] == target)
      {
         count++;
      }
   }

   return count;
}

//--------------------------------------------------------------------
// Function DisplayArray() has two parameters:
//     s[]      : array of type float
//     size     : integer, the number of elements of s[]
// The function displays all array elements of array s[]
//     with 5 values each line except the last line.
//     Each value will be displayed with 8 spaces.
// One example output with 8 values in the array:
//    45.5    50.0    47.5    55.5    58.5
//    60.0    49.5    55.5
// DO_03: Specify parameters as In, Out, or InOut
// Parameters: (in , in)
//--------------------------------------------------------------------
void DisplayArray(const float s[], int size)
{
   cout << fixed << showpoint << setprecision(1); 
   cout << "The array elements are" << endl;

   for ( int i = 0; i < size; i++ )
   {
      cout << setw(8) << s[i];
	  if ( (i + 1) % 5 == 0 )
	     cout << endl;
   }


   return;
}

//--------------------------------------------------------------------
// The function inputs an integer value to size and then
//    inputs size float numbers into array s[]
// Parameters: (Out, Out)
//--------------------------------------------------------------------
void ReadArray(float s[], int& size)
{
   // DO_04: Write the function body.
   //        You must use a for loop.
   int i;
   cin >> size;
   for (int i; i < s[i]; i++);
   {
      
      cin >> s[i];
   }

   return;
}	
