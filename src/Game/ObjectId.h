#include "PrisonArchitectLinux.h"

class ObjectId
{
private:
    int i, u;

public:
    ObjectId()
    {
        u = -1;
        i = -1;
    }

    ObjectId(int i, int u)
    {
        u = u;
        i = i;
    }

    bool operator!=(const ObjectId &rhs)
    {
        if ((u != -1 && i != -1) && (rhs->u != -1 && rhs->i != -1))
        {
            return u != rhs->u || i != rhs->i;
        }

        return true;
    }

    bool operator<(const ObjectId &rhs)
    {
        return u < rhs->u;
    }

    void SetInvalid()
    {
        i = -1;
        u = -1;
    }
};

class ObjectIdDArray
{
private:
    DArray<ObjectId> m_objectIds;
    WorldCell m_worldCell;

public:
    ObjectIdDArray(WorldCell &worldCell)
    {
        m_worldCell = worldCell;
    }

    void RemoveData(int a1);
    void PutData(const ObjectId &obj);
};