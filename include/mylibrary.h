#ifndef MYLIBRARY_H
#define MYLIBRARY_H


#include <SFML/Graphics.hpp>
#include <string>

namespace ktx {
    class cInputText {
    public:
        cInputText();
        ~cInputText();
        void readKey();
        void draw(sf::RenderWindow& window) const;

        void setRectSize(sf::Vector2f l_RectSize);
        void setColorText(sf::Color l_ColorText);
        void setColorRect(sf::Color l_ColorRect);
        void setFont(const sf::Font&);
        void setString(const std::string& l_String);
        void setPositionText(sf::Vector2f);
        void setPositionRectangleShape(sf::Vector2f);
        void setCharacterSize(unsigned int l_size);

        sf::Vector2f getRectSize() const;
        sf::Color getColorText() const;
        sf::Color getColorRect() const;
        std::string getString() const;
        sf::Vector2f getPositionText() const;
        sf::Vector2f getPositionRectangleShape() const;
        unsigned int getCharacterSize() const;

    private:
        sf::RectangleShape m_rsRect;
        sf::Text m_txText;
    };
}

#endif // MYLIBRARY_H
