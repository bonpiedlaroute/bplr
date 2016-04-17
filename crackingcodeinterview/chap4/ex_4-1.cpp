#include <algorithm>

using namespace std;

struct Node
{
   int data;
   Node* left;
   Node* right;
};


int min_depth(Node * head)
{
   if( head == NULL )
      return 0;

   return 1 + std::min(min_depth(head->left), min_depth(head->right));
}


int max_depth(Node* head)
{
   if( head == NULL)
      return 0;

   return 1 + std::max(max_depth(head->left), max_depth(head->right));
}


bool IsBalanced(Node* head)
{
   int min = min_depth(head);
   int max = max_depth(head);

   return (max - min) <= 1 ;
}


int main()
{
   return 0;
}
