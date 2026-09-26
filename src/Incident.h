#ifndef INCIDENT_H
#define INCIDENT_H

#include <string>

class IncidentState;

class Incident {
private:
    int incidentId;
    std::string description;
    std::string location;
    IncidentState* currentState;

public:
    Incident(int id, std::string desc, std::string loc);
    virtual ~Incident();

    void changeState(IncidentState* newState);
    bool dispatchResponders();
    bool containThreat();
    bool resolveIncident();
    std::string getStatus();

    int getId() const;
    std::string getLocation() const;
    std::string getDescription() const;
};

#endif
