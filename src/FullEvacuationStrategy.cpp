#include "FullEvacuationStrategy.h"
#include "DoorControlInterface.h"
#include "CampusMediator.h"
#include <iostream>

using namespace std;

// family of algorithms encapsulated and interchangeable; executeTactic is where interchanging comes in

FullEvacuationStrategy::FullEvacuationStrategy() {
	
}

void FullEvacuationStrategy::executeTactic(const std::string& loc, DoorControlInterface* doors, CampusMediator* med) {
	cout << "[Stategy: Full Evacuation] Executing evacuation for zone '"<<loc<<"'.\n";

	if(doors){
		doors->unlockZone(loc);
	}
	if(med){
		med->notify(nullptr, "EVACUATION_ORDERED", loc);
	}
}

std::string FullEvacuationStrategy::getStrategyName() {
	return "Full Evacuation Strategy";
}
