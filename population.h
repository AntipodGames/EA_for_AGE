#ifndef POPULATION_H
#define POPULATION_H

#include <cell.h>
#include <boost/random.hpp>
#include <time.h>

namespace ea4age {

class Population
{
public:
    Population(){}

    Population(int size){
        init(size);
    }

    Population(const Population& pop) : _cells(pop._cells){}

    void init(int size){
        boost::random::mt19937 random;
        random.seed(time(NULL));
        _cells = std::vector<Cell>(size,random);
    }

    const std::vector<Cell>& get_cells(){return _cells;}

private:
    std::vector<Cell> _cells;
};

}

#endif // POPULATION_H
