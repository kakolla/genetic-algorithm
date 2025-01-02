#include "individual.h"
#include <vector>
#include <iostream>
#include <cstdlib>
#include <cmath>


using namespace std;

Individual::Individual(int gene_size, string target) : 
gene_size_(gene_size), target_(target)
{
    cout << "Creating individual with gene size" << gene_size << endl;
    total_fitness_ = 0;
    for (int i = 0; i < gene_size_; ++i)
    {
        // generate random genes initially

        char nucleotide_char = 'a' + (rand()%26);
        string nucleotide(1, nucleotide_char); // create string size 1 w/ the character
        genes.push_back(nucleotide);
    }

    // calculate fitness
    calcFitness();
    

}

void Individual::print()
{
    for (size_t i = 0; i < genes.size(); ++i)
    {
        cout << genes[i];
    }
    cout << endl;
    
}

void Individual::mutateIndividual()
{
    cout << "Mutating individual" << endl;

}

void Individual::calcFitness()
{
    // distance from the actual target string
    total_fitness_ = 0;
    
    
    for (size_t i = 0; i < genes.size(); i++)
    {
        // compare char values at ith index and add up distances
        total_fitness_ += abs(target_.at(i) - genes[i][0]); 

    }


}

