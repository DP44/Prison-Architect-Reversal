#include "InformantSystem.h"

Informant::Informant()
{
    m_dataRegistry = new DataRegistry();
    m_prisoner = new ObjectId();
    m_suspicion = 0f;
    m_burnPoint = 0f;
    m_highestSuspicion = 0f;
    m_state = 0;
    m_timer = 0f;
    m_coverage = 0f;

    m_dataRegistry->RegisterData(&m_prisoner, "Prisoner.i", "Prisoner.u");
    m_dataRegistry->RegisterData("State", &m_state, false);
    m_dataRegistry->RegisterData("Suspicion", &m_suspicion, false);
    m_dataRegistry->RegisterData("Timer", &m_timer, false);
    m_dataRegistry->RegisterData("Coverage", &m_coverage, false);
    m_dataRegistry->RegisterData("BurnPoint", &m_burnPoint, false);
    m_dataRegistry->RegisterData("HighestSuspicion", &m_highestSuspicion, false);
    // m_dataRegistry->ProvideEnum("State", 8, (std::string *)s_stateNames);
}

void Informant::ChangeSuspicion(float suspicion)
{
    float newSuspicion = suspicion + m_suspicion;

    if (100f < newSuspicion)
    {
        m_suspicion = 100f;
    }
    else if (0f <= newSuspicion)
    {
        m_suspicion = newSuspicion;
    }
    else
    {
        m_suspicion = 0f;
    }
}

bool Informant::IsAssassinationTarget()
{
    return m_burnPoint <= m_suspicion;
}

void Informant::NotifyCoverBlown()
{
    m_suspicion = 100f;
    m_state = 4;
}

void Informant::Read(Directory *dir)
{
    m_dataRegistry->Read(dir, false);
}

void Informant::Write(Directory *dir)
{
    m_dataRegistry->Write(dir, true, false);
}

// ===================================================================================

InformantSystem::InformantSystem() : SynchronisableSystem("InformantSystem")
{
    m_informants = new FastList<Informant *>();
    field7_0x48 = false;
}

InformantSystem::~InformantSystem()
{
}

Informant *InformantSystem::GetInformant(const ObjectId &informantId)
{
}

int InformantSystem::CountActiveInformants()
{
    if (m_informants.size < 0)
    {
        return 0;
    }

    int numActiveInformants = 0;

    for (int i = 0; i < m_informants.size; i++)
    {
        Informant *informant = m_informants.field0_0x0;

        if (informant != NULL && informant->m_state == 2)
        {
            numActiveInformants++;
        }
    }

    return numActiveInformants;
}

bool InformantSystem::IsReleaseable(const ObjectId &informantId)
{
    Prisoner *prisoner = (Prisoner *)g_app->m_world->GetObject(informantId);

    if (prisoner != NULL && prisoner->m_type == 109 && prisoner->IsDead() == false)
    {
        Informant *informant = GetInformant(informantId);

        if (informant == NULL)
        {
            return false;
        }

        if (prisoner->m_biography->HasReputation(32) == false)
        {
            if (informant->m_state == 4)
            {
                return false;
            }

            if (20.0 < informant->m_suspicion)
            {
                return false;
            }

            // Is this correct??
            return prisoner->IsIncapacitated();
        }
    }

    return true;
}

bool InformantSystem::IsInformant(const ObjectId &informantId)
{
    return GetInformant(informantId) != NULL;
}

bool InformantSystem::IsRecruitable(const ObjectId &informantId)
{
    Informant *informant = GetInformant(this, informantId);
    Prisoner *prisoner = (Prisoner *)g_app->m_world->GetObject(informantId);

    if (prisoner != NULL && prisoner->m_type == 109 && informant == NULL &&
        g_app->m_world->m_misconductSystem->IsBeingPunished(prisoner) == 2 &&
        (informantId->u + informantId->i) % 3 < 1)
    {
        MisconductReport *report = g_app->m_world->m_misconductSystem->GetReport(prisoner);
        float punishmentAmount = 0.0;

        if (report != NULL)
        {
            float punishmentRatio = report->CountPunishment(2);
            punishmentRatio = (punishmentRatio - 60.0) / 600.0;

            if (punishmentRatio <= 1.0 && 0.0 <= punishmentRatio)
            {
                punishmentAmount = punishmentRatio + 0.0;
            }
        }

        float firstStatusEffectFraction = prisoner->m_statusEffects->GetStatusEffectFrac(1);
        float secondStatusEffectFraction = prisoner->m_statusEffects->GetStatusEffectFrac(5);
        float addictionAmount = prisoner->AddictionAmount(true, true);

        return 0.7 < addictionAmount + secondStatusEffectFraction +
                     punishmentAmount + firstStatusEffectFraction;
    }

    return false;
}

bool InformantSystem::IsInformantInvestigationMode(const ObjectId &informantId)
{
    Informant *informant = GetInformant(informantId);
    return informant != NULL ? informant->m_state - 5 < 3 : false;
}

bool InformantSystem::RequestEscortPrisonerToSecurity(const ObjectId &informantId)
{
}

void InformantSystem::Update(float a1)
{
}

void InformantSystem::RenderDebug()
{
}

float InformantSystem::DetermineCoverage(const ObjectId &informantId)
{
}

float InformantSystem::DetermineCoverage(float a1, bool a2)
{
    float coverage = a1 / 1440.0;
    coverage = a2 ? coverage * 1.25 : coverage;
    return coverage;
}

float InformantSystem::DetermineActiveCoverage()
{
}

void InformantSystem::ChangeSuspicion(float newSuspicion)
{
}

void InformantSystem::ChangeSuspicion(const ObjectId &informantId, float newSuspicion)
{
    Informant *informant = GetInformant(informantId);

    if (informant != NULL)
    {
        informant->ChangeSuspicion(newSuspicion)
    }
}

void InformantSystem::DeactivateInvestigation(const ObjectId &informantId)
{
    DeActivateInformant(informantId, true);
}

void InformantSystem::RegisterInformant(const ObjectId &informantId)
{
}

void InformantSystem::DeActivateInformant(const ObjectId &informantId, bool a2)
{
    Informant *informant = GetInformant(informantId);

    if (informant == NULL)
    {
        return;
    }

    informant->m_state = ~(-(unsigned int)(!a2) & 7);
    g_app->m_world->m_workQueue->CancelAllJobs(informantId);
    field7_0x48 = false;
}

void InformantSystem::ActivateInformant(const ObjectId &informantId, bool a2)
{
}

void InformantSystem::ReleaseInformant(const ObjectId &informantId)
{
}
