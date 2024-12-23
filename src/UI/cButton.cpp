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
    Button::Button(sf::RenderWindow &pWindow) : m_pWindow(&pWindow), m_bStatus(false), m_buttonL(false) {
        // setPosition({300,300});
        // setSize({100, 100});
        // setFillColor(sf::Color::White);
        // setHoverColor(sf::Color(40, 40, 40));
        // m_sfRsRectangleShape[0].setOutlineColor(sf::Color::White);
        // m_sfRsRectangleShape[0].setOutlineThickness(2.f);
        // m_sfRsRectangleShape[1].setOutlineColor(sf::Color::White);
        // m_sfRsRectangleShape[1].setOutlineThickness(2.f);
    }

    ///
    /// @brief Диструктор
    ///
    Button::~Button() = default;

    ///
    /// @brief Логика и обработка событий
    ///
    void Button::logic() {
        // if (buttonL()) {
        //     std::cout << "click" << std::endl;
        //     if (collision(m_pWindow, m_sfRsRectangleShape[0].getSize(), m_sfRsRectangleShape[0].getPosition())) {
        //         m_bStatus = !m_bStatus;
        //     }
        // }
    }

    ///
    /// @brief Логика и обработка событий
    ///
    void Button::draw() const {
        m_pWindow->draw(m_sfRsRectangleShape);
        //... text drawing
    }

    ///
    /// @brief Получение статуса кнопки
    ///
    bool Button::getStatus() const { return m_bStatus; }

    ///
    /// @brief установка позиции кнопки
    ///
    void Button::setPosition(const sf::Vector2f sfVecFValue) {
        // m_sfRsRectangleShape[0].setPosition(sfVecFValue);
        // m_sfRsRectangleShape[1].setPosition(sfVecFValue);
        m_VecFPosition = sfVecFValue;
    }

    ///
    /// @brief установка размера кнопки
    ///
    void Button::setSize(const sf::Vector2f sfVecFValue) {
        // m_sfRsRectangleShape[0].setSize(sfVecFValue);
        // m_sfRsRectangleShape[1].setSize(sfVecFValue);
        m_VecFSize = sfVecFValue;
    }

    ///
    /// @brief установка цвета нижнего прямоугольника
    ///
    void Button::setFillColor(const sf::Color sfCrColorText) {
        // m_sfRsRectangleShape[0].setFillColor(sfCrColorText);
        // m_sfRsRectangleShape[0].setOutlineColor(sfCrColorText);
        m_sfCrColor = sfCrColorText;
    }

    ///
    /// @brief установка цвета верхнего прямоугольника
    ///
    void Button::setHoverColor(const sf::Color sfCrColorHover) {
        // m_sfRsRectangleShape[1].setFillColor(sfCrColorHover);
        m_sfCrColorHover = sfCrColorHover;
    }

    ///
    /// @brief установка цвета обводки
    ///
    void Button::setOutlineColor(const sf::Color color) {
        // m_sfRsRectangleShape[1].setOutlineColor(color);
        m_sfCrColorOutline = color;
    }

    ///
    /// @brief установка толщины обводки
    ///
    void Button::setOutlineThickness(const float thickness) {
        // m_sfRsRectangleShape[0].setOutlineThickness(thickness);
        // m_sfRsRectangleShape[1].setOutlineThickness(thickness);
        m_fOutlineThickness = thickness;
    }
}
