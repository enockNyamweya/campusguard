#include "FacilitiesUnit.h"
#include <iostream>
 
FacilitiesUnit::FacilitiesUnit(std::string id, CampusMediator* med) : ResponseUnit(id, med) {
}
 
void FacilitiesUnit::isolateHVAC(const std::string& building) {
    std::cout << "[FacilitiesUnit " << getId() << "] Isolating HVAC in " << building << std::endl;
    sendEvent("HVAC_ISOLATED", building);
}
 
void FacilitiesUnit::restoreHVAC(const std::string& building) {
    std::cout << "[FacilitiesUnit " << getId() << "] Restoring HVAC in " << building << std::endl;
    sendEvent("HVAC_RESTORED", building);
}
 
void FacilitiesUnit::receiveNotification(const std::string& senderId, const std::string& event, const std::string& data) {
    if (event == "FIRE_DETECTED") {
        isolateHVAC(data);
    }
}
