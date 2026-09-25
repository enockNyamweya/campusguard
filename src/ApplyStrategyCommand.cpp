#include "ApplyStrategyCommand.h"
#include "ResponseStrategy.h"
#include "Incident.h"
#include "DoorControlInterface.h"
#include "CampusMediator.h"
#include <iostream>

using namespace std;

ApplyStrategyCommand::ApplyStrategyCommand(ResponseStrategy* s, Incident* inc, DoorControlInterface* d, CampusMediator* m, const std::string& loc)
    : strategy(s), incident(inc), doors(d), mediator(m), location(loc) {
	
}

bool ApplyStrategyCommand::execute() {
	cout <<"[Command] Executing ApplyStrategyCommand for zone '"<<location<<".\n";

	if (incident){
		incident->dispatchResponders();
	}

	if (strategy){
		strategy->executeTactic(location, doors, mediator);
	}

	return true;
}

bool ApplyStrategyCommand::undo() {
	cout <<"[CommandUndo] Rolling back ApplyStrategyCommand for zone '"<<location<<"'. Restoring default access.\n";

	if(doors){
		doors->unlockZone(location);
	}
	return true;
}

std::string ApplyStrategyCommand::getName() {
	
	return "ApplyStrategyCommand";
}
