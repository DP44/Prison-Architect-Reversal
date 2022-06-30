// #include <pthread.h>
#include "PrisonArchitectLinux.h"

class Mutex
{
public:
    pthread_mutex_t *m_threadMutex;

    Mutex()
    {
        pthread_mutex_init(m_threadMutex, NULL);
    }

    ~Mutex()
    {
        pthread_mutex_destroy(m_threadMutex);
    }

    bool TryLock()
    {
        return pthread_mutex_trylock(m_threadMutex) == 0;
    }

    void Lock()
    {
        pthread_mutex_lock(m_threadMutex);
    }

    void Unlock()
    {
        pthread_mutex_unlock(m_threadMutex);
    }
};

class RecursiveMutex
{
public:
    pthread_mutexattr_t m_attr;
    pthread_mutex_t *m_threadMutex;

    RecursiveMutex()
    {
        pthread_mutexattr_init(&m_attr);
        pthread_mutexattr_settype(&m_attr, 1);
        pthread_mutex_init(m_threadMutex, &m_attr);
    }

    ~RecursiveMutex()
    {
        pthread_mutex_destroy(m_threadMutex);
        pthread_mutexattr_destroy(&m_attr);
    }

    bool TryLock()
    {
        return pthread_mutex_trylock(m_threadMutex) == 0;
    }

    void Lock()
    {
        pthread_mutex_lock(m_threadMutex);
    }

    void Unlock()
    {
        pthread_mutex_unlock(m_threadMutex);
    }
};

class MutexLock; // TODO

class RecursiveMutexLock
{
public:
    RecursiveMutex *m_recursiveMutex;

    RecursiveMutexLock(RecursiveMutex *recursiveMutex)
    {
        m_recursiveMutex = recursiveMutex;
        pthread_mutex_lock(recursiveMutex->m_threadMutex);
    }

    ~RecursiveMutexLock()
    {
        pthread_mutex_unlock(m_recursiveMutex->m_threadMutex);
    }
};

/*
int main()
{
    Mutex *mutexTest = new Mutex();
    mutexTest->Lock();
    // important stuff here
    mutexTest->Unlock();
    
    RecursiveMutex *recursiveMutexTest = new RecursiveMutex();
    recursiveMutexTest->Lock();
    // important stuff here
    recursiveMutexTest->Unlock();
    
    return 0;
}
*/