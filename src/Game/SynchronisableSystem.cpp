#include "SynchronisableSystem.h"

SynchronisableSystem::SynchronisableSystem(std::string systemName, bool registerSystem)
{
    m_systemName = systemName;
    field2_0x28 = 0;

    if (registerSystem)
    {
        Register();
    }
}

SynchronisableSystem::~SynchronisableSystem()
{
    /*
        *(_QWORD *)this = &SynchronisableSystem_VTABLE;
        char *v1 = (char *)this + 24; // rbx
        SynchronisableSystem::Unregister(this);
        char *v2 = (char *)*((_QWORD *)this + 1); // rdi
        if ( v2 != v1 )
        {
            operator delete(v2);
        }
    */
    Unregister();

    if (m_systemName != NULL)
    {
        delete m_systemName;
    }
}

void SynchronisableSystem::Register() {}
void SynchronisableSystem::Unregister() {}