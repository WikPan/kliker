#pragma once

#include "SFML/Graphics.hpp"
#include "Gold.h"
#include "Button.h";
#include "Upgrade.h"
#include "AutoClick.h"
#include "SaveSystem.h"
#include <future>

class Game {
public:
    Game();

    void run();

private:
    sf::RenderWindow window;
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    Gold gold;
    Button button;
    Upgrade upgrade;
    AutoClick autoClick;
    SaveSystem saveSystem;
    std::future<void> progressFuture;

    void loadProgressInBackground();
};