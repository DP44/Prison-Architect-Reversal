#include "Mutex.h"

class ConditionVariable
{
private:
    pthread_cond_t m_threadCond;

public:
    ConditionVariable()
    {
        pthread_cond_init(&m_threadCond, NULL);
    }

    ~ConditionVariable()
    {
        pthread_cond_destroy(&m_threadCond);
    }

    void SignalAll()
    {
        pthread_cond_broadcast(&m_threadCond);
    }
    
    void SignalOne()
    {
        pthread_cond_signal(&m_threadCond);
    }
    
    void Wait(Mutex *mutex, int waitAmount)
    {
        timespec abstime;
        timeval timeOfDay;

        if (waitAmount < 0)
        {
            pthread_cond_wait(&m_threadCond, &mutex->m_thread);
        }
        else
        {
            gettimeofday(&timeOfDay, NULL);
            abstime.tv_sec = waitAmount / 1000 + timeOfDay.tv_sec;
            abstime.tv_nsec = 1000 * timeOfDay.tv_usec + 1000000 * (waitAmount % 1000);

            if (999999999 < abstime.tv_nsec)
            {
                abstime.tv_nsec += -1000000000;
                abstime.tv_sec++;
            }

            pthread_cond_timedwait(&m_threadCond, &mutex->m_thread, &abstime);
        }
    }
};
