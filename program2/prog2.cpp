/*

This program calculates the yearly payment on a loan
and prints out a table of the yearly payments

Input:  Rate year and Amount

Output: A table of the Yearly payments

´¯`·.¸¸.·´¯`·.¸¸.·´¯`·-{¥NÖP}-·´¯`·.¸¸.·´¯`·.¸¸.·´¯`

*/

#include <iostream.h>
#include <iomanip.h>
#include <math.h>                                                       
  
double PaymentLoan(double Amount, double RateOfInerest, int Years);    // Definition of function
void InputLoan(double& Amount,double& Rate, int& Years);               // Definition of function 
void OutputPayment(double Payment, double Amount, double Rate, int Year);// Definition of function


      
void main(void)
{
   double 
      Amount,                          // Amount to be barowed
      Rate,                            // The Rate of interest
      Payment = NULL;                  // Yearly payment
   int
      Years,                           // Number of years
      Cur_Year;                        // Temp for the curent year
      
      
   InputLoan(Amount,Rate,Years);      
   OutputPayment(Payment,Amount,Rate,Years);   // Payment NULL, causes Output to print Header     
   
   for(Cur_Year = Years; Cur_Year > 0; Cur_Year--)
   {
      Payment = 12 * PaymentLoan(Amount,Rate,Years);      
      OutputPayment(Payment,Amount,Rate,Cur_Year);
      Amount = Amount - Payment;
   }
      
}


double PaymentLoan(double Amount, double RateOfInterest, int Years)
{
   /*
   pre: Amount is the annual interset of type double
        RateOfInterest is the rate of type double         
        Years is the number of years of type int
   post:
        returns (P) the Payment from the calculation of the three inputs
        
                  AR
         P = -------------
              1-(1+R)^(-Y) 
       
   */
        
   double  P;
   int Months = Years * 12;
   
   P = (Amount * RateOfInterest) / (1 - pow(1 + RateOfInterest,(-1 * Months)));
      
   return P;
}


void InputLoan(double& Amount, double& Rate, int& Years)
{
  /*
  pre:  Amount and Rate are of type double
        Years is of int
  post: Changes the values in amount rate and years
  */
   cout << "Enter the Amount\n";
   cin >> Amount;
   cout << "Enter the rate\n";
   cin >> Rate;
   cout << "Enter the num of years\n";
   cin >> Years;
}


void OutputPayment(double Payment, double Amount, double Rate, int Year)
{
  /*
  pre:  Payment Amount and rate are of type double, year is of int
  post: outputs to screen year amount rate and payment
  */
  if(Payment == NULL)
  {
     cout << "Year | Amount |  Rate | Payment\n"; 
     cout << "--------------------------------\n";
  }
  else
  {
     cout << Year << "    | " << Amount << " | " << Rate << " | " << Payment << "\n";
  }
  
}