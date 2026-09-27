#include "ContainedState.h"
#include "ResolvedState.h"
#include "Incident.h"

ContainedState::ContainedState() = default;
bool ContainedState::handleDispatch(Incident*) { return false; }
bool ContainedState::handleContain(Incident*) { return false; }
bool ContainedState::handleResolve(Incident* context) {
    if (!context) return false;
    context->changeState(new ResolvedState());
    return true;
}
std::string ContainedState::getStateName() { return "Contained"; }
