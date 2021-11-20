#pragma once

#include <string>
#include <unordered_map>

namespace Quartz::Graphics
{
	class Shader
	{
	public:
		Shader(const std::string& vertex, const std::string& fragment);
		~Shader();

		void Bind();
		void Unbind();

		void SetUniformInt(const std::string& name, int value);
		void SetUniformFloat(const std::string& name, float value);
		void SetUniformFloat2(const std::string& name, float value1, float value2);
		void SetUniformFloat3(const std::string& name, float value1, float value2, float value3);
		void SetUniformFloat4(const std::string& name, float value1, float value2, float value3, float value4);

	private:
		int GetUniformLocation(const std::string& name);

	private:
		uint32_t programID;

		std::unordered_map<std::string, int> uniformLocations;
	};
}