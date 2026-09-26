#include "DispatchedState.h"
#include "ContainedState.h"
#include "ReportedState.h"
#include "Incident.h"

DispatchedState::DispatchedState() = default;
bool DispatchedState::handleDispatch(Incident*) { return false; }
bool DispatchedState::handleContain(Incident* context) {
    if (!context) return false;
    context->changeState(new ContainedState());
    return true;
}
bool DispatchedState::handleResolve(Incident*) { return false; }
bool DispatchedState::handleCancel(Incident* context) {
    if (!context) return false;
    context->changeState(new ReportedState());
    return true;
}
std::string DispatchedState::getStateName() { return "Dispatched"; }
