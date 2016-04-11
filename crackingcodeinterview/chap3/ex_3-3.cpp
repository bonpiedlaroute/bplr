#include <iostream>
#include <stack>

using namespace std;

#define NUMBER 3


struct SetOfStack
{
private:
   stack<int> MyStack[NUMBER];
   int max_size = 5;
   int current_stack = 0;
   int current[NUMBER] = {0};

public:
   void push( int value)
   {
      if( current[current_stack] == max_size )
      {
         if( (current_stack + 1) == NUMBER )
            return;
         else
            current_stack++;
      }

      MyStack[current[current_stack]].push(value);

      current[current_stack]++;
   }

   int pop()
   {
      if( current[current_stack] == 0 )
      {
         if( current_stack > 0 )
         {
            current_stack--;
            current[current_stack] = max_size;
         }
         else
            return -1;
      }

      --current[current_stack];

      int result = MyStack[current[current_stack]].top();
      
      MyStack[current[current_stack]].pop();

      return result;
   }


   int pop_at_i(int index)
   {

      if( index == current_stack ) 
      {
         return pop();
      }


      int result = MyStack[index].top();
      MyStack[index].pop();


      current_stack = index;
      current[current_stack]= max_size - 1;
      
      stack<int> tmp;

      while(!MyStack[index+1].empty())
      {
         tmp.push(MyStack[index+1].top());

         MyStack[index+1].pop();
      }

      while( !tmp.empty() )
      {
         push(tmp.top());
         tmp.pop();
      }

      return result;
   }

};


int main()
{

   return 0;
}
