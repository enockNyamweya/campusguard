#ifndef TURNSTILEADAPTER_H
#define TURNSTILEADAPTER_H

#include "DoorControlInterface.h"
#include "LegacyTurnstileSystem.h"
#include <string>

class TurnstileAdapter : public DoorControlInterface {
private:
    LegacyTurnstileSystem* legacyHardware;
    int mapZoneToSector(const std::string& zone);

public:
    TurnstileAdapter(LegacyTurnstileSystem* legacy);
    virtual ~TurnstileAdapter();

    bool lockZone(const std::string& zone) override;
    bool unlockZone(const std::string& zone) override;
    bool isZoneLocked(const std::string& zone) override;
};

#endif
