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

        void setRect(sf::FloatRect l_Rect);
        void setColorText(sf::Color l_ColorText);
        void setColorRect(sf::Color l_ColorRect);

        sf::FloatRect getRect() const;
        sf::Color getColorText() const;
        sf::Color getColorRect() const;
        std::string getTextInput() const;

    private:
        sf::FloatRect m_flRect;
        sf::Color m_clColorText;
        sf::Color m_clColorRect;
        sf::Text m_txText;
        sf::Font m_ftFont;
    };
}

#endif // MYLIBRARY_H
