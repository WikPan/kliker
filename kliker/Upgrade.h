#pragma once

#include <SFML/Graphics.hpp>
#include "Gold.h"
#include "Button.h";

class Upgrade {
private:
    sf::RenderWindow& window;
    Gold& gold;
    int cost;
    int increaseAmount;
    sf::RectangleShape upgradeButton;
    sf::Font font;
    sf::Text costText;
    sf::Text nameText;
    Button& button;

public:
    Upgrade(sf::RenderWindow& win, Gold& gd, Button& btn);
    void draw();
    void updateText();
    void handleUpgrade();
    bool isClicked(const sf::Vector2f& mousePos) const;
};
