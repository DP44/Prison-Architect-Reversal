#include "App.h"

pthread_t AppThreadStart(void *(*startRoutine)(void *), void *arg)
{
    int result;   // eax
    pthread_t th; // [rsp+0h] [rbp-18h] BYREF

    result = pthread_create(th, NULL, startRoutine, arg);

    if (!result)
    {
        pthread_detach(th);
        return th;
    }

    return NULL;
}

pthread_t AppThreadCurrentId()
{
    return pthread_self();
}

bool AppThreadIdEqual(unsigned long firstThreadId, unsigned long secondThreadId)
{
    return firstThreadId == secondThreadId;
}

void AppThreadSleep(int seconds)
{
    usleep(1000 * seconds);
}

int64_t AppThreadTerminate()
{
    return NULL;
}

void AppWaitUntilThreadDone(pthread_t thread)
{
    pthread_join(thread, NULL);
}