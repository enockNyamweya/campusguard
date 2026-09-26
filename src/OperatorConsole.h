#ifndef OPERATORCONSOLE_H
#define OPERATORCONSOLE_H

#include "Command.h"
#include <vector>

class OperatorConsole {
private:
    std::vector<Command*> history;

public:
    OperatorConsole();
    virtual ~OperatorConsole();

    bool executeCommand(Command* cmd);
    bool undoLastCommand();
};

#endif
