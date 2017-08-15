/*

This program calculates the total cost and miles per gallon 
of a vihicle, based on the miles traveled, fuel consumed,
cost per gallon of fuel, and operating cost per mile.

Input:  The total miles traveled, total fuel consumed,
        unit cost of the fuel, and operating cost per mile.
        
Output: The miles per gallon, total cost of the trip,
        and the cost per mile.
        
´¯`·.¸¸.·´¯`·.¸¸.·´¯`·-{¥NÖP}-·´¯`·.¸¸.·´¯`·.¸¸.·´¯`

*/

#include <iostream.h>
#include <iomanip.h>

int main(void)
{
   
          
   const 
      int Width = 7;                              // the width of output field
      double ConvRate = 1.26;                     // the convertion rate for canadian
         
   cout << "\nPlease enter:\n\tthe total miles traveled,"
        << "\n\tthe gallons of fuel used,"
        << "\n\tthe total cost per gallon of the fuel, and"
        << "\n\tthe operating cost per mile."
        << "\n\t==>";
   
   double
      Miles,                                     // total miles traveled  
      GallonsOfFuel,                             // total gallons used
      UnitFuelCost,                              // fuel cost per gallon
      UnitOperatingCost;                         // operating cost per mile
      
   cin >> Miles >> GallonsOfFuel
       >> UnitFuelCost >> UnitOperatingCost;
   
   
   double
      MPG = Miles / GallonsOfFuel,
      
      TotalFuelCost = UnitFuelCost * GallonsOfFuel,
      
      TotalOperatingCost = UnitOperatingCost * Miles,
      
      TotalTripCost = TotalFuelCost + TotalOperatingCost,
      
      CostPerMile = TotalTripCost / Miles,
      
      TotalCanadianCost = 1.26 * TotalTripCost;
      
   cout << setiosflags(ios::showpoint | ios::fixed)
        << setprecision(2)
        << "\n\tMiles per gallon:            " << setw(Width) << MPG
        << "\n\tTotal cost:                 $" << setw(Width) << TotalTripCost
        << "\n\tCost per mile:              $" << setw(Width) << CostPerMile
        << "\n"
        << "\n\tTotal Cost in Canadian:  CAN$" << setw(Width) << TotalCanadianCost
        << "\n\n";
   
   return 0;
}