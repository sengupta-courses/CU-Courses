#include <iostream>
#include <string> 
#include <vector>
#include <fstream>
#include <chrono>
#include <unistd.h>
#include <thread>
#include "fpLinear.hpp"
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

    float insertLineardataA[400];
    float searchLineardataA[400];
    float insertLineardataB[400];
    float searchLineardataB[400];

    HashTable LinearA(40009);
    HashTable LinearB(40009);
    int insertLinearCounter = 0;
    int tempInsertVal = 0;
    int test = 0;

    //LINEAR INSERT TIME COMPLEXITY
    for (int a = 0; a < 400; a++)
    {
        int tempTimeA = 0;
        int tempTimeB = 0;
        for (int i = tempInsertVal; i < (tempInsertVal + 99); i++)
        {
            using namespace std::chrono;
        
            auto start = steady_clock::now();

            LinearA.insert(testDataA[i]);

            auto end = steady_clock::now();

            tempTimeA = tempTimeA + duration_cast<nanoseconds>(end - start).count();

            using namespace std::chrono;
        
            auto start1 = steady_clock::now();

            LinearA.insert(testDataB[i]);

            auto end1 = steady_clock::now();

            tempTimeB = tempTimeB + duration_cast<nanoseconds>(end1 - start1).count();
        }

        //cout << tempTimeA/100 << endl;

        tempInsertVal += 100;
        insertLineardataA[insertLinearCounter] = tempTimeA/100;
        insertLineardataB[insertLinearCounter] = tempTimeB/100;
        insertLinearCounter++;
    }

    cout << insertLineardataA[0] << endl;
    cout << insertLineardataA[199] << endl;
    cout << insertLineardataA[399] << endl;

    cout << insertLineardataB[0] << endl;
    cout << insertLineardataB[199] << endl;
    cout << insertLineardataB[399] << endl;

    /*int searchBSTCounter = 0;
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
    BSTA.open("BSTA.txt");
    for (int i = 0; i < 400; i++)
    {
        BSTA << i << "," << insertBSTdataA[i] << "," << searchBSTdataA[i] << endl;
    }
    BSTA.close();

    ofstream BSTB;
    BSTB.open("BSTB.txt");
    for (int i = 0; i < 400; i++)
    {
        BSTB << i << "," << insertBSTdataB[i] << "," << searchBSTdataB[i] << endl;
    }
    BSTB.close();*/

    return 0;
}