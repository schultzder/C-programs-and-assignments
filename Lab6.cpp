//---------------------------------------------------------------------
// DO: 1. Fill in your name 
// Name:   Derek Schultz
// DO: 2. Fill in your section number
// Course:  CS 1430, Section 2, Spring 2017
//
// Purpose: This program reads numbers and either classifies them as
//          prime or prints their prime divisors.  The program quits 
//          when the user enters a number less than the First Prime, 
//          which is 2.
//
// Input:   A list of integers, terminated by a number <= 1.
//
// Output:  For each input number
//              Display a message if the input number is a prime.
//              Print all prime divisors if the input number is not
//              prime.
//
//---------------------------------------------------------------------

#include <iostream>
#include <cmath>	// cmath is needed for the sqrt() function
using namespace std;

const int FIRST_PRIME = 2;
const int DIVISOR_TWO = 2;

// DO: 3. Complete the prototype for IsPrime.
//        HINT: See function definition below.
bool IsPrime(int number);

bool IsAPrimeDivisor(int candidate, int number);

// DO: 4. Complete the prototoype for PrintPrimeDivisors.
//        HINT: See the function definition below and 
//              the call to the function in main().
void PrintPrimeDivisors(int number);

int main()
{
   int number;

   cout << "Enter a number: ";
   cin  >> number;
   cout << endl;
   
   while( number >= FIRST_PRIME )
   {
      // DO: 5. Complete the NEXT line by adding a call to
      //        the IsPrime function.
      //        HINT:  Look at the function definition for
      //               the parameter. Also look at the return
      //               for IsPrime() for use in the If 
      //               conditional.    
      if(IsPrime(number))
         cout << number << " is prime." << endl;
      else 
      {
         cout << "Prime divisors of " << number << ":" << endl;
         PrintPrimeDivisors(number);
      }

      cout << endl;
      cout << "Enter a number: ";
      cin  >> number;
      cout << endl;
   }  // End of while loop

   cout << endl;
   cout << "Completed processing!";

   return 0;
} // End of main()


// IsPrime: returns true if given number is prime, false otherwise.
//          Note: a number is prime if no value between 2 and
//                the square root of the number is a factor.
// Parameter: (in)
bool IsPrime( int num )
{
   int limit;

   // DO: 6. Complete the next line by calling the sqrt(int) function 
   //		 from <cmath> to find the largest number that needs to
   //		 be examined, and the number is the square root of "num".
   limit = int(sqrt(num));

   int count = FIRST_PRIME;
   while( count <= limit )
   {
      if( num % count == 0 )
         return false;  // num is not prime!
      count++;
   }
   return true;			// num is prime!
} // end of IsPrime()



//
// IsAPrimeDivisor: returns IF candidate divides number evenly
//                  AND candidate is prime, then return true;
//                  OTHERWISE the candidate is not prime 
//                  then the function returns false.
// Hint: make the first parameter to be the "candidate" and the second
//       to be the "number", return whether the "candidate" divides 
//       "number" evenly AND "candidate" is a prime, you need to use 
//       LOGICAL AND "&&" here.
// Parameters: (in, in)
// DO: 7A. Complete the following function header
//        so it matches its specification.
bool IsAPrimeDivisor(int canidate, int number)
{
   if (number % canidate == 0 && IsPrime(canidate) == true)

      // DO: 7B. Complete the following function code so it matches 
                // the function's specification, see the hint above. //

   {
      return (true);
   }
   else return (false);

} // end of IsAPrimeDivisor()


// DO: 8-10. Complete the following function definition 
//        using the following pseudocode:
// 
//        for each value between FIRST_PRIME and half of the
//              <target>, which we refer to as the <limit>, (inclusive)
//
//           if the value Is A Prime Divisor of the target
//              print the value followed by a space
//        print an endl (end of line marker)
//
// Note that this is a count-controlled loop problem.
// Be sure you call IsAPrimeDivisor() in the if statement.
//
// PrintPrimeDivisors: find and print the prime divisors of target
// Parameter: (in)
void PrintPrimeDivisors(int target)
{
   int limit = target / DIVISOR_TWO;

   int primeCandidate  = FIRST_PRIME;

   while( primeCandidate  <= limit )
   {
      // DO: 8. Complete the if condition as described above 	
      if (IsAPrimeDivisor(primeCandidate, target))
      {
         // DO: 9. Complete the cout as described above.
         cout << primeCandidate << " ";
      }
      // DO: 10. increment the loop counter.
      
      primeCandidate++;
   } // end of for loop

   cout << endl;

} // end of PrintPimeDivisors() function
  
