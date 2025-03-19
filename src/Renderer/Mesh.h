#pragma once

#include <glm/glm.hpp>

#include <cstdint>
#include <vector>

struct Vertex
{
    glm::vec3 pos;
    glm::vec2 texCoord;
};

class Mesh
{
public:
    void Init(std::vector<Vertex>& vertices, std::vector<uint32_t>& indices);
    void Destroy();

    void Render();

private:
    uint32_t m_VertCount;
    uint32_t m_Vao, m_Vbo, m_Ebo;
};