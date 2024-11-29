#include "population.h"
#include <vector>
#include <iostream>
#include <string>


using namespace std;

Population::Population(string target_str, int target_size, int size)
{
    cout << "Creating population" << endl;
    target_ = target_str;
    target_len_ = target_size;
    pop_size_ = size;

    // create <pop_size> number of inviduals in starting generation
    for (int i = 0; i < pop_size_; ++i)
    {
        addIndividual(target_len_);

    }


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
    cout << "Adding Individual" << endl;
    Individual* indiv = new Individual(gene_size, target_);
    population_list.push_back(indiv);

}