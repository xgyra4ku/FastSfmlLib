///
/// InterfaseUI class
///
#include "../include/UI.hpp"
InterfaceUI::InterfaceUI() = default;
InterfaceUI::~InterfaceUI() = default;


void InterfaceUI::setFont(const sf::Font & font) {
    this->m_pFont = font;
}
void InterfaceUI::setString(const std::string &strString) {
    m_sfTxtText.setString(strString);
}
void InterfaceUI::setCharacterSize(const unsigned int iSize) {
    m_sfTxtText.setCharacterSize(iSize);
}
void InterfaceUI::setPosition(const sf::Vector2f sfVecFValue) {
    this->m_VecFPosition = sfVecFValue;
}void InterfaceUI::setSize(const sf::Vector2f sfVecFValue) {
    this->m_VecFSize = sfVecFValue;
}
void InterfaceUI::setFillColor(const sf::Color sfCrColorText) {
    this->m_sfCrColor = sfCrColorText;
}
void InterfaceUI::setHoverColor(const sf::Color sfCrColorHover) {
    this->m_sfCrColorHover = sfCrColorHover;
}
void InterfaceUI::setOutlineColor(const sf::Color color) {
    this->m_sfCrColorOutline = color;
}

void InterfaceUI::setOutlineThickness(const float thickness) {
    this->m_fOutlineThickness = thickness;
}

void InterfaceUI::setText(const sf::Text &text) {
    this->m_sfTxtText = text;
}
void InterfaceUI::setTIME(const float fTime) {
    this->m_TIME = fTime;
}


sf::Font InterfaceUI::getFont() const {
 return m_pFont;
}
sf::Color InterfaceUI::getFillColor() const {
    return m_sfCrColor;
}
sf::Color InterfaceUI::getHoverColor() const {
    return m_sfCrColorHover;
}sf::Color InterfaceUI::getOutlineColor() const {
    return m_sfCrColorOutline;
}
float InterfaceUI::getOutlineThickness() const {
    return m_fOutlineThickness;
}
sf::Vector2f InterfaceUI::getPosition() const {
    return m_VecFPosition;
}sf::Vector2f InterfaceUI::getSize() const {
    return m_VecFSize;
}
std::string InterfaceUI::getString() const {
    return m_sfTxtText.getString();
}
unsigned int InterfaceUI::getCharacterSize() const {
    return m_sfTxtText.getCharacterSize();
}
sf::Text InterfaceUI::getText() const {
    return m_sfTxtText;
}
float InterfaceUI::getTIME() const {
    return m_TIME;
}

bool InterfaceUI::collision(const sf::RenderWindow* window, const sf::Vector2f RectSize, const sf::Vector2f RectPosition) {
    // Получаем позицию мыши относительно окна
    const sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
    // Проверяем, находится ли мышь внутри прямоугольника
    if (const sf::Vector2f MousePosition(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
        MousePosition.x >= RectPosition.x &&
        MousePosition.x <= RectPosition.x + RectSize.x &&
        MousePosition.y >= RectPosition.y &&
        MousePosition.y <= RectPosition.y + RectSize.y) {
        return true;
        }
    return false;
}

///
/// @brief Левая кнопка мыши нажата
///
bool InterfaceUI::buttonL() {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if (!LButton) {
            LButton = true; // Устанавливаем флаг
            return true;
        }
    } else {
        LButton = false; // Сбрасываем флаг, если кнопка отпущена
    }
    return false;
}

///
/// @brief Правая кнопка мыши нажата
///
bool InterfaceUI::buttonR() {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
        if (!RButton) {
            RButton = true; // Устанавливаем флаг
            return true;
        }
    } else {
        RButton = false; // Сбрасываем флаг, если кнопка отпущена
    }
    return false;
}

