typedef unsigned char       undefined;
typedef unsigned char       undefined1;
typedef unsigned short      undefined2;
typedef unsigned int        undefined4;
typedef unsigned long       undefined5;
typedef unsigned long       undefined6;
typedef unsigned long       undefined7;
typedef unsigned long       undefined8;

typedef unsigned char       byte;
typedef unsigned char       dwfenc;
typedef unsigned int        dword;
typedef unsigned long       qword;
// ============================================================================================

#include <iostream>

// ============================================================================================

typedef unsigned int wchar32;
typedef long __ssize_t;
typedef __ssize_t ssize_t;
typedef int __pid_t;
typedef long __off64_t;
typedef int __clockid_t;
typedef int __int32_t;
typedef unsigned int __useconds_t;
typedef unsigned int __socklen_t;
typedef long __suseconds_t;
typedef long __clock_t;
typedef unsigned long size_t;
typedef unsigned long pthread_t;

// ============================================================================================

struct fde_table_entry
{
    dword initial_loc; // Initial Location
    dword data_loc; // Data location
};

struct pollfd
{
    int fd;
    short events;
    short revents;
};

struct __pthread_internal_list
{
    __pthread_internal_list * __prev;
    __pthread_internal_list * __next;
};

struct __pthread_mutex_s
{
    int __lock;
    unsigned int __count;
    int __owner;
    unsigned int __nusers;
    int __kind;
    int __spins;
    __pthread_list_t __list;
};

union pthread_mutex_t
{
    __pthread_mutex_s __data;
    char __size[40];
    long __align;
};

union pthread_mutexattr_t
{
    char __size[4];
    int __align;
};

union pthread_cond_t
{
    struct
    {
        int __lock;
        unsigned int __futex;
        unsigned long long __total_seq;
        unsigned long long __wakeup_seq;
        unsigned long long __woken_seq;
        void *__mutex;
        unsigned int __nwaiters;
        unsigned int __broadcast_seq;
    } __data;
    char __size[48];
    long long __align;
};

union pthread_attr_t
{
    char __size[56];
    long __align;
};

union pthread_condattr_t
{
    char __size[4];
    int __align;
};

// ============================================================================================

class basic_string 
{
    void *field0_0x0;
    long field1_0x8;
    char GAP_0x10[16];
};

// ============================================================================================

class Insanity_c {};
class MemoryBlock {};
class WardenInventory {};
class CalamityHackParams {};
class CalamityParams {};
class MiscParams {};
class LuaCore {};
class SpriteTemplate {};
class SupplyChainShortages {};
class CampaignFade {};
class CloneRoomFloorType {};
class GangLibrary {};
class ScriptState {};
class ContrabandPositioner {};
class EscapeTunnelCell {};
class SectorCell {};
class WorkQueueCellCache {};
class FallAnimation {};
class FontLoader {};
class LuaUtils {};
class EscapeMapCellInfo {};
class StaffBreakSystem {};
class Climate {};
class WorkQueueIdCache {};
class WeatherMapCellInfo {};
class SavedPlanningJob {};
class CustomUniformColour {};
class BlockId {};
class LuaWorld {};
class RangeCoder {};
class LuaWobj {};
class WorkQueueTargetObjectCache {};
class CloneRoomObject {};
class LightMapCellInfo {};
class Deployment {};
class ReformProgramReport {};
class CJKLineBreaker {};
class WorkQueueAssignedObjectCache {};
class DetectionInstrumentHelpers {};
class BakeryProductSubtypes {};
class WobbleAnimation {};
class LuaInterface {};
class DefaultMultiLineTextClient {};
class CrisisSector {};
class ScratchIterator {};
class RenderCacheItem {};
class Area {};
class ScriptZoneProperty {};
class Rat {};
class PowerBroadcast {};
class Colour {};
class DataRegistry {};
class ObjectId {};
class Gang {};
class MisconductPolicy {};
class GridNavigationRoute {};
class DirectoryData {};
class RenderStyle {};
class ComprDataIO {};
class CampaignCommand {};
class InputScroller {};
class ReleasedPrisonerLog {};
class SavedPlanningSet {};
class DeliveryStop {};
class RPCBase {};
class NeedsDistributionCalculator {};
class RPCInterface {};
class CampaignExclusionZone {};
class AttractScreenThread {};
class MultiLineTextCache {};
class ExecutionWindow {};
class SDL_Event {};
class NameInTheGame {};
class Directory {};
class Vector3 {};
class Matrix33 {};
class Matrix34 {};
class GrantTracker {};
class PopsWrapper {};
class CrisisCustomisationData {};
class IconBoxItem {};
class NeedTemplate {};
class TextFileWriter {};
class ProcessorRule {};
class LStringSymbols {};
class DspGargle {};
class DialogEditor {};
class PhotonInterfaceThreadBase {};
class UncompressedArchiveRAR {};
class Light {};
class FileSystem {};
class CustomSectorNetworkData {};
class SelectionListItem {};
class CameraMove {};
class EventSystem {};
class SynchronisableSystem {};
class TransferSystem {};
class ProfilerPlugin {};
class VertexArrayOpenGLVBO {};
class PlayerListWindow {};
class EscapeTunnelDigger {};
class VertexArrayBlock {};
class CodexPackRectWindow {};
class AdviserSystem {};
class HTTPCallback {};
class SecurityMenuWindow {};
class FireEngine {};
class PreparedFontText {};
class NodeGridSector {};
class ConstructionVehicle {};
class ProgramScheduleWindow {};
class Conviction {};
class GangMembership {};
class RatTrap {};
class BakedLangEntry {};
class CampaignPolaroid {};
class FireAlarm {};
class EntityNeed {};
class AdjacencyMap {};
class SoundSampleDecoder {};
class NewMapSettings {};
class CommandData {};
class DamagedElectricalCable {};
class AnimalContainer {};
class EscapeTunnelMarkerIcon {};
class WorldEventTemplate {};
class CauseOfDeath {};
class Actor {};
class DialogRenderer {};
class InformantsWindow {};
class LuaTable {};
class SimpleRegime {};
class ReformWindowItem {};
class DialogComponentBlueprint {};
class PrefabZones {};
class Tree {};
class RatSystem {};
class CivilianChild {};
class BiographyWindow {};
class DialogComponentEditor {};
class Random {};
class VictoryLog {};
class CloneRoomSystem {};
class PowerSwitch {};
class PerformanceTestWindow {};
class VertexArray {};
class WorldRendererObject {};
class AssignmentConfirmWindow {};
class VisualEffect {};
class StatusEffect {};
class DeliveryObject {};
class CutscenePolaroid {};
class Fountain {};
class Semaphore {};
class GridNavigationCellInfo {};
class RestaurantCacheInfo {};
class GrantSystem {};
class WeatherMapWorldState {};
class LightMapOptions {};
class SoundParameterGraph {};
class RoadMaintenanceVehicle {};
class Edge {};
class SpriteBank {};
class Interface {};
class App {};
class World {};
class FindData {};
class BitmapFileHeader {};
class Node {};
class BoomboxTiming {};
class Renderer {};
class ChangedRoomCell {};
class URLInfo {};
class LStringPart {};

typedef dword LandscapeGeneratorConfig;

class MaterialLibrary {};
class LandscapeGenerator {};
class UpsellWindow {};
class SoundEventBlueprint {};
class Vector2 {};
class Sector {};
class EscapeMapCellRoute {};
class GangSystemParams {};
class DataRegistryEnum {};
class BakedBakeryProduct {};
class PolygonRenderer {};
class GangSystem {};
class MutatorSystem {};
class Runnable {};
class LightMap {};
class CampaignTrigger {};
class Unpack {};
class GangTerritory {};
class InputManagerSDL2 {};
class DrainageVehicle {};
class NetworkSoundId {};
class EscapeMapBuffer {};
class CodexMainWindow {};
class DangerMap {};
class PhotonRoom {};
class StringPart {};
class TextReader {};
class BinaryReader {};
class TextFileReader {};
class MetalDetector {};
class UpdateNITG {};
class ConditionVariable {};
class RunnableGroup {};
class GuardPavilionCorner {};
class ArchiveFile {};
class LaundrySystem {};

typedef dword PhotonWarning;

class TransferWindow {};
class ConstructionJob {};
class TherapyAnimal {};

typedef dword EUGCMatchingUGCType;

class BoxingRing {};
class DogCrate {};
class DspHandle {};
class PatrolSystemStation {};
class Regime {};
class SoundLibrary2dSDL {};
class CodexWindow {};
class Staff {};
class StatusEffectManager {};
class AvatarControlMode {};
class RawBakeryProduct {};
class DropDownMenuOption {};
class CrookedGuardsMarkerIcon {};
class UncompressedArchiveZIP {};
class CodexSteamTrendingWindow {};
class CampaignChapter {};
class CompostBin {};
class CmdExtract {};
class BuildToolbar {};
class FontSet {};
class Fireman {};
class ArchiveUncompressorList {};
class Limo {};
class WindowManagerSDL2 {};
class InputEvent {};
class VisibilityObserver {};
class GangPlay {};
class NITGCodexEntry {};
class Turbine {};
class DspReverb {};
class ArchiveUncompressorZIP {};
class DialogWindow {};
class ShopFront {};
class ObjectiveRenderData {};
class FerryDock {};
class IntakeCategory {};
class GridNavigationRequest {};
class GangPlayMarkerIcon {};
class Obstruction {};
class WorldObject {};
class SquadMember {};
class ExperienceSystem {};
class Entity {};
class PrisonerBrewingSystem {};
class Biography {};
class WorldPosition {};
class PrisonerReputationSystem {};
class Prisoner {};
class PrisonerNeedsSystem {};
class QueuedRPCInterface {};
class ActionVisitBakery {};
class WeatherMachine {};
class StreetLight {};
class LaundryTracker {};
class ReformProgram {};
class WorkQueueItem {};
class GangTargetIcon {};
class SectorNode {};
class Hearse {};
class ShelfContainer {};
class ScriptDebuggerWindow {};
class Mutex {};
class MessageQueue {};
class TimeLapseSettings {};
class EscapeMap {};
class NeedProvider {};
class SortedWorkItem_c {};
class BitmapFont {};
class LightMapWorldState {};
class VM_PreparedProgram {};
class DspEcho {};
class Squad {};
class IngredientsPolicyWindow {};
class BoilingPointWindow {};
class NetworkStaffAlert {};
class NetworkSoundSystem {};
class GrantsWindow {};
class SoundDspEditorWindow {};
class MaterialTemplate {};
class DockedSupplyVehicle {};
class TreeStump {};
class ClimateSystem {};
class ControlToolbar {};
class PolaroidTracker {};
class DeliveryPlannerSystem {};
class ScanTree {};
class signed {};
class SoundConstraint {};
class StaffBiographyGenerator {};
class Worker {};
class LaundryBasket {};

typedef dword VM_StandardFilters;

class PenaltySystem {};
class Buoy {};
class CodexExtrasWindow {};
class LauncherSettings {};
class DspResLowPass {};
class RecVolumes {};
class PowerExportMeter {};
class RichTextPopupLine {};
class ObjectIdDArray {};
class WorldCell {};
class CodexOptionsExperimentalWindow {};
class CustomSectorWindow {};
class Bitmap {};
class FindFile {};
class NetworkDataUsageTest {};
class CanteenTracker {};
class PopupWindow {};
class SoundLibrary3dInterfaceLock {};
class SonicDeterrent {};
class Polaroid {};
class PhotonPlayer {};
class ShopShelf {};
class WindowManager {};
class CodexGameBibleWindow {};
class Civilian {};
class GangGraffiti {};
class Mod {};
class Servo {};
class Inventory {};
class RoomConnections {};
class NodeGrid {};
class PowerSystemCell {};
class SaveGameSender {};
class StatHistory {};
class ObjectSummary {};
class KnownContrabandItem {};
class RatSystemParams {};
class ShopCounter {};
class SoundParameter {};
class MultiLineText {};
class NetworkingManager {};
class VisibilitySystem {};
class IconBox {};
class LogicBridge {};
class ReformWindow {};
class PrisonerCategoryCombination {};
class CompressionThread {};
class SoundChannelViewerWindow {};
class LabourManagement {};
class WeatherPopup {};
class CodexPolaroidsWindow {};
class WingConnectivityMap {};
class DataFieldStruct {};
class PhotonInterfaceCallbacks {};
class CrookedGuardsParams {};
class WorkshopFile {};
class SteamAchievementsWrapper {};
class SteamWrapper {};
class SteamWorkshopWrapper {};
class ArchiveUncompressorRAR {};
class CloneRoomMaterial {};
class MisconductEntry {};
class DialogInputEvent {};
class WiredConnection {};
class MarkerIcon {};
class PhotonInterfaceData {};
class InfluenceBroadcast {};
class Doctor {};
class WorldEvent {};
class SectorSystemParams {};
class DeepFreezeParams {};
class FirePropagationParams {};
class BoilingPointParams {};
class HeatstrokeParams {};
class ConfigManager {};
class PullUpBars {};
class WardenSquadMemberInfo {};
class Ingredient {};
class WeatherLogItem {};
class ObjectiveSystem {};
class StringReplacement {};
class ObjectiveRequirement {};
class HighQualityRandom {};
class Resource {};
class WeaponRack {};
class AppDebugOutRedirectBuffer {};
class Objective {};
class Meal {};
class SwollenDoorMarkerIcon {};
class Decode {};
class VisitationTable {};
class CodexGameBibleEntry {};
class LetterWindow {};
class RichTextPopup {};
class PrisonerMail {};
class GridNavigationRouteNode {};
class MisconductSystem {};
class Footbridge {};
class ProfileWindow {};
class Archive {};
class SupplyTruck {};
class VM_PreparedOperand {};
class PracticeSolarPanel {};
class TransferData {};

typedef dword FILE_HANDLETYPE;

class LoadingBarWindow {};
class MarkerSystem {};
class Visitation {};
class Collectable {};
class RapSheetWindow {};
class MultiLineTextClient {};
class InputManager {};
class TroopTruck {};
class CoveragePlan {};

typedef dword EmptyAndHaveNoContraband;

class SecuritySectorGradingWindow {};
class ReformProgramsWindow {};
class ScannerSystem {};
class AmbienceTracker {};
class WaterSystem {};
class StatusLight {};
class GrowthSystem {};
class WeatherOnTheFlyGenerateSystem {};
class CodexEntry {};

typedef dword ObjectiveFilter;

class Menu {};
class LanguageTable {};
class StringList {};
class SolarLight {};
class EventLoggingSystem {};
class LaundryMachine {};
class SmokeGenerator {};
class ExecutionWitness {};
class CloneRoom {};
class CropDistribution {};
class FloodLight {};
class GridRoutingSystem {};

typedef struct _IO_FILE FILE;
typedef void _IO_lock_t;

struct _IO_FILE
{
    int _flags;
    char *_IO_read_ptr;
    char *_IO_read_end;
    char *_IO_read_base;
    char *_IO_write_base;
    char *_IO_write_ptr;
    char *_IO_write_end;
    char *_IO_buf_base;
    char *_IO_buf_end;
    char *_IO_save_base;
    char *_IO_backup_base;
    char *_IO_save_end;
    _IO_marker *_markers;
    _IO_FILE *_chain;
    int _fileno;
    int _flags2;
    __off_t _old_offset;
    unsigned short _cur_column;
    char _vtable_offset;
    char _shortbuf[1];
    _IO_lock_t *_lock;
    __off64_t _offset;
    void *__pad1;
    void *__pad2;
    void *__pad3;
    void *__pad4;
    size_t __pad5;
    int _mode;
    char _unused2[20];
};

struct _IO_marker
{
    _IO_marker *_next;
    _IO_FILE *_sbuf;
    int _pos;
};

class File {};
class GymMat {};
class LStringArchiveReader {};
class PolicyData {};
class HomelessPrisonerIcon {};
class MisconductHistory {};
class Penalty {};
class MotdPopupWindow {};
class Analytics {};
class CustomReportsWindow {};
class CameraLimits {};
class SupplyAndDemandWindow {};
class Boombox {};
class FileDialog {};
class GangDemandMarkerIcon {};
class EventLog {};
class JobTemplate {};
class HTTPThread {};
class StorageShelf {};
class EscapeMode {};
class ConfirmWindow {};
class SquadSystem {};
class OldEscapeMode {};
class Shelf {};
class GridNavigationResult {};
class DoorControlSystem {};
class DialogBlueprint {};
class CodexTimeLapseWindow {};
class GraphsWindow {};
class DeploymentSchedule {};
class BLUnZip {};
class Fire {};
class ScriptSystem {};
class ContrabandSystem {};
class RapSheetWorkAndEducationWindow {};
class BitInput {};
class Orderly {};
class PowerSystem {};
class Battery {};
class Guard {};
class RequiredMods {};
class JoypadButton {};
class ContextMenu {};
class DrinkingFountain {};
class WorldReadResult {};
class PenaltyTemplate {};
class SectorBroadcast {};
class RAROptions {};
class SoundInstance {};
class PolaroidSystem {};
class RestaurantMealCooking {};
class VictoryConditionTemplate {};

typedef dword Matrix;

class ObjectiveRenderData_TextElement {};
class CloneRoomWallBlock {};
class FallenTreeMarkerIcon {};
class Log {};
class CodexOptionsWindowBase {};
class SearchCache {};
class SpriteMarker {};
class OrderlyMarkerIcon {};
class Informant {};
class ProfilerPlugin_SlowFrameCatcher {};
class BurstPipeMarkerIcon {};
class ReportsWindow {};
class GangHeatMapEvent {};
class AnimalDroppings {};
class Wired {};
class CSteamID {};
class InputField {};
class DrawModeRectangleOverlay {};
class RarTime {};
class CellColourRenderer {};
class SoundSampleBank {};
class PremadePrison {};
class FireSprinkler {};
class GameOverWindow {};
class ProductionSystem {};
class CodexModsWindow {};
class CakeStand {};
class PopsTelemetryEvent {};
class Electrical {};
class ClearPlanWindow {};
class GridNavigationSystem {};
class ApproveAllTransferWindow {};
class EscapingPrisonerIcon {};
class SubAllocator {};
class SectorWingMap {};
class Shader {};
class BMFontMetrics {};
class FinanceSystem {};
class SupplyChainOrder {};
class VictorySystem {};
class EntityNeedsLibrary {};
class Image {};
class WorldRenderer {};
class TextDataReader {};
class NamedRectangle {};
class MemMappedFileList {};
class LStringReader {};
class ProductionRule {};
class NeedsSystem {};
class ProfiledElement {};

typedef dword DataDirection;

class ThrownContraband {};
class CalamitySurfaceSystem {};
class SearchPoint {};
class ScheduleSearchMenuWindow {};
class RendererClipZone {};
class PlanningTool {};
class GangsWindow {};
class ArchiveUncompressor {};
class CrisisToolbar {};
class RestaurantCustomer {};
class CryptData {};
class Punchbag {};
class PatrolController {};
class KitchenTracker {};
class CodexCampaignWindow {};
class GangTemplate {};
class AutoHarvester {};
class Camera {};
class PhotonResult {};
class FamilyMember {};
class ChewedFenceMarkerIcon {};
class StaffNeedsSystem {};
class ResearchRequiredWindow {};
class CropDistributionData {};
class LightMapThread {};
class Dog {};
class BridgeMap {};
class StaffAlertPopUp {};
class PressurePad {};
class OverdoseIcon {};
class AvatarModeInfoWindow {};
class BitArray {};
class InfluenceBroadcastCell {};
class SaveFilePos {};
class PrefabMaterial {};
class PhotonInterfaceNew {};

typedef dword EUGCQuery;

class BlockedArea {};
class ObjectTemplate {};
class SoundObjectId {};
class VertexArrayManager {};
class SelectionList {};
class BirthdayPresent {};
class CodexLegalWindow {};
class RapSheetGradingWindow {};
class NewItemTracker {};
class PlayerMarker {};
class CrimeTemplate {};
class TweakableRegistry {};
class UncompressedArchive {};
class Hyphenator {};
class WaterSpout {};
class StereoSample {};

typedef dword NeedsWindowItem;

class WardenMode {};
class FinanceReport {};
class DeliveryMan {};
class Stack {};
class GuardTower {};
class ModSystem {};
class BitmapFontMetrics {};
class Thermometer {};
class WaterSystemCell {};
class Crop {};
class AppData {};
class RiotGuard {};
class AdviserSpeech {};
class Teacher {};
class Cooker {};
class ReoffendEntry {};
class MutexLock {};
class VisitationSystem {};
class CollectableSystem {};
class JoblistWindow {};
class StrikeFire {};
class DropDownMenu {};
class WeatherPregenerateSystem {};
class PolicyWindow {};
class CustomComponent {};
class BuildPlanWindow {};
class CropDistributionPopup {};
class StaffAlert {};
class BinaryFileReader {};
class FerryBoat {};
class MemMappedFileArchive {};
class CalamityRewardStruct {};
class LuaModule {};
class ArcadeMachine {};
class Table {};
class WageRatesPolicyWindow {};
class CodexMultiplayerStartWindow {};
class SoundInstanceBlueprint {};
class DialogPosition {};
class PatrolSystemCell {};
class CandidateContainer {};
class AnalyticsHTTPCallback {};
class DogHandler {};
class ResearchSystem {};
class WeightBench {};
class ContrabandTracker {};
class SentencesSystem {};
class RegimeWindow {};
class SoundSampleBankEditorWindow {};
class MiniMapWindow {};
class PowerSource {};
class ZoneRequirement {};
class VM_PreparedCommand {};
class ScriptZones {};
class DropDownOptionData {};
class SectorStation {};
class CurlThread {};
class lua_State {};
class AnalyticsRecord {};
class PrefabObject {};
class ScannerMonitor {};
class PlanningJob {};
class ShaderOpenGL {};
class WorkQueueItemLock {};
class Vehicle {};
class ReoffendingChanceDetail {};
class AppDialogRenderer {};
class DialogComponent {};
class ExecutionAssignment {};
class RestaurantSystem {};
class RenderStyleTable {};
class WeatherMapOptions {};
class RoomGrading {};
class DataRegistryItem {};
class EventDebugWindow {};
class DspSmoother {};
class DialogRenderEvent {};
class LightningRod {};
class JoypadDriver {};
class WorkQueue {};
class BinaryDataReader {};
class MultiTouch {};
class CalamityRewardSystem {};
class AutoScythe {};
class JoypadManager {};
class RarVM {};
class CoverageWindow {};
class JoypadInstance {};
class CodexOptionsWindow {};
class ReformProgramTemplate {};
class SoundSystem {};
class PatrolSystem {};
class ShowerHead {};
class NeedProviderTemplate {};

typedef dword CharacterEncoding;

class ReputationButton {};
class GangSegregationWindow {};
class DeploymentScheduler {};
class DogTunnelHistory {};
class SecuritySectorGrade {};
class BinaryDataWriter {};
class SoundSystemInterface {};
class EscapeTunnelManager {};
class CodexNewWindow {};
class ScannerMachine {};
class OpenGLFrameBuffer {};
class PhotonInterfaceOld {};
class ProductionList {};
class PrisonerBus {};
class RecursiveMutex {};
class SquadWindow {};
class BitmapInfoHeader {};
class TemperatureParameters {};
class CodexMapSettings {};
class SoundEditorWindow {};
class ConsumableAutoOrder {};
class Soldier {};
class Unlockables {};
class ConstructionSystem {};
class Supplychain {};
class SectorSystemDebugger {};
class HardwareCompatWindow {};
class SquadMemberInventory {};
class HWSendHTTPCallback {};
class DataRegistryEditor {};
class CodexOptionsGameplayWindow {};
class Container {};
class DoorTimerWindow {};
class FileHeader {};
class CodexPremadePrisonWindow {};
class TimeLapse {};
class Sniper {};
class Equipment {};
class POPS_SLegalGetDocumentsListResult {};
class UnlockSystem {};
class ChannelModifier {};

typedef dword float16_t;

class UndoButtonWindow {};
class ZoneTemplate {};
class EffectsSystem {};
class WeatherMap {};
class Visitor {};
class NeedsDistribution {};
class KnownContraband {};
class WeatherMapThread {};

typedef dword MESSAGE_TYPE;

class ArmisticeVolunteer {};
class RenderCache {};
class SoundLibrary3dInterface {};
class WorldEventPreReq {};
class JoinedCurveGenerator {};
class VertexArraySet {};
class DoorTimer {};
class FallenTree {};
class Sprite {};
class VehicleMarkerIcon {};
class SampleGroup {};
class InformantSystem {};
class CurveGenerator {};
class RawRead {};
class SoundParameterEditorWindow {};
class VertexArrayOpenGL {};
class CodexOptionsSubWindow {};
class PhotonNetworkingManager {};
class Room {};
class WardenSystem {};
class CutsceneCamera {};
class VictoryCondition {};
class RPCOptions {};
class SoundLibrary3d {};
class TrayDispenser {};
class MailSatchel {};
class SectorSystem {};
class CodexTesterToolWindow {};
class PowerSourceCapWindow {};
class SoundLibrary2d {};
class Campaign {};
class ValuationWindow {};
class RandomChooser {};
class ArchiveFileZIP {};
class AttractScreen {};
class RSCoder {};
class NewIntakeSystem {};
class CreditsWindow {};
class Matrix.conflict {};
class TextScroller {};
class CoveragePlanManager {};
class Rijndael {};
class ResearchWindow {};
class InputSlider {};

typedef dword OVERWRITE_MODE;

class HTTPSystem {};
class ResearchItem {};
class GuardMarkerIcon {};
class SoundInstanceId {};
class FallenCrateMarkerIcon {};
class ErrorWindow {};
class JoypadTestWindow {};
class ScratchedCell {};
class CampaignCutscene {};
class RendererOpenGL {};
class POPS_STelemetryData {};
class RollcallMarker {};
class EquipmentTemplate {};
class OutdoorSprinkler {};
class UncompressedArchiveList {};
class StatusToolbar {};
class CodexNamesInTheGameWindow {};
class EmulatedMouseButtonSDL2 {};
class FoodSystem {};
class OffscreenBuffer {};
class Canvas {};
class CoveragePlanEmergencyStruct {};
class DialogWindowEditor {};
class ReputationPoints {};
class WorldRenderer3D {};
class WindowResolution {};
class Cctv {};
class TyreApparatus {};
class CloudRead {};
class GuardPav {};
class MisconductReport {};
class Repairman {};
class OpenGLFrameBufferMultiSampled {};
class ReoffenderMarkerIcon {};
class Prop {};
class Garbage {};
class EncodeFileName {};
class SavedEntityData {};
class Door {};
class CodexCutscenesWindow {};
class POPS_SLegalGetDocumentResult {};
class EscapeMapIterator {};
class Profiler {};
class ApproveTransferWindow {};
class DeliveryLocation {};
class ContrabandLog {};
class CalloutTemplate {};
class DropDownWindow {};
class BinaryWriter {};
class VictoryWindow {};
class Dispatcher {};
class CropData {};
class WillBeDamagedElectricalCable {};
class ProgressBar {};
class ServingTable {};
class TopBarWindow {};
class CheckBox {};
class ArmisticeBanner {};
class FinanceWindow {};
class Transformer {};
class CodexMultiplayerOptions {};
class ScriptSystemLog {};
class Baby {};
class Avatar {};
class CodexOptionsGraphicsWindow {};
class PhotonInterfaceThread {};
class StaffBiography {};
class ObjectivesWindow {};
class WindSock {};
class CodexSteamWorkshopWindow {};
class MemMappedFileRAR {};
class LibraryShelf {};
class TextArchiveReader {};
class CodexLoadSaveWindow {};
class RapSheetExperienceWindow {};
class ErrorHandler {};
class GuardPavilion {};
class BLZip {};
class LogicCircuit {};
class DespawningObject {};
class WeatherAntenna {};

class MultiInputSlider {};
class PrisonerTracker {};
class CctvMonitor {};
class ArmedGuard {};
class Administrator {};
class MutatorWindow {};
class ConstructionPrefab {};
class ClockWindow {};
class PhoneMonitor {};
class Processor {};
class PolaroidPreviewWindow {};
class UpdateNITG_HeadCallback {};
class DripPipe {};
class Gatherer {};
class ConnectionMenu {};
class DeploymentScheduleWindow {};
class DoorProperties {};
class SoundLibrary3dSoftware {};
class RestaurantMeal {};
class ScoreWindow {};
class PipeValve {};
class Shape {};
class CutsceneCaption {};
class ReformProgramManager {};
class ChangeCellPopup {};
class TimeLapseEncoder {};
class GraphicsConfirmWindow {};
class OverheatMarkerIcon {};
class EightBitFontMetrics {};
class SquadMemberInfo {};
class DspBlueprint {};
class InventoryToolbar {};
class CodexMultiplayerJoinWindow {};
class HelpWindow {};
class RecursiveMutexLock {};
class UpdateNITG_GetCallback {};
class CalamityRewardRequirementStruct {};

typedef dword NavigationTab;

class SoundBlueprintManager {};
class PrisonerCellIcon {};
class CodexOverlay {};
class SupplyChainWindow {};
class EliteOpsHeli {};
class WardenModeSquadWindow {};
class BinaryArchiveReader {};
class DumbbellRack {};
class ExecutionSystem {};
class GangLeaderAssassinationIcon {};
class RapSheetCharacterWindow {};
class GangDealerMarkerIcon {};
class ModelPPM {};
class KitchenSink {};
class AppSoundInterface {};
class SoftwareChannel {};
class WaterStation {};
class CodexLanguageWindow {};
class VersionChangeHTTPCallback {};
class EscapeModeSquadWindow {};
class FastRandom {};
class SoundSampleHandle {};
class Preferences {};
class MemMappedFile {};
class ZoneInfo {};
class PolicySystem {};
class DinerBooth {};
class Fertilizer {};
class StaffAlertSystem {};
class ManufacturedObjectCount {};

typedef dword stun_msg_type;

class CodexOptionsSoundWindow {};
class ContrabandMarkerIcon {};
class CodexUsesModsWindow {};
class ModType {};
class Waterman {};
class DspBitCrusher {};
class ModNotificationWindow {};
class MedicalBed {};
class NavigationTabs {};
class ReformProgramAllocation {};
class AttractFade {};
class ObjectiveRenderData_FeedPrisoners {};
class BinaryFileWriter {};
class ScrollBar {};
class ProfilerPlugin_IntelVTune {};
class Treadmill {};
class SharedZipHandle {};
class IntakeWindow {};
class PhotonInterface {};
class StaffWindow {};
class DisplayList {};
class InfluenceSystem {};
class LStringFileReader {};
class PopsLegal {};
class WaterLeak {};
class BiographyGenerator {};
class OrderTypes {};
class ExecutionReportWindow {};
class WorldEventData {};
class KneeRaise {};
class MenuItem {};
class VehicleHijackMarker {};

typedef dword EResult;

class SentencesWindow {};
class PushUpStones {};
class LStringDataReader {};
class SpriteBankEditor {};
class MouseButtonSDL2 {};
class AchievementSystem {};
class InputWindow {};
class MotdHTTPCallback {};
class StatsTracker {};
class CCTVBadBehaviourIcon {};
class FireAlarmMarkerIcon {};
class VertexArrayRange {};
class TrainingDummy {};
class LabourManagementPopup {};
class GuardInvestigationSystem {};
class BackupGenerator {};
class ValuationCategory {};
class DialogManager {};
class NeedsWindow {};
class SteamTags {};
class PerformanceTest {};
class ApplyEffectParams {};

typedef dword Weather_e;
typedef dword Season_e;

class Layer {};

typedef dword seq;

class ScratchedCellIterator {};

typedef dword OverloadReason;
typedef dword PowerTypes;
// typedef dword {lambda(int&&,int&&,bool&&)#1};

class Char {};
class Info {};
class Common {};

typedef dword Direction;

class FrozenPeople {};
class WorkRateReduction {};
class FrozenTunnels {};
class FrozenPumps {};
class FrozenValves {};
class FluOutbreak {};
class FrozenPipes {};
class SteppingStonePath {};
class SteppingStone {};

typedef dword __normal_iterator;
typedef dword _Val_comp_iter;
typedef dword _Iter_less_iter;
typedef dword _Iter_pred;
typedef dword _Iter_comp_iter;
typedef dword _Iter_equals_val;
typedef dword _Rb_tree_iterator;
typedef dword random_access_iterator_tag;
typedef dword _Ios_Iostate;
typedef dword fpos;
typedef dword _Bit_iterator;
typedef dword _Manager_operation;
typedef dword _Bind;
typedef dword forward_iterator_tag;
typedef dword _Deque_iterator;
typedef dword _Ios_Seekdir;
typedef dword shared_ptr;
typedef dword _Ios_Openmode;
typedef dword function;
typedef dword integral_constant;
typedef dword initializer_list;
typedef dword _Rb_tree_const_iterator;
typedef dword _Node_const_iterator;

// typedef dword {lambda(int&&,ObjectId_const&,ObjectId_const&)#1};

class CalamityStatus {};

// typedef dword {lambda(int&&,int&&,int&&,int&&,int&&,int&&)#1};

class Bridge {};
class Tile {};
class DocumentListData {};
class DocumentData {};
class ObjectiveTelemetry {};
class Category {};
class NodeIndex {};
class IconData {};
class Frame {};
class Record {};

// typedef dword {lambda(int&&)#1};

class ScopedGangSpecialReputationValidator {};
class ScopedBioReputationValidator {};

typedef dword IconTypes;
typedef dword State;
typedef dword WebFlags;
typedef dword PunchConnState;
typedef dword type;
// typedef dword {lambda(int&&,int&&,int&&,int&&)#1};
typedef dword DefaultFactory;
typedef dword FileType;
// typedef dword {lambda(int&&,ObjectId_const&,bool&&)#1};
// typedef dword {lambda(int&&,int&&)#1};
// typedef dword {lambda(int&&,ObjectId_const&,int&&)#1};

typedef int (* __compar_fn_t)(void *, void *);
typedef unsigned short sa_family_t;
typedef __socklen_t socklen_t;

struct addrinfo {
    int ai_flags;
    int ai_family;
    int ai_socktype;
    int ai_protocol;
    socklen_t ai_addrlen;
    sockaddr * ai_addr;
    char * ai_canonname;
    addrinfo * ai_next;
};

struct sockaddr {
    sa_family_t sa_family;
    char sa_data[14];
};

typedef struct MD5state_st MD5_CTX;

struct MD5state_st {
    unsigned int A;
    unsigned int B;
    unsigned int C;
    unsigned int D;
    unsigned int Nl;
    unsigned int Nh;
    unsigned int data[16];
    unsigned int num;
};

typedef struct evp_pkey_ctx_st EVP_PKEY_CTX;
struct evp_pkey_ctx_st {};

struct timezone {
    int tz_minuteswest;
    int tz_dsttime;
};

typedef __clockid_t clockid_t;

struct timeval {
    __time_t tv_sec;
    __suseconds_t tv_usec;
};

typedef struct timezone * __timezone_ptr_t;
typedef __clock_t clock_t;
typedef __time_t time_t;

struct tm {
    int tm_sec;
    int tm_min;
    int tm_hour;
    int tm_mday;
    int tm_mon;
    int tm_year;
    int tm_wday;
    int tm_yday;
    int tm_isdst;
    long tm_gmtoff;
    char *tm_zone;
};

typedef long __fd_mask;

struct fd_set {
    __fd_mask fds_bits[16];
};

typedef void * iconv_t;

typedef enum Elf_ProgramHeaderType {
    PT_NULL=0,
    PT_LOAD=1,
    PT_DYNAMIC=2,
    PT_INTERP=3,
    PT_NOTE=4,
    PT_SHLIB=5,
    PT_PHDR=6,
    PT_TLS=7,
    PT_GNU_EH_FRAME=1685382480,
    PT_GNU_STACK=1685382481,
    PT_GNU_RELRO=1685382482
} Elf_ProgramHeaderType;

struct Elf64_Phdr {
    enum Elf_ProgramHeaderType p_type;
    dword p_flags;
    qword p_offset;
    qword p_vaddr;
    qword p_paddr;
    qword p_filesz;
    qword p_memsz;
    qword p_align;
};

struct Elf64_Rela {
    qword r_offset; // location to apply the relocation action
    qword r_info; // the symbol table index and the type of relocation
    qword r_addend; // a constant addend used to compute the relocatable field value
};

typedef enum Elf_SectionHeaderType {
    SHT_NULL=0,
    SHT_PROGBITS=1,
    SHT_SYMTAB=2,
    SHT_STRTAB=3,
    SHT_RELA=4,
    SHT_HASH=5,
    SHT_DYNAMIC=6,
    SHT_NOTE=7,
    SHT_NOBITS=8,
    SHT_REL=9,
    SHT_SHLIB=10,
    SHT_DYNSYM=11,
    SHT_INIT_ARRAY=14,
    SHT_FINI_ARRAY=15,
    SHT_PREINIT_ARRAY=16,
    SHT_GROUP=17,
    SHT_SYMTAB_SHNDX=18,
    SHT_ANDROID_REL=1610612737,
    SHT_ANDROID_RELA=1610612738,
    SHT_GNU_ATTRIBUTES=1879048181,
    SHT_GNU_HASH=1879048182,
    SHT_GNU_LIBLIST=1879048183,
    SHT_CHECKSUM=1879048184,
    SHT_SUNW_move=1879048186,
    SHT_SUNW_COMDAT=1879048187,
    SHT_SUNW_syminfo=1879048188,
    SHT_GNU_verdef=1879048189,
    SHT_GNU_verneed=1879048190,
    SHT_GNU_versym=1879048191
} Elf_SectionHeaderType;

struct Elf64_Shdr {
    dword sh_name;
    enum Elf_SectionHeaderType sh_type;
    qword sh_flags;
    qword sh_addr;
    qword sh_offset;
    qword sh_size;
    dword sh_link;
    dword sh_info;
    qword sh_addralign;
    qword sh_entsize;
};

typedef enum Elf64_DynTag {
    DT_NULL=0,
    DT_NEEDED=1,
    DT_PLTRELSZ=2,
    DT_PLTGOT=3,
    DT_HASH=4,
    DT_STRTAB=5,
    DT_SYMTAB=6,
    DT_RELA=7,
    DT_RELASZ=8,
    DT_RELAENT=9,
    DT_STRSZ=10,
    DT_SYMENT=11,
    DT_INIT=12,
    DT_FINI=13,
    DT_SONAME=14,
    DT_RPATH=15,
    DT_SYMBOLIC=16,
    DT_REL=17,
    DT_RELSZ=18,
    DT_RELENT=19,
    DT_PLTREL=20,
    DT_DEBUG=21,
    DT_TEXTREL=22,
    DT_JMPREL=23,
    DT_BIND_NOW=24,
    DT_INIT_ARRAY=25,
    DT_FINI_ARRAY=26,
    DT_INIT_ARRAYSZ=27,
    DT_FINI_ARRAYSZ=28,
    DT_RUNPATH=29,
    DT_FLAGS=30,
    DT_PREINIT_ARRAY=32,
    DT_PREINIT_ARRAYSZ=33,
    DT_RELRSZ=35,
    DT_RELR=36,
    DT_RELRENT=37,
    DT_ANDROID_REL=1610612751,
    DT_ANDROID_RELSZ=1610612752,
    DT_ANDROID_RELA=1610612753,
    DT_ANDROID_RELASZ=1610612754,
    DT_ANDROID_RELR=1879040000,
    DT_ANDROID_RELRSZ=1879040001,
    DT_ANDROID_RELRENT=1879040003,
    DT_GNU_PRELINKED=1879047669,
    DT_GNU_CONFLICTSZ=1879047670,
    DT_GNU_LIBLISTSZ=1879047671,
    DT_CHECKSUM=1879047672,
    DT_PLTPADSZ=1879047673,
    DT_MOVEENT=1879047674,
    DT_MOVESZ=1879047675,
    DT_FEATURE_1=1879047676,
    DT_POSFLAG_1=1879047677,
    DT_SYMINSZ=1879047678,
    DT_SYMINENT=1879047679,
    DT_GNU_HASH=1879047925,
    DT_TLSDESC_PLT=1879047926,
    DT_TLSDESC_GOT=1879047927,
    DT_GNU_CONFLICT=1879047928,
    DT_GNU_LIBLIST=1879047929,
    DT_CONFIG=1879047930,
    DT_DEPAUDIT=1879047931,
    DT_AUDIT=1879047932,
    DT_PLTPAD=1879047933,
    DT_MOVETAB=1879047934,
    DT_SYMINFO=1879047935,
    DT_VERSYM=1879048176,
    DT_RELACOUNT=1879048185,
    DT_RELCOUNT=1879048186,
    DT_FLAGS_1=1879048187,
    DT_VERDEF=1879048188,
    DT_VERDEFNUM=1879048189,
    DT_VERNEED=1879048190,
    DT_VERNEEDNUM=1879048191,
    DT_AUXILIARY=2147483645,
    DT_FILTER=2147483647
} Elf64_DynTag;

struct Elf64_Dyn {
    enum Elf64_DynTag d_tag;
    qword d_val;
};

struct Gnu_BuildId {
    dword namesz; // Length of name field
    dword descsz; // Length of description field
    dword type; // Vendor specific type
    char name[4]; // Build-id vendor name
    byte description[20]; // Build-id value
};

struct Elf64_Ehdr {
    byte e_ident_magic_num;
    char e_ident_magic_str[3];
    byte e_ident_class;
    byte e_ident_data;
    byte e_ident_version;
    byte e_ident_osabi;
    byte e_ident_abiversion;
    byte e_ident_pad[7];
    word e_type;
    word e_machine;
    dword e_version;
    qword e_entry;
    qword e_phoff;
    qword e_shoff;
    dword e_flags;
    word e_ehsize;
    word e_phentsize;
    word e_phnum;
    word e_shentsize;
    word e_shnum;
    word e_shstrndx;
};

struct Elf64_Sym {
    dword st_name;
    byte st_info;
    byte st_other;
    word st_shndx;
    qword st_value;
    qword st_size;
};

typedef unsigned int uint32_t;
typedef unsigned short uint16_t;

struct group {
    char * gr_name;
    char * gr_passwd;
    __gid_t gr_gid;
    char * * gr_mem;
};

struct timespec {
    __time_t tv_sec;
    long tv_nsec;
}

// ============================================================================================

#include "TemplateClassesLinux.h"