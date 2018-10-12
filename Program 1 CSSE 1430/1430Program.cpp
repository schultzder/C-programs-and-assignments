//------------------------------------------------------------------------
//
// Name:    Derek Schultz
//
// Course:  CS 1430, Section 2
//
// Purpose: Wtrie a program to calculate the GPA for four courses. 
//
// Input:   The program will accept inputs in the form of integers for the credits and grades. 
//             grades - as an int
//             credits - as an int
// Output:  The program will provide the semester summary for a given student, including:
//             Total creidts: Whether or not it was a full load
//             GPA: Whether or not the student made the honors list
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

const int fullLoad = 12;
const float honorList = 3.5;

int main()
{
   // Input Variables //

   int course1_credits;
   int course2_creidts;
   int course3_credits;
   int course4_credits;

   int course1_grade;
   int course2_grade;
   int course3_grade;
   int course4_grade;

   int totalCredits;
   int gradePoints;

   float GPA;

   string lastname;


   // Prompt: Enter last name //

   cout << "Enter last name: " << endl;
   cin >> lastname;
   // Prompts: Enter credits and grades //

   cout << "Enter the credits for Course 1: " << endl;
   cin >> course1_credits;
   cout << "Enter the grade for Course 1, where F=0, A=4: " << endl;
   cin >> course1_grade;
   cout << "Enter the credits for Course 2: " << endl;
   cin >> course2_creidts;
   cout << "Enter the grade for Course 2, where F=0, A=4: " << endl;
   cin >> course2_grade;
   cout << "Enter the credits for Course 3: " << endl;
   cin >> course3_credits;
   cout << "Enter the grade for Course 3, where F=0, A=4: " << endl;
   cin >> course3_grade;
   cout << "Enter the credits for Course 4: " << endl;
   cin >> course4_credits;
   cout << "Enter the grade for Course 4, where F=0, A=4: " << endl;
   cin >> course4_grade;



   // Calculations // 

   totalCredits = course1_credits + course2_creidts + course3_credits 
      + course4_credits;

   gradePoints = (course1_credits * course1_grade) + 
      (course2_creidts * course2_grade) + 
      (course3_credits * course3_grade) + 
      (course4_credits * course4_grade);
   
   GPA = float(float(gradePoints) / float(totalCredits));

   
   // Final Output // 

   cout << "Semester summary for "; cout << lastname << endl;
   cout << " Credits: "; cout << totalCredits << endl;
   if (totalCredits >= fullLoad) cout << "  Full Credit Load " << endl;
  
   cout << " GPA: "; cout << GPA << endl;

   if (GPA >= 3.5) cout << "  Honors List " << endl;
  


   cout << "Normal Termination of Program 1." << endl;



   return 0;
}