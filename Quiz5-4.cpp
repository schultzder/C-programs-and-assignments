//------------------------------------------------------------------------
// DO_1: fill in your name and section
// Name:    Derek Schultz 
//
// Course:  CS 1430, Section 2
//
// Purpose: Write a program to manage employees, where you can calculate
//          wages and print a paycheck. 
//
// Input:   Three employee's information.
//
// Output:  A list of employees with their pay.
//------------------------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Employee
{
   // DO_2: write the keyword to determine the scope for data members.
   //       Data members are only accessible within the class.	
private:
   int id;
   string name;
   float  payRate;
   float  hours;
   float  wages;
 
   // Member functions declared after the public keyword are accessible
   // outside of the class.
public:
  
   //-------------------------------------------------------------------
   //  Default Constructor. Initializes an employee with an id of 999,
   //  a name  JaneDoe, payRate = 10.00, hours = 20, and wages are 0.
   //-------------------------------------------------------------------
   // DO_3: Finish this default constructor.
   Employee()
   {
      id = 999;
      name = "JaneDoe";
      payRate = 10.00;
      hours = 20;
      wages = 0;
   }

   //-------------------------------------------------------------------
   //  Constructor that  creates an employee using an id, name,
   //  payrate, and hours. Use a value of 0 for wages.
   //  param: (in, in, in, in, in)
   //-------------------------------------------------------------------
   // DO_4: Finish this constructor
   Employee(int inId, string inName, float inPayRate, float inHours)
   {
      id = inId;
      name = inName;
      payRate = inPayRate;
      hours = inHours;
      wages = 0;
   }
   
   //-------------------------------------------------------------------
   // This method reads in an employee.
   // param: ()
   //-------------------------------------------------------------------
   void Read()
   {
      cin >> id >> name >> payRate >> hours;
   }

   //---------------------------------------------------------------------
   // Calculate the salary of the employee.
   // Params: (none)
   //---------------------------------------------------------------------
   void  CalcSalary()
   {
      // DO_5: calculate the wages based on payRate and hours. 
      //
      wages = payRate * hours;
   }

   //---------------------------------------------------------------------
   // Print out an employee's info.
   // Params: (none)
   //---------------------------------------------------------------------
   void PrintPayCheck()
   {
      cout << "Employee ID : " << id << endl << "Name : " << name << endl
         << "Pay rate: " << "$" << payRate << endl << "Hours: " << hours
         << endl << "Wages: " << "$" << wages << endl << endl;
   }
};

//---------------------------------------------------------------------
// main() creates a instances of employees and handles the input
// commands. It calls the proper methods based on the input.
//---------------------------------------------------------------------
int main()
{
   cout << fixed << showpoint << setprecision(2);

   // DO_6: create a new Employee class called employee1 using the 
   //       default constructor.
   Employee employee1;
   // Create a new employee with a set of values
   Employee employee2(1234, "JohnDoe", 12.50, 36);

   
   // DO_7: Create a new employee object named employee 3 using the 
   //       default constructor. 
   Employee employee3;
   
   //Do_8: Read in values for a new Employee object named employee3.
   employee3.Read();
   
   //DO_8: Calculate the wages for all three employees. You must use
   //      three separate assignment statements.
   employee1.CalcSalary();
   employee2.CalcSalary();
   employee3.CalcSalary();

   
   

   //DO_10: Print info for all three employees. You must use
   //      three separate assignment statements.
   employee1.PrintPayCheck();
   employee2.PrintPayCheck();
   employee3.PrintPayCheck();



   return 0;
}