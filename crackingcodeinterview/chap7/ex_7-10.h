


template <typename T>
class shared_ptr
{
private:
   T* m_ptr;
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
   shared_ptr(T* ptr = 0)
   {
      m_ptr = ptr;
      m_count = new long(1);
   }

   shared_ptr<T>& operator=(const shared_ptr<T>& p)
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

   shared_ptr(const shared_ptr<T>& shr)
   {
      m_ptr = shr.m_ptr;
      m_count = shr.m_count;
      (*m_count)++;
   }

   T& operator*()
   {
      return *m_ptr;
   }

   ~shared_ptr()
   {
      dispose();
   }

   T* operator->()
   {
      return m_ptr;
   }

};
