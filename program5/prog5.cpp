/*
Name: John Talton
Class: CS120
Prog5.cpp   

This program takes in two matricis preformes addition
subtractoin and multiplication, along with the 
mminimum value and the maximum value in the matrixes
´¯`·.¸¸.·´¯`·.¸¸.·´¯`·-{¥NÖP}-·´¯`·.¸¸.·´¯`·.¸¸.·´¯`  
*/
#include <iostream.h>
                                                
const maxsize = 10;                                                
                                                
void init_matriz(int mat1[][maxsize], int mat2[][maxsize]);
void input_matrix(int mat1[][maxsize], int mat2[][maxsize], int& size);  
void output(int mat1[][maxsize], int mat2[][maxsize], int size,
            int answer[][maxsize], char operation);
void menu(int& option);
void add_matrix(int mat1[][maxsize], int mat2[][maxsize],
                int size, int answer[][maxsize]);
void sub_matrix(int mat1[][maxsize], int mat2[][maxsize],
                int size, int answer[][maxsize]);
void mult_matrix(int mat1[][maxsize], int mat2[][maxsize],
                 int size, int answer[][maxsize]);
void matrix_min(int mat1[][maxsize], int mat2[][maxsize],
                int size, int answer[][maxsize]);
void matrix_max(int mat1[][maxsize], int mat2[][maxsize],
                int size, int answer[][maxsize]);

void main()
{
   int 
      mat1[maxsize][maxsize],// the first matrix
      mat2[maxsize][maxsize],// the second matrix
      answer[maxsize][maxsize],// var to hold answers
      size = 0,              // working size of matrix
      option = 0;            // menu control
   char
      op = ' ';              // operation controler
   input_matrix(mat1, mat2, size); // input size and matrix values
   while(op != 'x')          // loop menu while the op code is not exit (x) 
   {
      menu(option);          // print menu, returen selection
      switch(option)
      {
         case 0:
         {
            break;
         }
         case 1:             // add matrix and set op code to +
         {
            add_matrix(mat1,mat2,size,answer);
            op = '+';
            break;
         }
         case 2:             // subtract matrix and set op code to -
         {
            sub_matrix(mat1,mat2,size,answer);
            op = '-';
            break;
         }
         case 3:             // mult matrix and set code to *
         {
            mult_matrix(mat1,mat2,size,answer);
            op = '*';
            break;
         }
         case 4:             // find min of matrix, set code l
         {
            matrix_min(mat1,mat2,size,answer);
            op = 'l';        // code for lowest                
            break;
         }
         case 5:             // find max of matrix, set code l
         {
            matrix_max(mat1,mat2,size,answer);
            op = 'h';        // code for high
            break;
         }
         case 6:            // kill or exit all with a goodbye message
         {
            op = 'x';       // kill code
            break;
         }
      }
      output(mat1,mat2,size,answer,op);// output aproprat values
   }// end while
}//end main   
/*
pre: mat1 and mat2 are pased and two dimentional arrays
post: mat1 and mat2 contain valid matircis or square size size
*/
void input_matrix(int mat1[][maxsize], int mat2[][maxsize], int& size)               
{
   cout << "Please input the square size of the matrix:  ";
   cin >> size;
   cout << "Enter the first matrix:  \n";
   for(int a = 1; a < size; a++)
   {
      for(int b = 1; b < size; b++)
      {
         cin >> mat1[a][b];
      }
   }
   cout << "Enter the secoud matrix:  \n";
   for(int c = 1; c < size; c++)
   {
      for(int d = 1; d < size; d++)
      {
         cin >> mat2[c][d];
      }
   }
}
/*
pre: mat1 mat2 size answer and operation are valid format
post: if ioeration is + - * then the two matrix are printed
      along with the answer else the max or min is printed.
      if operation is the exit charicter 'x' then say goodbye to
      user and exit
*/
void output(int mat1[][maxsize], int mat2[][maxsize], 
            int size, int answer[][maxsize], char operation)
{
   // if adding subtracting or multipling print out mat1, mat2, answer   
   if((operation == '+') || (operation == '-') || (operation == '*'))
   {   
      for(int a = 1; a < size; a++)
      {   
         cout << "\n";         
         for(int b = 1; b < size; b++)
         {
            cout << mat1[a][b];
            if((b == size - 1) && (a == (size / 2)))
            {
               cout << " " << operation << " "; // print out +, -, *
            }           
            else if(b == size - 1)
            {              
               cout << "   ";
            }
            else
            {
               cout << " ";
            }
         }
         for(int c = 1; c < size; c++)
         {
            cout << mat2[a][c];
            if((c == size - 1) && (a == (size / 2)))
            {
               cout << " = "; 
            }           
            else if(c == size - 1)
            {              
               cout << "   ";
            }
            else
            {
               cout << " ";
            }
         }
         for(int d = 1; d < size; d++)
         {
            cout << answer[a][d];
            cout << " ";
         }
      } 
      cout << '\n';
   }   
   else if(operation == 'h') // the max value
   {
      cout << "\nThe max value is " << answer[maxsize][maxsize] << '\n';
   }
   else if(operation == 'l') // the min value
   {
      cout << "\nThe minimum value is " << answer[0][0] << '\n';
   }
   else if(operation == 'x') // Exit code 
   {
      cout << "\nSee you later!";
   }
}
/*
pre: option is integer.
post: prints out menu on screen and waits for valid input
      form user, returns users seclection
*/
void menu(int& option)
{
   option = 0;
   while(!((option > 0) && (option < 7)))
   {  
      cout << "\n1...Add the two Matrix\n";
      cout << "2...Subtract the two Matrix\n";
      cout << "3...Multiply the two Matrix\n";
      cout << "4...Find the Minimum value in the Matrix\n";   
      cout << "5...Find the Maximum value in the Matrix\n";
      cout << "6...Exit Program\n";
      cout << "\nEnter a number 1 - 6  ";
      cin >> option;
   }
}
/*
pre: mat1 and mat2 are valid matrix of size 'size'
post: the addition of mat1 and mat2 is stored
      in answer.
*/
void add_matrix(int mat1[][maxsize], int mat2[][maxsize], 
                int size, int answer[][maxsize])
{
   for(int a = 1; a < size; a++)
   {   
      for(int b = 1; b < size; b++)
      {
         answer[a][b] = mat1[a][b] + mat2[a][b];
      }
   }
}
/*
pre: mat1 and mat2 are valid matrix of size 'size'
post: the subtraction of mat1 and mat2 is stored
      in answer.

*/
void sub_matrix(int mat1[][maxsize], int mat2[][maxsize],
                int size, int answer[][maxsize])
{
   for(int a = 1; a < size; a++)
   {
      for(int b = 1; b < size; b++)
      {
         answer[a][b] = mat1[a][b] - mat2[a][b];
      }
   }
}
/*
pre: mat1 and mat2 are valid matrix of size 'size'
post: the multiplication of mat1 and mat2 is stored
      in answer.
*/
void mult_matrix(int mat1[][maxsize], int mat2[][maxsize],
                 int size, int answer[][maxsize])
{
   int sum;
   
   for(int a = 1; a <= size; a++)
   {
      for(int b = 0; b <= size; b++);
      { 
         sum = 0;   
         for(int c = 0; c <= size; c++)
         {
            sum = sum + (mat1[b][c] * mat2[c][a]);
         }
         answer[b][a] = sum;
      }
   }      
}
/*
pre: mat1 and mat2 are valid matrix of size 'size'
post: the minimum value in mat1 and mat2 is stored
      in answer[0][0].
*/
void matrix_min(int mat1[][maxsize], int mat2[][maxsize], 
                int size, int answer[][maxsize])
{
   int min = 32000;          // max value 
   
   for(int a = 1; a < size; a++)
   {   
      for(int b = 1; b < size; b++)
      {
         if(mat1[a][b] < min)
         {
            min = mat1[a][b];
         }
         if(mat2[a][b] < min)
         {
            min = mat2[a][b];
         } 
      }
   }
   answer[0][0] = min;       
}
/*
pre: mat1 and mat2 are valid matrix of size 'size'
post: the maximum value in mat1 and mat2 is stored
      in answer[10][10].
*/
void matrix_max(int mat1[][maxsize], int mat2[][maxsize], 
                int size, int answer[][maxsize])
{
   int max = 0;
   
   for(int a = 1; a < size; a++)
   {   
      for(int b = 1; b < size; b++)
      {
         if(mat1[a][b] > max)
         {
            max = mat1[a][b];
         }
         if(mat2[a][b] > max)
         {
            max = mat2[a][b];
         } 
      }
   }
   answer[maxsize][maxsize] = max;
}