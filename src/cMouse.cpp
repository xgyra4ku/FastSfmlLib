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
namespace FS {
    ///
    /// constructors
    ///
    Mouse::Mouse() : LButton(sf::Mouse::Button::Left), RButton(sf::Mouse::Button::Right) {}

    ///
    /// destructor
    ///
    Mouse::~Mouse() = default;

    ///
    /// @brief колизия мыши с прямоугольником
    /// @param MousePosition Позиция мыши
    /// @param RectSize Размер прямоугольника
    /// @param RectPosition Позиция прямоугольника
    /// @return bool true если мышь в прямоугольнике
    ///
    bool Mouse::collision(const sf::Vector2f& MousePosition, const sf::Vector2f RectSize, const sf::Vector2f RectPosition) {
        if (static_cast<float>(MousePosition.x) >= RectPosition.x &&
            static_cast<float>(MousePosition.x) <= RectPosition.x + RectSize.x &&
            static_cast<float>(MousePosition.y) >= RectPosition.y &&
            static_cast<float>(MousePosition.y) <= RectPosition.y + RectSize.y) {
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
        if constexpr (sf::Mouse::Button::Right && !RButton) {
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
