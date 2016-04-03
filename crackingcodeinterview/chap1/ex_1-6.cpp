#include <iostream>

using namespace std;

#define N   4

int result[N][N] = {0};


void rotate_matrix(int matrix[N][N])
{
   for(int i = 0; i < N; ++i)
   {
      for(int j = 0; j < N; ++j)
      {
         result[i][j] = matrix[N-1-j][i];
      }
   }

}


void print( int matrix[N][N])
{
   for(int i = 0; i < N; ++i)
   {
      for(int j=0; j < N; ++j)
      {
         cout << matrix[i][j] << " ";
      }
      cout << "\n";
   }
}
int main()
{
   int matrix[N][N] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};

   print(matrix);

   cout << "\n becomes \n";

   rotate_matrix(matrix);

   print(result);

   return 0;
}  
