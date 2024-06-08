#ifndef FILE_H
#define FILE_H

#include <bits/stdc++.h>
using namespace std;
class File {
    private:
        string name;
        string content;
    public:
        File(const string &name, const string &content);
        
        string getName() const;
        void setName(const string &name);

        string getContent() const;
        void setContent(const string &name);
};

#endif