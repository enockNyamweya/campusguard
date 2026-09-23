#include "ApplyStrategyCommand.h"
#include "ResponseStrategy.h"
#include "Incident.h"
#include "DoorControlInterface.h"
#include "CampusMediator.h"

ApplyStrategyCommand::ApplyStrategyCommand(ResponseStrategy* s, Incident* inc, DoorControlInterface* d, CampusMediator* m, const std::string& loc)
    : strategy(s), incident(inc), doors(d), mediator(m), location(loc) {
	// TODO - implement ApplyStrategyCommand::ApplyStrategyCommand
}

bool ApplyStrategyCommand::execute() {
	// TODO - implement ApplyStrategyCommand::execute
	throw "Not yet implemented";
}

bool ApplyStrategyCommand::undo() {
	// TODO - implement ApplyStrategyCommand::undo
	throw "Not yet implemented";
}

std::string ApplyStrategyCommand::getName() {
	// TODO - implement ApplyStrategyCommand::getName
	return "ApplyStrategyCommand";
}
