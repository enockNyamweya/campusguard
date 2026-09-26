#include "ResolvedState.h"

ResolvedState::ResolvedState() = default;
bool ResolvedState::handleDispatch(Incident*) { return false; }
bool ResolvedState::handleContain(Incident*) { return false; }
bool ResolvedState::handleResolve(Incident*) { return false; }
std::string ResolvedState::getStateName() { return "Resolved"; }
