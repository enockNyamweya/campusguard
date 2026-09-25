#include "LockdownContainmentStrategy.h"
#include "DoorControlInterface.h"
#include "CampusMediator.h"
#include <iostream>

using namespace std;

LockdownContainmentStrategy::LockdownContainmentStrategy() {
	
}

void LockdownContainmentStrategy::executeTactic(const std::string& loc, DoorControlInterface* doors, CampusMediator* med) {
	cout << "[Strategy: Lockdown Containment] Executing lockdown protocol for zone '"<<loc<<"'.\n";

	if(doors){
		doors->lockZone(loc);

	}

	if(med){
		med->notify(nullptr, "LOCKDOWN_TRIGGERED", loc);
	}
}

std::string LockdownContainmentStrategy::getStrategyName() {
	return "Lockdown Containment Strategy";
}
