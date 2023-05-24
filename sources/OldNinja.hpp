#ifndef OLD_NINJA_HPP
#define OLD_NINJA_HPP

#include "Ninja.hpp"
constexpr int OLD_NINJA_SPEED = 8;
constexpr int OLD_NINJA_HITS = 150;

namespace ariel {
    class OldNinja : public Ninja{
        public:
            OldNinja(string,const Point&);
            OldNinja(const OldNinja&);
            OldNinja() = delete;
            OldNinja(OldNinja &&) = delete;
            OldNinja& operator=(OldNinja const &) = delete;
            OldNinja& operator=(OldNinja &&) = delete;
            ~OldNinja() override = default;
    };
}

#endif