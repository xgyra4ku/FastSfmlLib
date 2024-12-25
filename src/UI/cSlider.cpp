///
/// Slider class
///
#include "../include/FastSfml.hpp"
namespace fs::UI {
    ///
    /// @brief Конструктор
    ///
    Slider::Slider(sf::RenderWindow &pWindow) : m_pWindow(&pWindow), m_iStatus(1), m_iOption(1) {
        setPosition({0,0});
        setSize({100, 100});
        setFillColor(sf::Color::White);
        setHoverColor(sf::Color::Blue);
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
    int Slider::getStatus() const {
        return m_iStatus;
    }

    ///
    /// @brief установка статуса кнопки
    ///
    void Slider::setStatus(const int iStatus) {
        // логика обработки перемешения слайдера
        m_iStatus = iStatus;
    }

    ///
    /// @brief установка позиции кнопки
    ///
    void Slider::setPosition(const sf::Vector2f sfVecFValue) {
        // Устанавливаем позицию для первого (горизонтального) прямоугольника
        m_sfRsRectangleShape[1].setPosition(sfVecFValue);
        m_sfRsRectangleShape[0].setPosition({sfVecFValue.x, (sfVecFValue.y + m_VecFSize.y / 2.45f)});

        // Запоминаем общую позицию
        m_VecFPosition = sfVecFValue;
    }

    ///
    /// @brief установка размера кнопки
    ///
    void Slider::setSize(const sf::Vector2f sfVecFValue) {
        // Запоминаем общий размер
        m_VecFSize = sfVecFValue;

        // Устанавливаем размер для горизонтального прямоугольника
        // Горизонтальный прямоугольник будет занимать всю ширину, но только определенную высоту
        m_sfRsRectangleShape[0].setSize(sf::Vector2f(sfVecFValue.x, sfVecFValue.y / 5)); // Например, горизонтальный прямоугольник будет очень тонким

        // Устанавливаем размер для вертикального прямоугольника
        // Вертикальный прямоугольник будет занимать всю высоту, но определенную ширину
        m_sfRsRectangleShape[1].setSize(sf::Vector2f(((sfVecFValue.x / 15.0f < sfVecFValue.y / 2.5f) ? sfVecFValue.x / 15 : sfVecFValue.y / 1.5f), sfVecFValue.y)); // Например, вертикальный прямоугольник будет тонким, но высоким
    }


    ///
    /// @brief установка цвета нижнего прямоугольника
    ///
    void Slider::setFillColor(const sf::Color sfCrColorText) {
        m_sfRsRectangleShape[0].setFillColor(sfCrColorText);
        m_sfCrColor = sfCrColorText;
    }

    ///
    /// @brief установка цвета верхнего прямоугольника
    ///
    void Slider::setHoverColor(const sf::Color sfCrColorHover) {
        m_sfRsRectangleShape[1].setFillColor(sfCrColorHover);
        m_sfCrColorHover = sfCrColorHover;
    }

    ///
    /// @brief установка количество опций
    ///
    void Slider::setOption(const int iOption) {
        m_iOption = iOption;
    }

    ///
    /// @brief получение количество опций
    ///
    int Slider::getOption() const {
        return m_iOption;
    }
}
