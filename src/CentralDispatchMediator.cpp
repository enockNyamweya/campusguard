#include "CentralDispatchMediator.h"
#include "ResponseUnit.h"
#include "DoorControlInterface.h"

CentralDispatchMediator::CentralDispatchMediator(DoorControlInterface* d) : doors(d) {
	// TODO - implement CentralDispatchMediator::CentralDispatchMediator
}

CentralDispatchMediator::~CentralDispatchMediator() {
	// TODO - implement CentralDispatchMediator::~CentralDispatchMediator
}

void CentralDispatchMediator::registerColleague(ResponseUnit* unit) {
	// TODO - implement CentralDispatchMediator::registerColleague
	throw "Not yet implemented";
}

void CentralDispatchMediator::notify(ResponseUnit* sender, const std::string& event, const std::string& data) {
	// TODO - implement CentralDispatchMediator::notify
	throw "Not yet implemented";
}
