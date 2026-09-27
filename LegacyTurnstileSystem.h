#ifndef LEGACYTURNSTILESYSTEM_H
#define LEGACYTURNSTILESYSTEM_H
 
#include <map>
 
class LegacyTurnstileSystem {
private:
    std::map<int, int> sectorState;
 
public:
	int raw_set_barrier(int sectorCode, int lockFlag);
 
	int get_sector_status(int sectorCode);
};
 
#endif