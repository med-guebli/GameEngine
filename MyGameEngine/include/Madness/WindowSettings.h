#pragma once

#include<string>

namespace Madness {
	class WindowSettings {
	public:
		WindowSettings(const std::string& title, const unsigned int width, const unsigned int height) {
			this->m_title = title;
			this->m_width = width;
			this->m_height = height;
		}

		std::string GetTitle() {
			return this->m_title;
		}

		unsigned int GetWidth() {
			return this->m_width;
		}

		unsigned int GetHeight() {
			return this->m_height;
		}

	private:


	private:
		std::string m_title;
		unsigned int m_width;
		unsigned int m_height;
	};
}