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
    int num_individuals = 20;
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
        
        // select sub-population (parents) that survives (highest fitness = lowest distance)
        double selection_ratio = 0.20;
        vector<Individual*> sub_population = pop.selectAlivePopulation(selection_ratio);

        cout << "Printing sub population picked" << endl;
        for (auto elem : sub_population)
        {
            elem->print();
        }
        cout << endl;

        
       

        // crossover genes of selected parents and add to child_population list
        pop.crossOverPopulation(sub_population, selection_ratio); 


        // mutate the children (0.08 rate) to explore newer solutions & evaluate fitness
        for (auto child : pop.child_population)
        {
            child->mutateIndividual(0.08);
            // child->print();
            // cout << child->total_fitness_ << endl;
        }

    
        

        
        // select child survivors with highest fitness for the next generation
        // add children to the population and clear out child_population list
        for (auto child : pop.child_population)
        {
            pop.population_list.push_back(child);

        }
        while (!pop.child_population.empty()) // remember auto would create a copy
        {
            pop.child_population.pop_back();
        }


        cout << "prniting sub population" << endl;
        for (auto& elem : sub_population)
        {
            elem->print();
        }

        // select new parents
        sub_population = pop.selectAlivePopulation(selection_ratio);
        
        cout << "prniting sub population" << endl;
        for (auto& elem : sub_population)
        {
            elem->print();
            cout << elem->total_fitness_ << endl;
        }


        generations++;
        if (generations == 1) sim_complete = true;
        
    }


    cout << "Finished sim" << endl;



    return 0;
}