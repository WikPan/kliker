#pragma once

#include <SFML/Graphics.hpp>
#include "Gold.h"

#include <thread>
#include <mutex>

class AutoClick {
private:
    sf::RenderWindow& window;
    Gold& gold;
    int level;
    int cost;
    std::thread autoClickThread;
    bool running;
    std::mutex mtx;
    sf::RectangleShape autoClickButton;
    sf::Font font;
    sf::Text costText;
    sf::Text nameText;
    bool maxLevelReached;

public:
    AutoClick(sf::RenderWindow& win, Gold& gd);
    ~AutoClick();
    void startAutoClick();
    void stopAutoClick();
    void autoClickLoop();
    void draw();
    bool isClicked(const sf::Vector2f& mousePos) const;
    void updateText();
    void handleUpgrade();
};
