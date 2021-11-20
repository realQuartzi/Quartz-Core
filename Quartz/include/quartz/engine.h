#pragma once

#include "core/window.h"

namespace Quartz
{
	class Engine
	{
	public:
		static Engine& Instance();
		~Engine() {}

		void Run();
		inline void Quit()
		{
			isRunning = false;
		}

	private:
		void GetInfo();
		[[nodiscard]] bool Initialize();
		void Shutdown();

	private:
		bool isRunning;
		bool isInitialized;

		Core::Window window;

		// Singleton
		Engine();
		static Engine* instance;
	};


}