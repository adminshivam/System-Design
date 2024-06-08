#ifndef UI_H
#define UI_H

#include "StorageManager.h"

class UI {
private:
    StorageManager storageManager;

public:
    void displayMenu();
    void handleUserInput();
};

#endif // UI_H
