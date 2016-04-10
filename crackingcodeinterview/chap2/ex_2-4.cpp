#include <forward_list>

using namespace std;


forward_list<int> add_two_numbers(forward_list<int> list1, forward_list<int> list2)
{
   int operand1 = 0, operand2 = 0, result = 0;
  
   for(int d : list1)
   {
      operand1 = d + operand1 * 10;
   }

   for(int d : list2)
   {
      operand2 = d + operand2 * 10;
   }

   result = operand1 + operand2;

   forward_list<int> sum;

   while( result > 0 )
   {
      sum.push_front(result%10);
      result /= 10;
   }

   return sum;
}

int main()
{

   return 0;
}
