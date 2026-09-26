#include "FireResponseUnit.h"
#include <iostream>
 
FireResponseUnit::FireResponseUnit(std::string id, CampusMediator* med) : ResponseUnit(id, med) {
}
 
void FireResponseUnit::deploySuppression(const std::string& zone) {
    std::cout << "[FireResponseUnit " << getId() << "] Deploying suppression in " << zone << std::endl;
    sendEvent("FIRE_DETECTED", zone);
}
 
void FireResponseUnit::receiveNotification(const std::string& senderId, const std::string& event, const std::string& data) {
    if (event == "ZONE_CORDONED") {
        std::cout << "[FireResponseUnit " << getId() << "] Standing by, zone " << data << " cordoned by " << senderId << std::endl;
    }
}
