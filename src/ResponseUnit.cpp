#include "ResponseUnit.h"
#include "CampusMediator.h"
 
ResponseUnit::ResponseUnit(std::string id, CampusMediator* med) : mediator(med), unitId(id) {
    if (mediator) {
        mediator->registerColleague(this);
    }
}
 
ResponseUnit::~ResponseUnit() {
}
 
std::string ResponseUnit::getId() const {
    return unitId;
}
 
void ResponseUnit::sendEvent(const std::string& event, const std::string& data) {
    if (mediator) {
        mediator->notify(this, event, data);
    }
}
