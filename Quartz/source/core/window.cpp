#include <iostream>

#include "engine.h"
#include "extend/debug.h"

#include "core/window.h"
#include "SDL2/SDL.h"
#include "Glad/glad.h"

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
		window = SDL_CreateWindow("Quartz", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
		if (!window)
		{
			Debug::LogError(("Error Creating Window: {}", SDL_GetError()));
			//std::cout << "Error Creating Window: " << SDL_GetError() << std::endl;
			return false;
		}

#ifdef QUARTZ_PLATFORM_MAC
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG);
#endif

		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

		SDL_SetWindowMinimumSize(window, 480, 270);

		glContext = SDL_GL_CreateContext(window);

		if (glContext == nullptr)
		{
			Debug::Log( ("Error creating OpenGL context: {}", SDL_GetError()) );
		}

		gladLoadGLLoader(SDL_GL_GetProcAddress);

		// TODO: Move this to a renderer Init call;
		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LEQUAL);

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glClearColor(255, 0, 0, 255);

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

	void Window::BeginRender()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void Window::EndRender()
	{
		SDL_GL_SwapWindow(window);
	}
}