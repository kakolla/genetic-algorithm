#include "individual.h"
#include <vector>
#include <iostream>
#include <cstdlib>


using namespace std;

Individual::Individual(int gene_size)
{
    cout << "Creating individual with gene size" << gene_size << endl;
    gene_size_ = gene_size;
    for (int i = 0; i < gene_size_; ++i)
    {
        // generate random genes initially

        char nucleotide_char = 'a' + (rand()%26);
        string nucleotide(1, nucleotide_char); // create string size 1 w/ the character
        genes.push_back(nucleotide);
    }


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

int Individual::getFitness(string target)
{
    // distance from the actual target string



    return -1;
}

void Individual::crossOver()
{
    
}