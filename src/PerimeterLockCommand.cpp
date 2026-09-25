#include "PerimeterLockCommand.h"
#include "DoorControlInterface.h"
#include <iostream>

using namespace std;

PerimeterLockCommand::PerimeterLockCommand(DoorControlInterface* doors, const std::string& zone)
    : doorSystem(doors), targetZone(zone), previousLockState(false) {
	// done
}

bool PerimeterLockCommand::execute() {
	if(!doorSystem) return false;

	previousLockState = doorSystem->isZoneLocked(targetZone);

	cout << "[Command] Executing PerimeterLockCommand: Locking zone '"<<targetZone<<"'.\n";

	return doorSystem->lockZone(targetZone);

}

bool PerimeterLockCommand::undo() {
	if(!doorSystem) return false;

	cout <<"[CommandUndo] Rolling back PerimeterLockCommand for zone '"<<targetZone<<"'. Restoring previous state: "<<(previousLockState ? "LOCKED" : "UNLOCKED") <<".\n";

	if(previousLockState){
		return doorSystem->lockZone(targetZone);
	} else {
		return doorSystem->unlockZone(targetZone);
	}
}

std::string PerimeterLockCommand::getName() {
	
	return "PerimeterLockCommand";
}
