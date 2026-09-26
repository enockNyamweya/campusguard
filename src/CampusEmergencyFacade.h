#ifndef CAMPUSEMERGENCYFACADE_H
#define CAMPUSEMERGENCYFACADE_H

#include <string>

class DoorControlInterface;
class CentralDispatchMediator;
class OperatorConsole;
class ResponseStrategy;
class Incident;

class CampusEmergencyFacade {
private:
    DoorControlInterface* doorSystem;
    CentralDispatchMediator* mediator;
    OperatorConsole* console;
    ResponseStrategy* evacuationStrategy;
    ResponseStrategy* lockdownStrategy;

public:
    CampusEmergencyFacade(DoorControlInterface* ds, CentralDispatchMediator* med, OperatorConsole* cs, ResponseStrategy* es, ResponseStrategy* ls);
    virtual ~CampusEmergencyFacade();

    void handleChemicalSpillProtocol(Incident* incident, const std::string& zone);
    void handleActiveIntruderProtocol(Incident* incident, const std::string& zone);
    void handleGeneralEvacuation(Incident* incident, const std::string& zone);
};

#endif
