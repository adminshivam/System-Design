#include "StorageManager.h"

bool StorageManager::createFile(const std::string &name, const std::string &content) {
    return storage.createFile(name, content);
}

std::shared_ptr<File> StorageManager::readFile(const std::string &name) {
    if (accessControl.hasAccess(name)) {
        return storage.readFile(name);
    }
    return nullptr; // Access denied
}

bool StorageManager::deleteFile(const std::string &name) {
    if (accessControl.hasAccess(name)) {
        return storage.deleteFile(name);
    }
    return false; // Access denied
}

bool StorageManager::updateFileName(const std::string &oldName, const std::string &newName) {
    if (accessControl.hasAccess(oldName) && accessControl.hasAccess(newName)) {
        return storage.updateFileName(oldName, newName);
    }
    return false; // Access denied
}

bool StorageManager::updateFileContent(const std::string &name, const std::string &content) {
    if (accessControl.hasAccess(name)) {
        return storage.updateFileContent(name, content);
    }
    return false; // Access denied
}

void StorageManager::grantAccess(const std::string &filename, bool hasAccess) {
    accessControl.grantAccess(filename, hasAccess);
}