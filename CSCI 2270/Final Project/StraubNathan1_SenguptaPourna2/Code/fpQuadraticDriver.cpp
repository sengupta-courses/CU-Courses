//Created by Nathan Straub and Pourna Sengupta 
#include <iostream>
#include <string> 
#include <vector>
#include <fstream>
#include <chrono>
#include <unistd.h>
#include <thread>
#include "fpQuadratic.hpp"
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
    

    float insertItemA[400];
    float searchItemA[400];
    float insertItemB[400];
    float searchItemB[400];

    HashTable HashA(40009);
    HashTable HashB(40009);
   
    int insertListCounter = 0;
    int tempInsertVal = 0;

    //LINKED LIST INSERT TIME COMPLEXITY
    bool tempA = false;
    bool tempB = false;

    for (int a = 0; a < 400; a++)
    {
        int tempTimeA = 0;
        int tempTimeB = 0;
        for (int i = tempInsertVal; i < (tempInsertVal + 100); i++)
        {
            cout << i << endl; 
            using namespace std::chrono;
        
            auto start = steady_clock::now();

            if (i == 0)
            {
                HashA.insert(testDataA[i]);
            }
            else
            {
                HashA.insert(testDataA[i]);
            }
            
            auto end = steady_clock::now();

            tempA = HashA.search(testDataA[i]);

            tempTimeA = tempTimeA + duration_cast<nanoseconds>(end - start).count();

            auto start1 = steady_clock::now();

            HashB.insert(testDataB[i]);

            auto end1 = steady_clock::now();

            tempB = HashB.search(testDataB[i]);

            tempTimeB = tempTimeB + duration_cast<nanoseconds>(end1 - start1).count();
            //cout << "reached here 4" << endl;
        }

        //cout << tempTime/100 << endl;

        tempInsertVal += 100;
        insertItemA[insertListCounter] = tempTimeA/100;
        insertItemB[insertListCounter] = tempTimeB/100;
        insertListCounter++;
    }

    cout << insertItemA[0] << endl;
    cout << insertItemA[399] << endl;

    cout << insertItemB[0] << endl;
    cout << insertItemB[399] << endl;

    int searchListCounter = 0;
    int tempSearchVal = 100;

    //LINKED LIST SEARCH TIME COMPLEXITY
    for (int a = 0; a < 400; a++)
    {
        int tempTimeA = 0;
        int tempTimeB = 0;
        for (int i = tempSearchVal; i < (tempSearchVal + 100); i++)
        {
            using namespace std::chrono;

            int x = rand() % tempSearchVal;
        
            auto start = steady_clock::now();

            HashA.search(testDataA[x]);

            auto end = steady_clock::now();

            tempTimeA = tempTimeA + duration_cast<nanoseconds>(end - start).count();

            auto start1 = steady_clock::now();

            HashB.search(testDataB[x]);

            auto end1 = steady_clock::now();

            tempTimeB = tempTimeB + duration_cast<nanoseconds>(end1 - start1).count();
        }

        //cout << tempTime/100 << endl;

        tempSearchVal += 100;
        searchItemA[searchListCounter] = tempTimeA/100;
        searchItemB[searchListCounter] = tempTimeB/100;
        searchListCounter++; 
    }

    cout << searchItemA[0] << endl;
    cout << searchItemA[399] << endl;

    cout << searchItemB[0] << endl;
    cout << searchItemB[399] << endl;


    ofstream listA; 
    listA.open("quadraticA.csv"); 
    for(int i = 0; i < 400; i++){
        listA << i << ", " << insertItemA[i] << ", " << searchItemA[i] << endl; 
    }

    listA.close(); 

    ofstream listB; 
    listB.open("quadraticB.csv"); 
    for(int i = 0; i < 400; i++){
        listB << i << ", " << insertItemA[i] << ", " << searchItemA[i] << endl; 
    }

    listB.close(); 

    return 0;
}