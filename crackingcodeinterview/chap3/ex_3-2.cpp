#include <iostream>

#define SIZE 10

int MyStack[SIZE] = {0};
int MinStack[SIZE] = {0};
int current = 0, current_min = 0;


void push(int value)
{
   MyStack[current] = value;
   current++;

   if( MinStack[current_min - 1 ] > value )
   {     
      MinStack[current_min] = value;
      current_min++;
   }
}


int pop()
{
   current--;
   if( MyStack[current] == MinStack[current_min - 1] )
   {
      current_min--;
   }

   return MyStack[current];
}

int min()
{
   return MinStack[current_min-1];
}

int main()
{

   return 0;
}
