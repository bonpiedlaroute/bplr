#include <mutex>

using namespace std;

class Singleton
{
private:
   static Singleton* m_pInstance;
   Singleton(){};
   static mutex mtx;  

public:
   static Singleton* GetInstance()
   {
     if( m_pInstance == nullptr )
     {
        mtx.lock();
        if( m_pInstance == nullptr )
        {
          m_pInstance = new Singleton();
        }
        mtx.unlock();
     }
     
     return m_pInstance;
   }

};
