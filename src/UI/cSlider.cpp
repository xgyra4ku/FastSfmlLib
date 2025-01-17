///
/// Slider class
///
#include "../include/FastSfml.hpp"
namespace fs::UI {
    ///
    /// @brief Конструктор
    ///
    Slider::Slider(sf::RenderWindow &pWindow) :
    m_pWindow(&pWindow),m_iStatus(0),m_iOption(1),
    m_fLastPositionMouse(getMousePosition(m_pWindow).x) , m_bButtonPressed(false), m_bInput(false) {
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
        //сть встроеные функции buttonClampingL() и buttonPressAndReleaseL()
        if (buttonPressOneAction()) {
            if (collision(m_pWindow, m_sfRsRectangleShape[1].getSize(), m_sfRsRectangleShape[1].getPosition())) m_bInput = true;
            else m_bInput= false;
        }
        if (buttonClampingL()) {
            if (collision(m_pWindow, m_sfRsRectangleShape[1].getSize(), m_sfRsRectangleShape[1].getPosition()))
                m_bButtonPressed = true;
        } else {
            m_fLastPositionMouse = getMousePosition(m_pWindow).x;
            m_bButtonPressed = false;
        }
        if (m_bButtonPressed && m_bInput) {
            const float stepWidth = getSize().x / static_cast<float>(m_iOption);
            float currentMousePositionX = getMousePosition(m_pWindow).x;
            if (m_fLastPositionMouse - stepWidth > currentMousePositionX &&m_iStatus > 0) {
                m_iStatus--;
                m_sfRsRectangleShape[1].setPosition(
                    m_sfRsRectangleShape[1].getPosition().x - stepWidth,
                    m_sfRsRectangleShape[1].getPosition().y
                );
                m_fLastPositionMouse -= stepWidth;
            }
            else if (m_fLastPositionMouse + stepWidth < currentMousePositionX &&m_iStatus < m_iOption) {
                m_iStatus++;
                m_sfRsRectangleShape[1].setPosition(
                    m_sfRsRectangleShape[1].getPosition().x + stepWidth,
                    m_sfRsRectangleShape[1].getPosition().y
                );
                m_fLastPositionMouse += stepWidth;
            }
        }
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
        m_sfRsRectangleShape[1].setPosition(
            im_VecFPosition.x + static_cast<float>(iStatus) * getSize().x / static_cast<float>(m_iOption),
            im_VecFPosition.y
        );
        m_iStatus = iStatus;
    }



    ///
    /// @brief установка позиции кнопки
    ///
    void Slider::setPosition(const sf::Vector2f sfVecFValue) {
        // Устанавливаем позицию для первого (горизонтального) прямоугольника
        m_sfRsRectangleShape[1].setPosition(sfVecFValue);
        m_sfRsRectangleShape[0].setPosition({sfVecFValue.x, (sfVecFValue.y + im_VecFSize.y / 2.45f)});

        // Запоминаем общую позицию
        im_VecFPosition = sfVecFValue;
    }

    ///
    /// @brief установка размера кнопки
    ///
    void Slider::setSize(const sf::Vector2f sfVecFValue) {
        // Запоминаем общий размер
        im_VecFSize = sfVecFValue;
        m_sfRsRectangleShape[0].setSize(sf::Vector2f(sfVecFValue.x, sfVecFValue.y / 5));
        float xx = (sfVecFValue.x > sfVecFValue.y) ? 3.f : 1.5f;

        m_sfRsRectangleShape[1].setSize(sf::Vector2f(
            (sfVecFValue.x / 15.0f < sfVecFValue.y / xx) ? sfVecFValue.x / 15.0f : sfVecFValue.y / xx,
            sfVecFValue.y
        ));

    }


    ///
    /// @brief установка цвета нижнего прямоугольника
    ///
    void Slider::setFillColor(const sf::Color sfCrColorText) {
        m_sfRsRectangleShape[0].setFillColor(sfCrColorText);
        im_sfCrColor = sfCrColorText;
    }

    ///
    /// @brief установка цвета верхнего прямоугольника
    ///
    void Slider::setHoverColor(const sf::Color sfCrColorHover) {
        m_sfRsRectangleShape[1].setFillColor(sfCrColorHover);
        im_sfCrColorHover = sfCrColorHover;
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
