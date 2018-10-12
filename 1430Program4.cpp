//------------------------------------------------------------------------
//
// Name:    Derek Schultz & Sam Shay
//
// Course:  CS 1430, Section 02
//
// Purpose: This program will maintain the inventory for a company. 
// The program will use 5 diffrent command types that will do the following:
//                A - Add command. Add an item to the list along with its coast
//                S - Sell command. Sell an item from the list, as well as delete it from the array
//                P - Print command. Print the inventory list and the total value of everything in the inventory. 
//                O - Order command. Sort the arrays by name using the Selection sort. There is no output for this command.
//                V - Average command. If type is 'C' calcualte and print the average coast of the inventory items. 
//                    If type 'T' then calcualte and print the average number of itmes in the inventory. 
//
// Input:   Set of commands that will alter the inventory list. 
//
// Output:  Print the corresponding output respectivly given the command. 
//------------------------------------------------------------------------
// 
// TODO1: Right-click to the right of the last dash above, select 
//   Guidelines, and then select Add Guideline.  This will place a 
//   Guideline at the end of column 74.  Do not go past it!
//   You can also change the color of the Guideline by right-clicking.
// TODO2: To reformat, click Edit -> Advanced -> Format Document.
//   This will clean up the formatting if you have issues.
//   Then recheck to make sure line lengths are inside the Guidelines.
// The above TODO's assume templates were properly installed as per
// Step 4 of the Visual_Studio_2015_Installation document at:
//     K:\Academic\CSSE\Software\VisualStudo2015_Installation

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
const int MAX_ITEMS = 6;

void AddFunction(const string items[], const int numItems[], const float costItems[], int count, 
   string item, int num, float itemPrice);
void SellFunction(const string items[], const int numItems[], const float costItems[], int count, float & profit);
void DeleteItem(const string items[], const int numItems[], const float costItems[], int & count, string item,
   int num, float itemPrice);
void PrintFunction();
void OrderFunction();
void AverageFunction();
int Find(const string items[], int count, string item);
void AddItem(const string items[], const int numItems[], const float costItems[], int & count, string item, int num,
   float itemPrice);

int main()
{
   cout << fixed << showpoint << setprecision(2) << endl;
   string items[MAX_ITEMS], item;
   int numItems[MAX_ITEMS], num;
   float costItems[MAX_ITEMS], itemPrice;
   char command;
   for (int i = 0; i < MAX_ITEMS; i++)
   {
      items[i] = "None";
      numItems[i] = 0;
      costItems[i] = 0.00;
   }
   cin >> command;
   int count = 0;
   float profit = 0;
   while (!cin.eof())
   {
      if (command == 'A')
      {
         AddFunction(items, numItems, costItems, count, item, num, itemPrice);
      }
      else if (command == 'S')
      {
         SellFunction(items, numItems, costItems, count, profit);
      }
      else if (command == 'P')
      {

      }
      else if (command == 'O')
      {

      }
      else if (command == 'V')
      {

      }
      cin >> command;
   }

   return 0;
}

void AddFunction(const string items[], const int numItems[], const float costItems[], int count, 
   string item, int num, float itemPrice)
{   
   cin >> item, num, itemPrice;
   int index = Find(items, num, item);
   if (index >= 0)
   {
      numItems[index] + num;
      cout << num << item << "(s) added." << endl;
   }
   else
   {
      AddItem(items, numItems, costItems, count, item, num, itemPrice);
   }
}

void SellFunction(const string items[], const int numItems[], const float costItems[], int count, float & profit)
{
   string sellItem;
   int sellNum, num;
   float sellPrice, cost;
   cin >> sellItem, sellNum, sellPrice;
   int index = Find(items, count, sellItem);
   cost = 0;
   if (index >= 0)
   {
      cost = costItems[index];
      num = numItems[index];
      if (sellNum >= num)
      {
         profit = profit + ((sellPrice - cost) * num);
         DeleteItem(items, numItems, costItems, count, sellItem, num, sellPrice);
      }
      else
      {
         numItems[index] == num - sellNum;
         profit = profit + ((sellPrice - cost) * num);
      }
   }
   else
   {
      cout << "Can't sell " << sellItem << ". Not in stock." << endl;
   }
     
}
   


int Find(const string items[], int count, string item)
{
   int i = 0;
   while (i < count && items[i] != item)
   {
      i = i + 1;
      if (i < count)
      {
         return i;
      }
      return -1; 

   }


}

void AddItem(const string items[], const int numItems[], const float costItems[], int & count, string item, 
   int num, float itemPrice)
{
   if (count >= MAX_ITEMS)
   {
      cout << "Item" << item << "not added. No more room for items." << endl;
   }
   else
   {
      items[count] == item;
      numItems[count] == num;
      costItems[count] == itemPrice;
      count++;
   }


}

void DeleteItem(const string items[], const int numItems[], const float costItems[], int & count, string item,
   int num, float itemPrice)
{
   int index;
   items[index] == items[count - 1];
   count = count - 1;
}
   

   