/*
Name: John Talton
Class: CS120

This program calculats the aproximit value of "r" for the 
equation:              
         n
   A * R^  - P = 0
   
The user inputs the valuse of A,N and P. Then the user 
inputs a high (positive) and low (negative) gess of the 
value for R. Using the midpoint of R1 and R2 the computer
calculats a value of R.    
´¯`·.¸¸.·´¯`·.¸¸.·´¯`·-{¥NÖP}-·´¯`·.¸¸.·´¯`·.¸¸.·´¯`  
*/
#include <iostream.h>
#include <iomanip.h>

float power(float num, int pow);    // function to raise 'num' to the power of 'pow'

void main(void)  // the main program, returning nothing
{
   int
      A = 0,    // the A or Amount value, user input
      P = 0,    // the Payment value, user input
      n = 0;    // the Number of years, user input
   float 
      r = 0,   // the rate to solve for
      r1 = 0,  // temp rate value, positive
      r2 = 0;  // another temp rate value, negative

   cout << "\nSolving for the equation A*R^N-P = 0\n";// statment of eq to solve
   cout << "\nEnter ther A or Q to Quit.  ";          // normal user prompt
   cin >> A;                                // enter the A value
   if(A == 0)                               // If non number cin retunes 0
   {
      cout << "See you later "; // a genaric goodbye statment, got to be nice
   }
   else
   {
      cout << "\nEnter Payment  ";          // user prompt
      cin >> P;                             // user input, P 
      cout << "\nEnter Number of Years  ";  // user prompt
      cin >> n;                             // user input, n
      cout << "\nEnter you first guess for the rate, positive number "; // user prompt
      cin >> r1;                            // user input, r1
      cout << "\nEnter you second guess for the rate, negative number  ";// user prompt
      cin >> r2;                            // user input, r2
      while ((r1-r2) > 0.01)                // loop to control acuracy of answer
      {  
         r = (r1 + r2) / 2;                 //  to find midpoint of r1 & r2
         if (((A * power(r,n)) - P) < 0)    // test of how close to gess is 
         { 
            r2 = (r1 + r2) / 2;             // if lessthat 0 than r2 is set to midpont
         }
         else 
         {
            r1 = (r1 + r2) / 2;             // if greaterthat 0 than r1 is set to midpont
         }
      }   
      cout << "\nYou entered " << A << " for Annuity"; // echo inputs
      cout << "\nYou entered " << P << " for the Payment";//echo imputs
      cout << "\nThe Calculated Rate is : " << r << '\n'; // print results out
      cout << endl;                         // end output stream
   }                                        // end if 
}                                           // end main
float power(float num,int pow)              // power function
{
/*
pre:  num and pow are valid float and integer values
post: returens the value of 'num' raised to the power of 'pow'
*/
   float prod = 1;
   for(int i=1; i <= pow; i++)              // repetitive loop
   {                                                          
         prod = num * prod;                 // calculation
   }            
   return prod;                             // return value
}