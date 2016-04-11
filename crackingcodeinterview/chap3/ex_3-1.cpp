#include <iostream>


#define NUMBER 3

#define SIZE   1000


int MyStack[NUMBER * SIZE];
int current[NUMBER] = {0};


bool IsEmpty(int num);


void push(int num, int value)
{
   if( current[num] < SIZE )
   {
      MyStack[num * SIZE + current[num]] = value;
      current[num]++;
   }

}



int pop(int num)
{
   if( (current[num] - 1) >= 0 )
   {
      current[num]--;
      return MyStack[num * SIZE + current[num]];
   }
   else
   {
      return -1;
   }
}

int peek(int num)
{
   if(! IsEmpty(num) )
      return MyStack[num*SIZE + current[num] - 1];
   else
      return 0;
}

bool IsEmpty(int num)
{
   return current[num] == 0;
}

int main()
{

   return 0;
}
