#include "WorldObject.h"

WorldObject::WorldObject()
{
    field1_0x8 = new DataRegistry();
    field2_0x20 = new DataRegistry();
    m_id = new ObjectId();
    m_type = 0;
    m_subType = -1;
    m_pos.x = 0.0f;
    m_pos.y = 0.0f;
    m_name = NULL;
    m_posZ = 0.0f;
    m_origin.x = 0.0f;
    m_origin.y = 0.0f;
    m_walls.x = 0.0f;
    m_walls.y = 0.0f;
    m_damage = 0.0f;
    m_remove = false;
    m_hidden = false;
    m_loaded = false;
    m_locked = false;
    m_garbage = false;
    field17_0x71 = false;
    field18_0x72 = false;
    field36_0xb0 = new DataRegistry();

    ObjectId *slotIter = &m_slot0;
    
    while (slotIter != &field66_0x178)
    {
        slotIter++ = new ObjectId();
    }

    field66_0x178 = NULL;
    
    m_velocity.x = 0.0f;
    m_velocity.y = 0.0f;
    m_animateVelocity = false;
    m_animateRotation = false;
    m_hasCustomReport = false;
    field81_0x1bb = false;
    field103_0x218 = new Obstruction();
    m_dryness = 0.0f;
    m_origin.x = 0.0f;
    m_origin.y = 1.0f;
    // (this->field103_0x218).field0_0x0 = this;

    field1_0x8->RegisterCategory("WorldObject");
    
    m_id->RegisterData(field1_0x8, "Id.i", "Id.u");
    field1_0x8->RegisterData("Type", &m_type, false);
    field1_0x8->RegisterData("SubType", &m_subType, false);
    field1_0x8->RegisterData("Pos", &m_pos, false);
    field1_0x8->RegisterData("PosZ", &m_posZ, false);
    field1_0x8->RegisterData("Or", &m_origin, false);
    field1_0x8->RegisterData("Walls", &m_walls, false);
    field1_0x8->RegisterData("Damage", &m_damage, false);
    field1_0x8->RegisterData("Carried", &m_carried, false);
    field1_0x8->RegisterData("Loaded", &m_loaded, false);
    field1_0x8->RegisterData("Locked", &m_locked, false);
    field1_0x8->RegisterData("Garbage", &m_garbage, false);
    field1_0x8->RegisterData("Name", &m_name, false);
    field1_0x8->RegisterData("Hidden", &m_hidden, false);
    field1_0x8->RegisterData("Vel", &m_velocity, false);
    field1_0x8->RegisterData("AnimateVelocity", &m_animateVelocity, false);
    field1_0x8->RegisterData("AnimateRotation", &m_animateRotation, false);
    field1_0x8->RegisterData("Tooltip", &m_tooltip, false);
    field1_0x8->RegisterData("HasCustomReport", &m_hasCustomReport, false);
    field1_0x8->RegisterData("Scanned", &m_scanned, false);
    field1_0x8->RegisterData("Dryness", &m_dryness, false);
    field1_0x8->RegisterData("RepairCooldown", &m_repairCooldown, false);
    field1_0x8->RegisterData("DiscountWhenPurchased", &m_discountWhenPurchased, false);
    field1_0x8->RegisterData("Remove", &m_remove, false);
    
    m_carrierId->RegisterData(field1_0x8, "CarrierId.i", "CarrierId.u");
    m_slot0->RegisterData(field1_0x8,  "Slot0.i", "Slot0.u");
    m_slot1->RegisterData(field1_0x8,  "Slot1.i", "Slot1.u");
    m_slot2->RegisterData(field1_0x8,  "Slot2.i", "Slot2.u");
    m_slot3->RegisterData(field1_0x8,  "Slot3.i", "Slot3.u");
    m_slot4->RegisterData(field1_0x8,  "Slot4.i", "Slot4.u");
    m_slot5->RegisterData(field1_0x8,  "Slot5.i", "Slot5.u");
    m_slot6->RegisterData(field1_0x8,  "Slot6.i", "Slot6.u");
    m_slot7->RegisterData(field1_0x8,  "Slot7.i", "Slot7.u");
    m_slot8->RegisterData(field1_0x8,  "Slot8.i", "Slot8.u");
    m_slot9->RegisterData(field1_0x8,  "Slot9.i", "Slot9.u");
    m_slot10->RegisterData(field1_0x8, "Slot10.i", "Slot10.u");
    m_slot11->RegisterData(field1_0x8, "Slot11.i", "Slot11.u");
    m_slot12->RegisterData(field1_0x8, "Slot12.i", "Slot12.u");
    m_slot13->RegisterData(field1_0x8, "Slot13.i", "Slot13.u");
    m_slot14->RegisterData(field1_0x8, "Slot14.i", "Slot14.u");
    m_slot15->RegisterData(field1_0x8, "Slot15.i", "Slot15.u");
    m_slot16->RegisterData(field1_0x8, "Slot16.i", "Slot16.u");
    m_slot17->RegisterData(field1_0x8, "Slot17.i", "Slot17.u");
    m_slot18->RegisterData(field1_0x8, "Slot18.i", "Slot18.u");
    m_slot19->RegisterData(field1_0x8, "Slot19.i", "Slot19.u");
}

WorldObject::~WorldObject()
{

}