#include "Debug.h"
#include <cstring>

class MemoryBlock
{
private:
    unsigned long m_length;
    void *m_data;

public:
    MemoryBlock()
    {
        m_length = 0;
        m_data = NULL;
    }

    MemoryBlock(const MemoryBlock &other)
    {
        m_length = other.m_length;
        m_data = new void *[other.m_length];

        AppDebugOut("MemoryBlock::Copy Constructor %d bytes\n", other.m_length);
        memcpy(m_data, other.m_data, m_length);
    }

    MemoryBlock(MemoryBlock &&other)
    {
        m_data = NULL;
        m_length = 0;

        m_data = other.m_data;
        m_length = other.m_length;

        other.m_data = NULL;
        other.m_length = 0;
    }

    MemoryBlock(unsigned long _length, const void *_data)
    {
        void *__dest;

        m_length = _length;
        m_data = NULL;

        if (0 < _length)
        {
            __dest = new void *[_length];
            m_data = __dest;

            if (_data != NULL)
            {
                memcpy(__dest, _data, _length);
            }
        }
    }

    ~MemoryBlock()
    {
        if (m_data != NULL)
        {
            delete[] &m_data;
        }
    }

    MemoryBlock *operator=(const MemoryBlock &rhs)
    {
        void *__dest;

        AppDebugOut("MemoryBlock::Copy assignment %d bytes\n", rhs.m_length);

        if (&rhs != this)
        {
            if (m_data != NULL)
            {
                delete[] &m_data;
            }

            m_length = rhs.m_length;
            __dest = new void *[rhs.m_length];
            m_data = __dest;

            memcpy(__dest, rhs.m_data, m_length);
        }

        return this;
    }

    MemoryBlock *operator=(MemoryBlock &&rhs)
    {
        if (this != &rhs)
        {
            if (m_data != NULL)
            {
                delete[] &m_data;
            }

            m_data = rhs.m_data;
            m_length = rhs.m_length;

            rhs.m_data = NULL;
            rhs.m_length = 0;
        }

        return this;
    }

    const unsigned long GetLength()
    {
        return m_length;
    }

    const void *GetData()
    {
        return m_data;
    }

    void Truncate(int newLength)
    {
        if (m_length == newLength || m_length < newLength)
        {
            newLength = m_length;
        }

        m_length = newLength;
    }
};
