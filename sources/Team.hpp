#ifndef TEAM_HPP
#define TEAM_HPP

#include "Cowboy.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "OldNinja.hpp"
#include <vector>

constexpr int MAX_TEAM_MEMBERS = 10;

namespace ariel {
    class Team {
        private:
            Character *_leader;
            vector<Character*> _warriors;

        public:
            Team(Character*);
            Team() = delete;
            Team(Team const &) = delete;
            Team(Team &&) = delete;
            Team& operator=(Team const &) = delete;
            Team& operator=(Team &&) = delete;
            virtual ~Team();

            virtual void add(Character*);
            virtual void attack(Team *);
            Character* getTarget(Team*) const;
            void print() const;
            void attackAlgorithm(Team*,Character*);
            int stillAlive() const;
            vector<Character*> getTeam() const;
            void setTeam(vector<Character*>);
            Character* getLeader() const;
    };
}

#endif