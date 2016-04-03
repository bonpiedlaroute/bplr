#include <vector>
#include <iostream>
#include <utility>


using namespace std;

#define M 3
#define N 3


void zero_matrix(int matrix[M][N])
{
   vector<pair<int,int>> list_of_zero;

   for(int i = 0; i < M ; ++i)
   {
      for(int j = 0; j < N; ++j )
      {
         if( matrix[i][j] == 0 )
         {
            list_of_zero.push_back(pair<int, int>(i,j));
         }
      }
   }

   for( pair<int, int> p : list_of_zero )
   {
      for(int i = 0; i < M; ++i )
         matrix[i][p.second] = 0;

      for(int j = 0; j < N; ++j )   
         matrix[p.first][j] = 0;
   }
}

void print( int matrix[M][N])
{
   for(int i = 0; i < M; ++i)
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
   int matrix [M][N] = {{1,2,3},{4,0,5},{6,7,8}};

   cout << "\n before \n";
   print(matrix);
   zero_matrix(matrix);
   cout << "\n after \n";
   print(matrix);
   return 0;
}
