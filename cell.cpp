#include "cell.h"
#include "math.h"

using namespace ea4age;

void Cell::init(boost::random::mt19937 &rand){

    boost::random::uniform_real_distribution<> gen_dist_tolerance(parameters::distance_min,
                                                                 parameters::distance_max);
    boost::random::uniform_real_distribution<> gen_number_tolerance(parameters::number_min,
                                                                    parameters::number_max);
    boost::random::uniform_real_distribution<> gen_bin(0,1.);

    boost::random::uniform_real_distribution<> gen_velocity(parameters::frequence_min,
                                                            parameters::frequence_max);

    _genome[0] = gen_dist_tolerance(rand);
    _genome[1] = gen_velocity(rand);
    _genome[2] = gen_number_tolerance(rand);

    for(int i = 3; i < parameters::genome_size ; i++)
        _genome[i] = gen_bin(rand);


}

Cell::actions Cell::behaviour(const Environment_Descriptor& ED){

    actions act;
    float N_ur = (float) ED.up_right.mobs_info.size() ,
          N_rd = (float) ED.right_down.mobs_info.size() ,
          N_dl = (float) ED.down_left.mobs_info.size() ,
          N_lu = (float) ED.left_up.mobs_info.size();

    if(N_ur > _genome[2]){
        std::vector<Mob_Info>::const_iterator closer_mob;
        closer_mob = std::min_element(ED.up_right.mobs_info.begin(),ED.up_right.mobs_info.end());
        if(closer_mob->distance < _genome[0])
            act.shoot = 1;
        act.angle = closer_mob->angle;
    }else if(N_rd > _genome[2]){
        std::vector<Mob_Info>::const_iterator closer_mob;
        closer_mob = std::min_element(ED.right_down.mobs_info.begin(),ED.right_down.mobs_info.end());
        if(closer_mob->distance < _genome[0])
            act.shoot = 1;
        act.angle = closer_mob->angle;
    }else if(N_dl > _genome[2]){
        std::vector<Mob_Info>::const_iterator closer_mob;
        closer_mob = std::min_element(ED.down_left.mobs_info.begin(),ED.down_left.mobs_info.end());
        if(closer_mob->distance < _genome[0])
            act.shoot = 1;
        act.angle = closer_mob->angle;
    }else if(N_lu > _genome[2]){
        std::vector<Mob_Info>::const_iterator closer_mob;
        closer_mob = std::min_element(ED.left_up.mobs_info.begin(),ED.left_up.mobs_info.end());
        if(closer_mob->distance < _genome[0])
            act.shoot = 1;
        act.angle = closer_mob->angle;
    }


    float eval_up, eval_down, eval_left, eval_right;

    eval_up = eval_direction(N_ur,N_rd,N_dl,N_lu,3);
    eval_down = eval_direction(N_ur,N_rd,N_dl,N_lu,7);
    eval_left = eval_direction(N_ur,N_rd,N_dl,N_lu,11);
    eval_right = eval_direction(N_ur,N_rd,N_dl,N_lu,15);

    act.up = (int) std::floor(.5 + eval_up);
    act.down = (int) std::floor(.5 + eval_down);
    act.left = (int) std::floor(.5 + eval_left);
    act.right = (int) std::floor(.5 + eval_right);

    return act;
}

void Cell::eval(float time, int life, int N_u, int N_d, int N_l, int N_r, int S){
    _performance = time + (float) life;
    _cost = 1./_genome[1]*parameters::velocity_importance
            + (float) (N_u + N_d + N_r + N_l)*parameters::directions_importance
            + (float) S * parameters::shoot_importance;
}
