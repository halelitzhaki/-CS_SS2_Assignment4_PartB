#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "Point.hpp"

#include <string>

namespace ariel{
    class Character {
        private:
            Point _location;
            int _hits, _isMember;
            string _name;

        public:
            Character(string, const Point&, int);
            Character(const Character&);
            Character(const Character*);
            Character();
            Character(Character &&) = delete;
            Character& operator=(Character const &) = default;
            Character& operator=(Character &&) = default;
            virtual ~Character() = default;

            Point getLocation() const;
            void setLocation(const Point&);
            string getName() const;
            int getHits() const;
            void setHits(int);
            bool getIsMember() const;
            void setIsMember(int);
            double distance(const Character&) const;
            bool isAlive() const;
            void hit(int);
            virtual string print() const;

    };

}

#endif