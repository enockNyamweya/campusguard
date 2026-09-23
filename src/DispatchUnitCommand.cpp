#include "DispatchUnitCommand.h"
#include "Incident.h"
#include "ResponseUnit.h"

DispatchUnitCommand::DispatchUnitCommand(Incident* inc, ResponseUnit* unit)
    : incident(inc), responder(unit), executed(false) {
	// TODO - implement DispatchUnitCommand::DispatchUnitCommand
}

bool DispatchUnitCommand::execute() {
	// TODO - implement DispatchUnitCommand::execute
	throw "Not yet implemented";
}

bool DispatchUnitCommand::undo() {
	// TODO - implement DispatchUnitCommand::undo
	throw "Not yet implemented";
}

std::string DispatchUnitCommand::getName() {
	// TODO - implement DispatchUnitCommand::getName
	return "DispatchUnitCommand";
}
