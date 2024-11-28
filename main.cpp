#include <vector>
#include <iostream>
#include <fstream>
#include <string>



using namespace std;
int main()
{
    ifstream file("target.txt");
    string target;
    file >> target;
    cout << target << endl;



    return 0;
}