#ifndef CAMPUSMEDIATOR_H
#define CAMPUSMEDIATOR_H

#include <string>

class ResponseUnit;

class CampusMediator {
public:
    virtual ~CampusMediator() {}

    virtual void registerColleague(ResponseUnit* unit) = 0;
    virtual void notify(ResponseUnit* sender, const std::string& event, const std::string& data) = 0;
};

#endif
