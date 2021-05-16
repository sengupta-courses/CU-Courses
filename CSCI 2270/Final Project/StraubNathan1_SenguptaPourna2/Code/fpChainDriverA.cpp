#include <iostream>
#include <string> 
#include <vector>
#include <fstream>
#include <chrono>
#include <unistd.h>
#include <thread>
#include "fpChain.hpp"
using namespace std;

int main (int argc, char* argv[])
{
    ifstream fileA;
    fileA.open("test.csv");
    int testDataA[40000];
    int numberA = 0;
    while (fileA.good())
    {
        string line;
        getline(fileA, line, ',');
        testDataA[numberA] = stoi(line);
        numberA++;
    }
    fileA.close();

    //cout << testDataA[9] << endl;

    float insertChaindataA[400];
    float searchChaindataA[400];

    HashTable ChainA(40009);
    int insertChainCounter = 0;
    int tempInsertValA = 0;
    

    //CHAIN INSERT TIME COMPLEXITY
    for (int a = 0; a < 400; a++)
    {
        int tempTimeA = 0;
        
        using namespace std::chrono;

        auto start = steady_clock::now();

        for (int i = tempInsertValA; i < (tempInsertValA + 99); i++)
        {
            ChainA.insertItem(testDataA[i]);
        }

        auto end = steady_clock::now();

        tempTimeA = duration_cast<nanoseconds>(end - start).count();

        tempInsertValA += 100;
        insertChaindataA[insertChainCounter] = tempTimeA/100;
        insertChainCounter++;
    }

    cout << insertChaindataA[0] << endl;
    cout << insertChaindataA[199] << endl;
    cout << insertChaindataA[399] << endl;

    //ChainA.printTable();

    int searchChainCounter = 0;
    int tempSearchVal = 0;

    //CHAIN SEARCH TIME COMPLEXITY
    for (int a = 0; a < 400; a++)
    {
        int tempTimeA = 0;
        tempSearchVal = tempSearchVal + 100;
        for (int i = tempSearchVal; i < (tempSearchVal + 99); i++)
        {
            using namespace std::chrono;

            int x = rand() % tempSearchVal;
        
            auto start = steady_clock::now();

            ChainA.searchItem(testDataA[x]);

            auto end = steady_clock::now();

            tempTimeA = tempTimeA + duration_cast<nanoseconds>(end - start).count();
        }

        //cout << tempTimeA/100 << endl;

        searchChaindataA[searchChainCounter] = tempTimeA/100;
        searchChainCounter++;
    }

    cout << searchChaindataA[0] << endl;
    cout << searchChaindataA[199] << endl;
    cout << searchChaindataA[399] << endl;

    ofstream HashChainA;
    HashChainA.open("HashChainA.txt");
    for (int i = 0; i < 400; i++)
    {
        HashChainA << i << "," << insertChaindataA[i] << "," << searchChaindataA[i] << endl;
    }
    HashChainA.close();

    return 0;
}