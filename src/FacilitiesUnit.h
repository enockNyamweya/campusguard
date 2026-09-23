#ifndef FACILITIESUNIT_H
#define FACILITIESUNIT_H

#include "ResponseUnit.h"
#include <string>

class FacilitiesUnit : public ResponseUnit {
public:
    FacilitiesUnit(std::string id, CampusMediator* med);
    virtual ~FacilitiesUnit() {}

    void isolateHVAC(const std::string& building);
    void restoreHVAC(const std::string& building);
    void receiveNotification(const std::string& senderId, const std::string& event, const std::string& data) override;
};

#endif
