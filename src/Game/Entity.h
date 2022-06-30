#include "WorldObject.h"

class Entity : WorldObject
{
private:
    int m_equipment;

public:
    Entity();
    virtual ~Entity();
    virtual ~Entity();
    virtual void Create();
    virtual void Initialise();
    virtual void Update();
    virtual void ClientUpdate();
    virtual void InExclusionNoRenderZone();
    virtual void RenderEffects();
    virtual void Damage();
    virtual void Destroy();
    virtual void NotifyLoadedInto();
    virtual void NotifyCarried();
    virtual void Read();
    virtual void Write();
    virtual void Update_Resting();
    virtual void Update_StatusEffect();
    virtual void UpdateVisualEffects();
    virtual void GetPrisonerBiography();
    virtual NeedsSystem *Needs();
    virtual void PerformDuties();
    virtual bool IsGuardObject();
    virtual void PlayerSetsTarget();
    virtual void NotifyLockdown();
    virtual void HitByTazer();
    virtual void AttackedBy();
    virtual void IntimidatedBy();
    virtual void Create();


    bool InVehicle();
    bool IsEquipped();
    bool IsUnconscious();
    bool IsAITargetSet();
};