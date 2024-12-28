///
/// Button class
///
#include "../include/FastSfml.hpp"

///
/// @brief Простравнство имен библиотеки
///
namespace fs::UI {
    ///
    /// @brief Конструктор
    ///
    Button::Button(sf::RenderWindow &pWindow) : m_pWindow(&pWindow), m_bStatus(false) {
        setPosition({0,0});
        setSize({100, 100});
        setFillColor(sf::Color::White);
        setHoverColor(sf::Color(40, 40, 40));
    }

    ///
    /// @brief Диструктор
    ///
    Button::~Button() = default;

    ///
    /// @brief Логика и обработка событий
    ///
    void Button::logic() {
        if (buttonPressAndReleaseL() && collision(m_pWindow, m_sfRsRectangleShape.getSize(), m_sfRsRectangleShape.getPosition())) m_bStatus = true;
        else m_bStatus = false;
    }

    ///
    /// @brief Логика и обработка событий
    ///
    void Button::draw() {
        if (m_bStatus) {
            m_sfRsRectangleShape.setFillColor(im_sfCrColorHover);
            m_pWindow->draw(m_sfRsRectangleShape);
            m_pWindow->draw(im_sfTxtText);
            m_sfRsRectangleShape.setFillColor(im_sfCrColor);
        } else {
            m_pWindow->draw(m_sfRsRectangleShape);
            m_pWindow->draw(im_sfTxtText);
        }
    }

    ///
    /// @brief Получение статуса кнопки
    ///
    bool Button::getStatus() const { return m_bStatus; }

    ///
    /// @brief установка позиции кнопки
    ///
    void Button::setPosition(const sf::Vector2f sfVecFValue) {
        m_sfRsRectangleShape.setPosition(sfVecFValue);
        im_VecFPosition = sfVecFValue;
    }

    //
    /// @brief установка размера кнопки
    ///
    void Button::setSize(const sf::Vector2f sfVecFValue) {
        m_sfRsRectangleShape.setSize(sfVecFValue);
        im_VecFSize = sfVecFValue;
    }

    ///
    /// @brief установка цвета нижнего прямоугольника
    ///
    void Button::setFillColor(const sf::Color sfCrColorText) {
        m_sfRsRectangleShape.setFillColor(sfCrColorText);
        im_sfCrColor = sfCrColorText;
    }

    ///
    /// @brief установка цвета верхнего прямоугольника
    ///
    void Button::setHoverColor(const sf::Color sfCrColorHover) {
        im_sfCrColorHover = sfCrColorHover;
    }

    ///
    /// @brief установка цвета обводки
    ///
    void Button::setOutlineColor(const sf::Color color) {
        m_sfRsRectangleShape.setOutlineColor(color);
        im_sfCrColorOutline = color;
    }

    ///
    /// @brief установка толщины обводки
    ///
    void Button::setOutlineThickness(const float thickness) {
        m_sfRsRectangleShape.setOutlineThickness(thickness);
        im_fOutlineThickness = thickness;
    }

    ///
    /// @brief установка шрифта
    ///
    void Button::setFont(const sf::Font &font) {
        im_sfTxtText.setFont(font);
        im_pFont = font;
    }

    ///
    /// @brief установка текста
    ///
    void Button::setText(const sf::Text &text) {
        im_sfTxtText = text;
    }

    void Button::setString(const std::string &strString) {
        im_sfTxtText.setString(strString);
    }

    ///
    /// @brief установка размера шрифта
    ///
    void Button::setCharacterSize(const unsigned int iSize) {
        im_sfTxtText.setCharacterSize(iSize);
    }
}
