#include "CampusEmergencyFacade.h"
#include "DoorControlInterface.h"
#include "CentralDispatchMediator.h"
#include "OperatorConsole.h"
#include "ResponseStrategy.h"
#include "Incident.h"

CampusEmergencyFacade::CampusEmergencyFacade(DoorControlInterface* ds, CentralDispatchMediator* med, OperatorConsole* cs, ResponseStrategy* es, ResponseStrategy* ls)
    : doorSystem(ds), mediator(med), console(cs), evacuationStrategy(es), lockdownStrategy(ls) {
	// TODO - implement CampusEmergencyFacade::CampusEmergencyFacade
}

CampusEmergencyFacade::~CampusEmergencyFacade() {
	// TODO - implement CampusEmergencyFacade::~CampusEmergencyFacade
}

void CampusEmergencyFacade::handleChemicalSpillProtocol(Incident* incident, const std::string& zone) {
	// TODO - implement CampusEmergencyFacade::handleChemicalSpillProtocol
	throw "Not yet implemented";
}

void CampusEmergencyFacade::handleActiveIntruderProtocol(Incident* incident, const std::string& zone) {
	// TODO - implement CampusEmergencyFacade::handleActiveIntruderProtocol
	throw "Not yet implemented";
}

void CampusEmergencyFacade::handleGeneralEvacuation(Incident* incident, const std::string& zone) {
	// TODO - implement CampusEmergencyFacade::handleGeneralEvacuation
	throw "Not yet implemented";
}
