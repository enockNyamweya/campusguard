#include "TurnstileAdapter.h"
#include <functional>
#include <iostream>
 
TurnstileAdapter::TurnstileAdapter(LegacyTurnstileSystem* legacy) : legacyHardware(legacy) {
}
 
TurnstileAdapter::~TurnstileAdapter() {
}
 
int TurnstileAdapter::mapZoneToSector(const std::string& zone) {
    std::hash<std::string> hasher;
    return static_cast<int>(hasher(zone) % 9000) + 100;
}
 
bool TurnstileAdapter::lockZone(const std::string& zone) {
    if (!legacyHardware) {
        return false;
    }
    int sector = mapZoneToSector(zone);
    std::cout << "[TurnstileAdapter] lockZone(\"" << zone << "\") -> sector " << sector << std::endl;
    int result = legacyHardware->raw_set_barrier(sector, 1);
    return result == 0;
}
 
bool TurnstileAdapter::unlockZone(const std::string& zone) {
    if (!legacyHardware) {
        return false;
    }
    int sector = mapZoneToSector(zone);
    std::cout << "[TurnstileAdapter] unlockZone(\"" << zone << "\") -> sector " << sector << std::endl;
    int result = legacyHardware->raw_set_barrier(sector, 0);
    return result == 0;
}
 
bool TurnstileAdapter::isZoneLocked(const std::string& zone) {
    if (!legacyHardware) {
        return false;
    }
    int sector = mapZoneToSector(zone);
    int status = legacyHardware->get_sector_status(sector);
    return status == 1;
}