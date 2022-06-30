#include "SynchronisableSystem.h"
#include "Utils.h"

class Informant
{
private:
    DataRegistry m_dataRegistry;
    ObjectId m_prisoner;
    float m_suspicion;
    float m_burnPoint;
    float m_highestSuspicion;
    unsigned int m_state;
    float m_timer;
    float m_coverage;

public:
    Informant();

    void ChangeSuspicion(float suspicion);
    bool IsAssassinationTarget();
    void NotifyCoverBlown();

    void Read(Directory *dir);
    void Write(Directory *dir);
};

class InformantSystem : SynchronisableSystem
{
private:
    FastList<Informant *> m_informants;
    bool field7_0x48;

public:
    InformantSystem();
    ~InformantSystem();

    Informant *GetInformant(const ObjectId &informantId);
    int CountActiveInformants();
    
    bool IsReleaseable(const ObjectId &informantId);
    bool IsInformant(const ObjectId &informantId);
    bool IsRecruitable(const ObjectId &informantId);
    bool IsInformantInvestigationMode(const ObjectId &informantId);
    bool RequestEscortPrisonerToSecurity(const ObjectId &informantId);

    void Update(float a1);
    void RenderDebug();

    float DetermineCoverage(const ObjectId &informantId);
    float DetermineCoverage(float a1, bool a2);
    float DetermineActiveCoverage();

    void ChangeSuspicion(float newSuspicion);
    void ChangeSuspicion(const ObjectId &informantId, float newSuspicion);

    const bool HasAvailableInformants();
    const float GetHighestSuspicionRatio();

    void DeactivateInvestigation(const ObjectId &informantId);

    void RegisterInformant(const ObjectId &informantId);
    void DeActivateInformant(const ObjectId &informantId, bool a2);
    void ActivateInformant(const ObjectId &informantId, bool a2);
    void ReleaseInformant(const ObjectId &informantId);
};
