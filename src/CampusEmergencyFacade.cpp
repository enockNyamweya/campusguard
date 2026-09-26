#include "CampusEmergencyFacade.h"
#include "DoorControlInterface.h"
#include "CentralDispatchMediator.h"
#include "OperatorConsole.h"
#include "ResponseStrategy.h"
#include "Incident.h"
#include "PerimeterLockCommand.h"
#include "ApplyStrategyCommand.h"
#include <iostream>
 
using namespace std;
 
CampusEmergencyFacade::CampusEmergencyFacade(DoorControlInterface* ds, CentralDispatchMediator* med, OperatorConsole* cs, ResponseStrategy* es, ResponseStrategy* ls)
    : doorSystem(ds), mediator(med), console(cs), evacuationStrategy(es), lockdownStrategy(ls) {
}
 
CampusEmergencyFacade::~CampusEmergencyFacade() {
}
 
void CampusEmergencyFacade::handleChemicalSpillProtocol(Incident* incident, const std::string& zone) {
    cout << "[Facade] Chemical spill protocol initiated for zone '" << zone << "'.\n";
    console->executeCommand(new PerimeterLockCommand(doorSystem, zone));
    console->executeCommand(new ApplyStrategyCommand(lockdownStrategy, incident, doorSystem, mediator, zone));
}
 
void CampusEmergencyFacade::handleActiveIntruderProtocol(Incident* incident, const std::string& zone) {
    cout << "[Facade] Active intruder protocol initiated for zone '" << zone << "'.\n";
    console->executeCommand(new ApplyStrategyCommand(lockdownStrategy, incident, doorSystem, mediator, zone));
    console->executeCommand(new PerimeterLockCommand(doorSystem, zone));
}
 
void CampusEmergencyFacade::handleGeneralEvacuation(Incident* incident, const std::string& zone) {
    cout << "[Facade] General evacuation initiated for zone '" << zone << "'.\n";
    console->executeCommand(new ApplyStrategyCommand(evacuationStrategy, incident, doorSystem, mediator, zone));
}