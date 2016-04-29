#include <iostream>


void ** My2Dalloc(int rows, int cols)
{
   int header =  rows * sizeof(int*);
   int data = rows*cols *sizeof(int);

   void ** result = (void **) malloc(header + data);
   int *buf  = (int*)(result + rows);
   
   for(int i=0; i<rows; ++i)
   {
      result[i] = buf + i*cols;
   }

   return result;
}

int main()
{

   return 0;
}
