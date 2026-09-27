#include "Incident.h"
#include "IncidentState.h"
#include "ReportedState.h"
#include <iostream>
#include <stdexcept>
#include <utility>

Incident::Incident(int id, std::string desc, std::string loc)
    : incidentId(id), description(desc), location(loc),
      currentState(new ReportedState()), handlingAction(false) {
    if (id <= 0 || desc.empty() || loc.empty())
        throw std::invalid_argument("An incident needs a positive ID, description and location");
    std::cout << "[Incident #" << incidentId << "] Reported: " << description << " at " << location << '\n';
}
Incident::~Incident() = default;
void Incident::changeState(IncidentState* newState) {
    if (!newState) throw std::invalid_argument("Incident state must not be null");
    if (newState == currentState.get() || newState == pendingState.get()) return;
    if (handlingAction) pendingState.reset(newState);
    else currentState.reset(newState);
}
bool Incident::perform(bool (IncidentState::*action)(Incident*), const std::string& name) {
    if (handlingAction) throw std::logic_error("Reentrant incident action is not supported");
    const std::string previous = getStatus();
    handlingAction = true;
    bool accepted;
    try {
        accepted = (currentState.get()->*action)(this);
    } catch (...) {
        handlingAction = false;
        pendingState.reset();
        throw;
    }
    handlingAction = false;
    if (accepted && pendingState) currentState = std::move(pendingState);
    else pendingState.reset();
    if (accepted)
        std::cout << "[Incident #" << incidentId << "] " << previous << " -> " << getStatus() << '\n';
    else
        std::cout << "[Incident #" << incidentId << "] Rejected " << name << " while " << previous << '\n';
    return accepted;
}
bool Incident::dispatchResponders() { return perform(&IncidentState::handleDispatch, "dispatch"); }
bool Incident::containThreat() { return perform(&IncidentState::handleContain, "contain"); }
bool Incident::resolveIncident() { return perform(&IncidentState::handleResolve, "resolve"); }
bool Incident::cancelDispatch() { return perform(&IncidentState::handleCancel, "cancel dispatch"); }
std::string Incident::getStatus() { return currentState->getStateName(); }
int Incident::getId() const { return incidentId; }
std::string Incident::getLocation() const { return location; }
std::string Incident::getDescription() const { return description; }
