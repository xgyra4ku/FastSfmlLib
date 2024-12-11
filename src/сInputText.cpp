///
/// InputText class
///
#include "../include/FastSfml.hpp"
namespace FS {
    InputText::InputText() {
        setColorRect(sf::Color(255, 255, 255));
        setColorText(sf::Color(0, 0, 0));
        setString("");
        m_fTime = 0;
        m_bInput = false;
    }

    InputText::~InputText() = default;

    void InputText::readKey(const float l_fTime) {
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
            if (m_fTime > 2.0f) {
                const bool shiftPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) ||
                                          sf::Keyboard::isKeyPressed(sf::Keyboard::RShift);

                for (const auto& [key, character] : keyMap) {
                    if (sf::Keyboard::isKeyPressed(key)) {
                        if (shiftPressed && std::isalpha(character)) {
                            inputText += std::toupper(character);
                        } else {
                            inputText += character;
                        }
                        m_fTime = 0;
                        break;
                    }
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace) && !inputText.empty()) {
                    inputText.pop_back();
                    m_fTime = 0;
                }
            }

            m_sfTxtText.setString(inputText);
        }
    }
    void InputText::setInput(const bool l_bool) {
        m_bInput = l_bool;
    }

    void InputText::draw(sf::RenderWindow& window) const {
        window.draw(m_sfRsRect);
        window.draw(m_sfTxtText);
    }

    void InputText::setPositionText(const sf::Vector2f l_pos) {
        m_sfTxtText.setPosition(l_pos);
    }

    void InputText::setPositionRectangleShape(const sf::Vector2f l_pos) {
        m_sfRsRect.setPosition(l_pos);
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

    sf::Vector2f InputText::getPositionText() const {
        return m_sfTxtText.getPosition();
    }

    sf::Vector2f InputText::getPositionRectangleShape() const {
        return m_sfRsRect.getPosition();
    }

    unsigned int InputText::getCharacterSize() const {
        return m_sfTxtText.getCharacterSize();
    }
}