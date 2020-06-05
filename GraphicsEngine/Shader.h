#pragma once

#include <string>
#include <unordered_map>
#include "glm.hpp"

namespace GraphicsEngine
{
    struct ShaderProgramSource
    {
        std::string VertexSource;
        std::string FragmentSource;
    };

    class Shader
    {
    public:
        Shader(const std::string &);
        ~Shader();

        void Bind() const;
        void Unbind() const;

        void SetUniformMat4f(const std::string &, const glm::mat4 &);
        void SetUniformVec3f(const std::string &, const glm::vec3 &);
        void SetUniformVec4f(const std::string &, const glm::vec4 &);
        void SetUniform4f(const std::string &, float, float, float, float);

    private:
        std::unordered_map<std::string, int> m_UniformLocationCache;
        std::string m_FilePath;
        unsigned int m_RendererID;

        unsigned int GetUniformLocation(const std::string &);

        ShaderProgramSource ParseShader();

        unsigned int CompileShader(unsigned int, const std::string &);
        unsigned int Createshader(const std::string &, const std::string &);

    };
}
