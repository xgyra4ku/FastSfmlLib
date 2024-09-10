# LibKyraText

LibKyraText — это простая библиотека для ввода текста, основанная на SFML. Она предоставляет удобный интерфейс для управления текстовым вводом в графических приложениях. Библиотека позволяет захватывать ввод с клавиатуры, отображать текст и настраивать его внешний вид.

## Особенности

- Захват текстового ввода с клавиатуры.
- Поддержка базового редактирования текста (например, удаление символов).
- Отображение текста и прямоугольной области с настраиваемыми цветами, шрифтами и размерами.
- Возможность включения и отключения текстового ввода.
- Простая интеграция с `RenderWindow` из SFML.

## Зависимости

- [SFML](https://www.sfml-dev.org/) (Simple and Fast Multimedia Library)

## Установка

1. Установите SFML на свою систему.
2. Склонируйте или загрузите этот репозиторий.
3. Добавьте файлы `LibKyraText.h` и `LibKyraText.cpp` в свой проект.
4. При компиляции вашего проекта свяжите его с библиотеками SFML.

## Использование

### Инициализация

Для использования класса `cInputText` создайте его экземпляр и настройте его свойства по своему усмотрению:

```
#include "LibKyraText.h"
#include <SFML/Graphics.hpp>

ktx::cInputText inputText;
inputText.setRectSize(sf::Vector2f(300, 50));
inputText.setColorText(sf::Color::Black);
inputText.setColorRect(sf::Color::White);
```
## Обработка ввода
Метод ```readKey()``` обрабатывает ввод с клавиатуры, а метод ```setInput()``` включает или отключает возможность ввода текста:
```
// Включить ввод
inputText.setInput(true);
// В игровом цикле обновляйте ввод текста, передавая значение времени
inputText.readKey(elapsedTime);
```
## Отрисовка
```
Метод draw() используется для отрисовки текста и фона на экране с помощью RenderWindow из SFML:
// В цикле отрисовки
window.clear();
inputText.draw(window);
window.display();
```
Настройки
Позиция текста: ```setPositionText(sf::Vector2f)```

Позиция прямоугольника: ```setPositionRectangleShape(sf::Vector2f)```

Шрифт: ```setFont(const sf::Font&)```

Цвет текста: ```setColorText(sf::Color)```

Цвет прямоугольника: ```setColorRect(sf::Color)```

Размер текста: ```setCharacterSize(unsigned int)```


## Пример

```
#include <SFML/Graphics.hpp>
#include "LibKyraText.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "LibKyraText Example");
    sf::Font font;
    font.loadFromFile("path/to/font.ttf");

    ktx::cInputText inputText;
    inputText.setRectSize(sf::Vector2f(300, 50));
    inputText.setPositionRectangleShape(sf::Vector2f(100, 100));
    inputText.setFont(font);
    inputText.setInput(true);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        inputText.readKey(1.0f); // Обновление ввода

        window.clear();
        inputText.draw(window); // Отрисовка текста и фона
        window.display();
    }

    return 0;
}
```
## Документация API
### Методы
```void readKey(float l_fTime)```
Обрабатывает ввод с клавиатуры с учетом времени.

```void draw(sf::RenderWindow& window) const```
Отрисовывает прямоугольник и текст в указанном окне SFML.

```void setRectSize(sf::Vector2f l_RectSize)```
Устанавливает размер прямоугольника.

```void setColorText(sf::Color l_ColorText)```
Устанавливает цвет текста.

```void setColorRect(sf::Color l_ColorRect)```
Устанавливает цвет прямоугольника.

```void setFont(const sf::Font& l_Font)```
Устанавливает шрифт для текста.

```void setString(const std::string& l_String)```
Устанавливает начальную строку текста.

```void setPositionText(sf::Vector2f l_pos)```
Устанавливает позицию текста.

```void setPositionRectangleShape(sf::Vector2f l_pos)```
Устанавливает позицию прямоугольника.

```void setCharacterSize(unsigned int l_size)```
Устанавливает размер текста.

```void setInput(bool l_bool)```
Включает или отключает ввод текста.

```sf::Vector2f getRectSize() const```
Возвращает размер прямоугольника.

```sf::Color getColorText() const```
Возвращает текущий цвет текста.

```sf::Color getColorRect() const```
Возвращает текущий цвет прямоугольника.

```std::string getString() const```
Возвращает текущую строку текста.

```sf::Vector2f getPositionText() const```
Возвращает текущую позицию текста.

```sf::Vector2f getPositionRectangleShape() const```
Возвращает текущую позицию прямоугольника.

```unsigned int getCharacterSize() const```
Возвращает текущий размер текста.

```bool getInput() const```
Возвращает статус ввода текста (включен или выключен).