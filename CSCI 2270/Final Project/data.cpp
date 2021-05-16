#include <iostream> 
#include <fstream> 

using namespace std; 

int main(){
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

    ofstream listA; 
    listA.open("dataA.csv"); 
    for(int i = 0; i < 40001; i++){
        listA << i << ", " << testDataA[i] << endl; 
        i = i+99; 
    }

    listA.close(); 

    ofstream listB; 
    listB.open("dataB.csv"); 
    for(int i = 0; i < 40001; i++){
        listB<< i << ", " << testDataB[i] << endl; 
        i = i+99; 
    }

    listB.close(); 

    return 0;
}