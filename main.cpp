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

    // initialize population with 10 individuals
    Population pop(target, target.size(), 10);


    // print all individuals
    for (size_t i = 0 ; i < target.size(); i++)
    {
        pop.population_list[i]->print();
        cout << pop.population_list[i]->total_fitness_ << endl;;
    }
    // evaluate fitness of population
    // int fitness = -1;


    


    // generate populations until maximum fitness achieved
    // while (true)
    // {
    //     // if ()
    //     time++;
        
    //     // select sub-population that survives 

    //     // crossover genes of selected parents

    //     // mutate the children (0.1 rate)

    //     // evaluate fitness

        

    // }




    return 0;
}