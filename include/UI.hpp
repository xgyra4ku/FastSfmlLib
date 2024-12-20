#ifndef FASTSFML_UI_HPP
#define FASTSFML_UI_HPP

#include <SFML/Graphics.hpp>
#include <string>

///
/// InterfaseUI class
///
class InterfaceUI {
private:
    bool LButton{};
    bool RButton{};
protected:
    float m_TIME = 0;
    float m_fOutlineThickness = 0;
    sf::Text m_sfTxtText;
    sf::Font m_pFont{};
    sf::Vector2f m_VecFPosition;
    sf::Vector2f m_VecFSize;
    sf::Color m_sfCrColor;
    sf::Color m_sfCrColorHover;
    sf::Color m_sfCrColorOutline;

    InterfaceUI();
    virtual ~InterfaceUI();

    static bool collision(const sf::RenderWindow* window, sf::Vector2f RectSize, sf::Vector2f RectPosition);
    bool buttonR();
    bool buttonL();
public:
    // Чисто функции интерфейса
    virtual void setFillColor(sf::Color sfCrColorText);
    virtual void setHoverColor(sf::Color sfCrColorHover);
    virtual void setFont(const sf::Font& font);
    virtual void setPosition(sf::Vector2f sfVecFValue);
    virtual void setSize(sf::Vector2f sfVecFValue);
    virtual void setString(const std::string& strString);
    virtual void setCharacterSize(unsigned int iSize);
    virtual void setText(const sf::Text &text);
    virtual void setTIME(float fTime);
    virtual void setOutlineThickness(float thickness);
    virtual void setOutlineColor(sf::Color color);

    virtual sf::Font getFont() const;
    virtual sf::Color getFillColor() const;
    virtual sf::Color getHoverColor() const;
    virtual sf::Vector2f getPosition() const;
    virtual sf::Vector2f getSize() const;
    virtual std::string getString() const;
    virtual unsigned int getCharacterSize() const;
    virtual sf::Text getText() const;
    virtual float getTIME() const;
    virtual float getOutlineThickness() const;
    virtual sf::Color getOutlineColor() const;
};
///
/// namespace UI
///
namespace fs::UI {
    ///
    /// Button class
    ///
    class Button final : protected InterfaceUI {
    public:
        explicit Button(sf::RenderWindow &pWindow);

        ~Button() override;
        void logic();
        bool getStatus() const;
        void draw() const;
        void setPosition(sf::Vector2f sfVecFValue) override;
        void setSize(sf::Vector2f sfVecFValue) override;
        void setFillColor(sf::Color sfCrColorText) override;
        void setHoverColor(sf::Color sfCrColorHover) override;
        void setOutlineColor(sf::Color color) override;
        void setOutlineThickness(float thickness) override;
    private:
        sf::RenderWindow *m_pWindow;
        sf::RectangleShape m_sfRsRectangleShape[2];
        bool m_bStatus;
        bool m_buttonL;
    };
    // class Switch {
    //     sf::RectangleShape staticRS; // стачиский который просто стои прямоугольник
    //     sf::RectangleShape changeableRS; // изменяемый прямоугольник он немного меньше статического на пару процентов
    //
    //     bool status;
    // public:
    //     Switch();
    //     ~Switch();
    //
    //     void setStatus(bool status);
    //
    //     bool getStatus() const;
    //
    //     void setSize(sf::Vector2f size);
    //     void setColorStaticRS(sf::Color color);
    //     void setColorChangeableRS(sf::Color color);
    //     void setPosition(sf::Vector2f pos);
    //
    //     bool getStatus();
    //     sf::Vector2f getSize();
    //     sf::Vector2f getPos();
    //     sf::Color getColorStaticRS();
    //     sf::Color getColorChangeableRS();
    //
    // };
    // class Slider {
    //
    // };

}

#endif //FASTSFML_UI_HPP