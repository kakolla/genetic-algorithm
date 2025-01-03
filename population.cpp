#include "population.h"
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>


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

Population::~Population()
{
    for (auto elem : child_population)
    {
        delete elem;
    }

    for (auto elem : population_list)
    {
        delete elem;
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

    // delete rest of population
    for (int i = population_list.size()-1; i >= num_individuals; i--)
    {
        delete population_list[i];
        population_list.pop_back();
    }
    for (int i = 0; i < num_individuals; ++i)
    {
        population_list.pop_back();
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

void Population::crossOverPopulation(vector<Individual*>& sub_population, double ratio)
{
    // Uses uniform crossover technique
    // take 2 parents chromosomes and uniformly cross them 
    // produces 1/ratio * 2 times more children to repopulate the entire population back to original size

    for (size_t i = 0; i < sub_population.size(); i+=2)
    {
        if (i+1 < sub_population.size())
        {
            // grab 2 parents
            Individual* p1 = sub_population[i];
            Individual* p2 = sub_population[i+1];

            
            // create 1/ratio  * 2 number of children
            int number_to_reproduce = ceil((1/ratio)) * 2;
            cout << "sub pop size: " << sub_population.size() << endl;
            cout << "num to reprod: " << number_to_reproduce << endl;
            for (int k = 0; k < number_to_reproduce; ++k)
            {
                vector<string> new_genes = crossOver(p1, p2);
                Individual* c1 = new Individual(new_genes.size(), target_);
                c1->genes = new_genes;
                c1->calcFitness(); // update fitness

                child_population.push_back(c1);
            }
            // i.e. 4 parents: 2 will reproduce each 10 times, which gets 2*10  back to 20 individuals.
        }
    }

    // clear out sub population
    while (!sub_population.empty())
    {
        sub_population.pop_back();
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
    // cout << "Adding Individual" << endl;
    Individual* indiv = new Individual(gene_size, target_);
    population_list.push_back(indiv);

}