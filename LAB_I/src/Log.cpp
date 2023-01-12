#include "Log.h"


	Ref<spdlog::logger> Log::s_Logger;

	void Log::Init()
	{
		//spdlog::set_pattern("%^[%T] %n: %v%$");
		spdlog::set_pattern("%v%$");
		s_Logger = spdlog::stdout_color_mt("LABORATOR");
		s_Logger->set_level(spdlog::level::trace);

	}

