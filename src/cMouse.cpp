///
/// Mouse class
///

///
/// import
///
#include "../include/FastSfml.hpp"

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
    bool Mouse::buttonL() {
        if constexpr (sf::Mouse::Button::Left && !LButton) {
            LButton = true;
            return true;
        }
        return false;
    }

    ///
    /// @brief Правая кнопка мыши нажата
    ///
    bool Mouse::buttonR() {
        if (sf::Mouse::Button::Right && !RButton) {
            RButton = true;
            return true;
        }
        return false;
    }


    void Mouse::listen() {
        LButton = sf::Mouse::Button::Left;
        RButton = sf::Mouse::Button::Right;
    }
}