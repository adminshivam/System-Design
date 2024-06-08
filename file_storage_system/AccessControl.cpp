#include "AccessControl.h"

void AccessControl::grantAccess(const string &fileName, bool hasAccess) {
    accessRights[fileName] = hasAccess;
};

bool AccessControl::hasAccess(const string &fileName) const {
    if(accessRights.count(fileName) && accessRights[fileName]) {
        return true;
    }
    return false;
};