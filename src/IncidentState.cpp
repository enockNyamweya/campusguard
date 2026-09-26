#include "IncidentState.h"
// Rejected unless a concrete state explicitly permits cancellation.
bool IncidentState::handleCancel(Incident*) { return false; }
