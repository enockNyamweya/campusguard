#ifndef RESOLVEDSTATE_H
#define RESOLVEDSTATE_H

#include "IncidentState.h"

class ResolvedState : public IncidentState {
public:
    ResolvedState();
    virtual ~ResolvedState() {}

    bool handleDispatch(Incident* context) override;
    bool handleContain(Incident* context) override;
    bool handleResolve(Incident* context) override;
    std::string getStateName() override;
};

#endif
