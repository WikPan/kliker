#pragma once

#include <SFML/Graphics.hpp>

class Gold {
private:
    int amount;
    sf::Font font;
    sf::Text goldText;

public:
    Gold();
    void updateText();
    void draw(sf::RenderWindow& window);
    int getAmount() const;
    void add(int value);
    bool subtract(int value);
};
