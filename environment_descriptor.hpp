#ifndef ENVIRONMENT_DESCRIPTOR_HPP
#define ENVIRONMENT_DESCRIPTOR_HPP

#include <vector>

namespace ea4age {

struct Mob_Info{
    double angle;
    double distance;

    Mob_Info(double angle = 0, double distance = 0) :
    angle(angle), distance(distance){}


    Mob_Info& operator=(const Mob_Info& m){
        angle = m.angle;
        distance = m.distance;
        return *this;
    }

    bool operator<(const Mob_Info& m) const {
        return distance < m.distance;
    }

};

typedef struct Environment_Descriptor{

    struct up_right{
        std::vector<Mob_Info> mobs_info;
    }up_right;

    struct right_down{
        std::vector<Mob_Info> mobs_info;
    }right_down;

    struct down_left{
        std::vector<Mob_Info> mobs_info;
    }down_left;

    struct left_up{
        std::vector<Mob_Info> mobs_info;
    }left_up;

}Environment_Descriptor;

}

#endif // ENVIRONMENT_DESCRIPTOR_HPP
