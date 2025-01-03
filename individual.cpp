#include "individual.h"
#include <vector>
#include <iostream>
#include <cstdlib>
#include <cmath>


using namespace std;

// constructor
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

// print function
const void Individual::print()
{
    for (size_t i = 0; i < genes.size(); ++i)
    {
        cout << genes[i];
    }
    cout << endl;
    
}


// mutates the individual's genes based on the rate
void Individual::mutateIndividual(double mut_rate)
{
    cout << "Mutating individual" << endl;
    int r;

    // mutating the individual nucleotides aka letters
    for (int i = 0; i < gene_size_; ++i)
    {
        r = rand() % 100;
        if (r < mut_rate * 100) 
        {
            char nucleotide_char = 'a' + (rand()%26);
            string nucleotide(1, nucleotide_char); // create string size 1 w/ the character
            genes[i] = nucleotide;
            // genes[i] = "M";

        }

    }
    calcFitness();

}

// calculates fitness defined as distance from the actual target string
void Individual::calcFitness()
{
    total_fitness_ = 0;
    
    
    for (size_t i = 0; i < genes.size(); i++)
    {
        // compare char values at ith index and add up distances
        total_fitness_ += abs(target_.at(i) - genes[i][0]); 

    }


}

