#ifndef DOORCONTROLINTERFACE_H
#define DOORCONTROLINTERFACE_H

#include <string>

class DoorControlInterface {
public:
    virtual ~DoorControlInterface() {}

    virtual bool lockZone(const std::string& zone) = 0;
    virtual bool unlockZone(const std::string& zone) = 0;
    virtual bool isZoneLocked(const std::string& zone) = 0;
};

#endif
