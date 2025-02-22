#ifndef FASTSFML_H
#define FASTSFML_H

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

#include "Text.hpp"
#include "UI.hpp"

namespace fs {
    class Mouse {
        bool LButton, m_bLButton;
        bool RButton, m_bRButton;
        sf::RenderWindow* window;
    public:

        explicit Mouse(sf::RenderWindow& sfRwWindow);
        ~Mouse();
        void listen();
        [[nodiscard]] bool collision(sf::Vector2f RectSize, sf::Vector2f RectPosition) const;

        [[nodiscard]] sf::Vector2f getMousePosition() const;
        [[nodiscard]] static bool buttonClampingL() ;
        [[nodiscard]] static bool buttonClampingR() ;
        bool buttonPressAndReleaseL();
        bool buttonPressAndReleaseR();
    };


    // class PhysicsObject {
    // public:
    //     void setCollision(bool value);
    //     void setCollisionLayer(int layer);
    //     void setRect(sf::IntRect rect);
    //     void setPosition(sf::Vector2f pos);
    //     void setMass(float mass);
    //     void setFriction(float friction);
    //     void setGravity(float gravity);
    //     [[nodiscard]] sf::IntRect getRect() const;
    //     [[nodiscard]] sf::Vector2f getPosition() const;
    //     [[nodiscard]] float getMass() const;
    //     [[nodiscard]] float getFriction() const;
    //     [[nodiscard]] float getGravity() const;
    //     [[nodiscard]] int getCollisionLayer() const;
    //     [[nodiscard]] bool getCollision() const;
    // };
    // class PhysicsWorld {
    // public:
    //     void addPhysicsObjectVec(std::vector<PhysicsObject>& obj);
    //     [[nodiscard]] std::vector<PhysicsObject>& getPhysicsObjectVec() const;
    // };

}

#endif
