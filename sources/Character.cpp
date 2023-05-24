#include "Character.hpp"

using namespace ariel;

Character::Character() {
    _name = string();
    _location = Point();
    _isMember = 0;
    _hits = 0;
}

Character::Character(string name, const Point& location, int hits) {
    _name = string(name);
    _location = Point(location);
    _hits = hits;
    _isMember = 0;
}

Character::Character(const Character &other) {
    *this = Character(other.getName(), other.getLocation(), other.getHits());
    _isMember = other.getIsMember();
}

Character::Character(const Character* other) {
    *this = Character(other->getName(), other->getLocation(), other->getHits());
    _isMember = other->getIsMember();
}

Point Character::getLocation() const {
    return _location;
}

void Character::setLocation(const Point& location) {
    this->_location = location;
}

string Character::getName() const {
    return _name;
}

int Character::getHits() const {
    return _hits;
}

void Character::setHits(int hits) {
    _hits = hits;
}

bool Character::getIsMember() const {
    return _isMember == 1;
}

void Character::setIsMember(int state) {
    _isMember = state;
}

double Character::distance(const Character& other) const {
    return _location.distance(other.getLocation());
}

bool Character::isAlive() const {
    return _hits > 0;
}

void Character::hit(int n) {
    if(n < 0) throw invalid_argument("invalid parameter");
    _hits -= n;
}

string Character::print() const {
    return string();
}