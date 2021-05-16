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
    ifstream fileB;
    fileB.open("dataSetB.csv");
    int testDataB[40000];
    int numberB = 0;
    while (fileB.good())
    {
        string line;
        getline(fileB, line, ',');
        testDataB[numberB] = stoi(line);
        numberB++;
    }
    fileB.close();

    //cout << testDataB[39999] << endl;

    float insertChaindataB[400];
    float searchChaindataB[400];

    HashTable ChainB(40009);
    int insertChainCounter = 0;
    int tempInsertValB = 0;

    //CHAIN INSERT TIME COMPLEXITY
    for (int a = 0; a < 400; a++)
    {
        int tempTimeB = 0;

        using namespace std::chrono;

        auto start1 = steady_clock::now();

        for (int i = tempInsertValB; i < (tempInsertValB + 99); i++)
        {
            ChainB.insertItem(testDataB[i]); 
        }

        auto end1 = steady_clock::now();

        tempTimeB = duration_cast<nanoseconds>(end1 - start1).count();

        //cout << tempTime/100 << endl;

        tempInsertValB += 100;
        insertChaindataB[insertChainCounter] = tempTimeB/100;
        insertChainCounter++;
    }

    cout << insertChaindataB[0] << endl;
    cout << insertChaindataB[199] << endl;
    cout << insertChaindataB[399] << endl;

    int searchChainCounter = 0;
    int tempSearchVal = 100;
    int test = 0;


    //CHAIN SEARCH TIME COMPLEXITY
    for (int a = 0; a < 399; a++)
    {
        int tempTimeB = 0;
        for (int i = tempSearchVal; i < (tempSearchVal + 99); i++)
        {
            int x = rand() % tempSearchVal;

            using namespace std::chrono;
        
            auto start1 = steady_clock::now();

            ChainB.searchItem(testDataB[i]);

            auto end1 = steady_clock::now();

            tempTimeB = tempTimeB + duration_cast<nanoseconds>(end1 - start1).count();
        }

        //cout << tempTimeA/100 << endl;

        tempSearchVal += 100;
        searchChaindataB[searchChainCounter] = tempTimeB/100;
        searchChainCounter++;
    }

    cout << searchChaindataB[0] << endl;
    cout << searchChaindataB[199] << endl;
    cout << searchChaindataB[398] << endl;

    ofstream HashChainB;
    HashChainB.open("HashChainB.csv");
    for (int i = 0; i < 400; i++)
    {
        HashChainB << i << "," << insertChaindataB[i] << "," << searchChaindataB[i] << endl;
    }
    HashChainB.close();

    return 0;
}