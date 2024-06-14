#include "TracyLLM.hpp"

namespace tracy
{

    namespace llm
    {
        namespace generic
        {
            const char* _LLMGenericTagNames[] = {
#define LLM_ENUM(Enum,Str,Group,Parent) Str,
                TRACY_LLM_ENUM_GENERIC_TAGS(LLM_ENUM)
            #undef LLM_ENUM
            };

            const char* _LLMGenericStatGroupNames[] = {
#define LLM_ENUM(Enum,Str,Group,Parent) Group,
                TRACY_LLM_ENUM_GENERIC_TAGS(LLM_ENUM)
            #undef LLM_ENUM
            };

            int32_t _LLMGenericParentTag[] = {
#define LLM_ENUM(Enum,Str,Group,Parent) static_cast<int32_t>(Parent),
                TRACY_LLM_ENUM_GENERIC_TAGS(LLM_ENUM)
            #undef LLM_ENUM
            };
        }

        namespace custom
        {
            const char** _LLMCustomTagNames = nullptr;
            const char** _LLMCustomStatGroupNames = nullptr;
            int32_t* _LLMCustomParentTag = nullptr;
        }
    }

}