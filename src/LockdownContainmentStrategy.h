#ifndef LOCKDOWNCONTAINMENTSTRATEGY_H
#define LOCKDOWNCONTAINMENTSTRATEGY_H

#include "ResponseStrategy.h"
#include <string>

class DoorControlInterface;
class CampusMediator;

class LockdownContainmentStrategy : public ResponseStrategy {
public:
    LockdownContainmentStrategy();
    virtual ~LockdownContainmentStrategy() {}

    void executeTactic(const std::string& loc, DoorControlInterface* doors, CampusMediator* med) override;
    std::string getStrategyName() override;
};

#endif
