///
/// InterfaseUI class
///
#include "../include/UI.hpp"
InterfaceUI::InterfaceUI() :
m_bLButton{}, m_bRButton {}, im_TIME{}, im_fOutlineThickness{},
im_sfTxtText{}, im_pFont{}, im_VecFPosition{},
im_VecFSize{}, im_sfCrColor{}, im_sfCrColorHover{}, im_sfCrColorOutline{} {}
InterfaceUI::~InterfaceUI() = default;

///
/// @param font новый шрифт
///
void InterfaceUI::setFont(const sf::Font & font) {
    this->im_pFont = font;
}

///
/// @param strString новый текст
///
void InterfaceUI::setString(const std::string &strString) {
    im_sfTxtText.setString(strString);
}

///
/// @param iSize новый размер шрифта
///
void InterfaceUI::setCharacterSize(const unsigned int iSize) {
    im_sfTxtText.setCharacterSize(iSize);
}

///
/// @param sfVecFValue новая позиция нижнего прямоугольника
///
void InterfaceUI::setPosition(const sf::Vector2f sfVecFValue) {
    this->im_VecFPosition = sfVecFValue;
}
///
/// @param sfVecFValue новая позиция нижнего прямоугольника
///
void InterfaceUI::setSize(const sf::Vector2f sfVecFValue) {
    this->im_VecFSize = sfVecFValue;
}
///
/// @param sfCrColorText новый цвет нижнего прямоугольника
///
void InterfaceUI::setFillColor(const sf::Color sfCrColorText) {
    this->im_sfCrColor = sfCrColorText;
}

///
/// @param sfCrColorHover новый цвет верхнего прямоугольника
///
void InterfaceUI::setHoverColor(const sf::Color sfCrColorHover) {
    this->im_sfCrColorHover = sfCrColorHover;
}

///
/// @param color новый цвет обводки
///
void InterfaceUI::setOutlineColor(const sf::Color color) {
    this->im_sfCrColorOutline = color;
}

///
/// @param thickness новая толщина обводки
///
void InterfaceUI::setOutlineThickness(const float thickness) {
    this->im_fOutlineThickness = thickness;
}

///
/// @param text новый текст
///
void InterfaceUI::setText(const sf::Text &text) {
    this->im_sfTxtText = text;
}

///
/// @brief установка времени интерфейса
///
void InterfaceUI::setTIME(const float fTime) {
    this->im_TIME = fTime;
}
///
/// @brief установка позиции текста
///
void InterfaceUI::setTextPosition(const sf::Vector2f sfVecFValue) {
    im_sfTxtText.setPosition(sfVecFValue);
}

///
/// @brief установка цвета текста
///
void InterfaceUI::setTextColor(const sf::Color color) {
    im_sfTxtText.setFillColor(color);
}


///
/// @return шрифт
///
sf::Font InterfaceUI::getFont() const {
 return im_pFont;
}

///
/// @return цвет фулл
///
sf::Color InterfaceUI::getFillColor() const {
    return im_sfCrColor;
}

///
/// @return цвет ховер
///
sf::Color InterfaceUI::getHoverColor() const {
    return im_sfCrColorHover;
}

///
/// @return цвет обводки
///
sf::Color InterfaceUI::getOutlineColor() const {
    return im_sfCrColorOutline;
}

///
/// @return толщина обводки
///
float InterfaceUI::getOutlineThickness() const {
    return im_fOutlineThickness;
}

///
/// @return позиция
///
sf::Vector2f InterfaceUI::getPosition() const {
    return im_VecFPosition;
}

///
/// @return размер
///
sf::Vector2f InterfaceUI::getSize() const {
    return im_VecFSize;
}

///
/// @return текст
///
std::string InterfaceUI::getString() const {
    return im_sfTxtText.getString();
}

///
/// @return размер шрифта
///
unsigned int InterfaceUI::getCharacterSize() const {
    return im_sfTxtText.getCharacterSize();
}

///
/// @return текст
///
sf::Text InterfaceUI::getText() const {
    return im_sfTxtText;
}

///
/// @return время интерфейса
///
float InterfaceUI::getTIME() const {
    return im_TIME;
}

///
/// @brief колизия мыши с прямоугольником
///
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
bool InterfaceUI::buttonPressOneAction() {
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

///
/// @brief Получение позиции текста
///
sf::Vector2f InterfaceUI::getTextPosition() const {
    return im_sfTxtText.getPosition();
}

///
/// @brief Получение цвета текста
///
sf::Color InterfaceUI::getTextColor() const {
    return im_sfTxtText.getFillColor();
}