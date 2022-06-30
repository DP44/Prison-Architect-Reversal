#include <functional>
#include <iostream>
#include <deque>

#include "App.h"
#include "Mutex.h"
#include "ConditionVariable.h"
#include "Dispatcher.h"

class MessageQueue
{
private:
    // void **_vtbl;                        // offset=0x0, len=0x8
    Mutex m_mutex;                          // offset=0x8, len=0x28
    ConditionVariable m_30;                 // offset=0x30, len=0x30
    ConditionVariable m_60;                 // offset=0x60, len=0x30
    ConditionVariable m_90;                 // offset=0x90, len=0x30
    pthread_t m_thread;                     // offset=0xc0, len=0x8
    std::deque<std::function<void()>> m_c8; // offset=0xc8, len=0x50

public:
    MessageQueue(const std::string &queueName);
    virtual ~MessageQueue();
    virtual ~MessageQueue();

    void SetThread(pthread_t thread);
    
    const pthread_t GetThread()
    {
        return m_thread;
    }

    // void ScheduleDispatcher(MutexLock &mutexLock);
    void ScheduleDispatcher();
    void Wait(float amount);
    const bool RunningOnThread();
    void SpawnThread();
    void AddToDispatcher(Dispatcher *a1);
    void Clear(bool a1);
    // NOTE: This might not be returning bool.
    bool ProcessMessage();
    void Run();
    bool TryProcessMessage();
    void Post(std::function<void()> func);
    void Terminate(std::function<void()> func);
};