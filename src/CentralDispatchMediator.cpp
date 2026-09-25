#include "CentralDispatchMediator.h"
#include "ResponseUnit.h"
#include "DoorControlInterface.h"
#include <algorithm>
#include <iostream>

CentralDispatchMediator::CentralDispatchMediator(DoorControlInterface* d) : doors(d) {}

CentralDispatchMediator::~CentralDispatchMediator() {}

void CentralDispatchMediator::registerColleague(ResponseUnit* unit) {
	if (!unit) {
        return;
    }
    bool alreadyRegistered = std::find(colleagues.begin(), colleagues.end(), unit) != colleagues.end();
    if (!alreadyRegistered) {
        colleagues.push_back(unit);
    }
}

void CentralDispatchMediator::notify(ResponseUnit* sender, const std::string& event, const std::string& data) {
	std::string senderId = sender ? sender->getId() : "SYSTEM";
 
    std::cout << "[CentralDispatchMediator] " << senderId
              << " -> event: " << event << " (" << data << ")" << std::endl;
 
    if (doors && (event == "ZONE_CORDONED" || event == "LOCKDOWN_TRIGGERED")) {
        doors->lockZone(data);
    } else if (doors && event == "EVACUATION_ORDERED") {
        doors->unlockZone(data);
    }
 
    for (std::vector<ResponseUnit*>::iterator it = colleagues.begin(); it != colleagues.end(); ++it) {
        ResponseUnit* colleague = *it;
        if (colleague != sender) {
            colleague->receiveNotification(senderId, event, data);
        }
    }
}
