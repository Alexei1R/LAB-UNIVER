#pragma once 

#include "../vendor/spdlog/include/spdlog/spdlog.h"
#include "../vendor/spdlog/include/spdlog/sinks/stdout_color_sinks.h"
#include "../vendor/spdlog/include/spdlog/fmt/ostr.h"
#include "macros.h"

	class Log
	{
	public:
		static void Init();

		inline static Ref<spdlog::logger>& GetLogger() { return s_Logger; }
	private:
		static Ref<spdlog::logger> s_Logger;
	};
	
	
	
	namespace LOG{

// Core log macros
#define LOG_TRACE(...)    ::Log::GetLogger()->trace(__VA_ARGS__);
#define LOG_INFO(...)     ::Log::GetLogger()->info(__VA_ARGS__);
#define LOG_WARN(...)     ::Log::GetLogger()->warn(__VA_ARGS__);
#define LOG_ERROR(...)    ::Log::GetLogger()->error(__VA_ARGS__);
#define LOG_CRITICAL(...) ::Log::GetLogger()->critical(__VA_ARGS__);

	}




