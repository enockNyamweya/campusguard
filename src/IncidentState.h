#ifndef INCIDENTSTATE_H
#define INCIDENTSTATE_H

#include <string>

class Incident;

class IncidentState {
public:
    virtual ~IncidentState() {}

    virtual bool handleDispatch(Incident* context) = 0;
    virtual bool handleContain(Incident* context) = 0;
    virtual bool handleResolve(Incident* context) = 0;
    virtual std::string getStateName() = 0;
};

#endif
