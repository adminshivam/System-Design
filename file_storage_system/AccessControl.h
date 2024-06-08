#ifndef ACCESSCONTROL_H
#define ACCESSCONTROL_H

#include <bits/stdc++.h>

using namespace std;

class AccessControl {
    private:
        unordered_map<string, bool> accessRights;
    public:
        void grantAccess(const string &fileName, bool hasAccess);
        bool hasAccess(const string &fileName) const;
};

#endif