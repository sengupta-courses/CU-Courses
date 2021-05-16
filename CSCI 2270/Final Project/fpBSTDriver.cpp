//Created by Nathan Straub and Pourna Sengupta 
#include <iostream>
#include <string> 
#include <vector>
#include <fstream>
#include <chrono>
#include <unistd.h>
#include <thread>
#include "fpBST.hpp"
using namespace std;

int main (int argc, char* argv[])
{
    ifstream fileA;
    fileA.open("dataSetA.csv");
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

    //cout << testData[39999] << endl;
    
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

    float insertBSTdataA[400];
    float searchBSTdataA[400];
    float insertBSTdataB[400];
    float searchBSTdataB[400];

    BST TreeA;
    BST TreeB;
    int insertBSTCounter = 0;
    int tempInsertVal = 0;

    //BST INSERT TIME COMPLEXITY
    for (int a = 0; a < 400; a++)
    {
        int tempTimeA = 0;
        int tempTimeB = 0;
        for (int i = tempInsertVal; i < (tempInsertVal + 100); i++)
        {
            using namespace std::chrono;
        
            auto start = steady_clock::now();

            TreeA.insert(testDataA[i]);

            auto end = steady_clock::now();

            tempTimeA = tempTimeA + duration_cast<nanoseconds>(end - start).count();

            using namespace std::chrono;
        
            auto start1 = steady_clock::now();

            TreeB.insert(testDataB[i]);

            auto end1 = steady_clock::now();

            tempTimeB = tempTimeB + duration_cast<nanoseconds>(end1 - start1).count();
        }

        //cout << tempTime/100 << endl;

        tempInsertVal += 100;
        insertBSTdataA[insertBSTCounter] = tempTimeA/100;
        insertBSTdataB[insertBSTCounter] = tempTimeB/100;
        insertBSTCounter++;
    }

    cout << insertBSTdataA[0] << endl;
    cout << insertBSTdataA[199] << endl;
    cout << insertBSTdataA[399] << endl;

    cout << insertBSTdataB[0] << endl;
    cout << insertBSTdataB[199] << endl;
    cout << insertBSTdataB[399] << endl;

    int searchBSTCounter = 0;
    int tempSearchVal = 100;

    //BST SEARCH TIME COMPLEXITY
    for (int a = 0; a < 400; a++)
    {
        int tempTimeA = 0;
        int tempTimeB = 0;
        for (int i = tempSearchVal; i < (tempSearchVal + 100); i++)
        {
            using namespace std::chrono;

            int x = rand() % tempSearchVal;
        
            auto start = steady_clock::now();

            TreeA.search(testDataA[x]);

            auto end = steady_clock::now();

            tempTimeA = tempTimeA + duration_cast<nanoseconds>(end - start).count();

            using namespace std::chrono;
        
            auto start1 = steady_clock::now();

            TreeB.search(testDataB[x]);

            auto end1 = steady_clock::now();

            tempTimeB = tempTimeB + duration_cast<nanoseconds>(end1 - start1).count();
        }

        //cout << tempTime/100 << endl;

        tempSearchVal += 100;
        searchBSTdataA[searchBSTCounter] = tempTimeA/100;
        searchBSTdataB[searchBSTCounter] = tempTimeB/100;
        searchBSTCounter++;
    }

    cout << searchBSTdataA[0] << endl;
    cout << searchBSTdataA[199] << endl;
    cout << searchBSTdataA[399] << endl;

    cout << searchBSTdataB[0] << endl;
    cout << searchBSTdataB[199] << endl;
    cout << searchBSTdataB[399] << endl;

    ofstream BSTA;
    BSTA.open("BSTA.csv");
    for (int i = 0; i < 400; i++)
    {
        BSTA << i << "," << insertBSTdataA[i] << "," << searchBSTdataA[i] << endl;
    }
    BSTA.close();

    ofstream BSTB;
    BSTB.open("BSTB.csv");
    for (int i = 0; i < 400; i++)
    {
        BSTB << i << "," << insertBSTdataB[i] << "," << searchBSTdataB[i] << endl;
    }
    BSTB.close();

    return 0;
}