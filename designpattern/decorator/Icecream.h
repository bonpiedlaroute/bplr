#include <iostream>

using namespace std;

class Icecream
{

public:
   virtual void make() = 0;
   virtual ~Icecream() {};
};

class SimpleIcecream : public Icecream
{

   public:
      virtual void make() override
      {
         cout << " make simple ice cream \n";
      }
};

class IcecreamDecorator : public Icecream
{

private:
    Icecream* m_Ice;
public:
   IcecreamDecorator( Icecream * i) : m_Ice(i)
   {
   
   }  

   void make() override
   {
      m_Ice->make();
   }

   virtual ~IcecreamDecorator() {};
};

class IcecreamWithChantilly : public IcecreamDecorator
{

public:
   IcecreamWithChantilly(Icecream* i) : IcecreamDecorator(i)
   {

   }

   void make()
   {
      IcecreamDecorator::make();
      AddChantilly();
   }
   
   void AddChantilly()
   {
      cout << " Add the chantilly \n";
   }

};


