#include "Mesh.h"

#include <glad/glad.h>

void Mesh::Init(std::vector<Vertex>& vertices, std::vector<uint32_t>& indices)
{
    m_VertCount = indices.size();

    glGenVertexArrays(1, &m_Vao);
    glGenBuffers(1, &m_Vbo);
    glGenBuffers(1, &m_Ebo);

    glBindVertexArray(m_Vao);
    glBindBuffer(GL_ARRAY_BUFFER, m_Vbo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_Ebo);

    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * vertices.size(), vertices.data(), GL_STATIC_DRAW);
    
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, pos));
    
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, color));

    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(uint32_t) * indices.size(), indices.data(), GL_STATIC_DRAW);

    glBindVertexArray(0);
}

void Mesh::Destroy()
{
    glDeleteVertexArrays(1, &m_Vao);
    glDeleteBuffers(1, &m_Vbo);
    glDeleteBuffers(1, &m_Ebo);
}

void Mesh::Render()
{
    glBindVertexArray(m_Vao);
    glDrawElements(GL_TRIANGLES, m_VertCount, GL_UNSIGNED_INT, 0);
}