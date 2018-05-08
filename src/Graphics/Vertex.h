//
// Created by thekatze on 06/02/18.
//

#ifndef SDLOGL_VERTEX_H
#define SDLOGL_VERTEX_H

#include "../Types/Vector2.h"
#include "../Types/Color.h"


struct UV {
    float u;
    float v;
};

/**
 * A two-dimensional vertex (point) consisting of position, color and texture mapping (UV) information.
 */
struct Vertex {
    Vector2 position;
    Color color;

    Vector2 uv;
};

#endif //SDLOGL_VERTEX_H
