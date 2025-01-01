#ifndef POPULATION_H
#define POPULATION_H
#include "individual.h"
#include <vector>
#include <string>

class Population
{
public:
    Population(std::string target_str, int target_size, int size);


    void selectAlivePopulation(int ratio);

    void mutatePopulation();

    void addIndividual(int gene_size);

    std::string printString();



    std::vector<Individual*> population_list;
    std::string target_;
    int target_len_;
    int pop_size_;

};




#endif