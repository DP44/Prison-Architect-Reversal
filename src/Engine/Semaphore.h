#include "PrisonArchitectLinux.h"

class Semaphore
{
private:
    sem_t *m_semaphore;

public:
    Semaphore(int unused)
    {
        m_semaphore = malloc(32);
    }

    ~Semaphore()
    {
        sem_destroy(m_semaphore);
        free(m_semaphore);
    }

    void Wait()
    {
        sem_wait(m_semaphore);
    }

    bool TryWait()
    {
        timespec v3; // [rsp+0h] [rbp-28h] BYREF
        v3.tv_sec = NULL;
        v3.tv_nsec = NULL;
        return sem_timedwait(m_semaphore, &v3) == 0;
    }

    void Signal()
    {
        sem_post(m_semaphore);
    }
};