#include <list>
#include <iostream>
#include <algorithm>
#include <string>


using namespace std;

class Menu
{

public:
   virtual void print()=0;
   virtual ~Menu(){}

};

class MenuComposite : public Menu
{

private:
   list<Menu*> m_Collection;

public:
   virtual void print() override
   {
      for(Menu* m : m_Collection)
      {
         m->print();
      }
   }

   void add(Menu * m)
   {
     m_Collection.push_back(m);
   }

   void remove(Menu *n)
   {
      list<Menu*>::iterator iter = std::find(m_Collection.begin(), m_Collection.end(), n);
      if( iter != m_Collection.end() )
         m_Collection.erase(iter);
   }
};

class Plate : public Menu
{
private:
   string m_name;
public:
   Plate(string name) : m_name(name)
   {

   }

   virtual void print()
   {
      cout << " Plate [" << m_name << "]\n";
   }
};
