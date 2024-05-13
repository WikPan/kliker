#include "Button.h"
#include <iostream>

Button::Button(sf::RenderWindow& win, Gold& gd) : window(win), gold(gd), clickWorth(1) {
    if (!buttonTexture.loadFromFile("button.png")) {
        std::cerr << "Failed to load button texture!" << std::endl;
    }
    buttonSprite.setTexture(buttonTexture);
    buttonSprite.setPosition(window.getSize().x / 2 - buttonTexture.getSize().x / 2, window.getSize().y / 1.6 - buttonTexture.getSize().y / 2);
}

void Button::draw() {
    window.draw(buttonSprite);
}

void Button::handleClick() {
    gold.add(clickWorth);
}

sf::FloatRect Button::getGlobalBounds() const {
    return buttonSprite.getGlobalBounds();
}

bool Button::isClicked(const sf::Vector2f& mousePos) const {
    return buttonSprite.getGlobalBounds().contains(mousePos);
}

int Button::getClickWorth() const {
    return clickWorth;
}

void Button::setClickWorth(int value) {
    clickWorth = value;
}
