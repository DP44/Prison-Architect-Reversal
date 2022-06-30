#include "App.h"
#include "ConditionVariable.h"
#include <functional>
#include <deque>

class Dispatcher
{
private:
    Mutex m_mutex;                                     // offset=0x0, len=0x28
    ConditionVariable m_28;                            // offset=0x28, len=0x30
    ConditionVariable m_58;                            // offset=0x58, len=0x30
    std::deque<std::function<void()>> m_functionQueue; // offset=0x88, len=0x50
    std::deque<MessageQueue *> m_messageQueue;         // offset=0xd8, len=0x50
    int m_128;                                         // offset=0x128, len=0x4
    bool m_12c;                                        // offset=0x12c, len=0x1
    char gap_12d[3];                                   // offset=0x12d, len=0x3
    unsigned long m_130;                               // offset=0x130, len=0x8
    int m_138;                                         // offset=0x138, len=0x4
    int m_numThreads;                                  // offset=0x13c, len=0x4
public:
    Dispatcher();
};