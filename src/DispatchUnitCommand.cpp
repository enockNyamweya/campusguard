#include "DispatchUnitCommand.h"
#include "Incident.h"
#include "ResponseUnit.h"
#include <iostream>

using namespace std;

DispatchUnitCommand::DispatchUnitCommand(Incident* inc, ResponseUnit* unit)
    : incident(inc), responder(unit), executed(false) {
	
}

bool DispatchUnitCommand::execute() {
	if(!incident || !responder) return false;

	cout << "[Command] Executing DispatchUnitCommand: Deploying unit "<<responder->getId()<<" to incident #"<<incident->getId()<<".\n";

	bool success = incident->dispatchResponders();

	executed = success;
	return success;

}

bool DispatchUnitCommand::undo() {
	if(!executed || !incident || !responder) return false;

	cout <<"[Command Undo] Recalling unit "<<responder->getId()<<" from incident #"<<incident->getId()<<".\n";

	executed = false;
	return true;
}

std::string DispatchUnitCommand::getName() {
	// TODO - implement DispatchUnitCommand::getName
	return "DispatchUnitCommand";
}
