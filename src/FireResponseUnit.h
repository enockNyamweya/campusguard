#ifndef FIRERESPONSEUNIT_H
#define FIRERESPONSEUNIT_H

#include "ResponseUnit.h"
#include <string>

class FireResponseUnit : public ResponseUnit {
public:
    FireResponseUnit(std::string id, CampusMediator* med);
    virtual ~FireResponseUnit() {}

    void deploySuppression(const std::string& zone);
    void receiveNotification(const std::string& senderId, const std::string& event, const std::string& data) override;
};

#endif
