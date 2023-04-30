#pragma once
#include<memory>

#include <spdlog/spdlog.h>
namespace Core
{
	class Log
	{
	public:
		static void Init();

		inline static std::shared_ptr < spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

#define ENGINE_CORE_TRACE(...)::Core::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define ENGINE_CORE_LOG(...)::Core::Log::GetCoreLogger()->debug(__VA_ARGS__)
#define ENGINE_CORE_INFO(...)::Core::Log::GetCoreLogger()->info(__VA_ARGS__)
#define ENGINE_CORE_WARNING(...)::Core::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define ENGINE_CORE_ERROR(...)::Core::Log::GetCoreLogger()->error(__VA_ARGS__)
#define ENGINE_CORE_CRITICAL(...)::Core::Log::GetCoreLogger()->critical(__VA_ARGS__)

#define ENGINE_CLIENT_TRACE(...)::Core::Log::GetClientLogger()->trace(__VA_ARGS__)
#define ENGINE_CLIENT_LOG(...)::Core::Log::GetClientLogger()->debug(__VA_ARGS__)
#define ENGINE_CLIENT_INFO(...)::Core::Log::GetClientLogger()->info(__VA_ARGS__)
#define ENGINE_CLIENT_WARNING(...)::Core::Log::GetClientLogger()->warn(__VA_ARGS__)
#define ENGINE_CLIENT_ERROR(...)::Core::Log::GetClientLogger()->error(__VA_ARGS__)
#define ENGINE_CLIENT_CRITICAL(...)::Core::Log::GetClientLogger()->critical(__VA_ARGS__)