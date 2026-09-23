#include "FacilitiesUnit.h"

FacilitiesUnit::FacilitiesUnit(std::string id, CampusMediator* med) : ResponseUnit(id, med) {
	// TODO - implement FacilitiesUnit::FacilitiesUnit
}

void FacilitiesUnit::isolateHVAC(const std::string& building) {
	// TODO - implement FacilitiesUnit::isolateHVAC
	throw "Not yet implemented";
}

void FacilitiesUnit::restoreHVAC(const std::string& building) {
	// TODO - implement FacilitiesUnit::restoreHVAC
	throw "Not yet implemented";
}

void FacilitiesUnit::receiveNotification(const std::string& senderId, const std::string& event, const std::string& data) {
	// TODO - implement FacilitiesUnit::receiveNotification
	throw "Not yet implemented";
}
