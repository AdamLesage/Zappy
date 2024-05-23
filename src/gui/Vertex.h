/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Vertex
*/

#include <glm/glm.hpp>

#ifndef VERTEX_H_
#define VERTEX_H_

struct Vertex {
    glm::vec3 position;
    glm::vec3 color;
    glm::vec2 texcoord;
    glm::vec3 normal;
};
    

#endif /* !VERTEX_H_ */
