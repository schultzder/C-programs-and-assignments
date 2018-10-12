//------------------------------------------------------------------------
// DO_1: fill in your name and section
// Name:    Derek Schultz,  Spring 2017
//
// Course:  CS 1430, Section 02
//
// Purpose: Maintain list of baseball teams by processing commands. Valid 
//          commands are A (Add), D (Delete), P (Print), and S (Sort,  
//          ascending order). Print an error if the command is invalid  
//          and ignore the rest of the command. Add at the end of the  
//          list.  Delete by replacing the team to be deleted with the  
//          last team in the list. Repeat this process until  
//          end-of-file: Use Ctrl-Z in Visual Studio for end-of-file.
//
// Input:   List of commands, some with arguments, terminated by 
//          end-of-file.
//
// Output:  A message is printed when a team is added to the list, 
//          deleted from the list, and sorted.  If the command is not  
//          valid, a message will be printed. If the P command is typed, 
//          the list is sorted in ascending order using the Selection Sort
//          algorithm from the textbook and then printed.
//------------------------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX_TEAMS = 6;
const int TEAM_SPACING = 20;


int Find(const string teams[], int num, string team);

//DO_8: Write the prototype for function Add here
void Add(const string names[], int & num);
void Delete(string teams[], int & num);
void Sort(string teams[], int num);
void PrintNames(const string teams[], int num);


int main()
{
   //DO_2: declare an arrays of strings named "teams" of size MAX_TEAMS
   string teams[MAX_TEAMS];
   int numTeams = 0;
   char command;

   cout << fixed << showpoint << setprecision(2);
   cin >> command;
   
   while (cin)
   {
      //DO_3:  write code to call the function to process a command, 
      //       calling the proper function. Valid commands are 
      //       A, D, P, and S.
      if (command == 'A')
      {
         Add(teams, numTeams);
      }
      else if (command == 'D')
      {
         Delete(teams, numTeams);
      }
      else if (command == 'P')
      {
         PrintNames(teams, numTeams);
      }
      else if (command == 'S')
      {
         Sort(teams, numTeams);
      }
     

      else
      {
         cout << "Bad Command!" << endl;
         cin.ignore(200, '\n');
      }
      cin >> command;
   }

   cout << "Normal Termination of Lab 9." << endl;
   return 0;
}

//------------------------------------------------------------------------
// This function will search for the team in the array teams[]. It will
// return a -1 if it is not found, and the index of the array team if it
// is found.
// params: (in, in, in)
//------------------------------------------------------------------------
int Find(const string names[], int num, string team)
{
   // DO_4: write the body of the Find function. Refer to the comments.
   for (int i = 0; i < num; i++)
   {
      cin >> team;
      if (names[i] == team)
      {
         return i;
      }
      else return -1;
   }
   
}

//------------------------------------------------------------------------
// This function will add a team to the end of the array list if the 
// team is not already in the list, and if the list is not full.
// params: (inout, inout)
//------------------------------------------------------------------------
//DO_5: Complete the function header for the Add function.
void Add(const string names[], int & num)
{
   string team;
   cin >> team;
  
   //DO_6: Call the Find function, saving the result in index.
   int index = Find(names, num, team);
   if (index >= 0)
   {
      cout << team << " is already in the list." << endl;
   }
   else if (num >= MAX_TEAMS)
   {
      cout << team + " wasn't added. List is full." << endl;
   }
   else
   {
      //DO_7: add the team to the end of the array and increment the 
      //      number of members.
      names[index + 1] == team;
      ++index; 
      cout << team + " was added to the list." << endl;
   }
}

//------------------------------------------------------------------------
// This function will delete a team from the array list if the team is 
// in the array. It will replace the team with the last member in the 
// array.
// params: (inout, inout)
//------------------------------------------------------------------------
void Delete(string teams[], int & num)
{
   string team;
   cin >> team;

   //DO_9: Call the Find function, saving the result in index.
   int index = Find(teams, num, team);
   if (index < 0)
   {
      cout << team + " was not removed because it is not in the list." 
           << endl;
   }
   else
   {
      //DO_10: remove the team by replacing it with the last member, and 
      //       decrement the number of members.
      teams[index] == team;
      --index;
      cout << team + " was removed from the list." << endl;
   }
}

//------------------------------------------------------------------------
// Prints the list of teams.
// params: (in, in)
//------------------------------------------------------------------------
void PrintNames(const string teams[], int num)
{
   cout << "The list of teams is:" << endl;
   for (int i = 0; i < num; i++)
      cout << "   " << left << setw(TEAM_SPACING) << teams[i] << endl;
}

//------------------------------------------------------------------------
// This function will sort the list of teams in ascending order, using 
// the Selection Sort algorithm from the text.
// params: (inout, in)
//------------------------------------------------------------------------
void Sort(string teams[], int num)
{
   string temp;
   for (int i = 0; i < num - 1; i++)
   {
      //DO_11: declare mindex and define it 
      int midindex = i;
      for (int j = i + 1; j < num; j++)
      {
         //DO_12: Check to see if the current slot is smaller than mindex
         //       and take appropriate action.
         if (teams[j] < teams[midindex])
         {
            string temp = teams[midindex];
         }
      }
      //DO_13: Swap the array cells at i and mindex.
      teams[midindex] = teams[i];
      teams[i] = temp;

   }
   cout << "List sorted by team." << endl;
}


