//
// Created by thekatze on 25/05/18.
//

#include "Camera2D.h"

Camera2D::Camera2D(int screenWidth, int screenHeight) :
        position(0.0f, 0.0f),
        cameraMatrix(1.0f),
        orthoMatrix(glm::ortho(0.0f, (float)screenWidth,0.0f, (float)screenHeight)),
        scale(1.0f),
        screenWidth(screenWidth),
        screenHeight(screenHeight)
{
    this->update();
}

Camera2D::~Camera2D() {

}

void Camera2D::update() {
    glm::vec3 translationVector(-position.x, -position.y, 0.0f);
    cameraMatrix = glm::translate(orthoMatrix, translationVector);

    glm::vec3 scaleVector(scale, scale, 0.0f);
    cameraMatrix = glm::scale(cameraMatrix, scaleVector);
}
