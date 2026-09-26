#ifndef INCIDENT_H
#define INCIDENT_H

#include <string>
#include <memory>
 
class IncidentState;
 
class Incident {
private:
    int incidentId;
    std::string description;
    std::string location;
    std::unique_ptr<IncidentState> currentState;
    std::unique_ptr<IncidentState> pendingState;
    bool handlingAction;
 
    bool perform(bool (IncidentState::*action)(Incident*), const std::string& name);
 
public:
    Incident(int id, std::string desc, std::string loc);
    virtual ~Incident();
 
    void changeState(IncidentState* newState);
    bool dispatchResponders();
    bool containThreat();
    bool resolveIncident();
    bool cancelDispatch();
    std::string getStatus();
 
    int getId() const;
    std::string getLocation() const;
    std::string getDescription() const;
};

#endif
