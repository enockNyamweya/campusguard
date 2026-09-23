#ifndef LEGACYTURNSTILESYSTEM_H
#define LEGACYTURNSTILESYSTEM_H

class LegacyTurnstileSystem {


public:
	int raw_set_barrier(int sectorCode, int lockFlag);

	int get_sector_status(int sectorCode);
};

#endif
