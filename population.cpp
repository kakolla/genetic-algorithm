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
    cout << "Selected " << num_individuals << " as parents" << endl;

    // sort population
    sort(population_list.begin(), population_list.end(), [](const Individual* a, const Individual* b) {
        return a->total_fitness_ < b->total_fitness_;
    });
    

    // select sub population that survives
    vector<Individual*> selected_individuals;
    for (int i = 0; i < num_individuals; ++i)
    {
        selected_individuals.push_back(population_list[i]);
    }

    return selected_individuals;
}


vector<string> Population::crossOver(const Individual* p1, const Individual* p2)
{
    if (p1->gene_size_ != p2->gene_size_) throw "different gene sizes for parents";

    int r; // random number to choose which parent's genes crossover
    vector<string> new_genes(p1->gene_size_, "a");
    for (int g = 0; g < p1->gene_size_; ++g)
    {
        r = rand() % 10;
        if (r <= 4) new_genes[g] = p1->genes[g];
        else if (r >= 5) new_genes[g] = p2->genes[g];
    }

    return new_genes;
}

vector<Individual*> Population::crossOverPopulation(vector<Individual*> sub_population)
{
    // Uses uniform crossover
    // take 2 parents chromosomes and uniformly cross them to produce 2 children chromosomes
    vector<Individual*> child_population;

    for (size_t i = 0; i < sub_population.size(); i+=2)
    {
        if (i+1 < sub_population.size())
        {
            // grab 2 parents
            Individual* p1 = sub_population[i];
            Individual* p2 = sub_population[i+1];

            
            // create child 1
            vector<string> new_genes = crossOver(p1, p2);
            Individual* c1 = new Individual(new_genes.size(), target_);
            c1->genes = new_genes;
            c1->calcFitness(); // update fitness

            // create child 2
            vector<string> new_genes2 = crossOver(p1, p2);
            Individual* c2 = new Individual(new_genes.size(), target_);
            c2->genes = new_genes2;
            c2->calcFitness();

            child_population.push_back(c1);
            child_population.push_back(c2);
        }
    }

    return child_population;

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