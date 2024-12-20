///
/// InputText class
///
#include "../include/FastSfml.hpp"
namespace fs::Text {
    InputText::InputText() : m_fSpeed(4), m_bInput(false), m_fTime(0), m_fTime2(0) {
        setColorRect({255, 255, 255});
        setColorText({0, 0, 0});
        setPosition({0,0});
        setString("");
    }

    InputText::~InputText() = default;

    void InputText::listen(const float l_fTime) {
        if (m_bInput) {
            std::string inputText = m_sfTxtText.getString();

            std::map<sf::Keyboard::Key, char> keyMap = {
                {sf::Keyboard::A, 'a'}, {sf::Keyboard::B, 'b'}, {sf::Keyboard::C, 'c'},
                {sf::Keyboard::D, 'd'}, {sf::Keyboard::E, 'e'}, {sf::Keyboard::F, 'f'},
                {sf::Keyboard::G, 'g'}, {sf::Keyboard::H, 'h'}, {sf::Keyboard::I, 'i'},
                {sf::Keyboard::J, 'j'}, {sf::Keyboard::K, 'k'}, {sf::Keyboard::L, 'l'},
                {sf::Keyboard::M, 'm'}, {sf::Keyboard::N, 'n'}, {sf::Keyboard::O, 'o'},
                {sf::Keyboard::P, 'p'}, {sf::Keyboard::Q, 'q'}, {sf::Keyboard::R, 'r'},
                {sf::Keyboard::S, 's'}, {sf::Keyboard::T, 't'}, {sf::Keyboard::U, 'u'},
                {sf::Keyboard::V, 'v'}, {sf::Keyboard::W, 'w'}, {sf::Keyboard::X, 'x'},
                {sf::Keyboard::Y, 'y'}, {sf::Keyboard::Z, 'z'}, {sf::Keyboard::Space, ' '},
                {sf::Keyboard::Num0, '0'}, {sf::Keyboard::Num1, '1'}, {sf::Keyboard::Num2, '2'},
                {sf::Keyboard::Num3, '3'}, {sf::Keyboard::Num4, '4'}, {sf::Keyboard::Num5, '5'},
                {sf::Keyboard::Num6, '6'}, {sf::Keyboard::Num7, '7'}, {sf::Keyboard::Num8, '8'},
                {sf::Keyboard::Num9, '9'},
            };

            m_fTime += 0.01f * l_fTime;
            m_fTime2 += 0.01f * l_fTime;
            if (m_fTime > 1.0f) {
                const bool shiftPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) ||
                                          sf::Keyboard::isKeyPressed(sf::Keyboard::RShift);

                for (const auto& [key, character] : keyMap) {
                    if (sf::Keyboard::isKeyPressed(key)) {
                        const char lastSymbol = inputText[inputText.size()-1];
                        if (!inputText.empty())
                            inputText.pop_back();
                        if (shiftPressed && std::isalpha(character)) {
                            inputText += std::toupper(character);
                        } else {
                            inputText += character;
                        }
                        inputText += lastSymbol;
                        m_fTime = 0;
                        break;
                    }
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace) && !inputText.empty()) {
                    const char lastSymbol = inputText[inputText.size()-1];
                    if (!inputText.empty())
                        inputText.pop_back();
                    if (!inputText.empty())
                        inputText.pop_back();
                    inputText += lastSymbol;
                    m_fTime = 0;
                }
            }
            if (m_fTime2 > m_fSpeed) {
                const char lastSymbol = inputText[inputText.size()-1];
                if (!inputText.empty())
                    inputText.pop_back();
                inputText += lastSymbol == ' ' ? '|' : ' ';
                m_fTime2 = 0;
            }

            m_sfTxtText.setString(inputText);
        }
    }
    void InputText::setCursorSpeed(const float l_speed) {
        m_fSpeed = l_speed;
    }
    void InputText::setInput(const bool l_bool) {
        m_bInput = l_bool;
    }

    void InputText::draw(sf::RenderWindow& window) const {
        window.draw(m_sfRsRect);
        window.draw(m_sfTxtText);
    }

    void InputText::setPosition(const sf::Vector2f l_pos) {
        m_sfTxtText.setPosition(l_pos);
        m_sfRsRect.setPosition(l_pos - sf::Vector2f{2.5f, 2.5f});
    }

    void InputText::setRectSize(const sf::Vector2f l_RectSize) {
        m_sfRsRect.setSize(l_RectSize);
    }

    void InputText::setColorText(const sf::Color l_ColorText) {
        m_sfTxtText.setFillColor(l_ColorText);
    }

    void InputText::setFont(const sf::Font& l_font) {
        m_sfTxtText.setFont(l_font);
    }

    void InputText::setColorRect(const sf::Color l_ColorRect) {
        m_sfRsRect.setFillColor(l_ColorRect);
    }
    void InputText::setString(const std::string& l_String) {
        m_sfTxtText.setString(l_String);

    }
    void InputText::setCharacterSize(const unsigned int l_size) {
        m_sfTxtText.setCharacterSize(l_size);
    }



    bool InputText::getInput() const {
        return m_bInput;
    }

   float InputText::getCursorSpeed() const {
        return m_fSpeed;
    }

    sf::Vector2f InputText::getRectSize() const {
        return m_sfRsRect.getSize();
    }

    sf::Color InputText::getColorText() const {
        return m_sfTxtText.getFillColor();
    }

    sf::Color InputText::getColorRect() const {
        return m_sfRsRect.getFillColor();
    }

    std::string InputText::getString() const {
        return m_sfTxtText.getString();
    }

    sf::Vector2f InputText::getPosition() const {
        return m_sfTxtText.getPosition();
    }

    unsigned int InputText::getCharacterSize() const {
        return m_sfTxtText.getCharacterSize();
    }
}
