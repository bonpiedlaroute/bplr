#include <iostream>

using namespace std;

class MyInterface
{
   public:
   virtual void DoSomething() = 0;
   virtual ~MyInterface(){}

};


class Adaptee
{
   public:
   void DoIt()
   {
      cout << " Do  It! \n";
   }
};

class Adaptor : public MyInterface
{
   Adaptee* m_A;
   public:
   Adaptor(Adaptee * a) : m_A(a)
   {

   }
   virtual void DoSomething() override
   {
      m_A->DoIt();
   }
};
