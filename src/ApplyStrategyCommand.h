#ifndef APPLYSTRATEGYCOMMAND_H
#define APPLYSTRATEGYCOMMAND_H

#include "Command.h"
#include <string>

class ResponseStrategy;
class Incident;
class DoorControlInterface;
class CampusMediator;

class ApplyStrategyCommand : public Command {
private:
    ResponseStrategy* strategy;
    Incident* incident;
    DoorControlInterface* doors;
    CampusMediator* mediator;
    std::string location;

public:
    ApplyStrategyCommand(ResponseStrategy* s, Incident* inc, DoorControlInterface* d, CampusMediator* m, const std::string& loc);
    virtual ~ApplyStrategyCommand() {}

    bool execute() override;
    bool undo() override;
    std::string getName() override;
};

#endif
