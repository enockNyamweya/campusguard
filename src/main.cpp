#include <iostream>
#include "CentralDispatchMediator.h"
#include "SecurityUnit.h"
#include "MedicalTeam.h"
#include "FacilitiesUnit.h"
#include "FireResponseUnit.h"
#include "LegacyTurnstileSystem.h"
#include "TurnstileAdapter.h"
#include "OperatorConsole.h"
#include "PerimeterLockCommand.h"
#include "ApplyStrategyCommand.h"
#include "DispatchUnitCommand.h"
#include "LockdownContainmentStrategy.h"
#include "FullEvacuationStrategy.h"
#include "CampusEmergencyFacade.h"
#include "Incident.h"

void printBanner(const std::string& title) {
    std::cout << "\n";
    std::cout << title << "\n";
    std::cout << "\n";
}

int main() {
    std::cout << "CampusGuard: Emergency Response Coordination System\n";

    LegacyTurnstileSystem legacyHardware;
    TurnstileAdapter doors(&legacyHardware);
    CentralDispatchMediator mediator(&doors);

    SecurityUnit security("SEC-1", &mediator);
    MedicalTeam medical("MED-1", &mediator);
    FacilitiesUnit facilities("FAC-1", &mediator);
    FireResponseUnit fire("FIRE-1", &mediator);

    OperatorConsole console;
    LockdownContainmentStrategy lockdown;
    FullEvacuationStrategy evacuation;
    CampusEmergencyFacade facade(&doors, &mediator, &console, &evacuation, &lockdown);

    printBanner("STORY 1: Chemical Spill, Chemistry Building (via Facade)");
    Incident spill(1001, "Chemical spill", "Chemistry Building");
    std::cout << "Status: " << spill.getStatus() << "\n\n";

    facade.handleChemicalSpillProtocol(&spill, "Chemistry Building");
    std::cout << "\nStatus after protocol: " << spill.getStatus() << "\n";

    std::cout << "\n--- Operator reviews the last action and decides to roll it back ---\n";
    console.undoLastCommand();

    std::cout << "\n--- Operator mistakenly tries to close the incident before it is contained ---\n";
    bool resolvedTooEarly = spill.resolveIncident();
    std::cout << "resolveIncident() while " << spill.getStatus()
              << " succeeded? " << (resolvedTooEarly ? "yes" : "no") << "\n";

    std::cout << "\n--- Proper sequence: contain, then resolve ---\n";
    spill.containThreat();
    spill.resolveIncident();
    std::cout << "Final status: " << spill.getStatus() << "\n";

    printBanner("STORY 2: Fire, Engineering Building (direct subsystem use)");
    Incident fireIncident(1002, "Structure fire", "Engineering Building");
    std::cout << "Status: " << fireIncident.getStatus() << "\n\n";

    std::cout << "--- FireResponseUnit detects and reports independently, no Facade involved ---\n";
    fire.deploySuppression("Engineering Building");

    std::cout << "\n--- Operator explicitly dispatches Medical via Command, tied to the incident ---\n";
    console.executeCommand(new DispatchUnitCommand(&fireIncident, &medical));
    std::cout << "Status: " << fireIncident.getStatus() << "\n";

    std::cout << "\n--- Operator applies the evacuation strategy directly, bypassing the Facade ---\n";
    console.executeCommand(new ApplyStrategyCommand(&evacuation, &fireIncident, &doors, &mediator, "Engineering Building"));

    std::cout << "\n--- Incident is walked to resolution ---\n";
    fireIncident.containThreat();
    fireIncident.resolveIncident();
    std::cout << "Final status: " << fireIncident.getStatus() << "\n";

    std::cout << "\nCampusGuard shutdown complete.\n";
    return 0;
}