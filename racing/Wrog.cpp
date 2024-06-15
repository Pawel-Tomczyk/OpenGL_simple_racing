#include "Wrog.h"

Wrog::Wrog(glm::mat4 M, float* vertices, int countVertices, float* normals, float* texCoords, glm::vec2 sizeOf2Dmodel) : Pojazd(M, vertices, countVertices, normals, texCoords, sizeOf2Dmodel)
{
	point = 0;
}

void Wrog::control(glm::vec2* points, int pointsSize)
{
    speed = 0.4;
    if (point >= pointsSize) point = 0;

    // Obliczanie wektora mi�dzy obecn� pozycj� a pozycj� celu
    glm::vec3 currentPosition = glm::vec3(M[3]);
    glm::vec3 targetPosition = glm::vec3(points[point].x, -0.99f, points[point].y); // Zak�adam, �e Y jest wysoko�ci�
    glm::vec3 direction = glm::normalize(targetPosition - currentPosition);

    // Ustalenie nowego kierunku prz�d
    glm::vec3 newFront = direction;

    // Obliczanie wektora prawo na podstawie kierunku prz�d
    glm::vec3 right = glm::cross(glm::vec3(0.0f, 1.0f, 0.0f), newFront);

    // Obliczanie kierunku g�ry na podstawie prawego i przodu
    glm::vec3 up = glm::cross(newFront, right);

    // Ustalenie nowej macierzy rotacji na podstawie nowych wektor�w kierunkowych
    glm::mat4 newRotationMatrix = glm::mat4(glm::vec4(right, 0.0f),
        glm::vec4(up, 0.0f),
        glm::vec4(newFront, 0.0f),
        glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));

    // Zastosowanie nowej macierzy rotacji do obiektu
    M = glm::translate(glm::mat4(1.0f), currentPosition) * newRotationMatrix;

    // Interpolacja liniowa pomi�dzy aktualn� pozycj� a pozycj� celu
    glm::vec3 newPosition = currentPosition + direction * speed;

    // Aktualizacja pozycji obiektu
    M[3] = glm::vec4(newPosition, 1.0f);

    // Sprawd�, czy obiekt dotar� do celu
    if (glm::distance(currentPosition, targetPosition) < 1.0f)
    {
        // Przejd� do nast�pnego punktu docelowego
        point++;
        if(point >= pointsSize) point = 0;
    }
    this->angle = acos(glm::normalize(size).x);
    this->calcPosition2D();
    this->calcPoints();
}