#include "../include/FastSfml.hpp"
///
/// @brief Простравнство имен библиотеки
///
namespace FS {
    ///
    /// @brief Конструктор
    ///
    Button::Button() {

    }

    ///
    /// @brief Диструктор
    ///
    Button::~Button() {

    }

    ///
    /// @brief Логика и обработка событий
    /// @param fTime Время
    ///
    void Button::logic(const float fTime) {

    }

    ///
    /// @brief Логика и обработка событий
    /// @param sfRwWindow Окно
    ///
    void Button::draw(const sf::RenderWindow &sfRwWindow) const {

    }

    void Button::setFont(const sf::Font &) {

    }

    void Button::setString(const std::string &strString) {

    }

    void Button::setCharacterSize(unsigned int iSize) {

    }

    void Button::setPosition(sf::Vector2f sfVecFValue) {

    }

    void Button::setFillColor(sf::Color sfCrColorText) {

    }

    const sf::Font *Button::getFont() const {
        return m_sfTxtTextButton.getFont();
    }

    sf::Vector2f Button::getPosition() const {
        return m_sfTxtTextButton.getPosition();
    }

    std::string Button::getString() const {
        return m_sfTxtTextButton.getString();
    }

    sf::Color Button::getFillColor() const {
        return m_sfTxtTextButton.getFillColor();
    }

    unsigned int Button::getCharacterSize() const {
        return m_sfTxtTextButton.getCharacterSize();
    }

}
