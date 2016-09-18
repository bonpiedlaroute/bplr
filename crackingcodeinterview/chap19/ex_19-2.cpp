#include <iostream>

#define N  4

bool HasWon(int Game[N][N], int value)
{
   bool won;

   /* check if won on rows */
   for(int i = 0; i < N ; ++i)
   {
      won = true;
      for(int j = 0; (j < N) && won ; ++j )
      {
         if( Game[i][j] != value )
         {
            won = false;
         }
      }

      if( won ) return true;
   }

   /* check if won on columns */
   
   for(int j = 0; j < N; ++j)
   {
      won = true;
      for(int i = 0; (i < N) && won; ++i)
      {
         if( Game[i][j] != value )
            won = false;
      }

      if( won ) return true;   
   }

   /* check diagonals */
   won = true;
   for(int i = 0; (i < N) && won ; ++i)
   {
      if( Game[i][i] != value )
         won = false;
   }

   if( won ) return true;

   /* check anti-diagonals */
   won = true;
   for(int j = N-1, i = 0; (j >= 0) && (i < N) && won ; --j, ++i)
   {
      if( Game[i][j] != value )
         won = false;
   }

   if( won ) 
      return true;
   else
      return false;
}

int main()
{
   return 0;
}
