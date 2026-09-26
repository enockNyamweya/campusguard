#include "ReportedState.h"
#include "DispatchedState.h"
#include "Incident.h"

ReportedState::ReportedState() = default;
bool ReportedState::handleDispatch(Incident* context) {
    if (!context) return false;
    context->changeState(new DispatchedState());
    return true;
}
bool ReportedState::handleContain(Incident*) { return false; }
bool ReportedState::handleResolve(Incident*) { return false; }
std::string ReportedState::getStateName() { return "Reported"; }
