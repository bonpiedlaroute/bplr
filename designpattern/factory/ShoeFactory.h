#include <iostream>

using namespace std;

class Shoe
{

};

class CityShoe : public Shoe
{

public:
   CityShoe()
   {
      cout << "CityShoe\n";
   }

};

class SportShoe : public Shoe
{
public:
   SportShoe()
   {
      cout << "SportShoe\n";
   }
};

class Boot : public Shoe
{

public:
   Boot()
   {
      cout << "Boot\n";
   }
};

class ShoeFactory
{
public:
   virtual Shoe* CreateShoe() = 0;
};

class CityShoeFactory : public ShoeFactory
{
public:
   virtual Shoe* CreateShoe() override {new CityShoe(); }
};

class SportShoeFactory : public ShoeFactory
{
public:
   virtual Shoe* CreateShoe() override {new SportShoe(); }

};

class BootFactory : public ShoeFactory
{
public:
   virtual Shoe* CreateShoe() override { new Boot();}
};




