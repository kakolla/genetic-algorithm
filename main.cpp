#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>

#include "population.h"
#include "individual.h"


using namespace std;
int main()
{
    srand(time(NULL));
    ifstream file("target.txt");
    string target;
    file >> target;
    cout << target << endl;


    // initialize time -- number of generations
    // int time = 0;

    // initialize population with 10 individuals & calculate fitness
    int num_individuals = 10;
    Population pop(target, target.size(), num_individuals);


    // print all individuals
    cout << "pop_size_: " << pop.pop_size_ << endl;
    for (size_t i = 0 ; i < pop.pop_size_; i++)
    {
        // pop.population_list[i]->print();
        cout << "fitness: " << pop.population_list[i]->total_fitness_ << endl;
    }


    


    // generate populations until maximum fitness achieved
    bool sim_complete = false;
    int generations = 0;
    while (!sim_complete)
    {
        generations++;
        
        // select sub-population (parents) that survives (highest fitness)
        double selection_ratio = 0.10;
        vector<Individual*> sub_population = pop.selectAlivePopulation(selection_ratio);

       

        // crossover genes of selected parents

        // mutate the children (0.1 rate) for more variation

        // evaluate fitness

        // select survivors from fitness


        if (generations == 1) sim_complete = true;
        

    }


    cout << "Finished sim" << endl;



    return 0;
}