#include <list>
#include <iostream>

using namespace std;


struct Node
{
   int data;
   Node* next;
};



Node* findloopbegining(Node* head)
{
   bool found = false;
   
   if( head == NULL )
      return NULL;

   Node* current = head;
   Node* rapid = head;

   while( rapid->next != NULL && !found )
   {
      current = current->next;
      rapid = rapid->next->next;
   
      if( rapid == NULL )
         return NULL;

      if( current->data == rapid->data )
         found = true;
   }

   if( found )
   {
      current = head;

      while( current->data != rapid->data )
      {
         current = current->next;
         rapid = rapid->next;
      }

      return current;
   }
   else
      return NULL;

}

int main()
{

   return 0;
}
