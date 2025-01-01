#include "population.h"
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>


using namespace std;

Population::Population(string target_str, int target_size, int size) 
: target_(target_str), target_len_(target_size), pop_size_(size)
{
    cout << "Creating population" << endl;
    // create <pop_size> number of inviduals in starting generation
    for (size_t i = 0; i < pop_size_; ++i)
    {
        addIndividual(target_len_);

    }


}

vector<Individual*> Population::selectAlivePopulation(double ratio)
{
    int num_individuals = ratio * pop_size_;
    cout << "Selected " << num_individuals << " as alive" << endl;

    // sort population
    sort(population_list.begin(), population_list.end(), [](const Individual* a, const Individual* b) {
        return a->total_fitness_ > b->total_fitness_;
    });
    

    // select sub population that survives
    vector<Individual*> selected_individuals;
    for (int i = 0; i < num_individuals; ++i)
    {
        selected_individuals.push_back(population_list[i]);
    }

    return selected_individuals;
}


void Population::crossOverPopulation()
{
    

}


void Population::mutatePopulation()
{
    cout << "Mutating population" << endl;

}


string Population::printString()
{

    return nullptr;
}

void Population::addIndividual(int gene_size)
{
    // cout << "Adding Individual" << endl;
    Individual* indiv = new Individual(gene_size, target_);
    population_list.push_back(indiv);

}