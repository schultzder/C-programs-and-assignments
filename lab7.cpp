//---------------------------------------------------------------------
//
// DO_01: Enter your name
// Name:   Derek Schultz
// DO_02: Enter your section
// Course:  CS 1430, Section 2, Spring 2017
//
// Purpose: This program reads a list of watermelon seed spitting
//          scores and computes a few statistics:  the average,
//          the number of spitters who spat far enough to earn a
//          "gold pin", and the number of spitters who earned
//          "silver pin" (but not gold).
//
// Input:   Gold and Silver thresholds
//          A list of non-negative distances
//
// Output:  The number of gold pin winners, the number of silver
//          pin winners, and the average.
//---------------------------------------------------------------------

#include <iostream>
#include <iomanip>
using namespace std;

const int PRECISION = 3;

float Average(float total, int count);

// DO_07: Complete the following prototypes:
void GetThreshold(float & gold_threshold, float & silver_threshold);
void UpdateAverageStats(float next_score, float & total, int & count);
void UpdatePinWinners(float player_score, float gold_threshold, float silver_threshold, int & gold_winners, int & silver_winners);
void PrintStats(float gold_threshold, float silver_threshold, int gold_winners, 
   int silver_winners, float sum, int count);

int main()
{
   float num, gold_threshold, silver_threshold, sum = 0.0;
   int count = 0, silver_winners = 0, gold_winners = 0;
   
   cout << fixed << showpoint << setprecision(PRECISION);
   
   GetThreshold(gold_threshold, silver_threshold);    

   cout << "Enter the scores, end with CNTRL-Z." << endl;
   cin >> num;
   cout << endl;
   while ( !cin.eof() )
   {
      // DO_08: Call UpdateAverageStats to update the sum and count
       UpdateAverageStats(num, sum, count);
      
      // DO_09: Call UpdatePinWinners to update silver_winners,
      //   and gold_winners
       UpdatePinWinners(num, gold_threshold, silver_threshold, gold_winners, silver_winners);

      cin >> num;
   }
      
   PrintStats(gold_threshold, silver_threshold, gold_winners, silver_winners,
              sum, count);           
   return 0;
}
//--------------------------------------------------------------------------
// DO_03: Define the parameters for this function.
// This function gets the thresholds for the gold pin and silver pin from
// the standard input. The thresholds will be used in the main() to decide
// the winners.
// params: (out, out)
//--------------------------------------------------------------------------
void GetThreshold(float & gold_threshold, float & silver_threshold)
{
   cout << "Score needed for Gold Pin: ";
   cin  >> gold_threshold;
   cout << endl;
   cout << "Score needed for Silver Pin: ";
   cin  >> silver_threshold;   
   cout << endl;   
}

//--------------------------------------------------------------------------
// DO_04: 
// Given a total score and the number of scores, this function returns the
// average of all scores, or returns 0 if count is 0.
// params: (in, in)
//--------------------------------------------------------------------------
float Average(float total, int count)
{
   if (count == 0)
   {
      return 0;
   }

   else return (total / count);
}

//--------------------------------------------------------------------------
// DO_05: Complete UpdateAverageStats by filling in its header and copying 
//        it to the prototype declaration above.  
// This function updates the statistics needed to compute the average: it 
// accepts a FLOAT score as input and updates the FLOAT total sum of all 
// numbers and the INTEGER count.  
// params: (in, inout, inout)
//--------------------------------------------------------------------------
void UpdateAverageStats(float next_score, float & total, int & count)
{
   total += next_score;
   ++count;
}

//--------------------------------------------------------------------------
// DO_06: Complete UpdateThresholdStats by filling in the header, copying it 
//        to the prototype declaration above, and writing the function body.  
// This function updates the two counts: the number of gold pin winners and 
// the number of silver pin winners. Each person can win at most one of those
// awards. They win the best award they qualify for. (Assume that gold is 
// better than silver). If they score better than (or equal to) an award, 
// they qualify for that award. It accepts a FLOAT score for this player, 
// a FLOAT score needed to win a silver pin, a FLOAT score needed to win a 
// gold pin, an INTEGER count of silver winners so far and an INTEGER count
// of gold winners so far.
// params: (in, in, in, inout, inout)
//--------------------------------------------------------------------------
void UpdatePinWinners(float num, float gold_threshold, float silver_threshold, int & gold_winners, int & silver_winners)
{
   if (num >= gold_threshold)
   {
      gold_winners++; 
   }

   else if (num < gold_threshold && num >= silver_threshold)
   {
      silver_winners++;
   }
   
}

//--------------------------------------------------------------------------
// This function outputs the number of gold pin winners based on the gold
// threshold, the number of silver pin winners based on the silver threshold
// , and the average distance of all scores.
// params: (in, in, in, in, in, in)
//--------------------------------------------------------------------------
void PrintStats(float gold_threshold, float silver_threshold, 
               int gold_winners, int silver_winners, float sum, int count ) 
{
   cout << "Gold Level   : " << gold_winners  << " awards (" << gold_threshold 
                            << ") feet" << endl;
   cout << "Silver Level : " << silver_winners << " awards (" << silver_threshold
                            << ") feet" << endl;     
   cout << "Average      : " << Average(sum, count) 
                             << "  feet" << endl;
}
