//list.cpp
#include "List.h"
#include <iostream.h>

   List::List()
   {
   
   }  
   
   void List::clear() 
   {
      cursize = 0;
   }
   
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
   
   int List::removeLastItem() 
   {
      cursize = cursize - 1;
      if((cursize + 1) != 0)
         return items[cursize + 1];
      else
      {
         op = 1;
         return 0;
      }
   }     
   
   void List::printList()
   {
      for(int i = 1;i < cursize;i++)
      {
         cout << items[i] << "  ";
      }
   }
   
   
   int List::empty()
   {
      if(cursize == 0)
         return 1;
      else 
         return 0;
   }
   
   int List::full()
   {
      if(cursize == maxSize_ - 1)
         return 1;
      else
         return 0; 
   }
   
   void List::sort()
   {
   
   }
   
   void List::someshit()
   {
   
   }
   
                
                              
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
   }    
   


