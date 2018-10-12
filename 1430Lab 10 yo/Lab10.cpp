//------------------------------------------------------------------------
// DO_1: fill in your name and section
// Name:    Derek Schultz, Spring 2017
//
// Course:  CS 1430, Section 02
//
// Purpose: Maintain a baseball player list.    
//          Valid commands are A (Add), D (Delete), P (Print), S (Sort)    
//          H (Print highest average), X (Clear list). Process commands 
//          until end-of-file.
//
// Input:   List of commands, some with arguments, terminated by 
//          end-of-file.
//
// Output:  A message is printed when a player is added to the list, 
//          deleted from the list,  the player with the highest batting 
//          average, and when the list is cleared. 
//------------------------------------------------------------------------
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int MAX_ITEM = 6;

class Players
{
   // DO_2: write the keyword to determine the scope for data members.
   //       data members are only accessible within the class.	
private:
   string playerNames[MAX_ITEM];
   string teams[MAX_ITEM];
   float  averages[MAX_ITEM];
   int    numPlayers;

   //---------------------------------------------------------------------
   //  DO_3: This is a helper function that is only accessible within the 
   // class. This method finds a given player in the list; it returns
   // the index if the player is found, otherwise returns -1;
   // Params: (in)
   //---------------------------------------------------------------------
   int Find(string player) const
   {
      for (int i = 0; i < numPlayers; i++)
      {
         if (playerNames[i] == player)
            return i; 
         else return -1;
      }
   }
   
   // Member functions declared after the public keyword are accessible
   // outside of the class.
public:
   //-------------------------------------------------------------------
   // DO_4: finish the default constructor that creates the empty lists.
   // Default Constructor
   //-------------------------------------------------------------------
   Players()
   {
     
 
     
   }

   //---------------------------------------------------------------------
   // Add a player to the list if the list is not full, and the
   // player is not in the cart.
   // If the player exists already, overwrite the old average with the new
   // average in the average list.
   // Params: (none)
   //---------------------------------------------------------------------
   void Add()
   {
      string player;
      string teamName;
      float avg;
      cin >> player >> teamName >> avg;

      int index = Find(player);
      if (index >= 0)
      {
         // DO_5: if the given player exists in the list, update the 
         //      batting average. 
         averages[index] = avg;
         
         cout << playerNames[index] << " average updated to "
              << averages[index] << endl;
      }
      else if (numPlayers >= MAX_ITEM)
      {
         cout << "List is full! Player " 
              << player << " was not added!" << endl;
      }
      else
      {
         // DO_6: add the player info to the end of the list, and increase 
         //       the size by 1.
         playerNames[numPlayers] = player;
         teams[numPlayers] = teamName;
         averages[numPlayers] = avg;
         numPlayers++;
         cout << player << " was added to the list!" << endl;
      }
   } //end of Add()

   //---------------------------------------------------------------------
   // Remove a player from the list if the player is in the list.
   // Params: (none)
   //---------------------------------------------------------------------
   void Delete()
   {
      string player;
      cin >> player;

      int index = Find(player);
      if (index < 0)
      {
         cout << player << " is not in the list!" << endl;
      }
      else
      {
         // DO_7: delete the player by replacing the player with the last 
         //       player in the list, and decrease the size by 1.

         
         
         
         
         cout << player << " was removed!" << endl;
      }
   } //end of Delete()

   //---------------------------------------------------------------------
   // Print out all players in the list.
   // Params: (none)
   //---------------------------------------------------------------------
   void Print() const
   {
      if (numPlayers == 0)
      {
         cout << "List is empty!" << endl;
      }
      else
      {
         cout << endl;
         cout << "Player Name      Team    AVG" << endl;
         cout << "----------------------------------------" << endl;
         for (int i = 0; i < numPlayers; i++)
            cout << setw(17) << playerNames[i]
                 << setw(8) << teams[i]
                 << setw(10) << averages[i] << endl;
      }
      cout << endl;
   }

   //---------------------------------------------------------------------
   // This method clears the list by setting the numPlayers to zero.  
   // Params: (none)
   //---------------------------------------------------------------------
   void Clear()
   {
      // DO_8: Clear the list.	
     
     
   }
   
   //---------------------------------------------------------------------
   // This method sorts the lists in ascending order (A to Z) by playerName.  
   // Params: (none)
   //---------------------------------------------------------------------
   void SortAsc()
   { 
      for (int i = 0; i < numPlayers - 1; i++)
      {
         int mindex = i;
         for (int j = i + 1; j < numPlayers; j++)
         {
            if (playerNames[j] < playerNames[mindex])
               mindex = j; 
         }
         
         // DO_9: Swap the array cells at i and mindex, for all three arrays.
         
        
        
        
        
        
        
        
        
        
        
      }

   cout << "List sorted by player." << endl;
   }
   //---------------------------------------------------------------------
   // This method sorts the list in descending order (highest to lowest)
   // by batting average.
   // Params: (none)
   //---------------------------------------------------------------------
   void SortDesc()
   { 
      for (int i = 0; i < numPlayers - 1; i++)
      {
         int mindex = i;
         for (int j = i + 1; j < numPlayers; j++)
         {
            if (averages[j] > averages[mindex])
               mindex = j; 
         }
         
          // DO_10: Swap the array cells at i and mindex, for all three arrays.
          //        You can use the same code as in DO_9.

          
          
          
          
          
          
          
          
      }
   }
   //---------------------------------------------------------------------
   // Prints out the player with the highest batting average. Assumes the 
   // list has been sorted in descending order on average by SortDesc().
   // Params: (none)
   //---------------------------------------------------------------------
   void PrintHighest()
   {
      if (numPlayers <= 0)
         cout << "The list is empty!" << endl;
      else
         cout << "The player with the highest batting average is "
              << playerNames[0] << " " << teams[0] << " " 
              << averages[0] << endl;
   }
   
};

//---------------------------------------------------------------------
// main() creates an instance of a player list and handles the input
// commands. It calls the proper methods and functions to manage the list.
//---------------------------------------------------------------------
int main()
{
   Players playerList;
   cout << left << fixed << showpoint << setprecision(3);
   
   char command;   
   cin >> command;
   while (cin)
   {
      //DO_11: finish the switch case statement by making the proper
      //       method calls.	
      switch (command)
      {
         'A':
                 
            break;
          'D':
           
            break;
          'P':
            
            break;
          'X':
            
            break;
          'S':
            
            break;
          'H':
           
           
            break;
      }  
      cin >> command;
   }  
   return 0;
}  

