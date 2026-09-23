#ifndef DISPATCHUNITCOMMAND_H
#define DISPATCHUNITCOMMAND_H

#include "Command.h"
#include <string>

class Incident;
class ResponseUnit;

class DispatchUnitCommand : public Command {
private:
    Incident* incident;
    ResponseUnit* responder;
    bool executed;

public:
    DispatchUnitCommand(Incident* inc, ResponseUnit* unit);
    virtual ~DispatchUnitCommand() {}

    bool execute() override;
    bool undo() override;
    std::string getName() override;
};

#endif
