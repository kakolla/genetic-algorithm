#ifndef POPULATION_H
#define POPULATION_H
#include "individual.h"
#include <vector>
#include <string>

class Population
{
public:
    Population(std::string target_str, int target_size, int size);

    ~Population();


    std::vector<Individual*> selectAlivePopulation(double ratio);

    void crossOverPopulation(std::vector<Individual*>& sub_population, double ratio);

    std::vector<std::string> crossOver(const Individual* p1, const Individual* p2);

    void mutatePopulation();

    void addIndividual(int gene_size);

    std::string printString();

    bool checkComplete(std::vector<Individual*>& list); // check if target has been reached



    std::vector<Individual*> population_list;
    std::vector<Individual*> child_population; // the children for the next generation (empty at first)
    std::string target_; // target string
    int target_len_; // length of the target string
    size_t pop_size_; // size of the population
    

};




#endif