#include <iostream>
#include <stack>

using namespace std;

template <typename T>
class MyQueue
{
private:
   stack<T> in;
   stack<T> out;

public:
   void push_back(T value)
   {
      while( ! out.empty() )
      {
         in.push(out.top());
         out.pop();
      }
   
      in.push(value);
   }

   T pop_front()
   {
      while( ! in.empty() )
      {
         out.push(in.top());
         in.pop();
      }

      T result = out.top();

      out.pop();
      
      return result;
   }
};

template class MyQueue<int>;

int main()
{

   return 0;
}
