#include "SmartTeam.hpp"

using namespace ariel;

SmartTeam::SmartTeam(Character* leader) : Team (leader){ }

void SmartTeam::add(Character* newWarrior) {
    if(newWarrior == nullptr) throw invalid_argument("null character");
    if(this->getTeam().size() == MAX_TEAM_MEMBERS) throw runtime_error("team is full");
    if(newWarrior->getIsMember()) throw runtime_error("character already member of other\this team");
    vector<Character*> temp = this->getTeam();
    newWarrior->setIsMember(1);
    temp.push_back(newWarrior);
    this->setTeam(temp);
}

void SmartTeam::attack(Team * enemies) {
    if(enemies == nullptr) throw invalid_argument("null team");
    if(enemies->stillAlive() == 0) throw runtime_error("enemies are already dead");
    Character* target = NULL;
    for(Character* enemy : enemies->getTeam()) {
        if(enemy->isAlive() && dynamic_cast<Cowboy*>(enemy) != NULL) {
            target = enemy;
            break;
        }
    }
    for(Character* enemy : enemies->getTeam()) {
        if(target == NULL) {
            for(Character* warrior : this->getTeam()) {
                if(enemy->isAlive() && warrior->isAlive() && warrior->getLocation().distance(enemy->getLocation()) <= OLD_NINJA_SPEED) {
                    target = enemy;
                    break;
                }
            }
        }
    }
    if(target != NULL) {
        attackAlgorithm(enemies, target);
        return;
    }
    for(Character* enemy : enemies->getTeam()) {
        if(enemy->isAlive()) target = enemy;
    }
    attackAlgorithm(enemies, target);
}