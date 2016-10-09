#include <iostream>


template <typename T>
class My_Shared_ptr
{

private:
   T * m_ptr;
   long* m_count;

   void dispose()
   {
      (*m_count)--;

      if( *m_count == 0 )
      {
         delete m_count;
         delete m_ptr;
      }
   }
public:
   My_Shared_ptr(T* ptr )
   {
      m_ptr = ptr;
      m_count = new long(1);
   }

   My_Shared_ptr(const My_Shared_ptr<T>& p)
   {
      m_ptr = p.m_ptr;
      m_count = p.m_count;
      (*m_count)++;
   }

   My_Shared_ptr<T>& operator=(const My_Shared_ptr& p)
   {
      if( this != &p )
      {
         dispose();
         m_ptr = p.m_ptr;
         m_count = p.m_count;
         (*m_count)++;
      }

      return *this;
   }

   T& operator*() const
   {
      return *m_ptr;
   }
   
   T* operator->() const
   {
      return m_ptr;
   }
   
   ~My_Shared_ptr()
   {
      dispose();
   }
};

int main()
{
   My_Shared_ptr<int> p (new int(2));

   return 0;
}
