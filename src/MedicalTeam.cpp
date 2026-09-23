#include "MedicalTeam.h"

MedicalTeam::MedicalTeam(std::string id, CampusMediator* med) : ResponseUnit(id, med) {
	// TODO - implement MedicalTeam::MedicalTeam
}

void MedicalTeam::deployTriage(const std::string& loc) {
	// TODO - implement MedicalTeam::deployTriage
	throw "Not yet implemented";
}

void MedicalTeam::requestHospitalEscort() {
	// TODO - implement MedicalTeam::requestHospitalEscort
	throw "Not yet implemented";
}

void MedicalTeam::receiveNotification(const std::string& senderId, const std::string& event, const std::string& data) {
	// TODO - implement MedicalTeam::receiveNotification
	throw "Not yet implemented";
}
