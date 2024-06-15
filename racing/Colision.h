#pragma once

#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <glm\glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Object.h"

float projektujNaOœ(const glm::vec2& punkt, const glm::vec2& oœ) {
    return glm::dot(punkt, oœ);
}

// Funkcja do znalezienia minimum i maksimum rzutów na oœ
void znajdzMinMaxRzutowania(const glm::vec2* punkty, const glm::vec2& oœ, float& min, float& max) {
    min = max = projektujNaOœ(punkty[0], oœ);
    for (int i = 1; i < 4; ++i) {
        float proj = projektujNaOœ(punkty[i], oœ);
        if (proj < min) {
            min = proj;
        }
        else if (proj > max) {
            max = proj;
        }
    }
}

// Funkcja do sprawdzenia kolizji za pomoc¹ SAT
bool sprawdzKolizjeSAT(Object* obj1, Object* obj2) {
    // Listy osi separacji
    std::vector<glm::vec2> osie;

    // Generowanie osi separacji dla pierwszego obiektu
    for (int i = 0; i < 4; ++i) {
        glm::vec2 p1 = obj1->points[i];
        glm::vec2 p2 = obj1->points[(i + 1) % 4];
        glm::vec2 edge = p2 - p1;
        glm::vec2 axis = glm::normalize(glm::vec2(-edge.y, edge.x));
        osie.push_back(axis);
    }

    // Generowanie osi separacji dla drugiego obiektu
    for (int i = 0; i < 4; ++i) {
        glm::vec2 p1 = obj2->points[i];
        glm::vec2 p2 = obj2->points[(i + 1) % 4];
        glm::vec2 edge = p2 - p1;
        glm::vec2 axis = glm::normalize(glm::vec2(-edge.y, edge.x));
        osie.push_back(axis);
    }

    // Sprawdzenie kolizji na ka¿dej osi
    for (const auto& axis : osie) {
        float minA, maxA, minB, maxB;
        znajdzMinMaxRzutowania(obj1->points, axis, minA, maxA);
        znajdzMinMaxRzutowania(obj2->points, axis, minB, maxB);

        // Sprawdzenie czy projekcje zachodz¹ na siebie
        if (maxA < minB || maxB < minA) {
            return false; // Brak kolizji
        }
    }

    // Obliczenie normalnej dla kolizji
    glm::vec2 collisionNormal = glm::normalize(obj1->points[0] - obj2->points[0]); // Przyk³ad normalnej, mo¿na ulepszyæ

    obj1->handleCollision(collisionNormal);
    obj2->handleCollision(-collisionNormal);
    return true; // Kolizja
}