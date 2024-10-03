#ifndef FASTSFML_H
#define FASTSFML_H


#include <SFML/Graphics.hpp>
#include <string>

namespace FS {
    class Mouse {
    public:
        bool collision(float x, float y);
        bool scroll();
        bool scrollUp();
        bool scrollDown();
        bool buttonR();
        bool buttonL();
        bool move();

        [[nodiscard]] sf::Vector2f getPosition() const;
    };

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
    class Switch {
        sf::RectangleShape staticRS;
        sf::RectangleShape changeableRS;

        bool statusSwitch;
    public:
        Switch();
        ~Switch();

        void setStatus();
        void setSize(sf::Vector2f size);
        void setColorStaticRS(sf::Color color);
        void setColorChangeableRS(sf::Color color);
        void setPosition(sf::Vector2f pos);

        bool getStatus();
        sf::Vector2f getSize();
        sf::Vector2f getPos();
        sf::Color getColorStaticRS();
        sf::Color getColorChangeableRS();

    };
    class Slider {

    };
    class InputText {
    public:
        InputText();
        ~InputText();
        void readKey(float l_fTime);
        void draw(sf::RenderWindow& window) const;

        void setRectSize(sf::Vector2f l_RectSize);
        void setColorText(sf::Color l_ColorText);
        void setColorRect(sf::Color l_ColorRect);
        void setFont(const sf::Font&);
        void setString(const std::string& l_String);
        void setPositionText(sf::Vector2f);
        void setPositionRectangleShape(sf::Vector2f);
        void setCharacterSize(unsigned int l_size);
        void setInput(bool l_bool);

        sf::Vector2f getRectSize() const;
        sf::Color getColorText() const;
        sf::Color getColorRect() const;
        std::string getString() const;
        sf::Vector2f getPositionText() const;
        sf::Vector2f getPositionRectangleShape() const;
        unsigned int getCharacterSize() const;
        bool getInput() const;

    private:
        sf::RectangleShape m_sfRsRect;
        sf::Text m_sfTxtText;
        float m_fTime;
        float m_fTime2{};
        bool m_bInput;
    };
}

#endif
