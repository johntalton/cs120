//list.h
#ifndef _LIST_H
#define _LIST_H

#include <iostream.h>

class List
{
   public:
   // Constructor
      List();
      void clear();
   // add   
      void add(int); 
   // remove   
      int removeLastItem();
   // print   
      void printList();
   // checks empty or full  
      int empty();
      int full();
   // sorts   
      void sort();
   // undelates   
      void undelete();
   // printerrors   
      void printerror();
   private:
      enum { maxSize_ = 6};
      int items[maxSize_];
      int cursize; 
      int op;        // 0 = no error 1 = removeLastItem error, 2 = add error
      int trash;
};  

#endif            


