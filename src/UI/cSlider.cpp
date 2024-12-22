///
/// Slider class
///
#include "../include/FastSfml.hpp"
namespace fs::UI {
    ///
    /// @brief Конструктор
    ///
    Slider::Slider(sf::RenderWindow &pWindow) : m_pWindow(&pWindow), m_iStatus(1) {
        //setPosition({300,300});
        //setSize({100, 100});
        //setFillColor(sf::Color::White);
        //setHoverColor(sf::Color(40, 40, 40));
        //m_sfRsRectangleShape[0].setOutlineColor(sf::Color::White);
        //m_sfRsRectangleShape[0].setOutlineThickness(2.f);
        //m_sfRsRectangleShape[1].setOutlineColor(sf::Color::White);
        //m_sfRsRectangleShape[1].setOutlineThickness(2.f);
    }

    ///
    /// @brief Диструктор
    ///
    Slider::~Slider() = default;

    ///
    /// @brief Логика и обработка событий
    ///
    void Slider::logic() {

    }

    ///
    /// @brief Логика и обработка событий
    ///
    void Slider::draw() const {
        m_pWindow->draw(m_sfRsRectangleShape[0]);
        m_pWindow->draw(m_sfRsRectangleShape[1]);
    }

    ///
    /// @brief Получение статуса кнопки
    ///
    int Slider::getStatus() const { return m_iStatus; }

    ///
    /// @brief установка позиции кнопки
    ///
    void Slider::setPosition(const sf::Vector2f sfVecFValue) {

    }

    ///
    /// @brief установка размера кнопки
    ///
    void Slider::setSize(const sf::Vector2f sfVecFValue) {

    }

    ///
    /// @brief установка цвета нижнего прямоугольника
    ///
    void Slider::setFillColor(const sf::Color sfCrColorText) {

    }

    ///
    /// @brief установка цвета верхнего прямоугольника
    ///
    void Slider::setHoverColor(const sf::Color sfCrColorHover) {

    }
}
