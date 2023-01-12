#pragma once


// Core log macros
#define LOG_TRACE(...)    ::Log::GetLogger()->trace(__VA_ARGS__);
#define LOG_INFO(...)     ::Log::GetLogger()->info(__VA_ARGS__);
#define LOG_WARN(...)     ::Log::GetLogger()->warn(__VA_ARGS__);
#define LOG_ERROR(...)    ::Log::GetLogger()->error(__VA_ARGS__);
#define LOG_CRITICAL(...) ::Log::GetLogger()->critical(__VA_ARGS__);


template<typename T>
using Scope = std::unique_ptr<T>;
template<typename T, typename ... Args>
constexpr Scope<T> CreateScope(Args&& ... args)
{
	return std::make_unique<T>(std::forward<Args>(args)...);
}

template<typename T>
using Ref = std::shared_ptr<T>;
template<typename T, typename ... Args>
constexpr Ref<T> CreateRef(Args&& ... args)
{
	return std::make_shared<T>(std::forward<Args>(args)...);
}