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
    void Button::draw() const {
        m_pWindow->draw(m_sfRsRectangleShape);
        m_pWindow->draw(m_sfText);
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
        m_VecFPosition = sfVecFValue;
    }

    //
    /// @brief установка размера кнопки
    ///
    void Button::setSize(const sf::Vector2f sfVecFValue) {
        m_sfRsRectangleShape.setSize(sfVecFValue);
        m_VecFSize = sfVecFValue;
    }

    ///
    /// @brief установка цвета нижнего прямоугольника
    ///
    void Button::setFillColor(const sf::Color sfCrColorText) {
        m_sfRsRectangleShape.setFillColor(sfCrColorText);
        m_sfCrColor = sfCrColorText;
    }

    ///
    /// @brief установка цвета верхнего прямоугольника
    ///
    void Button::setHoverColor(const sf::Color sfCrColorHover) {
        m_sfText.setFillColor(sfCrColorHover);
        m_sfCrColorHover = sfCrColorHover;
    }

    ///
    /// @brief установка цвета обводки
    ///
    void Button::setOutlineColor(const sf::Color color) {
        m_sfRsRectangleShape.setOutlineColor(color);
        m_sfCrColorOutline = color;
    }

    ///
    /// @brief установка толщины обводки
    ///
    void Button::setOutlineThickness(const float thickness) {
        m_sfRsRectangleShape.setOutlineThickness(thickness);
        m_fOutlineThickness = thickness;
    }
}
