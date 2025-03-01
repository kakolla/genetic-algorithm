#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <bits/stdc++.h>

#include "population.h"
#include "individual.h"


using namespace std;
int main(int argc, char* argv[])
{
    // Format: ./program <targetfile.txt> <num_individuals> <selection_ratio> <mutation_rate>
    if (argc < 5) {
        cout << "Not enough arguments" << endl;
        return -1;
    }
    srand(time(NULL));
    // ifstream file("target.txt");
    ifstream file(argv[1]);
    string target = "";
    string line;
    while (getline(file, line))
    {
        target += line;
        target += '\n';
    }
    // file >> target;
    transform(target.begin(), target.end(), target.begin(), ::tolower);
    cout << target << endl;
    


    // initialize population with 10 individuals & calculate fitness
    // int num_individuals = 200;
    int num_individuals = stoi(argv[2]);
    Population pop(target, target.size(), num_individuals);


    // print all individuals
    cout << "pop_size_: " << pop.pop_size_ << endl;


    


    // generate populations until maximum fitness achieved
    bool sim_complete = false;
    int generations = 0;
    while (!sim_complete)
    {
        cout << "---GENERATION " << generations << "---" << endl;
        // select sub-population (parents) that survives (highest fitness = lowest distance)
        // double selection_ratio = 0.10;
        double selection_ratio = stod(argv[3]);
        vector<Individual*> sub_population = pop.selectAlivePopulation(selection_ratio);


        // Display progress
        cout << "Printing sub population picked" << endl;
        for (auto elem : sub_population)
        {
            elem->print();
        }
        cout << endl;

        
       

        // crossover genes of selected parents and add to child_population list
        pop.crossOverPopulation(sub_population, selection_ratio); 


        // mutate the children (0.08 rate) to explore newer solutions & evaluate fitness
        double mutation_rate = stod(argv[4]);
        for (auto& child : pop.child_population)
        {
            // child->mutateIndividual(0.05);
            child->mutateIndividual(mutation_rate);
            // child->print();
            // cout << child->total_fitness_ << endl;
        }

        if (pop.checkComplete(pop.child_population))
        {
            sim_complete = true;
            cout << "num of generations: " << generations << endl;

        }

    
        

        // select child survivors with highest fitness for the next generation
        // add children to the population and clear out child_population list
        for (auto& child : pop.child_population)
        {
            pop.population_list.push_back(child);

        }
        while (!pop.child_population.empty()) // remember auto would create a copy
        {
            pop.child_population.pop_back();
        }




        generations++;

        
    }
    



    cout << "Finished generating" << endl;



    return 0;
}