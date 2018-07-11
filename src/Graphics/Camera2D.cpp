//
// Created by thekatze on 25/05/18.
//

#include <GL/glu.h>
#include "Camera2D.h"

Camera2D::Camera2D(int screenWidth, int screenHeight) :
        position(0.0f, 0.0f),
        cameraMatrix(1.0f),
        orthoMatrix(glm::ortho(0.0f, (float)screenWidth,0.0f, (float)screenHeight)),
        scaleFactor(1.0f),
        screenWidth(screenWidth),
        screenHeight(screenHeight)
{
    this->update();
}

Camera2D::~Camera2D() {

}

void Camera2D::update() {
    cameraMatrix = orthoMatrix;
    cameraMatrix = glm::rotate(cameraMatrix, glm::radians(this->rotation), glm::vec3(0.f, 0.f, 1.f));

    glm::vec3 translationVector(-position.x, -position.y, 0.0f);
    cameraMatrix = glm::translate(cameraMatrix, translationVector);

    glm::vec3 scaleVector(scaleFactor, scaleFactor, 0.0f);
    cameraMatrix = glm::scale(cameraMatrix, scaleVector);
}
