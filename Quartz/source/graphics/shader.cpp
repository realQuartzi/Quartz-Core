#include "graphics/shader.h"
#include "extend/debug.h"

#include "glad/glad.h"

namespace Quartz::Graphics
{
	Shader::Shader(const std::string& vertex, const std::string& fragment)
	{
		programID = glCreateProgram();

		int status = GL_FALSE;
		char error[512];

		uint32_t vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
		{
			const GLchar* glSource = vertex.c_str();
			glShaderSource(vertexShaderID, 1, &glSource, NULL);

			glCompileShader(vertexShaderID);

			glGetShaderiv(vertexShaderID, GL_COMPILE_STATUS, &status);

			if (status != GL_TRUE)
			{
				glGetShaderInfoLog(vertexShaderID, sizeof(error), NULL, error);
				Debug::LogError(("Vertex Shader compilation error: {}", error));
			}
			else
			{
				glAttachShader(programID, vertexShaderID);
			}
		}

		uint32_t fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
		{

			const GLchar* glSource = fragment.c_str();
			glShaderSource(fragmentShaderID, 1, &glSource, NULL);

			glCompileShader(fragmentShaderID);

			glGetShaderiv(fragmentShaderID, GL_COMPILE_STATUS, &status);

			if (status != GL_TRUE)
			{
				glGetShaderInfoLog(fragmentShaderID, sizeof(error), NULL, error);
				Debug::LogError(("Fragment Shader compilation error: {}", error));
			}
			else
			{
				glAttachShader(programID, fragmentShaderID);
			}
		}

		if (status == GL_TRUE)
		{
			glLinkProgram(programID);
			glValidateProgram(programID);
			glGetProgramiv(programID, GL_LINK_STATUS, &status);

			if (status != GL_TRUE)
			{
				glGetProgramInfoLog(programID, sizeof(error), NULL, error);
				Debug::LogError( ("Shader link error: {}", error) );
				glDeleteProgram(programID);
				programID = -1;
			}
		}


		glDeleteShader(vertexShaderID);
		glDeleteShader(fragmentShaderID);

	}

	Shader::~Shader()
	{
		glUseProgram(0);
		glDeleteProgram(programID);
	}

	void Shader::Bind()
	{
		glUseProgram(programID);
	}

	void Shader::Unbind()
	{
		glUseProgram(0);
	}

	void Shader::SetUniformInt(const std::string& name, int value)
	{
		glUseProgram(programID);
		glUniform1i(GetUniformLocation(name), value);
	}

	void Shader::SetUniformFloat(const std::string& name, float value)
	{
		glUseProgram(programID);
		glUniform1f(GetUniformLocation(name), value);
	}

	void Shader::SetUniformFloat2(const std::string& name, float value1, float value2)
	{
		glUseProgram(programID);
		glUniform2f(GetUniformLocation(name), value1, value2);
	}

	void Shader::SetUniformFloat3(const std::string& name, float value1, float value2, float value3)
	{
		glUseProgram(programID);
		glUniform3f(GetUniformLocation(name), value1, value2, value3);
	}

	void Shader::SetUniformFloat4(const std::string& name, float value1, float value2, float value3, float value4)
	{
		glUseProgram(programID);
		glUniform4f(GetUniformLocation(name), value1, value2, value3, value4);
	}

	int Shader::GetUniformLocation(const std::string& name)
	{
		auto it = uniformLocations.find(name);
		if (it == uniformLocations.end())
		{
			uniformLocations[name] = glGetUniformLocation(programID, name.c_str());
		}

		return uniformLocations[name];
	}
}