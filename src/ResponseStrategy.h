#ifndef RESPONSESTRATEGY_H
#define RESPONSESTRATEGY_H

#include <string>

class DoorControlInterface;
class CampusMediator;

class ResponseStrategy {
public:
    virtual ~ResponseStrategy() {}

    virtual void executeTactic(const std::string& loc, DoorControlInterface* doors, CampusMediator* med) = 0;
    virtual std::string getStrategyName() = 0;
};

#endif
