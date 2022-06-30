// #include <pthread.h>
#include "PrisonArchitectLinux.h"

#include "Mutex.h"
#include "Debug.h"

#include <iostream>

pthread_t AppThreadStart(void *(*start_routine)(void *), void *arg);
pthread_t AppThreadCurrentId();
bool AppThreadIdEqual(unsigned long firstThreadId, unsigned long secondThreadId);
void AppThreadSleep(int seconds);

int64_t AppThreadTerminate();
void AppWaitUntilThreadDone(pthread_t thread);
