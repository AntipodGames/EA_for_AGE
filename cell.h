#ifndef CELL_H
#define CELL_H

#include "environment_descriptor.hpp"
#include <boost/random.hpp>
#include <boost/shared_ptr.hpp>
#include "parameters.h"


namespace ea4age{

class Cell
{

public:

    typedef struct actions{
        float angle;
        int shoot;
        int up;
        int down;
        int left;
        int right;
    }actions;

    Cell(){_genome = std::vector<float>(parameters::genome_size);}

    Cell(boost::random::mt19937& rand){
        _genome = std::vector<float>(parameters::genome_size);
        init(rand);
    }

    void init(boost::random::mt19937 &rand);

    actions behaviour(const Environment_Descriptor &ED);

    void eval(float time, int life, int N_u, int N_d, int N_l, int N_r, int S);

    void set_performance(float perf){_performance = perf;}
    void set_cost(float cost){_cost = cost;}

    const std::vector<float>& get_genome() {return _genome;}
    float get_performance(){return _performance;}
    float get_cost(){return _cost;}

    typedef boost::shared_ptr<Cell> Ptr;

    //intern methodes
    float eval_direction(float N1,float N2,float N3,float N4,int n){
        return (_genome[n]*N1 + _genome[n+1]*N2 + _genome[n+2]*N3 + _genome[n+3]*N4 )/(N1 + N2 + N3 + N4);
    }

private:
    std::vector<float> _genome;
    float _performance;
    float _cost;

};

}

#endif // CELL_H
