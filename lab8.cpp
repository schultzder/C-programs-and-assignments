//---------------------------------------------------------------------
// Name: >>>Derek Schultz<<<
// 
// Course:  CS 1430, Section >>>2<<<, Spring 2017
//
// Purpose: This program reads a list of non-negative values and
//          computes and displays the following statistics: the total 
//          numbers of grades, the average, the deviation from the 
//          average, and the number of grades below the average.
//
// Input:   A list of non-negative values started by the number of 
//          grades to be read followed by the grades.
//          
// Output:  The total number of grades, average, standard deviation, 
//          and the number of grades below the average.
//---------------------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

const int PRECISION = 4;
const int NUMSIZE   = 100;


// 5. DO: Complete the following two prototypes 
//        Hint: see headers below.

float Average(const int grades[], int size);
int BelowAverage(const int grades[], int size, float ave);

void Deviation(const int grades[], float ave, int size, float& stanDev); 

int main()
{
   int grades[NUMSIZE];
   float average, standarDeviation;
   int count, belowAverage;
   
   cout << fixed << showpoint << setprecision(PRECISION);

     
   cin >> count;
   for (int i = 0; i < count; i++)
      cin >> grades[i];
       
   // 6. DO: Complete the call to Average to calculate the average of the grades
   //        and store it in variable average.
    
   average = Average(grades, count);

   Deviation(grades, average, count, standarDeviation);
                  
   // 7. DO: Complete the call to BelowAverage to calculate the number  
   //        of grades that are below average, assigning result to belowAverage.

   belowAverage = BelowAverage(grades, count, average);

      // NOTE: DO NOT MAKE **ANY** OTHER CHANGES TO MAIN
      // (That is, make no changes except to call
      //  Average and BelowAverage.)
      
   cout << "Total integers in the array      : " << count << endl ;
   cout << "Average of all array integers    : " << average << endl;
   cout << "Standard deviation of all grades : " << standarDeviation <<  endl;
   cout << "Count of grades below average    : " << belowAverage << endl ;
   return 0;
}

//---------------------------------------------------------------------
// 3. DO: Complete Average so it returns 0 if size is 0 and the average 
//        otherwise.  Hint: you will need to use a loop.
// params: (in, in)
//---------------------------------------------------------------------
float Average(const int grades[],  int size)
{
   float sum = 0;
   

   for ( int i = 0; i < size; i++)
   {
         sum = sum + grades[i];

        
        
   }

   
     

   
    if (size == 0)
   {
      return 0;
   }
    else
    {
       return (sum / size);
    }
    
   
   
   
   
   
}       

//---------------------------------------------------------------------
// 4. DO: Complete the the body of this function.
//    The function is to count the number of values below
//    the average.
//    Don't count numbers which are equal to average.
// params: (in, in, in)
//---------------------------------------------------------------------
int BelowAverage(const int grades[], int size, float ave)                        
{
   int count = 0;
   float sum = 0;
   

   for (int i = 0; i < size; i++)
   {
      sum = (sum + grades[i]);
 
   }

   for (int i = 0; i < size; i++)
   { 
      ave = (sum / size);
      if (grades[i] < ave)
      {
         count++;
      }
     
      

   }

  return count;


}

void Deviation(const int grades[], float ave, int size, float& stanDev)
{
   int i;
   float totalsquares = 0.0;
   float deviate[NUMSIZE]; 
   for (i = 0; i < size; i ++)
      deviate[i] = grades[i] - ave; 
   for (i = 0; i < size; i ++)
      deviate[i] *= deviate[i];
   for (i = 0; i < size; i ++)
      totalsquares += deviate[i];
   if (size == 0)
      stanDev = 0;
   else 
      stanDev = sqrt(totalsquares / size);  
} 

