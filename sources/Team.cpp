#include "Team.hpp"

using namespace ariel;

Team::Team(Character* leader) {
    if(leader == nullptr) throw invalid_argument("null character");
    if(leader->getIsMember()) throw runtime_error("character already leader of other team");
    _leader = leader;
    _leader->setIsMember(1);
    _warriors.push_back(leader);
}

Team::~Team() {
    for(Character * warrior : _warriors) {
        delete warrior;
    }
    _warriors.clear();
}

void Team::add(Character* newWarrior) {
    if(newWarrior == nullptr) throw invalid_argument("null character");
    if(_warriors.size() == MAX_TEAM_MEMBERS) throw runtime_error("team is full");
    if(newWarrior->getIsMember()) throw runtime_error("character already member of other\this team");
    if(dynamic_cast<Ninja*>(newWarrior) != NULL) {
        newWarrior->setIsMember(1);
        _warriors.push_back(newWarrior);
        return;
    }

    vector<Character*> newWarriors;
    int pushed = 0;
    for(Character * warrior : _warriors) {
        if(pushed == 0 && dynamic_cast<Ninja*>(warrior) != NULL) {
            newWarrior->setIsMember(1);
            newWarriors.push_back(newWarrior);
            pushed = 1;
        }
        newWarriors.push_back(warrior);
    }
    if(!newWarrior->getIsMember()) {
        newWarrior->setIsMember(1);
        newWarriors.push_back(newWarrior);
    }
    _warriors = newWarriors;
}

void Team::attack(Team * enemies) {
    if(enemies == nullptr) throw invalid_argument("null team");
    if(enemies->stillAlive() == 0) throw runtime_error("enemies are already dead");
    if(stillAlive() == 0) throw runtime_error("team is dead");
    if(!_leader->isAlive()) {
        Character * newLeader = nullptr;
        double closestWarriorDist = 0.0;
        for(Character *warrior : _warriors) {
            if(warrior->isAlive()) {
                closestWarriorDist = _leader->distance(*warrior);
                break;
            }
        }
        for(Character *warrior : _warriors) {
            if(warrior->isAlive() && _leader->distance(*warrior) <= closestWarriorDist) {
                closestWarriorDist = _leader->distance(*warrior);
                newLeader = warrior;
            }
        }
        if(newLeader == nullptr) return;
        _leader = newLeader;
    }
    Character* target = getTarget(enemies);
    if(target == nullptr) return;
    attackAlgorithm(enemies, target);
}

Character* Team::getTarget(Team* enemies) const {
    Character * target = nullptr;
    double closestEnemyDist = 0.0;
    if(enemies->stillAlive() == 0) return target;
    for(Character * enemy : enemies->getTeam()) {
        if(enemy->isAlive()) {
            closestEnemyDist = _leader->distance(*enemy);
            target = enemy;
            break;
        }
    }
    for(Character * enemy : enemies->getTeam()) {
        if(enemy->isAlive() && _leader->distance(*enemy) <= closestEnemyDist) {
            closestEnemyDist = _leader->distance(*enemy);
            target = enemy;
        }
    }
    return target;
}

void Team::attackAlgorithm(Team* enemies, Character* target) {
    int i = 1;
    for(Character * warrior : _warriors) {
        if(!target->isAlive()) {
            if(i == stillAlive()) return;
            target = getTarget(enemies);
            if(target == nullptr) return;
        }
        if(warrior->isAlive() && dynamic_cast<Cowboy*>(warrior) != NULL) {
            Cowboy * Cwarrior = dynamic_cast<Cowboy*>(warrior);
            if(Cwarrior->hasboolets()) Cwarrior->shoot(target);
            else Cwarrior->reload();
        }
        else if (warrior->isAlive() && dynamic_cast<Ninja*>(warrior) != NULL) {
            Ninja * Nwarrior = dynamic_cast<Ninja*>(warrior);
            if(warrior->getLocation().distance(target->getLocation()) < 1) Nwarrior->slash(target);
            else Nwarrior->move(target);
        }
        i++;
    }
}

int Team::stillAlive() const {
    int i = 0;
    for(Character* warrior : _warriors) {
        if(warrior->isAlive()) i++;
    }
    return i;
}

void Team::print() const {
    for(Character * warrior : _warriors) cout << warrior->print() << endl;
    cout << endl;
}

vector<Character*> Team::getTeam() const {
    return _warriors;
}

void Team::setTeam(vector<Character*> newTeam) {
    _warriors = newTeam;
}

Character* Team::getLeader() const {
    return _leader;
}