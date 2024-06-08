#include "File.h"
using namespace std;
File::File(const string &name, const string &content) : name(name), content(content) {}

string File::getName() const {
    return this->name;
}

void File::setName(const string &name) {
    this->name = name;
}

string File::getContent() const {
    return this->content;
}

void File::setContent(const std::string &content) {
    this->content = content;
}