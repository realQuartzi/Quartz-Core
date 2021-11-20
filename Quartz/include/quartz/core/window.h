#pragma once


struct SDL_Window;
using SDL_GLContext = void*;

namespace Quartz::Core
{
	class Window
	{
	public:
		Window();
		~Window();

		bool Create();
		void Shutdown();

		void BloatEvents();

		void BeginRender();
		void EndRender();

	private:
		SDL_Window* window;
		SDL_GLContext glContext;
	};
}