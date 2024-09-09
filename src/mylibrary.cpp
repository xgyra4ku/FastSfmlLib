#include "mylibrary.h"
namespace ktx {
    cInputText::cInputText() {
        setColorRect(sf::Color(255, 255, 255));
        setColorText(sf::Color(0, 0, 0));
    }

    cInputText::~cInputText() = default;

    void cInputText::readKey() {
        // Реализация метода readKey
    }

    void cInputText::setRectSize(const sf::Vector2f l_RectSize) {
        m_rsRect.setSize(l_RectSize);
    }

    void cInputText::setColorText(const sf::Color l_ColorText) {
        m_txText.setFillColor(l_ColorText);
    }

    void cInputText::setFont(const sf::Font& l_font) {
        m_txText.setFont(l_font);
    }

    void cInputText::setColorRect(const sf::Color l_ColorRect) {
        m_rsRect.setFillColor(l_ColorRect);
    }
    void cInputText::setString(std::string l_String) {
        m_txText.setString(l_String);
    }




    sf::Vector2f cInputText::getRectSize() const {
        return m_rsRect.getSize();
    }

    sf::Color cInputText::getColorText() const {
        return m_txText.getFillColor();
    }

    sf::Color cInputText::getColorRect() const {
        return m_rsRect.getFillColor();
    }

    std::string cInputText::getString() const {
        return m_txText.getString();
    }
}