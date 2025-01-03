#ifndef FASTSFML_UI_HPP
#define FASTSFML_UI_HPP

#include <SFML/Graphics.hpp>
#include <string>

///
/// InterfaceUI class
///
class InterfaceUI {
    bool m_bLButton;
    bool m_bRButton;
protected:
    float im_TIME = 0;
    float im_fOutlineThickness = 0;
    sf::Text im_sfTxtText;
    sf::Font im_pFont;
    sf::Vector2f im_VecFPosition;
    sf::Vector2f im_VecFSize;
    sf::Color im_sfCrColor;
    sf::Color im_sfCrColorHover;
    sf::Color im_sfCrColorOutline;

    InterfaceUI();
    virtual ~InterfaceUI();

    static bool collision(const sf::RenderWindow* window, sf::Vector2f RectSize, sf::Vector2f RectPosition);

    bool buttonPressOneAction();

    bool buttonPressAndReleaseR();

    static sf::Vector2f getMousePosition(const sf::RenderWindow* window);

    static bool buttonClampingR();
    static bool buttonClampingL();
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
    virtual void setTextColor(sf::Color color);
    virtual void setTextPosition(sf::Vector2f sfVecFValue);

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
    virtual sf::Color getTextColor() const;
    virtual sf::Vector2f getTextPosition() const;
};
///
/// Namespace UI
///
namespace fs::UI {
    ///
    /// Switch class
    ///
    class Switch final : protected InterfaceUI {
    public:
        explicit Switch(sf::RenderWindow &pWindow);

        ~Switch() override;
        void logic();
        bool getStatus() const;
        void setStatus(bool bStatus);
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

    ///
    /// Slider class
    ///
    class Slider final : public InterfaceUI {
    public:
        explicit Slider(sf::RenderWindow &pWindow);

        ~Slider() override;

        void logic();
        void draw() const;
        int getStatus() const;
        void setStatus(int iStatus);

        void setPosition(sf::Vector2f sfVecFValue) override;
        void setSize(sf::Vector2f sfVecFValue) override;
        void setFillColor(sf::Color sfCrColorText) override;
        void setHoverColor(sf::Color sfCrColorHover) override;
        void setOption(int iOption);

        int getOption() const;
    private:
        sf::RenderWindow *m_pWindow;
        sf::RectangleShape m_sfRsRectangleShape[2];
        int m_iStatus, m_iOption;
        float m_fLastPositionMouse;
        bool m_bButtonPressed, m_bInput;
    };

    ///
    /// Button class
    ///
    class Button final : protected InterfaceUI {
    public:
        explicit Button(sf::RenderWindow &pWindow);

        ~Button() override;
        void logic();
        bool getStatus() const;
        void draw();

        void setPosition(sf::Vector2f sfVecFValue) override;
        void setSize(sf::Vector2f sfVecFValue) override;
        void setFillColor(sf::Color sfCrColorText) override;
        void setHoverColor(sf::Color sfCrColorHover) override;
        void setOutlineColor(sf::Color color) override;
        void setOutlineThickness(float thickness) override;
        void setText(const sf::Text &text) override;
        void setFont(const sf::Font &font) override;
        void setString(const std::string &strString) override;
        void setCharacterSize(unsigned int iSize) override;
        void setTextPosition(sf::Vector2f sfVecFValue) override;
        void setTextColor(sf::Color color) override;
    private:
        sf::RenderWindow *m_pWindow;
        sf::RectangleShape m_sfRsRectangleShape;
        bool m_bStatus;
    };
}

#endif //FASTSFML_UI_HPP