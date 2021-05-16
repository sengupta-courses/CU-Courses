#include <iostream>
#include <string> 
#include <vector>
#include <fstream>
#include <chrono>
#include <unistd.h>
#include <thread>
#include "fpList.hpp"
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

    float insertListdataA[400];
    float searchListdataA[400];
    float insertListdataB[400];
    float searchListdataB[400];

    LinkedList ListA;
    LinkedList ListB;
    int insertListCounter = 0;
    int tempInsertVal = 0;

    //LINKED LIST INSERT TIME COMPLEXITY
    for (int a = 0; a < 400; a++)
    {
        int tempTimeA = 0;
        int tempTimeB = 0;
        for (int i = tempInsertVal; i < (tempInsertVal + 100); i++)
        {
            using namespace std::chrono;
        
            auto start = steady_clock::now();

            ListA.insertList(testDataA[i]);
            
            auto end = steady_clock::now();

            tempTimeA = tempTimeA + duration_cast<nanoseconds>(end - start).count();

            auto start1 = steady_clock::now();

            ListB.insertList(testDataB[i]);

            auto end1 = steady_clock::now();

            tempTimeB = tempTimeB + duration_cast<nanoseconds>(end1 - start1).count();
        }

        //cout << tempTime/100 << endl;

        tempInsertVal += 100;
        insertListdataA[insertListCounter] = tempTimeA/100;
        insertListdataB[insertListCounter] = tempTimeB/100;
        insertListCounter++;
    }

    cout << insertListdataA[0] << endl;
    cout << insertListdataA[399] << endl;

    cout << insertListdataB[0] << endl;
    cout << insertListdataB[399] << endl;

    //ListA.displayList();
    //ListA.getHead();

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

            ListA.searchList(testDataA[x]);

            auto end = steady_clock::now();

            tempTimeA = tempTimeA + duration_cast<nanoseconds>(end - start).count();

            auto start1 = steady_clock::now();

            ListB.searchList(testDataB[x]);

            auto end1 = steady_clock::now();

            tempTimeB = tempTimeB + duration_cast<nanoseconds>(end1 - start1).count();
        }

        //cout << tempTime/100 << endl;

        tempSearchVal += 100;
        searchListdataA[searchListCounter] = tempTimeA/100;
        searchListdataB[searchListCounter] = tempTimeB/100;
        searchListCounter++; 
    }

    cout << searchListdataA[0] << endl;
    cout << searchListdataA[399] << endl;

    cout << searchListdataB[0] << endl;
    cout << searchListdataB[399] << endl;

    ofstream LinkedListA;
    LinkedListA.open("LinkedListA.txt");
    for (int i = 0; i < 400; i++)
    {
        LinkedListA << i << "," << insertListdataA[i] << "," << searchListdataA[i] << endl;
    }
    LinkedListA.close();

    ofstream LinkedListB;
    LinkedListB.open("LinkedListB.txt");
    for (int i = 0; i < 400; i++)
    {
        LinkedListB << i << "," << insertListdataB[i] << "," << searchListdataB[i] << endl;
    }
    LinkedListB.close();

    return 0;
}