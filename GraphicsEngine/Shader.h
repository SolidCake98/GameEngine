#pragma once

#include <string>
#include <unordered_map>
#include "glm.hpp"

namespace GraphicsEngine {
    struct ShaderProgramSource {
        std::string VertexSource;
        std::string FragmentSource;
    };

    class Shader {
    private:
        std::unordered_map<std::string, int> m_UniformLocationCache;
        std::string m_FilePath;
        unsigned int m_RendererID;

        unsigned int GetUniformLocation(const std::string &name);

        ShaderProgramSource ParseShader();

        unsigned int CompileShader(unsigned int, const std::string &);

        unsigned int Createshader(const std::string &, const std::string &);

    public:
        Shader(const std::string &filename);

        ~Shader();

        void Bind() const;

        void Unbind() const;

        unsigned int t_Createshader(const std::string &, const std::string &);

        void SetUniformMat4f(const std::string &name, const glm::mat4 &);

        void SetUniformVec3f(const std::string &name, const glm::vec3 &);

        void SetUniformVec4f(const std::string &name, const glm::vec4 &);

        void SetUniform4f(const std::string &name, float v0, float v1, float v2, float v3);
    };
}
