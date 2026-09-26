#ifndef SECURITYUNIT_H
#define SECURITYUNIT_H

#include "ResponseUnit.h"
#include <string>

class SecurityUnit : public ResponseUnit {
public:
    SecurityUnit(std::string id, CampusMediator* med);
    virtual ~SecurityUnit() {}

    void cordonOffZone(const std::string& zone);
    void clearEscortRoute(const std::string& zone);
    void receiveNotification(const std::string& senderId, const std::string& event, const std::string& data) override;
};

#endif
