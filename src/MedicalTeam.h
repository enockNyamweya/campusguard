#ifndef MEDICALTEAM_H
#define MEDICALTEAM_H

#include "ResponseUnit.h"
#include <string>

class MedicalTeam : public ResponseUnit {
public:
    MedicalTeam(std::string id, CampusMediator* med);
    virtual ~MedicalTeam() {}

    void deployTriage(const std::string& loc);
    void requestHospitalEscort();
    void receiveNotification(const std::string& senderId, const std::string& event, const std::string& data) override;
};

#endif
