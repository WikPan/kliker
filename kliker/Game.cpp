#include "Game.h";
#include <iostream>

Game::Game() : window(sf::VideoMode(1024, 1024), "Clicker Game"), gold(), button(window, gold), upgrade(window, gold, button), autoClick(window, gold), saveSystem(gold) {
    if (!backgroundTexture.loadFromFile("background.png")) {
        std::cerr << "Failed to load background texture!" << std::endl;
    }
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setScale(float(window.getSize().x) / backgroundTexture.getSize().x, float(window.getSize().y) / backgroundTexture.getSize().y);

   
    progressFuture = std::async(std::launch::async, &Game::loadProgressInBackground, this);

    autoClick.startAutoClick();
}

void Game::run() {
    bool progressLoaded = false; 

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                saveSystem.saveProgress();
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (button.isClicked(sf::Vector2f(mousePos.x, mousePos.y))) {
                        button.handleClick();
                    }
                    if (upgrade.isClicked(sf::Vector2f(mousePos.x, mousePos.y))) {
                        upgrade.handleUpgrade();
                    }
                    if (autoClick.isClicked(sf::Vector2f(mousePos.x, mousePos.y))) {
                        autoClick.handleUpgrade();
                    }
                }
            }
        }
        window.clear();
        window.draw(backgroundSprite);
        gold.draw(window);
        button.draw();
        upgrade.draw();
        autoClick.draw();
        window.display();

        
        if (!progressLoaded && progressFuture.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            std::cout << "Game progress loaded!" << std::endl;
            progressLoaded = true; 
        }
    }
}

void Game::loadProgressInBackground() {
    saveSystem.loadProgress();
}
