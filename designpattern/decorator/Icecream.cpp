#include "Icecream.h"


int main()
{
   Icecream* ice = new IcecreamWithChantilly( new SimpleIcecream() );

   ice->make();

   return 0;
}
