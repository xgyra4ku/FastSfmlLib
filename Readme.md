## EN
---
![wmremove-transformed_preview_rev_1](https://github.com/user-attachments/assets/fa6f34d1-2483-425a-9cab-26ca2789f133)

 # FastSfml version 2.1.0

FastSfml is a library designed to simplify the creation of games using [SFML](https://www.sfml-dev.org/) (Simple and Fast Multimedia Library). It provides developers with intuitive and ready-to-use components to handle common UI and input tasks, reducing boilerplate code and accelerating development.

---

## Key Features

### Mouse Handling
FastSfml makes mouse input management simple and efficient. It abstracts common tasks, such as tracking mouse clicks and movement, and provides straightforward interfaces for developers to integrate into their projects.

### UI Components
FastSfml includes a set of powerful UI elements:

- **Button**: A clickable UI element that can be customized with different colors, sizes, fonts, and hover effects. Developers can attach logic to button states for seamless interactivity.
- **Slider**: A convenient slider element for selecting numeric values within a range. It supports setting dimensions, positions, and specific step options.
- **Switch**: A toggleable UI component with customizable appearance, useful for binary options like enabling/disabling features.

### Text Handling
FastSfml simplifies text input and management with the `InputText` component. This feature allows developers to create text input fields with:

- Customizable fonts and sizes.
- Dynamic text capturing and rendering.
- Adjustable positioning and bounding boxes.

These features make it easy to implement text-based interactions in games, such as chat systems or user settings.

---

## Installation

Currently, FastSfml is distributed as source code. To use it:
1. Download the library files.
2. Include the header files in your project.
3. Ensure you have [SFML 2.5.1](https://www.sfml-dev.org/download.php) or newer installed.

---

## Example Usage

Below is a detailed example demonstrating how to use FastSfml in a game project:

```cpp
#include <iostream>
#include <SFML/Graphics.hpp>
#include "FastSfml.hpp"

float fTime = 0;
sf::Clock oClock;

void time_func()
{
    fTime = oClock.getElapsedTime().asMicroseconds();
    oClock.restart();

    fTime = fTime / 1000;

    if (fTime > 20) fTime = 20;
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 800), "window");
    sf::Font font;
    if (!font.loadFromFile("fonts/arial.ttf"))
    {
        std::cout << "Error loading font" << std::endl;
        return EXIT_FAILURE;
    }

    fs::Text::InputText inputText;
    fs::Mouse mouse(window);
    fs::UI::Switch switch_(window);
    fs::UI::Slider slider(window);
    fs::UI::Button button(window);

    // Configure the switch
    switch_.setPosition(sf::Vector2f(400, 400));
    switch_.setSize(sf::Vector2f(300, 70));
    switch_.setFillColor(sf::Color::White);
    switch_.setHoverColor(sf::Color(40, 40, 40));
    switch_.setOutlineColor(sf::Color::White);
    switch_.setOutlineThickness(2.0f);

    // Configure the text input
    inputText.setFont(font);
    inputText.setCharacterSize(40);
    inputText.setRectSize(sf::Vector2f(300, 70));
    inputText.setPosition(sf::Vector2f(70, 70));

    // Configure the slider
    slider.setSize({100, 30});
    slider.setPosition({300, 600});
    slider.setOption(20);

    // Configure the button
    button.setPosition({600, 600});
    button.setSize({100, 30});
    button.setFont(font);
    button.setString("Button");
    button.setCharacterSize(10);
    button.setTextPosition({600, 600});
    button.setTextColor(sf::Color::Green);
    button.setFillColor(sf::Color::White);
    button.setHoverColor(sf::Color(40, 40, 40});

    while (window.isOpen())
    {
        time_func();
        inputText.listen(fTime);
        mouse.listen();
        switch_.logic();
        slider.logic();
        button.logic();

        sf::Event event{};

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        if (switch_.getStatus()) {
            inputText.setInput(true);
        } else {
            inputText.setInput(false);
        }

        if (button.getStatus()) {
            std::cout << "Button" << std::endl;
        }

        window.clear(sf::Color(33, 31, 48));

        inputText.draw(window);
        switch_.draw();
        slider.draw();
        button.draw();

        window.display();
    }
}
```

This example illustrates the use of multiple UI elements and demonstrates their interactivity in a game environment.

---

## Dependencies

- [SFML 2.5.1](https://www.sfml-dev.org/) or newer.

---

## License

This library is free to use, modify, and distribute. Feel free to adapt it to your needs.

---

## Future Documentation

Detailed documentation will be available in future releases. It will include:
- Full API references.
- Additional usage examples.
- Tips and tricks for customizing UI components.

---

## Multilingual README

This README is available in both English and Russian.

---
## RU
---

# FastSfml ver2.1.0

FastSfml - это библиотека, предназначенная для упрощения создания игр с использованием [SFML](https://www.sfml-dev.org/) (Simple and Fast Multimedia Library). Она предоставляет разработчикам интуитивно понятные и готовые к использованию компоненты для работы с пользовательским интерфейсом и вводом, сокращая шаблонный код и ускоряя разработку.

---

## Основные возможности

### Работа с мышью
FastSfml упрощает управление вводом с мыши. Она абстрагирует распространённые задачи, такие как отслеживание кликов и движения мыши, и предоставляет удобные интерфейсы для интеграции в проекты.

### UI-компоненты
FastSfml включает набор мощных элементов пользовательского интерфейса:

- **Кнопка (Button)**: Кликабельный UI-элемент, который можно настроить, изменяя цвет, размер, шрифт и эффекты наведения. Разработчики могут привязывать логику к состояниям кнопки для обеспечения интерактивности.
- **Ползунок (Slider)**: Удобный элемент управления, позволяющий выбирать числовые значения в заданном диапазоне. Поддерживает настройку размеров, позиций и шагов.
- **Переключатель (Switch)**: Переключаемый UI-компонент с настраиваемым внешним видом, полезный для бинарных опций, например, включения/выключения функций.

### Работа с текстом
FastSfml упрощает ввод и управление текстом с помощью компонента `InputText`. Этот компонент позволяет разработчикам создавать текстовые поля ввода с:

- Настраиваемыми шрифтами и размерами.
- Динамическим захватом и отображением текста.
- Регулируемым позиционированием и границами.

Эти функции облегчают реализацию текстовых взаимодействий в играх, например, чат-систем или пользовательских настроек.

---

## Установка

В настоящее время FastSfml распространяется в виде исходного кода. Чтобы использовать её:
1. Скачайте файлы библиотеки.
2. Подключите заголовочные файлы к вашему проекту.
3. Убедитесь, что у вас установлена [SFML 2.5.1](https://www.sfml-dev.org/download.php) или новее.

---

## Пример использования

Приведённый ниже пример демонстрирует использование FastSfml в игровом проекте:

```cpp
#include <iostream>
#include <SFML/Graphics.hpp>
#include "FastSfml.hpp"

float fTime = 0;
sf::Clock oClock;

void time_func()
{
    fTime = oClock.getElapsedTime().asMicroseconds();
    oClock.restart();

    fTime = fTime / 1000;

    if (fTime > 20) fTime = 20;
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 800), "window");
    sf::Font font;
    if (!font.loadFromFile("fonts/arial.ttf"))
    {
        std::cout << "Error loading font" << std::endl;
        return EXIT_FAILURE;
    }

    fs::Text::InputText inputText;
    fs::Mouse mouse(window);
    fs::UI::Switch switch_(window);
    fs::UI::Slider slider(window);
    fs::UI::Button button(window);

    // Настройка переключателя
    switch_.setPosition(sf::Vector2f(400, 400));
    switch_.setSize(sf::Vector2f(300, 70));
    switch_.setFillColor(sf::Color::White);
    switch_.setHoverColor(sf::Color(40, 40, 40));
    switch_.setOutlineColor(sf::Color::White);
    switch_.setOutlineThickness(2.0f);

    // Настройка текстового ввода
    inputText.setFont(font);
    inputText.setCharacterSize(40);
    inputText.setRectSize(sf::Vector2f(300, 70));
    inputText.setPosition(sf::Vector2f(70, 70));

    // Настройка ползунка
    slider.setSize({100, 30});
    slider.setPosition({300, 600});
    slider.setOption(20);

    // Настройка кнопки
    button.setPosition({600, 600});
    button.setSize({100, 30});
    button.setFont(font);
    button.setString("Button");
    button.setCharacterSize(10);
    button.setTextPosition({600, 600});
    button.setTextColor(sf::Color::Green);
    button.setFillColor(sf::Color::White);
    button.setHoverColor(sf::Color(40, 40, 40});

    while (window.isOpen())
    {
        time_func();
        inputText.listen(fTime);
        mouse.listen();
        switch_.logic();
        slider.logic();
        button.logic();

        sf::Event event{};

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        if (switch_.getStatus()) {
            inputText.setInput(true);
        } else {
            inputText.setInput(false);
        }

        if (button.getStatus()) {
            std::cout << "Button" << std::endl;
        }

        window.clear(sf::Color(33, 31, 48));

        inputText.draw(window);
        switch_.draw();
        slider.draw();
        button.draw();

        window.display();
    }
}
```

Этот пример демонстрирует использование нескольких элементов UI и их интерактивность в игровом окружении.

---

## Зависимости

- [SFML 2.5.1](https://www.sfml-dev.org/) или новее.

---

## Лицензия

Эта библиотека свободна для использования, модификации и распространения. Вы можете адаптировать её под свои нужды.

---

## Будущая документация

Подробная документация будет доступна в будущих выпусках. Она будет включать:
- Полное описание API.
- Дополнительные примеры использования.
- Советы и хитрости по кастомизации UI-компонентов.

---

## README на нескольких языках

Этот README доступен на английском и русском языках.

---

