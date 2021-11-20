#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>

namespace Debug
{
	void Log(std::string text);

	void LogWarning(std::string text);

	void LogError(std::string text);
}