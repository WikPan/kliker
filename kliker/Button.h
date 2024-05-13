#pragma once

#include <SFML/Graphics.hpp>
#include "Gold.h"

class Button {
private:
    sf::RenderWindow& window;
    Gold& gold;
    int clickWorth;
    sf::Texture buttonTexture;
    sf::Sprite buttonSprite;

public:
    Button(sf::RenderWindow& win, Gold& gd);
    void draw();
    void handleClick();
    sf::FloatRect getGlobalBounds() const;
    bool isClicked(const sf::Vector2f& mousePos) const;
    int getClickWorth() const;
    void setClickWorth(int value);
};
