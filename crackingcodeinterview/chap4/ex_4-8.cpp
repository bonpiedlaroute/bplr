#include <vector>
#include <iostream>

using namespace std;
vector<int> result;



struct Node
{
   int data;
   Node* left;
   Node* right;
};


bool sumup(Node* root, int value, int sum)
{
   if( sum == value )
   {
      result.push_back(-1);
      return true;
   }

   if( root == nullptr )
      return false;     

   result.push_back(root->data);

   sum+= root->data;

   bool res = sumup(root->left, value, sum);
   res |= sumup(root->right, value, sum);

   if( !res )
   {
      result.pop_back();
      return false;
   }
   else
      return true;
}

void print(vector<int>& vec)
{
   for(int val: vec)
   {
      if( val != -1 )
         cout << val;
      else
         cout << "\n";
   }
}

void printallpathto(Node* root,int value)
{
   if( sumup(root, value, 0) )
    {
      print(result);
    }
    else
    {
      cout << " no path sum up to "<< value <<"\n";
    }
}

int main()
{
   
   return 0;
}
