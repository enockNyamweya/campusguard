#ifndef CENTRALDISPATCHMEDIATOR_H
#define CENTRALDISPATCHMEDIATOR_H

#include "CampusMediator.h"
#include <vector>
#include <string>

class DoorControlInterface;
class ResponseUnit;

class CentralDispatchMediator : public CampusMediator {
private:
    std::vector<ResponseUnit*> colleagues;
    DoorControlInterface* doors;

public:
    CentralDispatchMediator(DoorControlInterface* d);
    virtual ~CentralDispatchMediator();

    void registerColleague(ResponseUnit* unit) override;
    void notify(ResponseUnit* sender, const std::string& event, const std::string& data) override;
};

#endif
