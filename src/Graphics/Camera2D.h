//
// Created by thekatze on 25/05/18.
//

#ifndef SHVRDENGINE_SRC_CAMERA2D_H
#define SHVRDENGINE_SRC_CAMERA2D_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "../Types/Vector2.h"

class Camera2D {
    glm::vec2 position;
    glm::mat4 orthoMatrix;
    glm::mat4 cameraMatrix;

    int screenWidth, screenHeight;

    float scaleFactor;
    float rotation;

    void update();
public:
    Camera2D(int screenWidth, int screenHeight);
    ~Camera2D();

    void translate(const Vector2 &vector) {
        this->position.x = this->position.x + vector.x;
        this->position.y = this->position.y + vector.y;
        this->update();
    }

    void scale(float factor) {
        this->scaleFactor *= factor;
        this->update();
    }

    void rotate(const float deltaRotation) {
        this->rotation += deltaRotation;
        this->update();
    }

    void setScreenDimensions(const Vector2 &newDimensions) {
        this->screenWidth = (int) newDimensions.x;
        this->screenHeight = (int) newDimensions.y;
        this->orthoMatrix = glm::ortho(0.0f, (float)screenWidth,0.0f, (float)screenHeight);
        this->update();
    }

    void setPosition(const Vector2 &newPosition) {
        this->position.x = newPosition.x;
        this->position.y = newPosition.y;
        this->update();
    }

    void setRotation(const float newRotation) {
        this->rotation = newRotation;
        this->update();
    }

    void setScale(float newScale) {
        this->scaleFactor = newScale;
        this->update();
    }

    Vector2 *getPosition() {
        return new Vector2{this->position.x, this->position.y};
    }

    float getScale() {
        return this->scaleFactor;
    }

    glm::mat4 getCameraMatrix() {
        return this->cameraMatrix;
    }
};


#endif //SHVRDENGINE_SRC_CAMERA2D_H
