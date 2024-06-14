#ifndef __TRACYLowLevelMemory_HPP__
#define __TRACYLowLevelMemory_HPP__

#include <stdint.h>

// Inspired from UE5.4 LLM tags source code
// https://github.com/yhyu13/UnrealEngine/blob/5.4/Engine/Source/Runtime/Core/Public/HAL/LowLevelMemTracker.h

namespace tracy
{

namespace llm
{
#define TRACY_LLM_STAT_NONE "STAT_None"
#define TRACY_GET_STATFNAME(StatName) #StatName

    // UE4 custom
    #define TRACY_LLM_ENUM_GENERIC_TAGS(macro) \
	macro(Untagged,								"Untagged",						TRACY_LLM_STAT_NONE,										-1)\
	macro(Paused,								"Paused",						TRACY_LLM_STAT_NONE,										-1)\
	macro(Total,								"Total",						TRACY_GET_STATFNAME(STAT_TrackedTotalSummaryLLM),		-1)\
	macro(Untracked,							"Untracked",					TRACY_GET_STATFNAME(STAT_TrackedTotalSummaryLLM),		-1)\
	macro(PlatformTotal,						"Total",						TRACY_LLM_STAT_NONE,										-1)\
	macro(TrackedTotal,							"TrackedTotal",					TRACY_GET_STATFNAME(STAT_TrackedTotalSummaryLLM),		-1)\
	macro(UntaggedTotal,						"Untagged",						TRACY_LLM_STAT_NONE,										-1)\
	macro(WorkingSetSize,						"WorkingSetSize",				TRACY_GET_STATFNAME(STAT_TrackedTotalSummaryLLM),		-1)\
	macro(PagefileUsed,							"PagefileUsed",					TRACY_GET_STATFNAME(STAT_TrackedTotalSummaryLLM),		-1)\
	macro(PlatformTrackedTotal,					"TrackedTotal",					TRACY_LLM_STAT_NONE,										-1)\
	macro(PlatformUntaggedTotal,				"Untagged",						TRACY_LLM_STAT_NONE,										-1)\
	macro(PlatformUntracked,					"Untracked",					TRACY_LLM_STAT_NONE,										-1)\
	macro(PlatformOverhead,						"LLMOverhead",					TRACY_LLM_STAT_NONE,										-1)\
	macro(PlatformOSAvailable,					"OSAvailable",					TRACY_LLM_STAT_NONE,										-1)\
	macro(FMalloc,								"FMalloc",						TRACY_LLM_STAT_NONE,										-1)\
	macro(FMallocUnused,						"FMallocUnused",				TRACY_GET_STATFNAME(STAT_EngineSummaryLLM),			-1)\
	macro(ThreadStack,							"ThreadStack",					TRACY_GET_STATFNAME(STAT_EngineSummaryLLM),			-1)\
	macro(ThreadStackPlatform,					"ThreadStack",					TRACY_LLM_STAT_NONE,										-1)\
	macro(ProgramSizePlatform,					"ProgramSize",					TRACY_LLM_STAT_NONE,										-1)\
	macro(ProgramSize,							"ProgramSize",					TRACY_GET_STATFNAME(STAT_EngineSummaryLLM),			-1)\
	macro(BackupOOMMemoryPoolPlatform,			"OOMBackupPool",				TRACY_LLM_STAT_NONE,										-1)\
	macro(BackupOOMMemoryPool,					"OOMBackupPool",				TRACY_GET_STATFNAME(STAT_EngineSummaryLLM),			-1)\
	macro(GenericPlatformMallocCrash,			"GenericPlatformMallocCrash",	TRACY_GET_STATFNAME(STAT_EngineSummaryLLM),			-1)\
	macro(GenericPlatformMallocCrashPlatform,	"GenericPlatformMallocCrash",	TRACY_GET_STATFNAME(STAT_EngineSummaryLLM),			-1)\
	macro(EngineMisc,							"EngineMisc",					TRACY_GET_STATFNAME(STAT_EngineSummaryLLM),			-1)\
	macro(TaskGraphTasksMisc,					"TaskGraphMiscTasks",			TRACY_GET_STATFNAME(STAT_EngineSummaryLLM),			-1)\
	macro(Audio,								"Audio",						TRACY_GET_STATFNAME(STAT_AudioSummaryLLM),			-1)\
	macro(AudioMisc,							"AudioMisc",					TRACY_GET_STATFNAME(STAT_AudioSummaryLLM),			LLMGenericTag::Audio)\
	macro(AudioSoundWaves,						"AudioSoundWaves",				TRACY_GET_STATFNAME(STAT_AudioSummaryLLM),			LLMGenericTag::Audio)\
	macro(AudioMixer,							"AudioMixer",					TRACY_GET_STATFNAME(STAT_AudioSummaryLLM),			LLMGenericTag::Audio)\
	macro(AudioMixerPlugins,					"AudioMixerPlugins",			TRACY_GET_STATFNAME(STAT_AudioSummaryLLM),			LLMGenericTag::Audio)\
	macro(AudioPrecache,						"AudioPrecache",				TRACY_GET_STATFNAME(STAT_AudioSummaryLLM),			LLMGenericTag::Audio)\
	macro(AudioDecompress,						"AudioDecompress",				TRACY_GET_STATFNAME(STAT_AudioSummaryLLM),			LLMGenericTag::Audio)\
	macro(AudioRealtimePrecache,				"AudioRealtimePrecache",		TRACY_GET_STATFNAME(STAT_AudioSummaryLLM),			LLMGenericTag::Audio)\
	macro(AudioFullDecompress,					"AudioFullDecompress",			TRACY_GET_STATFNAME(STAT_AudioSummaryLLM),			LLMGenericTag::Audio)\
	macro(AudioStreamCache,						"AudioStreamCache",				TRACY_GET_STATFNAME(STAT_AudioSummaryLLM),			LLMGenericTag::Audio)\
	macro(AudioStreamCacheCompressedData,		"AudioStreamCacheCompressedData",TRACY_GET_STATFNAME(STAT_AudioSummaryLLM),			LLMGenericTag::Audio)\
	macro(AudioSynthesis,						"AudioSynthesis",				TRACY_GET_STATFNAME(STAT_AudioSummaryLLM),			LLMGenericTag::Audio)\
	macro(RealTimeCommunications,				"RealTimeCommunications",		TRACY_LLM_STAT_NONE,										-1)\
	macro(FName,								"FName",						TRACY_GET_STATFNAME(STAT_EngineSummaryLLM),			-1)\
	macro(Networking,							"Networking",					TRACY_GET_STATFNAME(STAT_EngineSummaryLLM),			-1)\
	macro(Meshes,								"Meshes",						TRACY_GET_STATFNAME(STAT_MeshesSummaryLLM),			-1)\
	macro(Stats,								"Stats",						TRACY_GET_STATFNAME(STAT_EngineSummaryLLM),			-1)\
	macro(Shaders,								"Shaders",						TRACY_GET_STATFNAME(STAT_EngineSummaryLLM),			-1)\
	macro(PSO,									"PSO",							TRACY_GET_STATFNAME(STAT_EngineSummaryLLM),			-1)\
	macro(Textures,								"Textures",						TRACY_GET_STATFNAME(STAT_TexturesSummaryLLM),			-1)\
	macro(TextureMetaData,						"TextureMetaData",				TRACY_GET_STATFNAME(STAT_TexturesSummaryLLM),			-1)\
	macro(VirtualTextureSystem,					"VirtualTextureSystem",			TRACY_GET_STATFNAME(STAT_TexturesSummaryLLM),			-1)\
	macro(RenderTargets,						"RenderTargets",				TRACY_GET_STATFNAME(STAT_EngineSummaryLLM),			-1)\
	macro(SceneRender,							"SceneRender",					TRACY_GET_STATFNAME(STAT_EngineSummaryLLM),			-1)\
	macro(RHIMisc,								"RHIMisc",						TRACY_GET_STATFNAME(STAT_EngineSummaryLLM),			-1)\
	macro(AsyncLoading,							"AsyncLoading",					TRACY_GET_STATFNAME(STAT_EngineSummaryLLM),			-1)\
	macro(UObject,								"UObject",						TRACY_GET_STATFNAME(STAT_UObjectSummaryLLM),			-1)\
	macro(Animation,							"Animation",					TRACY_GET_STATFNAME(STAT_AnimationSummaryLLM),		-1)\
	macro(StaticMesh,							"StaticMesh",					TRACY_GET_STATFNAME(STAT_StaticMeshSummaryLLM),		LLMGenericTag::Meshes)\
	macro(Materials,							"Materials",					TRACY_GET_STATFNAME(STAT_MaterialsSummaryLLM),		-1)\
	macro(Particles,							"Particles",					TRACY_GET_STATFNAME(STAT_ParticlesSummaryLLM),		-1)\
    /* XD_MISC_ADD_MORE_LLM_TAGS_FOR_ENGINE - Begin */ \
    macro(ParticlesFastPool,					"ParticlesFastPool",			TRACY_GET_STATFNAME(STAT_ParticlesSummaryLLM),		LLMGenericTag::Particles)\
    /* XD_MISC_ADD_MORE_LLM_TAGS_FOR_ENGINE - End */ \
	macro(Niagara,								"Niagara",						TRACY_GET_STATFNAME(STAT_NiagaraSummaryLLM),			-1)\
	macro(GPUSort,								"GPUSort",						TRACY_GET_STATFNAME(STAT_EngineSummaryLLM),			-1)\
	macro(GC,									"GC",							TRACY_GET_STATFNAME(STAT_EngineSummaryLLM),			-1)\
	macro(UI,									"UI",							TRACY_GET_STATFNAME(STAT_UISummaryLLM),				-1)\
	macro(NavigationRecast,						"NavigationRecast",				TRACY_GET_STATFNAME(STAT_NavigationSummaryLLM),		-1)\
	macro(Physics,								"Physics",						TRACY_GET_STATFNAME(STAT_PhysicsSummaryLLM),			-1)\
	macro(PhysX,								"PhysX",						TRACY_GET_STATFNAME(STAT_PhysXSummaryLLM),			LLMGenericTag::Physics)\
	macro(PhysXGeometry,						"PhysXGeometry",				TRACY_GET_STATFNAME(STAT_PhysXSummaryLLM),			LLMGenericTag::Physics)\
	macro(PhysXTrimesh,							"PhysXTrimesh",					TRACY_GET_STATFNAME(STAT_PhysXSummaryLLM),			LLMGenericTag::Physics)\
	macro(PhysXConvex,							"PhysXConvex",					TRACY_GET_STATFNAME(STAT_PhysXSummaryLLM),			LLMGenericTag::Physics)\
	macro(PhysXAllocator,						"PhysXAllocator",				TRACY_GET_STATFNAME(STAT_PhysXSummaryLLM),			LLMGenericTag::Physics)\
	macro(PhysXLandscape,						"PhysXLandscape",				TRACY_GET_STATFNAME(STAT_PhysXSummaryLLM),			LLMGenericTag::Physics)\
	macro(Chaos,								"Chaos",						TRACY_GET_STATFNAME(STAT_ChaosSummaryLLM),			LLMGenericTag::Physics)\
	macro(ChaosGeometry,						"ChaosGeometry",				TRACY_GET_STATFNAME(STAT_ChaosSummaryLLM),			LLMGenericTag::Physics)\
	macro(ChaosAcceleration,					"ChaosAcceleration",			TRACY_GET_STATFNAME(STAT_ChaosSummaryLLM),			LLMGenericTag::Physics)\
	macro(ChaosParticles,						"ChaosParticles",				TRACY_GET_STATFNAME(STAT_ChaosSummaryLLM),			LLMGenericTag::Physics)\
	macro(ChaosLandscape,						"ChaosLandscape",				TRACY_GET_STATFNAME(STAT_ChaosSummaryLLM),			LLMGenericTag::Physics)\
	macro(ChaosTrimesh,							"ChaosTrimesh",					TRACY_GET_STATFNAME(STAT_ChaosSummaryLLM),			LLMGenericTag::Physics)\
	macro(ChaosConvex,							"ChaosConvex",					TRACY_GET_STATFNAME(STAT_ChaosSummaryLLM),			LLMGenericTag::Physics)\
	macro(EnginePreInitMemory,					"EnginePreInit",				TRACY_GET_STATFNAME(STAT_EngineSummaryLLM),			-1)\
	macro(EngineInitMemory,						"EngineInit",					TRACY_GET_STATFNAME(STAT_EngineSummaryLLM),			-1)\
	macro(RenderingThreadMemory,				"RenderingThread",				TRACY_GET_STATFNAME(STAT_EngineSummaryLLM),			-1)\
	macro(LoadMapMisc,							"LoadMapMisc",					TRACY_GET_STATFNAME(STAT_EngineSummaryLLM),			-1)\
	macro(StreamingManager,						"StreamingManager",				TRACY_GET_STATFNAME(STAT_EngineSummaryLLM),			-1)\
	macro(GraphicsPlatform,						"Graphics",						TRACY_LLM_STAT_NONE,										-1)\
	macro(FileSystem,							"FileSystem",					TRACY_GET_STATFNAME(STAT_EngineSummaryLLM),			-1)\
	macro(Localization,							"Localization",					TRACY_GET_STATFNAME(STAT_EngineSummaryLLM),			-1)\
	macro(AssetRegistry,						"AssetRegistry",				TRACY_GET_STATFNAME(STAT_EngineSummaryLLM),			-1)\
	macro(ConfigSystem,							"ConfigSystem",					TRACY_GET_STATFNAME(STAT_EngineSummaryLLM),			-1)\
	macro(InitUObject,							"InitUObject",					TRACY_GET_STATFNAME(STAT_EngineSummaryLLM),			-1)\
	macro(VideoRecording,						"VideoRecording",				TRACY_GET_STATFNAME(STAT_EngineSummaryLLM),			-1)\
	macro(Replays,								"Replays",						TRACY_GET_STATFNAME(STAT_EngineSummaryLLM),			-1)\
	macro(MaterialInstance,						"MaterialInstance",				TRACY_GET_STATFNAME(STAT_EngineSummaryLLM),			-1)\
	macro(SkeletalMesh,							"SkeletalMesh",					TRACY_GET_STATFNAME(STAT_EngineSummaryLLM),			LLMGenericTag::Meshes)\
	macro(InstancedMesh,						"InstancedMesh",				TRACY_GET_STATFNAME(STAT_EngineSummaryLLM),			LLMGenericTag::Meshes)\
	macro(Landscape,							"Landscape",					TRACY_GET_STATFNAME(STAT_EngineSummaryLLM),			LLMGenericTag::Meshes)\
	macro(CsvProfiler,							"CsvProfiler",					TRACY_GET_STATFNAME(STAT_EngineSummaryLLM),			-1)\
	macro(MediaStreaming,						"MediaStreaming",				TRACY_GET_STATFNAME(STAT_MediaStreamingSummaryLLM),	-1)\
	macro(ElectraPlayer,						"ElectraPlayer",				TRACY_GET_STATFNAME(STAT_MediaStreamingSummaryLLM),	LLMGenericTag::MediaStreaming)\
	macro(WMFPlayer,							"WMFPlayer",					TRACY_GET_STATFNAME(STAT_MediaStreamingSummaryLLM),	LLMGenericTag::MediaStreaming)\
	macro(PlatformMMIO,							"MMIO",							TRACY_LLM_STAT_NONE,										-1)\
	macro(PlatformVM,							"Virtual Memory",				TRACY_LLM_STAT_NONE,										-1)\
	macro(CustomName,							"CustomName",					TRACY_LLM_STAT_NONE,										-1)\
	/* XD_OPT_LLMTAG_EXTENSIONS begin */																																					   \
	macro(ExtRunnableThreadRun,					"ExtRunnableThreadRun",																TRACY_LLM_STAT_NONE,										-1)\
	macro(ExtUpdateReflectionCaptureContent,	"ExtUpdateReflectionCaptureContent",												TRACY_LLM_STAT_NONE,										-1)\
	macro(ExtUpdateDeferredCaptures,			"ExtUpdateDeferredCaptures",														TRACY_LLM_STAT_NONE,										-1)\
	macro(ExtTikerTick,							"ExtTikerTick",																		TRACY_LLM_STAT_NONE,										-1)\
	macro(ExtWorldTick,							"ExtWorldTick",																		TRACY_LLM_STAT_NONE,										-1)\
	macro(ExtViewportDraw,						"ExtViewportDraw",																	TRACY_LLM_STAT_NONE,										-1)\
    /* XD_OPT_LLMTAG_EXTENSIONS end */
    
/*
 * Enum values to be passed in to LLM_SCOPE() macro
 */
enum class LLMGenericTag : uint8_t
{
#define LLM_ENUM(Enum,Str,Group,Parent) Enum,
	TRACY_LLM_ENUM_GENERIC_TAGS(LLM_ENUM)
#undef LLM_ENUM

	GenericTagCount,

	//------------------------------
	// Custom tags
	CustomTagStart = 111,
	CustomTagEnd = 255,

};
static_assert( LLMGenericTag::GenericTagCount <= LLMGenericTag::CustomTagStart, "too many generic LLM tags defined"); 

constexpr uint32_t LLM_TAG_COUNT = 256;
constexpr uint32_t LLM_GENERIC_TAG_COUNT = static_cast<uint32_t>(LLMGenericTag::GenericTagCount);
constexpr uint32_t LLM_CUSTOM_TAG_START = static_cast<uint32_t>(LLMGenericTag::CustomTagStart); // Custom tag is from CustomTagStart to CustomTagEnd
constexpr uint32_t LLM_CUSTOM_TAG_END = static_cast<uint32_t>(LLMGenericTag::CustomTagEnd); // Custom tag is from CustomTagStart to CustomTagEnd

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

    extern const char* _LLMGenericTagNames[];

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

    extern const char* _LLMGenericStatGroupNames[];

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

    extern int32_t _LLMGenericParentTag[];

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
    extern const char** _LLMCustomTagNames;

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
    extern const char** _LLMCustomStatGroupNames;

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
    extern int32_t* _LLMCustomParentTag;

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
}

}

#endif