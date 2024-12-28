///
/// InterfaseUI class
///
#include "../include/UI.hpp"
InterfaceUI::InterfaceUI() :
m_bLButton{}, m_bRButton {}, im_TIME{}, im_fOutlineThickness{},
im_sfTxtText{}, im_pFont{}, im_VecFPosition{},
im_VecFSize{}, im_sfCrColor{}, im_sfCrColorHover{}, im_sfCrColorOutline{} {}
InterfaceUI::~InterfaceUI() = default;


void InterfaceUI::setFont(const sf::Font & font) {
    this->im_pFont = font;
}
void InterfaceUI::setString(const std::string &strString) {
    im_sfTxtText.setString(strString);
}
void InterfaceUI::setCharacterSize(const unsigned int iSize) {
    im_sfTxtText.setCharacterSize(iSize);
}
void InterfaceUI::setPosition(const sf::Vector2f sfVecFValue) {
    this->im_VecFPosition = sfVecFValue;
}void InterfaceUI::setSize(const sf::Vector2f sfVecFValue) {
    this->im_VecFSize = sfVecFValue;
}
void InterfaceUI::setFillColor(const sf::Color sfCrColorText) {
    this->im_sfCrColor = sfCrColorText;
}
void InterfaceUI::setHoverColor(const sf::Color sfCrColorHover) {
    this->im_sfCrColorHover = sfCrColorHover;
}
void InterfaceUI::setOutlineColor(const sf::Color color) {
    this->im_sfCrColorOutline = color;
}

void InterfaceUI::setOutlineThickness(const float thickness) {
    this->im_fOutlineThickness = thickness;
}

void InterfaceUI::setText(const sf::Text &text) {
    this->im_sfTxtText = text;
}
void InterfaceUI::setTIME(const float fTime) {
    this->im_TIME = fTime;
}


sf::Font InterfaceUI::getFont() const {
 return im_pFont;
}
sf::Color InterfaceUI::getFillColor() const {
    return im_sfCrColor;
}
sf::Color InterfaceUI::getHoverColor() const {
    return im_sfCrColorHover;
}sf::Color InterfaceUI::getOutlineColor() const {
    return im_sfCrColorOutline;
}
float InterfaceUI::getOutlineThickness() const {
    return im_fOutlineThickness;
}
sf::Vector2f InterfaceUI::getPosition() const {
    return im_VecFPosition;
}sf::Vector2f InterfaceUI::getSize() const {
    return im_VecFSize;
}
std::string InterfaceUI::getString() const {
    return im_sfTxtText.getString();
}
unsigned int InterfaceUI::getCharacterSize() const {
    return im_sfTxtText.getCharacterSize();
}
sf::Text InterfaceUI::getText() const {
    return im_sfTxtText;
}
float InterfaceUI::getTIME() const {
    return im_TIME;
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
bool InterfaceUI::buttonPressAndReleaseL() {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if (!m_bLButton) {
            m_bLButton = true; // Устанавливаем флаг
            return true;
        }
    } else {
        m_bLButton = false; // Сбрасываем флаг, если кнопка отпущена
    }
    return false;
}

///
/// @brief Правая кнопка мыши нажата
///
bool InterfaceUI::buttonPressAndReleaseR() {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
        if (!m_bRButton) {
            m_bRButton = true; // Устанавливаем флаг
            return true;
        }
    } else {
        m_bRButton = false; // Сбрасываем флаг, если кнопка отпущена
    }
    return false;
}

///
/// @brief Получение зажатия правой кнопки мыши
///
bool InterfaceUI::buttonClampingL() {
    return sf::Mouse::isButtonPressed(sf::Mouse::Left);
}
///
/// @brief Получение зажатия левой кнопки мыши
///
bool InterfaceUI::buttonClampingR() {
    return sf::Mouse::isButtonPressed(sf::Mouse::Right);
}

///
/// @brief Получение позиции мыши
///
sf::Vector2f InterfaceUI::getMousePosition(const sf::RenderWindow* window) {
    return sf::Vector2f(sf::Mouse::getPosition(*window));
}

