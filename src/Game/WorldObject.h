#include "PrisonArchitectLinux.h"
#include "Utils.h"
#include "ObjectId.h"
#include "Math.h"

class WorldObject
{
private:
    // void **_vtbl;
    DataRegistry field1_0x8;
    DataRegistry field2_0x20;
    ObjectId m_id;
    int m_type;
    int m_subType;
    Vector2 m_pos;
    float m_posZ;
    Vector2 m_origin;
    Vector2 m_walls;
    char GAP_0x64[4];
    float m_damage;
    bool m_remove;
    bool m_hidden;
    bool m_loaded;
    bool m_locked;
    bool m_garbage;
    bool field17_0x71;
    bool field18_0x72;
    char GAP_0x73[5];
    std::string m_name;
    ObjectId m_carrierId;
    char GAP_0xa0[4];
    bool m_scanned;
    char GAP_0xa5[3];
    int m_carried;
    char GAP_0xac[4];
    DataRegistry field36_0xb0;
    char GAP_0xc8[15];
    ObjectId m_slot0;
    ObjectId m_slot1;
    ObjectId m_slot2;
    ObjectId m_slot3;
    ObjectId m_slot4;
    ObjectId m_slot5;
    ObjectId m_slot6;
    ObjectId m_slot7;
    ObjectId m_slot8;
    ObjectId m_slot9;
    ObjectId m_slot10;
    ObjectId m_slot11;
    ObjectId m_slot12;
    ObjectId m_slot13;
    ObjectId m_slot14;
    ObjectId m_slot15;
    ObjectId m_slot16;
    ObjectId m_slot17;
    ObjectId m_slot18;
    ObjectId m_slot19;
    ObjectId field66_0x178;
    ScriptSystem *m_scriptSystem;
    char GAP_0x188[40];
    Vector2 m_velocity;
    bool m_animateVelocity;
    bool m_animateRotation;
    bool m_hasCustomReport;
    bool field81_0x1bb;
    char GAP_0x1bc[4];
    std::string m_tooltip;
    char GAP_0x1e0[8];
    void *field89_0x1e8;
    char GAP_0x1f0[8];
    // TODO: Verify if this is actually an std::pair list.
    FastList<std::pair<char, std::string>> field92_0x1f8;
    bool field93_0x208;
    char GAP_0x209[3];
    float m_repairCooldown;
    char GAP_0x210[4];
    float m_discountWhenPurchased;
    Obstruction field103_0x218;
    char GAP_0x241[7];
    float m_dryness;
    char GAP_0x24c[4];

public:
    WorldObject();
    /* 0  */ virtual ~WorldObject();
    /* 1  */ virtual ~WorldObject();
    /* 2  */ virtual void RenderPreEffects();
    /* 3  */ virtual void Initialise();
    /* 4  */ virtual void Update();
    /* 5  */ virtual void ClientUpdate();
    /* 6  */ virtual bool InExclusionNoRenderZone()
    {
        return false;
    }

    /* 7  */ // virtual void InExclusionNoRenderZone();
    /* 8  */ // virtual void RenderPreEffects();
    /* 9  */ virtual void RenderEffects();
    /* 10 */ virtual void RenderPreSprite(VertexArray *a1, Vector3 const &a2, Vector2 const &a3, Vector2 const &a4);
    /* 11 */ virtual void RenderPostSprite(VertexArray *a1, VertexArray *a2, Vector3 const &a3, Vector2 const &a4, Vector2 const &a5);
    /* 12 */ virtual void Damage();
    /* 13 */ virtual void Destroy();
    /* 14 */ virtual void GetSlotPosition(int a1, Vector2 &a2, Vector2 &a3, bool a4);
    /* 15 */ virtual int FindAppropriateSlot(int a1, int a2, int a3, int a4, int a5);
    /* 16 */ virtual const void CountSpaceToLoadObjectInto(const ObjectId &a1, int a2);
    /* 17 */ virtual void LoadObjectInto(const ObjectId &a1, int a2);
    /* 18 */ virtual void NotifyObjectUnloaded();
    /* 19 */ virtual void NotifyLoadedInto(const ObjectId &a1);
    /* 20 */ virtual void NotifyCarried();
    /* 21 */ virtual void NotifyDropped();
    /* 22 */ virtual void NotifyUnloaded();
    /* 23 */ virtual void NotifyInstalled();
    /* 24 */ virtual void OnHighlighted();
    /* 25 */ virtual void UpdateInventory();
    /* 26 */ virtual void NotifyUsedAsNeedProvider(const std::string &a1);
    /* 27 */ virtual void ProvideHeat(float a1);
    /* 28 */ // virtual void NotifyUsedAsNeedProvider();
    /* 29 */ virtual void RegisterScriptSyntax(lua_state *lua, const std::string &a2, const std::string &a3);
    /* 30 */ virtual bool CanMoveVehicle();
    /* 31 */ virtual bool CanMoveEntity();
    /* 32 */ virtual void Read(Directory *a1);
    /* 33 */ virtual void Write(Directory *a1);
    /* 34 */ // virtual void ReadNetworkUpdate(Directory *a1);
    /* 35 */ // virtual void WriteNetworkUpdate(Directory *a1);


    void CopyBaseData(WorldObject *other);
    



    ;



    WorldObject *Create();
    
    void QueryContentTypeAndQuantity(int &a1, int &a2);

    WorldObject *GetCarrierObject();

    bool IsLoaded();
    bool IsCarrying();
};

namespace WorldObject
{
    bool IsMedical(int id);
}