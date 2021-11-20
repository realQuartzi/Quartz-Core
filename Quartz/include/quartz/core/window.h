#pragma once


struct SDL_Window;

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

	private:
		SDL_Window* window;
	};
}