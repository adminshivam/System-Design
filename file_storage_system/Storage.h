#ifndef STORAGE_H
#define STORAGE_H

#include "File.h"
#include <bits/stdc++.h>
using namespace std;

class Storage {
    private:
        unordered_map<string, shared_ptr<File>> files;
    
    public:
        bool createFile(const string &name, const string &content);
        shared_ptr<File> readFile(const string &name) const;
        bool deleteFile(const string &name);
        bool updateFileName(const string &oldName, const string &newName);
        bool updateFileContent(const string &name, const string &content);
};

#endif