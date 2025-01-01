///
/// Mouse class
///

///
/// import
///
#include "../include/FastSfml.hpp"
#include <iostream>

///
/// namespace lib
///
namespace fs {
    ///
    /// constructors
    ///
    Mouse::Mouse(sf::RenderWindow& sfRwWindow) : LButton(false), RButton(false), window(&sfRwWindow) {
    }

    ///
    /// destructor
    ///
    Mouse::~Mouse() = default;

    ///
    /// @brief колизия мыши с прямоугольником
    /// @param RectSize Размер прямоугольника
    /// @param RectPosition Позиция прямоугольника
    /// @return bool true если мышь в прямоугольнике
    ///
    bool Mouse::collision(const sf::Vector2f RectSize, const sf::Vector2f RectPosition) const {
        if (!window) {
            return false; // Проверка на nullptr
        }
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
    bool Mouse::buttonPressOneAction() {
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
    bool Mouse::buttonPressAndReleaseR() {
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
    bool Mouse::buttonClampingL() {
        return sf::Mouse::isButtonPressed(sf::Mouse::Left);
    }
    ///
    /// @brief Получение зажатия левой кнопки мыши
    ///
    bool Mouse::buttonClampingR() {
        return sf::Mouse::isButtonPressed(sf::Mouse::Right);
    }

    ///
    /// @brief Получение позиции мыши
    ///
    sf::Vector2f Mouse::getMousePosition(const sf::RenderWindow* window) {
        return sf::Vector2f(sf::Mouse::getPosition(*window));
    }




    void Mouse::listen() {
        LButton = sf::Mouse::Button::Left;
        RButton = sf::Mouse::Button::Right;
    }
}
