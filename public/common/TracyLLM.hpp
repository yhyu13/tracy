#ifndef __TRACYLowLevelMemory_HPP__
#define __TRACYLowLevelMemory_HPP__

#include <stdint.h>

// Inspired from UE5.4 LLM tags source code
// https://github.com/yhyu13/UnrealEngine/blob/5.4/Engine/Source/Runtime/Core/Public/HAL/LowLevelMemTracker.h

namespace tracy
{

namespace llm
{
#define LLM_STAT_NONE "STAT_None"
#define GET_STATFNAME(StatName) #StatName

// Do not add to these macros. Please use the LLM_DECLARE_TAG family of macros below to create new tags.
#define LLM_ENUM_GENERIC_TAGS(macro) \
	macro(Untagged,								"Untagged",						LLM_STAT_NONE,										-1)\
	macro(Paused,								"Paused",						LLM_STAT_NONE,										-1)\
	macro(Total,								"Total",						GET_STATFNAME(STAT_TrackedTotalSummaryLLM),		-1)\
	macro(Untracked,							"Untracked",					GET_STATFNAME(STAT_TrackedTotalSummaryLLM),		-1)\
	macro(PlatformTotal,						"Total",						LLM_STAT_NONE,										-1)\
	macro(TrackedTotal,							"TrackedTotal",					GET_STATFNAME(STAT_TrackedTotalSummaryLLM),		-1)\
	macro(UntaggedTotal,						"Untagged",						LLM_STAT_NONE,										-1)\
	macro(WorkingSetSize,						"WorkingSetSize",				GET_STATFNAME(STAT_TrackedTotalSummaryLLM),		-1)\
	macro(PagefileUsed,							"PagefileUsed",					GET_STATFNAME(STAT_TrackedTotalSummaryLLM),		-1)\
	macro(PlatformTrackedTotal,					"TrackedTotal",					LLM_STAT_NONE,										-1)\
	macro(PlatformUntaggedTotal,				"Untagged",						LLM_STAT_NONE,										-1)\
	macro(PlatformUntracked,					"Untracked",					LLM_STAT_NONE,										-1)\
	macro(PlatformOverhead,						"LLMOverhead",					LLM_STAT_NONE,										-1)\
	macro(PlatformOSAvailable,					"OSAvailable",					LLM_STAT_NONE,										-1)\
	/*FMalloc is a special tag that is reserved for the Platform Tracker only. It's used with ELLMAllocType::FMalloc to calculate LLMGenericTag::FMallocUnused. */								   \
	macro(FMalloc,								"FMalloc",						LLM_STAT_NONE,										-1)\
	macro(FMallocUnused,						"FMallocUnused",				GET_STATFNAME(STAT_EngineSummaryLLM),			-1)\
	macro(RHIUnused,							"RHIUnused",					GET_STATFNAME(STAT_EngineSummaryLLM),			-1)\
	macro(ThreadStack,							"ThreadStack",					GET_STATFNAME(STAT_EngineSummaryLLM),			-1)\
	macro(ThreadStackPlatform,					"ThreadStack",					LLM_STAT_NONE,										-1)\
	macro(ProgramSizePlatform,					"ProgramSize",					LLM_STAT_NONE,										-1)\
	macro(ProgramSize,							"ProgramSize",					GET_STATFNAME(STAT_EngineSummaryLLM),			-1)\
	macro(BackupOOMMemoryPoolPlatform,			"OOMBackupPool",				LLM_STAT_NONE,										-1)\
	macro(BackupOOMMemoryPool,					"OOMBackupPool",				GET_STATFNAME(STAT_EngineSummaryLLM),			-1)\
	macro(GenericPlatformMallocCrash,			"GenericPlatformMallocCrash",	GET_STATFNAME(STAT_EngineSummaryLLM),			-1)\
	macro(GenericPlatformMallocCrashPlatform,	"GenericPlatformMallocCrash",	GET_STATFNAME(STAT_EngineSummaryLLM),			-1)\
	/* Any low-level memory that is not tracked in any other category. */ \
	macro(EngineMisc,							"EngineMisc",					GET_STATFNAME(STAT_EngineSummaryLLM),			-1)\
	/* Any task kicked off from the task graph that doesn't have its own category. Should be fairly low. */ \
	macro(TaskGraphTasksMisc,					"TaskGraphMiscTasks",			GET_STATFNAME(STAT_EngineSummaryLLM),			-1)\
	macro(LinearAllocator,						"LinearAllocator",				LLM_STAT_NONE,										-1)\
	macro(Audio,								"Audio",						GET_STATFNAME(STAT_AudioSummaryLLM),			-1)\
	macro(AudioMisc,							"AudioMisc",					GET_STATFNAME(STAT_AudioSummaryLLM),			LLMGenericTag::Audio)\
	macro(AudioSoundWaves,						"AudioSoundWaves",				GET_STATFNAME(STAT_AudioSummaryLLM),			LLMGenericTag::Audio)\
	macro(AudioSoundWaveProxies,				"AudioSoundWaveProxies",		GET_STATFNAME(STAT_AudioSummaryLLM),			LLMGenericTag::Audio)\
	macro(AudioMixer,							"AudioMixer",					GET_STATFNAME(STAT_AudioSummaryLLM),			LLMGenericTag::Audio)\
	macro(AudioMixerPlugins,					"AudioMixerPlugins",			GET_STATFNAME(STAT_AudioSummaryLLM),			LLMGenericTag::Audio)\
	macro(AudioPrecache,						"AudioPrecache",				GET_STATFNAME(STAT_AudioSummaryLLM),			LLMGenericTag::Audio)\
	macro(AudioDecompress,						"AudioDecompress",				GET_STATFNAME(STAT_AudioSummaryLLM),			LLMGenericTag::Audio)\
	macro(AudioRealtimePrecache,				"AudioRealtimePrecache",		GET_STATFNAME(STAT_AudioSummaryLLM),			LLMGenericTag::Audio)\
	macro(AudioFullDecompress,					"AudioFullDecompress",			GET_STATFNAME(STAT_AudioSummaryLLM),			LLMGenericTag::Audio)\
	macro(AudioStreamCache,						"AudioStreamCache",				GET_STATFNAME(STAT_AudioSummaryLLM),			LLMGenericTag::Audio)\
	macro(AudioSynthesis,						"AudioSynthesis",				GET_STATFNAME(STAT_AudioSummaryLLM),			LLMGenericTag::Audio)\
	macro(RealTimeCommunications,				"RealTimeCommunications",		LLM_STAT_NONE,										-1)\
	macro(FName,								"FName",						GET_STATFNAME(STAT_EngineSummaryLLM),			-1)\
	macro(Networking,							"Networking",					GET_STATFNAME(STAT_NetworkingSummaryLLM),		-1)\
	macro(Meshes,								"Meshes",						GET_STATFNAME(STAT_MeshesSummaryLLM),			-1)\
	macro(Stats,								"Stats",						GET_STATFNAME(STAT_EngineSummaryLLM),			-1)\
	macro(Shaders,								"Shaders",						GET_STATFNAME(STAT_EngineSummaryLLM),			-1)\
	macro(PSO,									"PSO",							GET_STATFNAME(STAT_EngineSummaryLLM),			-1)\
	macro(Textures,								"Textures",						GET_STATFNAME(STAT_TexturesSummaryLLM),			-1)\
	macro(TextureMetaData,						"TextureMetaData",				GET_STATFNAME(STAT_TexturesSummaryLLM),			-1)\
	macro(VirtualTextureSystem,					"VirtualTextureSystem",			GET_STATFNAME(STAT_TexturesSummaryLLM),			-1)\
	macro(RenderTargets,						"RenderTargets",				GET_STATFNAME(STAT_EngineSummaryLLM),			-1)\
	macro(SceneRender,							"SceneRender",					GET_STATFNAME(STAT_EngineSummaryLLM),			-1)\
	macro(RHIMisc,								"RHIMisc",						GET_STATFNAME(STAT_EngineSummaryLLM),			-1)\
	macro(AsyncLoading,							"AsyncLoading",					GET_STATFNAME(STAT_EngineSummaryLLM),			-1)\
    /* UObject is a catch-all for all Engine and game memory that is not tracked in any other category. */ \
	/* it includes any class inherited from UObject and anything that is serialized by that class including properties. */ \
	/* Note that this stat doesn't include Mesh or Animation data which are tracked separately. */ \
	/* It is correlated to the number of Objects placed in the Level. */ \
	macro(UObject,								"UObject",						GET_STATFNAME(STAT_UObjectSummaryLLM),			-1)\
	macro(Animation,							"Animation",					GET_STATFNAME(STAT_AnimationSummaryLLM),		-1)\
	/* This is the UStaticMesh class and related properties, and does not include the actual mesh data. */ \
	macro(StaticMesh,							"StaticMesh",					GET_STATFNAME(STAT_StaticMeshSummaryLLM),		LLMGenericTag::Meshes)\
	macro(Materials,							"Materials",					GET_STATFNAME(STAT_MaterialsSummaryLLM),		-1)\
	macro(Particles,							"Particles",					GET_STATFNAME(STAT_ParticlesSummaryLLM),		-1)\
	macro(Niagara,								"Niagara",						GET_STATFNAME(STAT_NiagaraSummaryLLM),			-1)\
	macro(GPUSort,								"GPUSort",						GET_STATFNAME(STAT_EngineSummaryLLM),			-1)\
	macro(GC,									"GC",							GET_STATFNAME(STAT_EngineSummaryLLM),			-1)\
	macro(UI,									"UI",							GET_STATFNAME(STAT_UISummaryLLM),				-1)\
	macro(NavigationRecast,						"NavigationRecast",				GET_STATFNAME(STAT_NavigationSummaryLLM),		-1)\
	macro(Physics,								"Physics",						GET_STATFNAME(STAT_PhysicsSummaryLLM),			-1)\
	macro(PhysX,								"PhysX",						GET_STATFNAME(STAT_PhysXSummaryLLM),			LLMGenericTag::Physics)\
	macro(PhysXGeometry,						"PhysXGeometry",				GET_STATFNAME(STAT_PhysXSummaryLLM),			LLMGenericTag::Physics)\
	macro(PhysXTrimesh,							"PhysXTrimesh",					GET_STATFNAME(STAT_PhysXSummaryLLM),			LLMGenericTag::Physics)\
	macro(PhysXConvex,							"PhysXConvex",					GET_STATFNAME(STAT_PhysXSummaryLLM),			LLMGenericTag::Physics)\
	macro(PhysXAllocator,						"PhysXAllocator",				GET_STATFNAME(STAT_PhysXSummaryLLM),			LLMGenericTag::Physics)\
	macro(PhysXLandscape,						"PhysXLandscape",				GET_STATFNAME(STAT_PhysXSummaryLLM),			LLMGenericTag::Physics)\
	macro(Chaos,								"Chaos",						GET_STATFNAME(STAT_ChaosSummaryLLM),			LLMGenericTag::Physics)\
	macro(ChaosGeometry,						"ChaosGeometry",				GET_STATFNAME(STAT_ChaosSummaryLLM),			LLMGenericTag::Physics)\
	macro(ChaosAcceleration,					"ChaosAcceleration",			GET_STATFNAME(STAT_ChaosSummaryLLM),			LLMGenericTag::Physics)\
	macro(ChaosParticles,						"ChaosParticles",				GET_STATFNAME(STAT_ChaosSummaryLLM),			LLMGenericTag::Physics)\
	macro(ChaosLandscape,						"ChaosLandscape",				GET_STATFNAME(STAT_ChaosSummaryLLM),			LLMGenericTag::Physics)\
	macro(ChaosTrimesh,							"ChaosTrimesh",					GET_STATFNAME(STAT_ChaosSummaryLLM),			LLMGenericTag::Physics)\
	macro(ChaosConvex,							"ChaosConvex",					GET_STATFNAME(STAT_ChaosSummaryLLM),			LLMGenericTag::Physics)\
	macro(ChaosScene,							"ChaosScene",					GET_STATFNAME(STAT_ChaosSummaryLLM),			LLMGenericTag::Physics)\
	macro(ChaosUpdate,							"ChaosUpdate",					GET_STATFNAME(STAT_ChaosSummaryLLM),			LLMGenericTag::Physics)\
	macro(ChaosActor,							"ChaosActor",					GET_STATFNAME(STAT_ChaosSummaryLLM),			LLMGenericTag::Physics)\
	macro(ChaosBody,							"ChaosBody",					GET_STATFNAME(STAT_ChaosSummaryLLM),			LLMGenericTag::Physics)\
	macro(ChaosConstraint,						"ChaosConstraint",				GET_STATFNAME(STAT_ChaosSummaryLLM),			LLMGenericTag::Physics)\
	macro(ChaosMaterial,						"ChaosMaterial",				GET_STATFNAME(STAT_ChaosSummaryLLM),			LLMGenericTag::Physics)\
	macro(EnginePreInitMemory,					"EnginePreInit",				GET_STATFNAME(STAT_EngineSummaryLLM),			-1)\
	macro(EngineInitMemory,						"EngineInit",					GET_STATFNAME(STAT_EngineSummaryLLM),			-1)\
	macro(RenderingThreadMemory,				"RenderingThread",				GET_STATFNAME(STAT_EngineSummaryLLM),			-1)\
	macro(LoadMapMisc,							"LoadMapMisc",					GET_STATFNAME(STAT_EngineSummaryLLM),			-1)\
	macro(StreamingManager,						"StreamingManager",				GET_STATFNAME(STAT_EngineSummaryLLM),			-1)\
	macro(GraphicsPlatform,						"Graphics",						LLM_STAT_NONE,										-1)\
	macro(FileSystem,							"FileSystem",					GET_STATFNAME(STAT_EngineSummaryLLM),			-1)\
	macro(Localization,							"Localization",					GET_STATFNAME(STAT_EngineSummaryLLM),			-1)\
	macro(AssetRegistry,						"AssetRegistry",				GET_STATFNAME(STAT_EngineSummaryLLM),			-1)\
	macro(ConfigSystem,							"ConfigSystem",					GET_STATFNAME(STAT_EngineSummaryLLM),			-1)\
	macro(InitUObject,							"InitUObject",					GET_STATFNAME(STAT_EngineSummaryLLM),			-1)\
	macro(VideoRecording,						"VideoRecording",				GET_STATFNAME(STAT_EngineSummaryLLM),			-1)\
	macro(Replays,								"Replays",						GET_STATFNAME(STAT_NetworkingSummaryLLM),		LLMGenericTag::Networking)\
	macro(MaterialInstance,						"MaterialInstance",				GET_STATFNAME(STAT_EngineSummaryLLM),			-1)\
	macro(SkeletalMesh,							"SkeletalMesh",					GET_STATFNAME(STAT_EngineSummaryLLM),			LLMGenericTag::Meshes)\
	macro(InstancedMesh,						"InstancedMesh",				GET_STATFNAME(STAT_EngineSummaryLLM),			LLMGenericTag::Meshes)\
	macro(Landscape,							"Landscape",					GET_STATFNAME(STAT_EngineSummaryLLM),			LLMGenericTag::Meshes)\
	macro(CsvProfiler,							"CsvProfiler",					GET_STATFNAME(STAT_EngineSummaryLLM),			-1)\
	macro(MediaStreaming,						"MediaStreaming",				GET_STATFNAME(STAT_MediaStreamingSummaryLLM),	-1)\
	macro(ElectraPlayer,						"ElectraPlayer",				GET_STATFNAME(STAT_MediaStreamingSummaryLLM),	LLMGenericTag::MediaStreaming)\
	macro(WMFPlayer,							"WMFPlayer",					GET_STATFNAME(STAT_MediaStreamingSummaryLLM),	LLMGenericTag::MediaStreaming)\
	macro(PlatformMMIO,							"MMIO",							LLM_STAT_NONE,										-1)\
	macro(PlatformVM,							"Virtual Memory",				LLM_STAT_NONE,										-1)\
	macro(CustomName,							"CustomName",					LLM_STAT_NONE,										-1)\

/*
 * Enum values to be passed in to LLM_SCOPE() macro
 */
enum class LLMGenericTag : uint8_t
{
#define LLM_ENUM(Enum,Str,Group,Parent) Enum,
	LLM_ENUM_GENERIC_TAGS(LLM_ENUM)
#undef LLM_ENUM

	GenericTagCount,

	//------------------------------
	// Custom tags
	CustomTagStart = 111,
	CustomTagEnd = 255,

};
static_assert( LLMGenericTag::GenericTagCount <= LLMGenericTag::CustomTagStart, "too many generic LLM tags defined"); 

constexpr inline uint32_t LLM_TAG_COUNT = 256;
constexpr inline uint32_t LLM_GENERIC_TAG_COUNT = static_cast<uint32_t>(LLMGenericTag::GenericTagCount);
constexpr inline uint32_t LLM_CUSTOM_TAG_START = static_cast<uint32_t>(LLMGenericTag::CustomTagStart); // Custom tag is from CustomTagStart to CustomTagEnd
constexpr inline uint32_t LLM_CUSTOM_TAG_END = static_cast<uint32_t>(LLMGenericTag::CustomTagEnd); // Custom tag is from CustomTagStart to CustomTagEnd

namespace generic
{
    /**
     * @brief Convert a generic LLM tag to a generic LLM tag index
     * 
     * @param Tag  The tag to convert
     * @return int32_t  The index of the tag, or -1 if the tag is invalid
     */
    inline int32_t CastToGenericLLMTag(uint8_t Tag)
    {
        if (Tag < LLM_GENERIC_TAG_COUNT)
        {
            return Tag;
        }
        return -1;
    }

    inline const char* _LLMGenericTagNames[] = {
    #define LLM_ENUM(Enum,Str,Group,Parent) Str,
        LLM_ENUM_GENERIC_TAGS(LLM_ENUM)
    #undef LLM_ENUM
    };

    /**
     * @brief Get the Generic L L M Tag Name object
     * 
     * @param Tag  The tag to get the name of
     * @return const char*  The name of the tag, or "N/A" if the tag is invalid
     */
    inline const char* GetGenericLLMTagName(uint8_t Tag)
    {
        if (Tag < LLM_GENERIC_TAG_COUNT)
        {
            return _LLMGenericTagNames[Tag];
        }
        return "N/A";
    }

    inline const char* _LLMGenericStatGroupNames[] = {
    #define LLM_ENUM(Enum,Str,Group,Parent) Group,
        LLM_ENUM_GENERIC_TAGS(LLM_ENUM)
    #undef LLM_ENUM
    };

    /**
     * @brief Get the Generic L L M Stat Group Name object
     * 
     * @param Tag  The tag to get the stat group name of
     * @return const char*  The name of the stat group, or "N/A" if the tag is invalid
     */
    inline const char* GetGenericLLMStatGroupName(uint8_t Tag)
    {
        if (Tag < LLM_GENERIC_TAG_COUNT)
        {
            return _LLMGenericStatGroupNames[Tag];
        }
        return "N/A";
    }

    inline int32_t _LLMGenericParentTag[] = {
    #define LLM_ENUM(Enum,Str,Group,Parent) static_cast<int32_t>(Parent),
        LLM_ENUM_GENERIC_TAGS(LLM_ENUM)
    #undef LLM_ENUM
    };

    /**
     * @brief Get the parent tag of a generic LLM tag
     * 
     * @param Tag  The tag to get the parent of
     * @return int32_t  The parent tag, or -1 if the tag is invalid or has no parent
     */
    inline int32_t GetGenericLLMTagParent(uint8_t Tag)
    {
        if (Tag < LLM_GENERIC_TAG_COUNT)
        {
            return _LLMGenericParentTag[Tag];
        }
        return -1;
    }
}

namespace custom
{
    /**
     * @brief Convert a custom LLM tag to a custom LLM tag index
     * 
     * @param Tag  The tag to convert
     * @return int32_t  The index of the tag, or -1 if the tag is invalid
     */
    inline int32_t CastToCustomLLMTag(uint8_t Tag)
    {
        if (Tag >= LLM_CUSTOM_TAG_START && Tag <= LLM_CUSTOM_TAG_END)
        {
            return Tag;
        }
        return -1;
    }

    // @User Initialize this array!
    inline const char** _LLMCustomTagNames = nullptr;

    /**
     * @brief Get the Custom L L M Tag Name object
     * 
     * @param Tag  The tag to get the name of
     * @return const char*  The name of the tag, or "N/A" if the tag is invalid
     */
    inline const char* GetCustomLLMTagName(uint8_t Tag)
    {
        if (Tag >= LLM_CUSTOM_TAG_START && Tag <= LLM_CUSTOM_TAG_END)
        {
            if (_LLMCustomTagNames)
            {
                return _LLMCustomTagNames[Tag];
            }
            else
            {
                return "CustomTagUninitialized";
            }
        }
        return "N/A";
    }

    // @User Initialize this array!
    inline const char** _LLMCustomStatGroupNames = nullptr;

    /**
     * @brief Get the Custom L L M Stat Group Name object
     * 
     * @param Tag  The tag to get the stat group name of
     * @return const char*  The name of the stat group, or "N/A" if the tag is invalid
     */
    inline const char* GetCustomLLMStatGroupName(uint8_t Tag)
    {
        if (Tag >= LLM_CUSTOM_TAG_START && Tag <= LLM_CUSTOM_TAG_END)
        {
            if (_LLMCustomStatGroupNames)
            {
                return _LLMCustomStatGroupNames[Tag];
            }
            else
            {
                return "CustomTagUninitialized";
            }
        }
        return "N/A";
    }

    // @User Initialize this array!
    inline int32_t* _LLMCustomParentTag = nullptr;

    /**
     * @brief Get the parent tag of a custom LLM tag
     * 
     * @param Tag  The tag to get the parent of
     * @return int32_t  The parent tag, or -1 if the tag is invalid or has no parent
     */
    inline int32_t GetCustomLLMTagParent(uint8_t Tag)
    {
        if (Tag >= LLM_CUSTOM_TAG_START && Tag <= LLM_CUSTOM_TAG_END)
        {
            if (_LLMCustomParentTag)
            {
                return _LLMCustomParentTag[Tag];
            }
            else
            {
                return -1;
            }
        }
        return -1;
    }
}

#undef LLM_ENUM_GENERIC_TAGS
#undef LLM_STAT_NONE
#undef GET_STATFNAME
}

}

#endif