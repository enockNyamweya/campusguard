#include "LegacyTurnstileSystem.h"
#include <iostream>
 
int LegacyTurnstileSystem::raw_set_barrier(int sectorCode, int lockFlag) {
    std::cout << "[LegacyTurnstileSystem] raw_set_barrier(sector=" << sectorCode
              << ", lockFlag=" << lockFlag << ")" << std::endl;
    if (sectorCode < 0) {
        return -1;
    }
    if (lockFlag != 0 && lockFlag != 1) {
        return -1;
    }
    sectorState[sectorCode] = lockFlag;
    return 0;
}
 
int LegacyTurnstileSystem::get_sector_status(int sectorCode) {
    std::map<int, int>::iterator it = sectorState.find(sectorCode);
    int status = (it == sectorState.end()) ? 0 : it->second;
    std::cout << "[LegacyTurnstileSystem] get_sector_status(sector=" << sectorCode
              << ") -> " << status << std::endl;
    return status;
}