#include "Entity.h"

Entity::Entity()
{
}

Entity::~Entity()
{
}

bool Entity::InVehicle()
{
    if (IsLoaded())
    {
        WorldObject *carrierObj = g_world->GetObject(m_carrierId);

        if (carrierObj != NULL)
        {
            return IsVehicle(carrierObj->m_type);
        }
    }

    return false;
}

bool Entity::IsEquipped()
{
    return m_equipment != 0;
}

bool Entity::IsUnconscious()
{
    return 0.7 <= m_damage;
}