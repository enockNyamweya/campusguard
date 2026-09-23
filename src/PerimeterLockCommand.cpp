#include "PerimeterLockCommand.h"
#include "DoorControlInterface.h"

PerimeterLockCommand::PerimeterLockCommand(DoorControlInterface* doors, const std::string& zone)
    : doorSystem(doors), targetZone(zone), previousLockState(false) {
	// TODO - implement PerimeterLockCommand::PerimeterLockCommand
}

bool PerimeterLockCommand::execute() {
	// TODO - implement PerimeterLockCommand::execute
	throw "Not yet implemented";
}

bool PerimeterLockCommand::undo() {
	// TODO - implement PerimeterLockCommand::undo
	throw "Not yet implemented";
}

std::string PerimeterLockCommand::getName() {
	// TODO - implement PerimeterLockCommand::getName
	return "PerimeterLockCommand";
}
