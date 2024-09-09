#include "mylibrary.h"
namespace ktx {
    cInputText::cInputText() = default;

    cInputText::~cInputText() = default;

    void cInputText::readKey() {
        // Реализация метода readKey
    }

    void cInputText::setRect(const sf::FloatRect l_Rect) {
        m_flRect = l_Rect;
    }

    void cInputText::setColorText(const sf::Color l_ColorText) {
        m_clColorText = l_ColorText;
    }

    void cInputText::setColorRect(const sf::Color l_ColorRect) {
        m_clColorRect = l_ColorRect;
    }

    sf::FloatRect cInputText::getRect() const {
        return m_flRect;
    }

    sf::Color cInputText::getColorText() const {
        return m_clColorText;
    }

    sf::Color cInputText::getColorRect() const {
        return m_clColorRect;
    }

    std::string cInputText::getTextInput() const {
        return m_txText.getString();
    }
}