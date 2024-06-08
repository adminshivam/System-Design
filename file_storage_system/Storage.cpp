#include "Storage.h"

bool Storage::createFile(const string &name, const string &content) {
    if(files.count(name)) {
        return false;
    }
    files[name] = make_shared<File>(name, content);
    return true;
}

std::shared_ptr<File> Storage::readFile(const std::string &name) const {
    auto it = files.find(name);
    if (it != files.end()) {
        return it->second;
    }
    return nullptr; // File not found
}

bool Storage::deleteFile(const std::string &name) {
    return files.erase(name) > 0;
}

bool Storage::updateFileName(const std::string &oldName, const std::string &newName) {
    auto it = files.find(oldName);
    if (it == files.end() || files.find(newName) != files.end()) {
        return false; // Old file not found or new file name already exists
    }
    auto file = it->second;
    files.erase(it);
    file->setName(newName);
    files[newName] = file;
    return true;
}

bool Storage::updateFileContent(const std::string &name, const std::string &content) {
    auto it = files.find(name);
    if (it != files.end()) {
        it->second->setContent(content);
        return true;
    }
    return false;
}