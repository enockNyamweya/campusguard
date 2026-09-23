#ifndef DISPATCHEDSTATE_H
#define DISPATCHEDSTATE_H

#include "IncidentState.h"

class DispatchedState : public IncidentState {
public:
    DispatchedState();
    virtual ~DispatchedState() {}

    bool handleDispatch(Incident* context) override;
    bool handleContain(Incident* context) override;
    bool handleResolve(Incident* context) override;
    std::string getStateName() override;
};

#endif
