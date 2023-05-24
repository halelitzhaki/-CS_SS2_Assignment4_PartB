#include "Point.hpp"

using namespace ariel;

Point::Point() {
    _x = 0.0;
    _y = 0.0;
}

Point::Point(double x,double y) {
    _x = x;
    _y = y;
}

Point::Point(const Point &other) {
    _x = other.getX();
    _y = other.getY();
}

string Point::print() const {
    string str = "(";
    str.append(to_string(_x));
    str.append(",");
    str.append(to_string(_y));
    str.append(")");
    return str;
}

double Point::distance(const Point &other) const {
    return sqrt(pow(other.getX() - _x, 2) + pow(other.getY()- _y, 2));
}

double Point::getX() const {
    return _x;
}

double Point::getY() const {
    return _y;
}

Point Point::moveTowards(const Point &src, const Point &dst ,double dist) {
    if(src.distance(dst) <= dist) return dst;
    if(dist == 0.0) return src;
    if(dist < 0.0) throw invalid_argument("Invalid distance - negative");
    double angle = (atan2(dst.getY()-src.getY(), dst.getX()-src.getX())), 
    dX = dist * cos(angle), dY = dist * sin(angle);
    return Point(src.getX()+dX, src.getY()+dY);
}

const Point& Point::operator+(const Point& other) {
    _x += other.getX();
    _y += other.getY();
    return *this;
  }