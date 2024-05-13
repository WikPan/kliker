#include "Upgrade.h"
#include <iostream>

Upgrade::Upgrade(sf::RenderWindow& win, Gold& gd, Button& btn) : window(win), gold(gd), cost(10), increaseAmount(1), button(btn) {
    upgradeButton.setSize(sf::Vector2f(300, 150));
    upgradeButton.setFillColor(sf::Color::Yellow);
    upgradeButton.setPosition(10, window.getSize().y - upgradeButton.getSize().y - 10);

    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Failed to load font!" << std::endl;
    }
    costText.setFont(font);
    costText.setCharacterSize(24);
    costText.setFillColor(sf::Color::Black);
    costText.setPosition(upgradeButton.getPosition().x + 10, upgradeButton.getPosition().y + 100);
    updateText();

    nameText.setFont(font);
    nameText.setCharacterSize(24);
    nameText.setFillColor(sf::Color::Black);
    nameText.setPosition(upgradeButton.getPosition().x + 10, upgradeButton.getPosition().y + 10);
    nameText.setString("Upgrade");
}

void Upgrade::draw() {
    window.draw(upgradeButton);
    window.draw(costText);
    window.draw(nameText);
}

void Upgrade::updateText() {
    costText.setString("Cost: " + std::to_string(cost));
}

void Upgrade::handleUpgrade() {
    if (gold.subtract(cost)) {
        button.setClickWorth(button.getClickWorth() + increaseAmount);
        increaseAmount++;
        cost *= 2;
        updateText();
    }
}

bool Upgrade::isClicked(const sf::Vector2f& mousePos) const {
    return upgradeButton.getGlobalBounds().contains(mousePos);
}
