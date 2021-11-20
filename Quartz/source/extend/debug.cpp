#include "../../include/quartz/extend/debug.h"
#include <sstream>

namespace Debug
{

#ifndef QUARTZ_CONIG_RELEASE

	void Log(std::string text)
	{
		std::time_t t = std::time(0);
		std::tm* now = std::localtime(&t);

		std::string hours, minutes, seconds;

		// Hours
		if (now->tm_hour < 10)
			hours = "0" + std::to_string(now->tm_hour);
		else
			hours = std::to_string(now->tm_hour);

		// Minutes
		if (now->tm_min < 10)
			minutes = "0" + std::to_string(now->tm_min);
		else
			minutes = std::to_string(now->tm_min);

		// Seconds
		if (now->tm_sec < 10)
			seconds = "0" + std::to_string(now->tm_sec);
		else
			seconds = std::to_string(now->tm_sec);

		// Log Time
		std::cout << "[" << hours << ":" << minutes << ":" << seconds << "] ";

		// Log Text
		std::cout << "[Log] " << text << std::endl;
	}

	void LogWarning(std::string text)
	{
		std::time_t t = std::time(0);
		std::tm* now = std::localtime(&t);
		std::string hours, minutes, seconds;

		// Hours
		if (now->tm_hour < 10)
			hours = "0" + std::to_string(now->tm_hour);
		else
			hours = std::to_string(now->tm_hour);

		// Minutes
		if (now->tm_min < 10)
			minutes = "0" + std::to_string(now->tm_min);
		else
			minutes = std::to_string(now->tm_min);

		// Seconds
		if (now->tm_sec < 10)
			seconds = "0" + std::to_string(now->tm_sec);
		else
			seconds = std::to_string(now->tm_sec);

		//Log Time
		std::cout << "[" << hours << ":" << minutes << ":" << seconds << "] ";

		//Log Warning
		std::cout << "\033[1;33m[Warning] " << text << "\033[0m" << std::endl;
	}

	void LogError(std::string text)
	{
		std::time_t t = std::time(0);
		std::tm* now = std::localtime(&t);
		std::string hours, minutes, seconds;

		// Hours
		if (now->tm_hour < 10)
			hours = "0" + std::to_string(now->tm_hour);
		else
			hours = std::to_string(now->tm_hour);

		// Minutes
		if (now->tm_min < 10)
			minutes = "0" + std::to_string(now->tm_min);
		else
			minutes = std::to_string(now->tm_min);

		// Seconds
		if (now->tm_sec < 10)
			seconds = "0" + std::to_string(now->tm_sec);
		else
			seconds = std::to_string(now->tm_sec);

		//Log Time
		std::cout << "[" << hours << ":" << minutes << ":" << seconds << "] ";

		//Log Error
		std::cout << "\033[31m[ERROR] " << text << "\033[0m" << std::endl;
	}

#else

	void Debug::Log(std::string text) { }

	void Debug::LogWarning(std::string text) {}

	void Debug::LogError(std::string text) {}
#endif

}