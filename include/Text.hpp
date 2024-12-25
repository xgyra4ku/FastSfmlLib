#ifndef FASTSFML_TEXT_HPP
#define FASTSFML_TEXT_HPP

#include <SFML/Graphics.hpp>
#include <string>

namespace fs::Text {
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
        std::map<sf::Keyboard::Key, char> keyMap;
        sf::RectangleShape m_sfRsRect;

        sf::Text m_sfTxtText;

        float m_fTime;
        float m_fTime2;
        float m_fSpeed;

        bool m_bInput;

        char m_cLastSymbol;
    };
}

#endif //FASTSFML_TEXT_HPP