#include "Menu.h"


int main()
{
   Plate* t1 = new Plate("couscous");
   Plate* t2 = new Plate("riz");
   Plate* t3 = new Plate("Plantain mur frit");
   Plate* t4 = new Plate("Bongo");
   Plate* t5 = new Plate("bol de lait");
   Plate* t6 = new Plate("goyave");


   MenuComposite* general = new MenuComposite();
   MenuComposite* desert = new MenuComposite();
   
   general->add(t1);
   general->add(t2);
   general->add(t3);
   general->add(t4);
   desert->add(t5);
   desert->add(t6);
   general->add(desert);

   general->remove(t4);

   delete t4;

   general->print();

   return 0;
}
