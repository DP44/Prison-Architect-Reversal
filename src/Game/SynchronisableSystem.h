#include "PrisonArchitectLinux.h"

class SynchronisableSystem
{
    std::string m_systemName;
    bool m_registered;
    int field3_0x2c; // undefined4

public:
    SynchronisableSystem(std::string systemName, bool registerSystem);
    ~SynchronisableSystem();

    void Register();
    void Unregister();

    std::string *GetSystemName();

    virtual unsigned long WriteNetworkUpdate(Directory *a1) = 0;
    virtual void ReadNetworkUpdate(Directory *a1) = 0;
}
