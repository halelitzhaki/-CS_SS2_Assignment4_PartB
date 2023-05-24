#include "Team2.hpp"

using namespace ariel;

Team2::Team2(Character* leader) : Team (leader){ }

void Team2::add(Character * newWarrior) {
    if(newWarrior == nullptr) throw invalid_argument("null character");
    if(this->getTeam().size() == MAX_TEAM_MEMBERS) throw runtime_error("team is full");
    if(newWarrior->getIsMember()) throw runtime_error("character already member of other\this team");
    vector<Character*> temp = this->getTeam();
    newWarrior->setIsMember(1);
    temp.push_back(newWarrior);
    this->setTeam(temp);
}