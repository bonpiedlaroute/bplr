#include <vector>

using namespace std;

class Observer;

class Subject
{
  private:
  vector<Observer*> m_Collection;
  public:
  virtual void RegisterObserver(Observer* ob) = 0;
  virtual void UnregisterObserver(Observer* ob) = 0;
  virtual void NotifyObserver() = 0;

  virtual ~Subject(){};
};
