/*
This program calculats the Greatest Common Divisor (GCD)
for two integers, using the CalcGCD and the DivMod
functions.
        
´¯`·.¸¸.·´¯`·.¸¸.·´¯`·-{¥NÖP}-·´¯`·.¸¸.·´¯`·.¸¸.·´¯`

*/

#include <iostream.h>                                // standerd header file

void InputInt(int & aNumber, const char prompt[]);   // function decleration 
void OutputInt(int aNumber, const char prompt[]);    // function decleration 
void DivMod(int num, int den, int& quo, int& rem);   // function decleration 
void CalcGCD(int i,int j,int & answer);              // function decleration 

void main()                                          // begin main function
{
   int 
      Num_one = 0,                                   // the first integer
      Num_two = 0,                                   // the second integer
      GCD = 0;                                       // the greatest common divisor
         
   InputInt(Num_one,"Input the first number:  ");    // function call of InputInt
   InputInt(Num_two,"\nInput the second number:  "); // function call of InputInt
   CalcGCD(Num_one,Num_two,GCD);                     // function call of CalcGCD
   OutputInt(GCD,"\nThe GCD is:  ");                 // function call of OutputInt
}

void InputInt(int & aNumber, const char prompt[])    // function definition
/*
Pre:  InputInt takes in a valid integer and a valid string of characters      

Post:  Prints out the string to standers output then waits for user input 
       for the variable aNumber.
       
This function is used to prompt the user and to gain one interger value
*/
{
   cout << prompt;                                   // print to standerd output (screen)
   cin >> aNumber;                                   // read in number fom user
}

void OutputInt(int aNumber, const char prompt[])     // function definition
/*
Pre:  OutputInt takes in a valid integer and a valid string of characters      

Post: Prints out the string of characters to standerd output then the value
      in aNumber

This function is used to print out a prompt message and a int value
*/
{
   cout << prompt;                                   // print of standerd output (screen)
   cout << aNumber;                                  // prints var aNumber to screen
}

void DivMod(int num, int den, int& quo, int& rem)    // function definition
/*
Pre:  num,den,quo,rem all all valid integer types
      the var num and den have a valid value in them

Post:  the var quo contains the whole part of the divition
       of num and den (num/den), the var rem contains the 
       remander of the divition of num and den (num%den)
       
This function returns the quotiont and the remander from the 
divition of the two numbers num and den
*/
{
   quo = num / den;                                  // interder divition
   rem = num % den;                                  // mod divition
}

void CalcGCD(int i,int j,int & answer)               // function definition
/*
Pre:  var i,j, and answer are of valid int type
      var i and j contain valid integers.

Post:  var answer contalins the Greatest Common Divison (GCD)
       of the vars i and j

This function finds the (GCD) of the two numbers i and j                          
*/
{
   int 
      whole,          // the whole part of the divition of small and larg
      remander,       // the remander of small and larg
      larg,           // the larger of the two numbers
      small;          // the smaller of the two numbers
              
   if(i > j)          // if statment to determan larg and small number
   {
      larg = i;
      small = j;
   }                  // end if (true)
   else
   {
      larg = j;
      small = i;
   }                  // end else                                 
   do                 // do while loop for repeating if remander is not 0
   {
      DivMod(larg,small,whole,remander);   // call to function DivMod
      if(remander == 0)           // if statment to determant if remander is 0
      {
         answer = small;
      }                           // end if (true)
      else
      {
         small = remander;
      }                           // end else
   }
   while(remander != 0);          // end while
}   


// ---------================----------
// end of GCD program, have a nice day.
// ---------================----------