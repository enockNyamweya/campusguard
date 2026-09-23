#ifndef FULLEVACUATIONSTRATEGY_H
#define FULLEVACUATIONSTRATEGY_H

#include "ResponseStrategy.h"
#include <string>

class DoorControlInterface;
class CampusMediator;

class FullEvacuationStrategy : public ResponseStrategy {
public:
    FullEvacuationStrategy();
    virtual ~FullEvacuationStrategy() {}

    void executeTactic(const std::string& loc, DoorControlInterface* doors, CampusMediator* med) override;
    std::string getStrategyName() override;
};

#endif
