//------------------------------------------------------------------------
//
// Name:    Derek Schultz
//
// Course:  CS 1430, Section 2
//
// Purpose: A program of UWP Tristate Sales that post-processes batch data for one day of sales
//
// Input:   The input will consist of a sting representing the name of the custmor
//          A string representing the home state of the customer
//          List of purchased items, which consists of the number of items, price and description
//          
//          Name of customer - as a string
//          State of customer - as a string
//          Number of items - as an int
//          Price - as a float
//          Description - as a string
//
// Output:  The program will output the cutomer's username and state, and a list of itmes in table format.
//          Each line displays the item, number, price, and total. 
//          After the list of itmes, the subtota, sales tax, shipping, and total are displayed. 
//          After the list of items, the subtotal, sales tax, shipping, and total are displayed. 
//          The daily totals will be displayed at the end of all customer data. 
//          The daily totals will consist of the number of customers, total sales, average sales per customer, 
//          total shiping, and the total sales tax of each of WI, IA, and IL. 
//          *NOTE* The total sales does not include sales tax or shipping. 
//          *NOTE* If the number of customers is 0, output 0.00 for average sales. 
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

// Declare all constants //

const int FIELD_WIDTH = 10;

const float pennyValue = 0.01F;
const float fortyNineValue = 49.99F;
const float fityValue = 50.00F;
const float ninityNineValue = 99.99F;
const float hundredValue = 100.00F;
const float doubleShippingCoast1 = 11.00F;
const float doubleShippingCoast2 = 5.00F;



const float WI_SALES_TAX = 0.05F;
const float IA_SALES_TAX = 0.06F;
const float IL_SALES_TAX = 0.0625F;

const float shipping_coast_none = 0.0F;
const float shipping_coast_max = 5.50F;
const float shipping_coast_min = 2.50F;
const float shipping_coast_free = 0.0F;

int main()
{
   cout << fixed << showpoint << setprecision(2);

   // Declare all variables, initializing to zero//

   string userName; 
   string nameOfState;
   
   string nameOfItem;
   int customerCount = 0;

   float taxSum;
   float totalFinal;

   float dailyTotalSales = 0;
   float dailyAverageSalesPerCustomer = 0;
   float dailyTotalShipping = 0;
   float dailyTotalWIsalesTax = 0;
   float dailyTotalIAsalesTax = 0;
   float dailyTotalILsalesTax = 0;
   
   cin >> userName >> nameOfState;
   customerCount++;

   
   // Start of outer while loop //

   while (cin)
   {
      // Initialize values to zero //

     int numberOfItems = 0; 
     float priceOfItem = 0;
     float subtotal = 0;
     float tax = 0;
     float priceSum = 0;
     float shippingCoast = 0;
     
     float taxSum = 0;
     float totalFinal = 0;

     // Output Username and state, input number of items, output Item, Number, Price, and Total//

      cout << userName << " " << nameOfState << endl;

      cin >> numberOfItems;

      cout << setw(FIELD_WIDTH) << "Item" << setw(FIELD_WIDTH) << "Number"
            << setw(FIELD_WIDTH) << "Price" << setw(FIELD_WIDTH) << "Total" << endl;
      
      // Start of inner while loop //

      while (numberOfItems != 0)
      {
         cin >> priceOfItem >> nameOfItem;
        
         cout << setw(FIELD_WIDTH) << nameOfItem << setw(FIELD_WIDTH) << numberOfItems
            << setw(FIELD_WIDTH) << priceOfItem;
        
         priceSum = float(priceOfItem) * float(numberOfItems);
         subtotal = float(subtotal) + float(priceSum);
         cout << setw(FIELD_WIDTH) << float(priceSum) << endl;

        
         
         cin >> numberOfItems;
        
     }

      // IF and ELSE statement to calcualte tax //

      if (nameOfState == "WI")
      
         {
            tax = WI_SALES_TAX;
            taxSum = tax * subtotal;
            dailyTotalWIsalesTax = dailyTotalWIsalesTax + taxSum;

         }

      else if (nameOfState == "IA")
      {
         tax = IA_SALES_TAX;
         taxSum = tax * subtotal;
         dailyTotalIAsalesTax = dailyTotalIAsalesTax + taxSum;

      }

      else if (nameOfState == "IL")
      {
         tax = IL_SALES_TAX;
         taxSum = tax * subtotal;
         dailyTotalILsalesTax = dailyTotalILsalesTax + taxSum;
      }

      else tax = 0;

      // IF and ELSE statements to calculate shipping coast //
      
      if (nameOfState == "WI" || nameOfState == "IL" || nameOfState == "IA")
      {
         if (subtotal == 0)
         {
            shippingCoast = shipping_coast_none;
         }
         else if (subtotal >= pennyValue && subtotal < fityValue)
         {
            shippingCoast = shipping_coast_max;
         }
         else if (subtotal >= fityValue && subtotal < hundredValue)
         {
            shippingCoast = shipping_coast_min;
         }
         else if (subtotal >= hundredValue)
         {
            shippingCoast = shipping_coast_free;
         }
      }
      else

      {
         if (subtotal == 0)
         {
            shippingCoast = (shipping_coast_none);
         }
         else if (subtotal >= pennyValue && subtotal <= fortyNineValue)
         {
            shippingCoast = doubleShippingCoast1;
         }
         else if (subtotal >= fityValue && subtotal <= ninityNineValue)
         {
            shippingCoast = doubleShippingCoast2;
         }
         else if (subtotal >= hundredValue)
         {
            shippingCoast = shipping_coast_free;
         }
         else if (subtotal >= ninityNineValue && subtotal <= hundredValue)
         {
            shippingCoast = doubleShippingCoast2;
         }
      }

     // Calclate total for data set and for daily total //

      totalFinal = subtotal + taxSum + shippingCoast;
      dailyTotalSales = dailyTotalSales + subtotal;

     
      
      
      dailyTotalShipping = dailyTotalShipping + shippingCoast;
      
      // Output Subtotal, Tax, Shipping, and Total //
     
      cout << setw(FIELD_WIDTH) << std::left << "Subtotal:" << setw(FIELD_WIDTH) << std:: right << subtotal << endl;
      cout << setw(FIELD_WIDTH) << std:: left << "Tax:" << setw(FIELD_WIDTH) << std:: right << taxSum << endl;
      cout << setw(FIELD_WIDTH) << std:: left << "Shipping:" << setw(FIELD_WIDTH) << std:: right << shippingCoast << endl;
      cout << setw(FIELD_WIDTH) << std:: left << "Total:" <<  setw(FIELD_WIDTH) << std:: right << totalFinal << endl;
      cout << endl;
      
      // Read in another username and state //


      cin >> userName >> nameOfState; 
      customerCount++;
   }
   cout << endl;
   
   // Daily Totals output //

   dailyAverageSalesPerCustomer = dailyTotalSales / (customerCount - 1);

   cout << "*** Daily Totals ***" << endl;
   cout << "Number of Customers: " << customerCount - 1 << endl;

   cout << "Total Sales: " << dailyTotalSales << endl;
   if (dailyTotalSales == 0)
   {
      cout << "Average Sales per Customer: 0.00" << endl;
   }
   else (cout << "Average Sales per Customer: " << dailyAverageSalesPerCustomer << endl);
   cout << "Total Shipping: " << dailyTotalShipping << endl;
   cout << "Total WI Sales Tax: " << dailyTotalWIsalesTax << endl;
   cout << "Total IA Sales Tax: " << dailyTotalIAsalesTax << endl;
   cout << "Total IL Sales Tax: " << dailyTotalILsalesTax << endl;
   cout << "Normal Termination of UWP Tristate Sales Program." << endl;

   


   return 0;
}