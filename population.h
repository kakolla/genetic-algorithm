#ifndef POPULATION_H
#define POPULATION_H
#include "individual.h"
#include <vector>

class Population
{
public:
    Population();


    void mutatePopulation();


    std::vector<Individual> population_list;
    
};




#endif