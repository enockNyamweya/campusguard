#ifndef CONTAINEDSTATE_H
#define CONTAINEDSTATE_H

#include "IncidentState.h"

class ContainedState : public IncidentState {
public:
    ContainedState();
    virtual ~ContainedState() {}

    bool handleDispatch(Incident* context) override;
    bool handleContain(Incident* context) override;
    bool handleResolve(Incident* context) override;
    std::string getStateName() override;
};

#endif
