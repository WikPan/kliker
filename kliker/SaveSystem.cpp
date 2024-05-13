#include "SaveSystem.h"
#include <iostream>
#include <fstream>
#include <filesystem>
#include <regex>

namespace fs = std::filesystem;

SaveSystem::SaveSystem(Gold& gd) : gold(gd) {}

void SaveSystem::saveProgress() {
    fs::path saveFilePath = fs::current_path() / saveFileName;
    std::ofstream file(saveFilePath, std::ios::trunc); 
    if (file.is_open()) {
        file << gold.getAmount();
        file.close();
    }
    else {
        std::cerr << "Failed to open save file for writing!" << std::endl;
    }
}

void SaveSystem::loadProgress() {
    fs::path saveFilePath = fs::current_path() / saveFileName;
    if (fs::exists(saveFilePath)) {
        std::ifstream file(saveFilePath);
        if (file.is_open()) {
            std::string line;
            if (std::getline(file, line)) {
                std::regex integerRegex("\\d+");
                if (std::regex_match(line, integerRegex)) {
                    int amount = std::stoi(line);
                    gold.add(amount);
                }
                else {
                    std::cerr << "Invalid save file format. Starting new game." << std::endl;
                }
            }
            file.close();
        }
        else {
            std::cerr << "Failed to open save file for reading!" << std::endl;
        }
    }
    else {
        std::cerr << "Save file not found. Starting new game." << std::endl;
    }
}
