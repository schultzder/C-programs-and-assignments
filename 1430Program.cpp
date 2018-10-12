//------------------------------------------------------------------------
//
// Name:    Sam Shay, Derek Schultz 50/50
//
// Course:  CS 1430, Section 
//
// Purpose: Keep track of a bank record for three diffrent banks.
//          Each bank object has several arrays that has account numbers, 
//          passwords, amount of money in the bank. 
//
// Input:   Inputs include the bank ID, a command, account number,
//          their password.
//
// Output:  The output will display messages given the typed command. 
//          For example if command 'A' were typed then the program would 
//          output "1132: Account added for 125-424. 
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

const int MAX_ACCOUNTS = 5;
const int ACCOUNT_WIDTH = 10;
const int BALANCE_WIDTH = 11;
const double BASIC_INTEREST = 0.001;
const double NOW_INTEREST = 0.0015;
const double MONEY_INTEREST = 0.002;
const double PREMIER_INTEREST = 0.0035;
const int ID_BANK1 = 1132;
const int ID_BANK2 = 3763;
const int ID_BANK3 = 6741;
enum AccountType { BASIC, NOW, MONEYMARKET, PREMIER };


//------------------------------------------------------------------------
// The start of the class called "Bank"
//------------------------------------------------------------------------
class Bank
{
   //---------------------------------------------------------------------
   // Private members include three arrays, an enumerated type,
   // and an int that keeps track of the number of accounts.
   //---------------------------------------------------------------------
private:
   string accounts[MAX_ACCOUNTS];
   string passwords[MAX_ACCOUNTS];
   double balances[MAX_ACCOUNTS];
   AccountType types[MAX_ACCOUNTS];
   int numAccounts;
   //---------------------------------------------------------------------
   // Start of public members
   //---------------------------------------------------------------------
public:
   //---------------------------------------------------------------------
   // Default constructor
   //---------------------------------------------------------------------
   Bank()
   {
      accounts[MAX_ACCOUNTS];
      numAccounts = 0;
   }
   //---------------------------------------------------------------------
   // Find method, finds a string in the array "account"
   // params: (in)
   //---------------------------------------------------------------------
   int Find(string account)
   {
      for (int i = 0; i < numAccounts; i++)
      {
         if (accounts[i] == account)
            return i;
      }
      return -1;
   }
   //--------------------------------------------------------------------
   // Add Method, cin's account, password, and bank type, then adds
   // the values to their respective arrays. 
   // Writes a message afterwords. 
   //--------------------------------------------------------------------
   void Add()
   {
      string account, password;
      char bankType;

      cin >> account >> password >> bankType;

      int index = Find(account);

      if (index >= 0)
      {
         cout << " Account already exists for " << account << endl;
      }
      else if (numAccounts < MAX_ACCOUNTS)
      {
         SetAccountType(numAccounts, bankType);
         accounts[numAccounts] = account;
         passwords[numAccounts] = password;
         balances[numAccounts] = 0.000;
         numAccounts++;
         cout << " Account added for " << account << endl;
      }
      else
      {
         cout << " Can't handle any more accounts" << endl;
      }
   }
   //---------------------------------------------------------------------
   // SetAccountType method is sent an index for the type array as well
   // as a char to determine which bank type the account is. Uses a 
   // switch statment with cases 'N', 'M', and 'P'. If the char type
   // is neither of these cases, it uses a default case which sets it
   // to BASIC. 
   // params: (in/in)
   //---------------------------------------------------------------------
   void SetAccountType(int index, char type)
   {
      switch (type)
      {
         case 'N':
            types[index] = NOW;
            break;
         case 'M':
            types[index] = MONEYMARKET;
            break;
         case 'P':
            types[index] = PREMIER;
            break;
         default:
            types[index] = BASIC;

      }
   }
   //---------------------------------------------------------------------
   // Deposit method cin's account, password, and amount. Checks to see 
   // if the password is correct, and then continues to deposit the 
   // amount. Updates the array balances[]. 
   //---------------------------------------------------------------------
   void Deposit()
   {
      string account, password;
      double amount;
      int index;

      cin >> account >> password >> amount;

      index = Find(account);

      if (index < 0)
      {
         cout << " No deposit - No account for " << account << endl;
      }
      else if (password != passwords[index])
      {
         cout << " No deposit - Incorrect password for " << account
            << endl;
      }
      else
      {
         balances[index] = balances[index] + amount;
         cout << " Deposit of " << "$" << amount << " for "
            << account << endl;
      }
   }
   //---------------------------------------------------------------------
   // Withdrawl method cin's account, password, and amount. If the 
   // ammount typed in is more than whats in the balances array, the 
   // function withdrawls all the money. Otherwise it subtracts the 
   // amount from the total.
   //---------------------------------------------------------------------
   void Withdrawl()
   {
      string account, password;
      double amount;
      int index;

      cin >> account >> password >> amount;

      index = Find(account);

      if (index < 0)
      {
         cout << " No withdrawal - No account for "
            << account << endl;
      }
      else if (password != passwords[index])
      {
         cout << " No withdrawal - Incorrect password for "
            << account << endl;
      }
      else if (balances[index] < amount)
      {
         cout << " Not enough in account " << account
            << " - Entire balance given out: " <<
            balances[index] << endl;

         balances[index] = 0.00;
      }
      else
      {
         balances[index] = balances[index] - amount;
         cout << " Withdrawal of " << "$" << amount << " for "
            << account << endl;
      }
   }
   //--------------------------------------------------------------------
   // Remove method removes an account from the bank list. 
   // Prints a message with the balance of the account that was removed.
   //--------------------------------------------------------------------
   void Remove()
   {
      string account;
      int index;

      cin >> account;

      index = Find(account);

      if (index >= 0)
      {
         cout << " Account removed for " << account
            << " - Entire balance" <<
            " given out: " << "$" << balances[index] << endl;

         for (int i = index; i < numAccounts - 1; i++)
         {
            accounts[i] = accounts[i + 1];
            passwords[i] = passwords[i + 1];
            balances[i] = balances[i + 1];
         }
         numAccounts--;

      }
      else
      {
         cout << " Can't remove account " << account
            << " - Account doesn't exist" << endl;
      }
   }
   //--------------------------------------------------------------------
   // The Print method prints out a list of the accounts as well as
   // the current balance in the accounts. 
   // -------------------------------------------------------------------
   void Print()
   {
      cout << " List of Accounts" << endl;
      for (int i = 0; i < numAccounts; i++)
         cout << setw(10) << accounts[i] << setw(11)
         << balances[i] << endl;
   }
   //--------------------------------------------------------------------
   // The intrest method calcualtes the intrest given the accounts bank
   // type. 
   // BASIC = 0.1% | NOW = 0.15% | MONEY MARKET = 0.2% | PREMIER = 0.35%
   //--------------------------------------------------------------------
   void Intrest()
   {
      for (int i = 0; i < numAccounts; i++)
      {
         switch (types[i])
         {

            case 1:
               balances[i] = balances[i] +
                  (balances[i] * NOW_INTEREST);
               break;
            case 2:
               balances[i] = balances[i] +
                  (balances[i] * MONEY_INTEREST);
               break;
            case 3:
               balances[i] = balances[i] +
                  (balances[i] * PREMIER_INTEREST);
               break;
            case 0:
               balances[i] = balances[i] +
                  (balances[i] * BASIC_INTEREST);
               break;

         }
      }
      cout << " Interest added to the accounts" << endl;
   }
}; // End of class



// Function parameter for ProccessCommandForBank
void ProcessCommandForBank(Bank & bank);
//------------------------------------------------------------------------
// Start of main
//------------------------------------------------------------------------
int main()
{
   int bankId;

   Bank bank1, bank2, bank3;

   cout << fixed << showpoint << setprecision(2);
   cin >> bankId;

   while (cin)
   {
      cout << bankId << ":";

      if (bankId == ID_BANK1)
      {
         ProcessCommandForBank(bank1);
      }
      else if (bankId == ID_BANK2)
      {
         ProcessCommandForBank(bank2);
      }
      else if (bankId == ID_BANK3)
      {
         ProcessCommandForBank(bank3);
      }

      cin >> bankId;
   }


   cout << "Normal Termination of Bank Program.";

   return 0;
}
//--------------------------------------------------------------------
// ProcessCommandForBank function is for main. This takes the
// command from main and implements it in a switch statment. 
// The switch statment process the command and then makes calls to
// the methods in the class. 
// params (in)
//--------------------------------------------------------------------
void ProcessCommandForBank(Bank & bank)
{
   char command;
   cin >> command;


   switch (command)
   {
      case 'A':
         bank.Add();
         break;
      case 'D':
         bank.Deposit();
         break;
      case 'W':
         bank.Withdrawl();
         break;
      case 'R':
         bank.Remove();
         break;
      case 'P':
         bank.Print();
         break;
      case 'I':
         bank.Intrest();
   }
}