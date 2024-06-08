#include "UI.h"
#include <iostream>

void UI::displayMenu() {
    std::cout << "File Storage System Menu:\n";
    std::cout << "1. Create File\n";
    std::cout << "2. Read File\n";
    std::cout << "3. Delete File\n";
    std::cout << "4. Update File Name\n";
    std::cout << "5. Update File Content\n";
    std::cout << "6. Grant Access\n";
    std::cout << "7. Exit\n";
}

void UI::handleUserInput() {
    int choice;
    std::string name, content, newName;

    while (true) {
        displayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter file name: ";
                std::cin >> name;
                std::cout << "Enter file content: ";
                std::cin.ignore();
                std::getline(std::cin, content);
                if (storageManager.createFile(name, content)) {
                    std::cout << "File created successfully.\n";
                } else {
                    std::cout << "File creation failed. File might already exist.\n";
                }
                break;
            case 2:
                std::cout << "Enter file name: ";
                std::cin >> name;
                if (auto file = storageManager.readFile(name)) {
                    std::cout << "File Content: " << file->getContent() << "\n";
                } else {
                    std::cout << "Failed to read file. Access denied or file not found.\n";
                }
                break;
            case 3:
                std::cout << "Enter file name: ";
                std::cin >> name;
                if (storageManager.deleteFile(name)) {
                    std::cout << "File deleted successfully.\n";
                } else {
                    std::cout << "Failed to delete file. Access denied or file not found.\n";
                }
                break;
            case 4:
                std::cout << "Enter old file name: ";
                std::cin >> name;
                std::cout << "Enter new file name: ";
                std::cin >> newName;
                if (storageManager.updateFileName(name, newName)) {
                    std::cout << "File name updated successfully.\n";
                } else {
                    std::cout << "Failed to update file name. Access denied or file not found.\n";
                }
                break;
            case 5:
                std::cout << "Enter file name: ";
                std::cin >> name;
                std::cout << "Enter new file content: ";
                std::cin.ignore();
                std::getline(std::cin, content);
                if (storageManager.updateFileContent(name, content)) {
                    std::cout << "File content updated successfully.\n";
                } else {
                    std::cout << "Failed to update file content. Access denied or file not found.\n";
                }
                break;
            case 6:
                std::cout << "Enter file name: ";
                std::cin >> name;
                bool hasAccess;
                std::cout << "Grant access (1 for yes, 0 for no): ";
                std::cin >> hasAccess;
                storageManager.grantAccess(name, hasAccess);
                std::cout << "Access updated successfully.\n";
                break;
            case 7:
                return;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    }
}
