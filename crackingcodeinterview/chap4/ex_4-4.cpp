#include <map>
#include <list>

using namespace std;

struct Node
{
   int data;
   Node* left;
   Node* right;
};

map<int, list<int>> result;

void CreateLinkedList(Node* root, int depth)
{
   if( root == nullptr )
      return;

   depth++;

   result[depth] = list<int>();

   result[depth].push_back(root->data);

   CreateLinkedList(root->left, depth);
   CreateLinkedList(root->right, depth);
}

int main()
{

   return 0;
}
