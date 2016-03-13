#include "ShoeFactory.h"

int main()
{
   ShoeFactory* cityfactory = new CityShoeFactory();

   Shoe* shoe = cityfactory->CreateShoe();

   ShoeFactory* bootfactory = new BootFactory();


   Shoe* boot = bootfactory->CreateShoe();
 
   return 0;
}
