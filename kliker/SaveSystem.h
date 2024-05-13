#pragma once

#include "Gold.h"

class SaveSystem {
private:
    Gold& gold;
    const std::string saveFileName = "save.txt";

public:
    SaveSystem(Gold& gd);
    void saveProgress();
    void loadProgress();
};
