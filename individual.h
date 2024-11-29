#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H
#include <string>
#include <vector>


class Individual
{
public:
    Individual(int gene_size);
    void mutateIndividual();


    int getFitness(std::string target);

    void crossOver();   


    void print();


    std::vector<std::string> genes;
    int gene_size_;

};






#endif