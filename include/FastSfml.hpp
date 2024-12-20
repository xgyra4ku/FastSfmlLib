#ifndef FASTSFML_H
#define FASTSFML_H


#include <SFML/Graphics.hpp>
#include <string>

namespace fs {
    class Mouse {
        bool LButton;
        bool RButton;
        sf::RenderWindow* window;
    public:
        explicit Mouse(sf::RenderWindow& sfRwWindow);
        ~Mouse();
        void listen();
        bool buttonR();
        bool buttonL();
        bool collision(sf::Vector2f RectSize, sf::Vector2f RectPosition) const;
    };

    // class Button {
    //     sf::Text m_sfTxtTextButton;
    // public:
    //     Button();
    //     ~Button();
    //     void draw(const sf::RenderWindow &sfRwWindow) const;
    //     void logic(float fTime);
    //
    //     void setFillColor(sf::Color sfCrColorText);
    //     void setFont(const sf::Font&);
    //     void setString(const std::string& strString);
    //     void setPosition(sf::Vector2f sfVecFValue);
    //     void setCharacterSize(unsigned int iSize);
    //
    //     const sf::Font *getFont() const;
    //     sf::Color getFillColor() const;
    //     std::string getString() const;
    //     sf::Vector2f getPosition() const;
    //     unsigned int getCharacterSize() const;
    // };
    // class Switch {
    //     sf::RectangleShape staticRS; // стачиский который просто стои прямоугольник
    //     sf::RectangleShape changeableRS; // изменяемый прямоугольник он немного меньше статического на пару процентов
    //
    //     bool status;
    // public:
    //     Switch();
    //     ~Switch();
    //
    //     void setStatus(bool status);
    //
    //     bool getStatus() const;
    //
    //     void setSize(sf::Vector2f size);
    //     void setColorStaticRS(sf::Color color);
    //     void setColorChangeableRS(sf::Color color);
    //     void setPosition(sf::Vector2f pos);
    //
    //     bool getStatus();
    //     sf::Vector2f getSize();
    //     sf::Vector2f getPos();
    //     sf::Color getColorStaticRS();
    //     sf::Color getColorChangeableRS();
    //
    // };
    // class Slider {
    //
    // };


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

    namespace Text {
//        class OptimizedText {
//        public:
//            OptimizedText();
//            ~OptimizedText();
//            float percentage(const float percent, const unsigned int num) {
//                return (percent / 100) * static_cast<float>(num);
//            }
//            float percentage1280(const float percent, const unsigned int num) {
//                const float i = (percent / 1280) * 100;
//                return percentage(i, num);
//            }
//            float percentage800(const float percent, const unsigned int num) {
//                const float i = (percent / 800) * 100;
//                return percentage(i, num);
//            }
//
//            unsigned int textSizeOptimization(sf::Vector2u currentSize, float textSize) {
//                return static_cast<int>(textSize * (std::sqrt(
//                                                        std::pow((static_cast<float>(currentSize.x) / 1280.0f), 2) + std::pow(
//                                                            (static_cast<float>(currentSize.y) / 800.0f), 2)) / std::sqrt(2)));
//            }
//        private:
//            sf::Vector2f m_fWindowSize;
//        };

        class InputText {
        public:
            InputText();
            ~InputText();

            void listen(float l_fTime);

            void draw(sf::RenderWindow& window) const;

            void setRectSize(sf::Vector2f l_RectSize);
            void setColorText(sf::Color l_ColorText);
            void setColorRect(sf::Color l_ColorRect);
            void setFont(const sf::Font&);
            void setString(const std::string& l_String);
            void setPosition(sf::Vector2f);
            void setCharacterSize(unsigned int l_size);
            void setInput(bool l_bool);
            void setCursorSpeed(float l_speed);


            sf::Color getColorText() const;
            sf::Color getColorRect() const;

            std::string getString() const;

            sf::Vector2f getPosition() const;
            sf::Vector2f getRectSize() const;

            unsigned int getCharacterSize() const;

            bool getInput() const;

            float getCursorSpeed() const;

        private:
            sf::RectangleShape m_sfRsRect;

            sf::Text m_sfTxtText;

            float m_fTime;
            float m_fTime2;
            float m_fSpeed;

            bool m_bInput;
        };
    }
}

#endif
