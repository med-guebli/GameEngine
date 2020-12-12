#pragma once

#include "Madness/window.h"

namespace Madness {
	class Engine {
	protected:
		Engine(Madness::WindowSettings& settings) :
			m_window(settings)
		{
			
		}

		virtual void OnUpdate() = 0;

	private:
		Madness::Window m_window;
	};
}