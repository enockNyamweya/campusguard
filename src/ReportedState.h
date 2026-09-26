#ifndef REPORTEDSTATE_H
#define REPORTEDSTATE_H

#include "IncidentState.h"

class ReportedState : public IncidentState {
public:
    ReportedState();
    virtual ~ReportedState() {}

    bool handleDispatch(Incident* context) override;
    bool handleContain(Incident* context) override;
    bool handleResolve(Incident* context) override;
    std::string getStateName() override;
};

#endif
