#ifndef PERIMETERLOCKCOMMAND_H
#define PERIMETERLOCKCOMMAND_H

#include "Command.h"
#include <string>

class DoorControlInterface;

class PerimeterLockCommand : public Command {
private:
    DoorControlInterface* doorSystem;
    std::string targetZone;
    bool previousLockState;

public:
    PerimeterLockCommand(DoorControlInterface* doors, const std::string& zone);
    virtual ~PerimeterLockCommand() {}

    bool execute() override;
    bool undo() override;
    std::string getName() override;
};

#endif
