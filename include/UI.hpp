#ifndef FASTSFML_UI_HPP
#define FASTSFML_UI_HPP

#include <SFML/Graphics.hpp>
#include <string>

namespace fs::UI {

    class Button {
        sf::Text m_sfTxtTextButton;
    public:
        Button();
        ~Button();
        void draw(const sf::RenderWindow &sfRwWindow) const;
        void logic(float fTime);

        void setFillColor(sf::Color sfCrColorText);
        void setFont(const sf::Font&);
        void setString(const std::string& strString);
        void setPosition(sf::Vector2f sfVecFValue);
        void setCharacterSize(unsigned int iSize);

        const sf::Font *getFont() const;
        sf::Color getFillColor() const;
        std::string getString() const;
        sf::Vector2f getPosition() const;
        unsigned int getCharacterSize() const;
    };
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

}

#endif //FASTSFML_UI_HPP