#include "Gold.h"
#include <iostream>
Gold::Gold() : amount(0) {
    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Failed to load font!" << std::endl;
    }
    goldText.setFont(font);
    goldText.setCharacterSize(24);
    goldText.setFillColor(sf::Color::Yellow);
    updateText();
}

void Gold::updateText() {
    goldText.setString("Gold: " + std::to_string(amount));
}

void Gold::draw(sf::RenderWindow& window) {
    window.draw(goldText);
}

int Gold::getAmount() const {
    return amount;
}

void Gold::add(int value) {
    amount += value;
    updateText();
}

bool Gold::subtract(int value) {
    if (amount >= value) {
        amount -= value;
        updateText();
        return true;
    }
    return false;
}
