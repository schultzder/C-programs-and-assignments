//--------------------------------------------------------------------
//  DO_01: Your Name and Section
//  Name:    Derek Schultz
//                              
//  Course:  CS1430, Section 02 , Spring 2017
//
//  Purpose: Define class Player and 
//           call class methods from main() function
//           Play a game of rock, paper, scissors, lizard, spock, where:
//           Scissors cuts Paper
//           Paper covers Rock
//           Rock crushes Lizard
//           Lizard poisons Spock
//           Spock smashes Scissors
//           Scissors decapitates Lizard
//           Lizard eats Paper
//           Paper disproves Spock
//           Spock vaporizes Rock
//           (and as it always has) Rock crushes Scissors
//           Uses an enum type and a switch statment.
//
//  Inputs:  Player data
//               
//  Outputs: Player data.
//--------------------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


// DO_2: Define an enumerated type named PlayType that has the following
//       members: ROCK, PAPER, SCISSORS, LIZARD, SPOCK
enum PlayType { ROCK, PAPER, SCISSORS, LIZARD, SPOCK };


class Player
{
private:
   string firstName;
   // DO_03: Define a variable of type PlayType named play:
   PlayType play; 
   int gamesWon;

public:
   //-----------------------------------------------------------------
   //Default Constructor
   //-----------------------------------------------------------------
   Player()
   {
	   gamesWon = 0;
   }
   
   // DO_4: Complete the following switch statement.
   // Converts a character into an associate PlayType value.
   // someChar == 'R' or 'P' or 'S' or 'L' or 'K'
   // Returns a PlayType to ProcessPlays based on the value
   // of someChar.
   // Params: in
   PlayType ConvertChoice(char someChar)
   {
	   switch (someChar)
	   {
         case 'R': return PlayType{ ROCK };
         case 'P': return PlayType{ PAPER };
         case 'S': return PlayType{ SCISSORS };
         case 'L': return PlayType{ LIZARD }; 
         case 'K': return PlayType{ SPOCK };
	   }
   }
  
   // This method reads in the player's first name.
   // Params: None
   void ReadName()
   {
      cout << "Enter the player's name: ";
      cin >> firstName;
      cout << endl;

   }

   // Complete method ReadPlay that inputs the player's first Name
   // and play choice. The play is read in as a character, where 'R' is ROCK,  
   // 'P' is PAPER, 'S' is SCISSORS, 'L' is LIZARD, and 'K' is SPOCK.  
   // Declare a char variable and read in the user's play choice into it.  
   // Assumes the user enters a valid response.
   // Call ConvertChoice to convert the user's answer to an associated 
   // PlayType value, returning the value into a variable of type PlayType.
   // Params: None
   void ReadPlay()
   {
	  // DO_5: Define a variable someChar to hold the user's choice.
      char someChar;
	  
      cout << "Enter the player's play choice. " << endl;
      cout << "Choices are 'R' is ROCK, 'P' is PAPER, " << endl;
		cout << "'S' is SCISSORS, 'L' is LIZARD, and 'K' is SPOCK: ";
	  // DO_6: read in the player's play choice into someChar.
     cin >> someChar;
	 
	 cout << endl;
	    
	  // DO_7: Call the method ConvertChoice with an argument of 
      //       someChar, assigning the returned value to the 
	  //       private member play. 
    play = ConvertChoice(someChar);
	  
   }
   
   // Determines whether there is a winning play or a tie. Prints who won
   // and who lost, or if there is a tie.
   // Params: in
   void ProcessPlay(Player & p2)
   {
	  if (play == p2.play)
	     cout << "It is a tie!" << endl;
      else if (play == PAPER && p2.play == ROCK)
      {	  
		 cout << "Paper covers ROCK, " << firstName << " wins!" << endl;
		 gamesWon++;
	  }
	  else if (play == SCISSORS && p2.play == PAPER)
	  {
         cout << "Scissors cuts paper, " << firstName << " wins!" << endl;
	     gamesWon++;
	  }
	  else if (play == ROCK && p2.play == SCISSORS)
	  {
         cout << "Rock crushes Scissors, " << firstName << " wins!" << endl;
         gamesWon++;
	  }		 
	  else if (play == ROCK && p2.play == LIZARD)
	  {
		 cout << "Rock crushes Lizard, " << firstName << " wins!" << endl;
		 gamesWon++;
	  }	
	  else if (play == LIZARD && p2.play == SPOCK)
	  {
		 cout << "Lizard poisons Spock, " << firstName << " wins!" << endl;
		 gamesWon++;
	  }	
	  else if (play == SPOCK && p2.play == SCISSORS)
	  {
		 cout << "Spock smashes Scissors, " << firstName << " wins!" << endl;
		 gamesWon++;
	  }	
	  else if (play == SCISSORS && p2.play == LIZARD)
	  {
		 cout << "Scissors decapitates Lizard, " << firstName << " wins!" << endl;
		 gamesWon++;
	  }	
      else if (play == LIZARD && p2.play == PAPER)
	  {
	     cout << "Lizard eats Paper, " << firstName << " wins!" << endl;
		 gamesWon++;
	  }	
	  else if (play == PAPER && p2.play == SPOCK)
	  {
	     cout << "Paper disproves Spock, " << firstName << " wins!" << endl;
		 gamesWon++;
	  }	
	  else if (play == SPOCK && p2.play == ROCK)
	  {
	     cout << "Spock vaporizes Rock, " << firstName << " wins!" << endl;
		 gamesWon++;
	  }	
	  else if (p2.play == PAPER && play == ROCK)
	  {
		 cout << "Paper covers ROCK, " << p2.firstName << " wins!" << endl;
		 p2.gamesWon++;
	  }	
	  else if (p2.play == SCISSORS && play == PAPER)
	  {
	     cout << "Scissors cuts paper, " << p2.firstName << " wins!" << endl;
		 p2.gamesWon++;
	  }	
	  else if (p2.play == ROCK && play == SCISSORS)
	  {
         cout << "Rock crushes Scissors, " << p2.firstName << " wins!" << endl;		
         p2.gamesWon++;
	  }			 
	  else if (p2.play == ROCK && play == LIZARD)
	  {
		 cout << "Rock crushes Lizard, " << p2.firstName << " wins!" << endl;
		 p2.gamesWon++;
	  }	
	  else if (p2.play == LIZARD && play == SPOCK)
	  {
		 cout << "Lizard poisons Spock, " << p2.firstName << " wins!" << endl;
		 p2.gamesWon++;
	  }	
	  else if (p2.play == SPOCK && play == SCISSORS)
	  {
		 cout << "Spock smashes Scissors, " << p2.firstName << " wins!" << endl;
		 p2.gamesWon++;
	  }	
	  else if (p2.play == SCISSORS && play == LIZARD)
	  {
		 cout << "Scissors decapitates Lizard, " << p2.firstName << " wins!" << endl;
		 p2.gamesWon++;
	  }	
      else if (p2.play == LIZARD && play == PAPER)
	  {
	     cout << "Lizard eats Paper, " << p2.firstName << " wins!" << endl;
		 p2.gamesWon++;
	  }	
	  else if (p2.play == PAPER && play == SPOCK)
	  {
	     cout << "Paper disproves Spock, " << p2.firstName << " wins!" << endl;
		 p2.gamesWon++;
	  }	
	  else if (p2.play == SPOCK && play == ROCK)
	  {
	     cout << "Spock vaporizes Rock, " << p2.firstName << " wins!" << endl;
		 p2.gamesWon++;
	  }	
   }
   
   // Prints the total games won for a player.
   // Params: None
   void PrintStats()
   {
	   cout << firstName << " won " << gamesWon << " game(s)." << endl;
   }
   
};
      
int main() 
{ 
   // DO_08: Create a class Player named p1 and another named p2 using 
   //        the default constructor.
   Player p1;
   Player p2;
    
   char answer = 'Y';
  
   cout << endl;
   // DO_09: Get the players name by calling ReadName() with p1 and p2 .
   p1.ReadName();
   p2.ReadName();
      
   while (answer == 'Y')
   {
      // DO_10: Get player's choices by calling ReadPlay() with p1 and p2.
      p1.ReadPlay();
      p2.ReadPlay();
         
      // DO_11: Play the game by with p1 by calling ProcessPlay(p2).
  
      p1.ProcessPlay(p2);

      cout << "Do you want to play Rock Paper Scissor Lizard Spock? Y for Yes, N for No: " << endl;
      cin >> answer;
   }
   // DO_12: Print the player win stats by calling PrintStats() for p1 and p2.
   p1.PrintStats();
   p2.PrintStats();

   return 0;
}
