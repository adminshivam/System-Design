#ifndef STORAGEMANAGER_H
#define STORAGEMANAGER_H

#include "Storage.h"
#include "AccessControl.h"

class StorageManager {
    private:
        Storage storage;
        AccessControl accessControl;

    public:
        bool createFile(const string &name, const string &content);
        std::shared_ptr<File> readFile(const std::string &name);
        bool deleteFile(const std::string &name);
        bool updateFileName(const std::string &oldName, const std::string &newName);
        bool updateFileContent(const std::string &name, const std::string &content);
        void grantAccess(const std::string &filename, bool hasAccess);
};

#endif