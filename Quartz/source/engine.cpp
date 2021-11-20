#include <iostream>
#include "engine.h"

#include "SDL2/SDL.h"

namespace Quartz
{
	// - -- Public -- -

	Engine& Engine::Instance()
	{
		if (!instance) 
		{
			instance = new Engine();
		}

		return *instance;
	}

	void Engine::Run() 
	{
		if (Initialize())
		{
			// Game Loop
			while (isRunning)
			{
				window.BloatEvents();
			}
		}
		Shutdown();
	}

	// - -- Private -- -

	bool Engine::Initialize()
	{
		bool retrn = false;

		if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		{
			std::cout << "Error initializing SDL2: " << SDL_GetError() << std::endl;
		}
		else
		{
			SDL_version version;
			SDL_VERSION(&version);

			std::cout << "SDL " << (int32_t)version.major << "." << (int32_t)version.minor << "." << (int32_t)version.patch << std::endl;

			if (window.Create())
			{
				retrn = true;
				isRunning = true;
			}
		}

		if (!retrn) 
		{
			std::cout << "Engine initialization failed. Shutting down." << std::endl;
		}

		return retrn;
	}

	void Engine::Shutdown()
	{
		isRunning = false;
		window.Shutdown();
		SDL_Quit();
	}

	//Get Information about current build
	void Engine::GetInfo() 
	{
#ifdef QUARTZ_CONFIG_DEBUG
		std::cout << "Configuration: DEBUG" << std::endl;
#endif

#ifdef QUARTZ_CONFIG_RELEASE
		std::cout << "Configuration: RELEASE" << std::endl;
#endif

#ifdef QUARTZ_PLATFORM_WINDOWS
		std::cout << "Platform: WINDOWS" << std::endl;
#endif

#ifdef QUARTZ_PLATFORM_LINUX
		std::cout << "Platform: LINUX" << std::endl;
#endif

#ifdef QUARTZ_PLATFORM_MAC
		std::cout << "Platform: MAC" << std::endl;
#endif
	}

	// - -- Singleton -- -
	Engine* Engine::instance = nullptr;

	Engine::Engine() : isRunning(false)
	{
		GetInfo();
	}
}