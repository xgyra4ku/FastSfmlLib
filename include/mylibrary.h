#ifndef MYLIBRARY_H
#define MYLIBRARY_H


#include <SFML/Graphics.hpp>
#include <string>

namespace ktx {
    class cInputText {
    public:
        cInputText();
        ~cInputText();
        static void readKey();

        void setRectSize(sf::Vector2f l_RectSize);
        void setColorText(sf::Color l_ColorText);
        void setColorRect(sf::Color l_ColorRect);
        void setFont(const sf::Font&);
        void setString(std::string l_String);

        sf::Vector2f getRectSize() const;
        sf::Color getColorText() const;
        sf::Color getColorRect() const;
        std::string getString() const;

    private:
        sf::RectangleShape m_rsRect;
        sf::Text m_txText;
    };
}

#endif // MYLIBRARY_H
