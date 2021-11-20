#include <iostream>

#include "engine.h"
#include "extend/debug.h"

#include "core/window.h"
#include "SDL2/SDL.h"

namespace Quartz::Core
{
	Window::Window() : window(nullptr) {}
	Window::~Window()
	{
		if (window) 
		{
			Shutdown();
		}
	}

	bool Window::Create() 
	{
		window = SDL_CreateWindow("Quartz", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
		if (!window)
		{
			Debug::LogError(("Error Creating Window: {}", SDL_GetError()));
			//std::cout << "Error Creating Window: " << SDL_GetError() << std::endl;
			return false;
		}

		return true;
	}

	void Window::Shutdown() 
	{
		SDL_DestroyWindow(window);
		window = nullptr;
	}

	void Window::BloatEvents()
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				Engine::Instance().Quit();
				break;
			default:
				break;
			}
		}
	}
}