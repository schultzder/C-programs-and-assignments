//--------------------------------------------------------------------
//  DO_01: Your name and section:
//  Name:    Derek Schultz 
//                              
//  Course:  CS1430, Section  , Spring 2017
//
//  Purpose: Function and parallel arrays. This program reads in 
//           initial values into two parallel arrays.  It then 
//           loops until EOF, reading in a name, then searching
//           for it in the arrays, and if it finds it, it prints the 
//           name and the score. Then it searches the arrays for the
//           student with the highest score, printing the info out.           
//
//  Inputs:  Number of students and their scores on test2
//               
//  Outputs: Search results, and then the name of student
//           with the highest score.
//--------------------------------------------------------------------

#include <iostream>
#include <iomanip> 
#include <string>

using namespace std;
const int MAX_SIZE = 16;

void GetInput(string name[], float grade[], int & size);
int IndexOfTarget(const string s[], int size, string target);
int IndexOfMax(const float s[], int size);


int main()
{
   int numStudents, index;
   string names[MAX_SIZE], theName;
   float CS143[MAX_SIZE], highest;

   // DO_12: Call GetInput() to input numStudents and 
   //        names[] and CS143[]
   GetInput(names, CS143, numStudents);

   cout << endl;
   cin >> theName;

   while (!cin.eof())
   {
      // DO_13: Call IndexOfTarget() to find the index of first student 
      //        whose name is theName.
      index = IndexOfTarget(names, numStudents, theName);

      if (index == -1)
         cout << "No student has name " << theName;
      else
         // DO_14: Complete the statement to print 
         //    the name and the score of that student
         cout << "Student " << theName
         << " has a score " << CS143[index] << endl;

      cout << endl;
      cin >> theName;
   }

   // DO_15: Call IndexOfMax() to find the index of first student 
   //        with the highest score.
    index = IndexOfMax(CS143, numStudents);
    highest = CS143[index];

   // DO_16: Complete the statement to print the name 
   //        of the first student with the highest score.
   cout << "Student " << names[index]
      << " has the highest score of " << highest;

   return 0;
}

//--------------------------------------------------------------------
// Function GetInput has three parameters:
//     name[]  : an array of type string
//     grade[]: an array of type float
//     size        : the size of both strArray and floatArray
// The function first reads the value of size, then reads size
//     values into both strArray[] and floatArray[].
// You must use one for loop for the function.
// See the prototype for the parameters
// Sample input
//    4 
//	Donna   48
//	Suboh   50
//	Joe     47
//	Lily    59
//
// DO_02: Specify the parameters as In, Out, or InOut.
// Parameters: (in, in, InOut)					
//--------------------------------------------------------------------
// DO_03: Complete the function header.
void GetInput(string name[], float grade[], int & size)
{
   // DO_04: Read in the value of size.
   cin >> size; 

   // DO_05: Use one for loop to read size values into 
   //        both name[] and grade[].

   for (int i = 0; i < size; i++)
   {
      cin >> name[i];
      cin >> grade[i];
   }
}

//--------------------------------------------------------------------
// Function IndexOfTarget has three parameters:
//     s[]   : an array of type string
//     size  : the number of elements in array s[]
//     target: string
// The function returns the index of the first element of s[]
//        that is equal to target. 
//     It returns -1 if target is not in s[].
// See the prototype for the parameters
// DO_06: Specify the parameters as In, Out, or InOut.
// Parameters: (In             ,      In        ,       In        )
//--------------------------------------------------------------------
// DO_07: Complete the function header.
int IndexOfTarget(const string s[], int size, string target)
{
   // DO_08: Complete the function body.
   bool found = false;
   int i = 0;
   while (i < size && !found)
   {
      if (s[i] == target)
      {
         found = true;
      }
      else
      {
         i = i + 1;
      }

      if (found)
      {
         return i;
      }
   }
   return -1; 
}

//--------------------------------------------------------------------
// Function IndexOfMax has two parameters:
//     s[] : an array of type float
//     size: the number of elements in array s[]
// The function returns the index of the first element that has 
//     the largest value among all array elements of s[].
// See the prototype for the parameters
// DO_09: Specify the parameters as In, Out, or InOut.
// Parameters: (         in    ,      in          )
//--------------------------------------------------------------------
// DO_10: Complete the function header.
int IndexOfMax(const float s[], int size)
{
   // DO_11: Complete the function body.
   int i = 0;
   int val;
   int temp = 0; 
   for (i = 0; i < size; i++)
   {
      if (s[i] > temp)
      {
         temp = s[i];
         val = i;
      }
   }
   return val; 
   

}
