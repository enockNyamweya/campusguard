#ifndef RESPONSEUNIT_H
#define RESPONSEUNIT_H

#include <string>

class CampusMediator;

class ResponseUnit {
protected:
    CampusMediator* mediator;
    std::string unitId;

public:
    ResponseUnit(std::string id, CampusMediator* med);
    virtual ~ResponseUnit();

    std::string getId() const;
    void sendEvent(const std::string& event, const std::string& data);
    virtual void receiveNotification(const std::string& senderId, const std::string& event, const std::string& data) = 0;
};

#endif
