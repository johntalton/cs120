///////////////////////////////////////////////////////////////////////////
//                                                                       //
// John Talton & Billy Krasso                            jta001 & bkr002 //
// Program 6                                   Due 10:59:59 p.m. 2/03/97 //
//                                                                       //
// In this program we displayed a Menu that allowed the user to enter in //
// a nuber, delate a number, print the list, clear the list, and does    //
// something useful that we wanted to do.                                //
//                                                                       //
///////////////////////////////////////////////////////////////////////////

#include <iostream.h>
#include "List.h"

////////////////////////////////////////////////////////////////////////////
//                                                                        //
// Function_Name : List()                                                 //
//                                                                        //
// This is a constructer.                                                 //
//                                                                        //
////////////////////////////////////////////////////////////////////////////
   
   List::List():cursize(0)
   {   } 
    
////////////////////////////////////////////////////////////////////////////
//                                                                        //
// Function_Name : clear()                                                //
//                                                                        //
// This is clears the list.                                               //
//                                                                        //
//////////////////////////////////////////////////////////////////////////// 
  
   void List::clear() 
   {
      cursize = 0;
   }
   
////////////////////////////////////////////////////////////////////////////
//                                                                        //
// Function_Name : add()                                                  //
//                                                                        //
// Inputs : NewItem : This is the item to be added                        //
//                                                                        //
// This is adds a number to the list.                                     //
//                                                                        //
////////////////////////////////////////////////////////////////////////////   
   
   void List::add(int NewItem)
   {
      if(cursize != maxSize_ -1)
      {
         cursize++;
         items[cursize] = NewItem;  
      }
      else
      {
         op = 2;   
      }
   }            
   
////////////////////////////////////////////////////////////////////////////
//                                                                        //
// Function_Name : removeLastItem()                                       //
//                                                                        //
//                                                                        //
// This is removes a number to the list.                                  //
//                                                                        //
////////////////////////////////////////////////////////////////////////////   
   
   int List::removeLastItem() 
   {
    
      trash = items[cursize];
      if((cursize) != 0)  
      {
         cursize = cursize - 1;
         return items[cursize + 1];
      }
      else
      {
         op = 1;
         return 0;
      }
   }     
   
////////////////////////////////////////////////////////////////////////////
//                                                                        //
// Function_Name : printList()                                            //
//                                                                        //
//                                                                        //
// This is prints the list.                                               //
//                                                                        //
////////////////////////////////////////////////////////////////////////////   

   void List::printList()
   {
      for(int i = 1;i < cursize + 1;i++)
      {
         cout << items[i] << "  ";
      }
      cout << '\n';
   }
   
   
////////////////////////////////////////////////////////////////////////////
//                                                                        //
// Function_Name : empty()                                                //
//                                                                        //
//                                                                        //
// This checks to see if list is empty.                                   //
//                                                                        //
////////////////////////////////////////////////////////////////////////////   

   int List::empty()
   {
      if(cursize == 0)
         return 1;
      else 
         return 0;
   }

////////////////////////////////////////////////////////////////////////////
//                                                                        //
// Function_Name : full()                                                 //
//                                                                        //
//                                                                        //
// This checks to see if list is full.                                    //
//                                                                        //
////////////////////////////////////////////////////////////////////////////   
   
   int List::full()
   {
      if(cursize == maxSize_ - 1)
         return 1;
      else
         return 0; 
   }

////////////////////////////////////////////////////////////////////////////
//                                                                        //
// Function_Name : full()                                                 //
//                                                                        //
//                                                                        //
// This checks to see if list is full.                                    //
//                                                                        //
////////////////////////////////////////////////////////////////////////////   

   void List::sort()
   {  
      items[0] = 0;
      for(int i = 2; i < cursize + 1; i++)
      {
         int nextItem = items[i];
         for (int j = i - 1; ((j >=0) && (items[j] > nextItem)); j--)
            items[j + 1] = items [j];
         items[j + 1] = nextItem;
      }
   }  

////////////////////////////////////////////////////////////////////////////
//                                                                        //
// Function_Name : undelate()                                             //
//                                                                        //
//                                                                        //
// This puts what is undelated back into the list.                        //
//                                                                        //
////////////////////////////////////////////////////////////////////////////   
 
   void List::undelete()
   {
      if(trash == 0)
      {
         op = 3;
      }
      else if(cursize != maxSize_ -1)
      {
         cursize++;
         items[cursize] = trash;  
         trash = 0;
      }
      else
      {
         op = 2;   
      }
   }
                              
////////////////////////////////////////////////////////////////////////////
//                                                                        //
// Function_Name : printerror()                                           //
//                                                                        //
//                                                                        //
// This prints the errors.                                                //
//                                                                        //
////////////////////////////////////////////////////////////////////////////   
   
   void List::printerror()
   {
      if(op == 1)
      {
         cout << "Sorry your request to remove the last Item could not\n";
         cout << "be completed due to the lack of a item in the list\n";
         cout << "Sorry, have a nice day.\n";
      }
      if(op == 2)
      {
         cout << "I am terribly sorry but I can not add a item to the\n";
         cout << "list because IT IS FULL!!!!\n";
      }
      if(op == 3)
      {
         cout << "Sorry but you have not deleted anything, or have already\n";
         cout << "undeleted the item, so sorry.\n";
      }
      op = 0; //no error
   }    
          
void main()
{
   List thelist;
   int cont = 1;
   
   while(cont != 0)  
   {
      cout << "1............Clear List\n";
      cout << "2..............Add Item\n";
      cout << "3......Delete Last Item\n";
      cout << "4.........UnDelete Item\n";
      cout << "5.................Print\n";
      cout << "6.........Sort the List\n";
      cout << "0..................Exit\n";
      cin >> cont;
      if(cont > 6 || cont <0)
      {
         cout << "Im sorry Dave, I can not do that!\n"; //2001 ref
      }
      switch(cont)
      {
         case 1:
         {
            thelist.clear();
            break;
         }
         case 2:
         {
            int temp;
             
            cout << "Please enter a number to add to the list now\n";
            cin >> temp; 
            thelist.add(temp);
            //~temp;
            break;
         }
         case 3:
         {
            thelist.removeLastItem();
            break;
         }        
         case 4:
         {
            thelist.undelete();
            break;
         }        
         case 5:
         {
            thelist.printList();
            break;
         }       
         case 6:
         {
            thelist.sort();
            break;
         }
         case 0:
         {        
            cout << "See you Later\n";
            break;
         }
      } 
      thelist.printerror();
   }
}
   