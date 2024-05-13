#include "AutoClick.h"
#include <iostream>
#include <chrono>

AutoClick::AutoClick(sf::RenderWindow& win, Gold& gd) : window(win), gold(gd), level(1), cost(100), running(true), maxLevelReached(false) {
    autoClickButton.setSize(sf::Vector2f(300, 150));
    autoClickButton.setFillColor(sf::Color::Yellow);
    autoClickButton.setPosition(window.getSize().x - autoClickButton.getSize().x - 10, window.getSize().y - autoClickButton.getSize().y - 10);

    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Failed to load font!" << std::endl;
    }
    costText.setFont(font);
    costText.setCharacterSize(24);
    costText.setFillColor(sf::Color::Black);
    costText.setPosition(autoClickButton.getPosition().x + 10, autoClickButton.getPosition().y + 100);
    updateText();

    nameText.setFont(font);
    nameText.setCharacterSize(24);
    nameText.setFillColor(sf::Color::Black);
    nameText.setPosition(autoClickButton.getPosition().x + 10, autoClickButton.getPosition().y + 10);
    nameText.setString("Auto Click");
}

AutoClick::~AutoClick() {
    running = false;
    if (autoClickThread.joinable()) {
        autoClickThread.join();
    }
}

void AutoClick::startAutoClick() {
    autoClickThread = std::thread(&AutoClick::autoClickLoop, this);
}

void AutoClick::stopAutoClick() {
    running = false;
}

void AutoClick::autoClickLoop() {
    while (running && level <= 10) {
        std::this_thread::sleep_for(std::chrono::seconds(11 - level));

        mtx.lock();
        gold.add(1 + level);
        mtx.unlock();
    }
}

void AutoClick::draw() {
    window.draw(autoClickButton);
    window.draw(costText);
    window.draw(nameText);
}

bool AutoClick::isClicked(const sf::Vector2f& mousePos) const {
    return autoClickButton.getGlobalBounds().contains(mousePos);
}

void AutoClick::updateText() {
    if (maxLevelReached) {
        costText.setString("Max");
    }
    else {
        costText.setString("Cost: " + std::to_string(cost));
    }
}

void AutoClick::handleUpgrade() {
    if (!maxLevelReached) {
        if (gold.subtract(cost)) {
            level++;
            if (level >= 10) {
                maxLevelReached = true;
            }
            cost *= 1.5;
            updateText();
        }
    }
}
