#include "SecurityUnit.h"
#include <iostream>
 
SecurityUnit::SecurityUnit(std::string id, CampusMediator* med) : ResponseUnit(id, med) {
}
 
void SecurityUnit::cordonOffZone(const std::string& zone) {
    std::cout << "[SecurityUnit " << getId() << "] Cordoning off zone " << zone << std::endl;
    sendEvent("ZONE_CORDONED", zone);
}
 
void SecurityUnit::clearEscortRoute(const std::string& zone) {
    std::cout << "[SecurityUnit " << getId() << "] Clearing escort route through " << zone << std::endl;
    sendEvent("ROUTE_CLEARED", zone);
}
 
void SecurityUnit::receiveNotification(const std::string& senderId, const std::string& event, const std::string& data) {
    if (event == "FIRE_DETECTED") {
        cordonOffZone(data);
    } else if (event == "HOSPITAL_ESCORT_REQUESTED") {
        clearEscortRoute(data);
    }
}