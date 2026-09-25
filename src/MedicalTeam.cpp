#include "MedicalTeam.h"
#include <iostream>
 
MedicalTeam::MedicalTeam(std::string id, CampusMediator* med) : ResponseUnit(id, med) {
}
 
void MedicalTeam::deployTriage(const std::string& loc) {
    std::cout << "[MedicalTeam " << getId() << "] Deploying triage at " << loc << std::endl;
    sendEvent("TRIAGE_DEPLOYED", loc);
}
 
void MedicalTeam::requestHospitalEscort() {
    std::cout << "[MedicalTeam " << getId() << "] Requesting hospital escort" << std::endl;
    sendEvent("HOSPITAL_ESCORT_REQUESTED", getId());
}
 
void MedicalTeam::receiveNotification(const std::string& senderId, const std::string& event, const std::string& data) {
    if (event == "ZONE_CORDONED") {
        deployTriage(data);
    }
}
