#include "LLUSPS.hpp"
#include <iostream>
#include <fstream>
#include <chrono>
#include <cstdlib>
using namespace std;
using namespace std::chrono;

int main(){
    //cout<<"entering main"<<endl;
    //array of nums from file
    int trackingNums[40000];
    //float array for time it takes to insert
    float insert[400];
    //search array for time it takes to search
    float search[400];
    string filename = "dataSetA.csv";
    string line;
    ifstream file;
    
    //cout<<"opening file and saving values"<<endl;
    //creating a LL for my tracking numbers
    LLUSPS myList;
    //opening my file 
    file.open(filename);
    //if the file isnt open say so and return bc you can do anthing without a file
    if(!file.is_open()){
        cout<<"FILE NOT OPEN!!!";
        return 1;
    //else loop through every line sep by commas and enter into your dats array
    }else{
        int counter = 0;
        int tempTrackingNum;
        while(getline(file, line, ',')){
            tempTrackingNum = stoi(line);
            trackingNums[counter] = tempTrackingNum;
            counter++;
        }
        file.close();
    }
    //at this point we have entered all of the data in the file



    //THIS PORTION OF CODE ACTUALLY USES THE INSERT AND SEARCH METHODS
    
    //varable to keep track of my index
    int startingIndex = 0;
    //variable to keep track of time array indexes
    int timeIndex = 0;
    //cout<<"before large for loop"<<endl;
    //loop goes to 400 for the 400 sets of data to record
    for(int x = 0; x<400; x++){
        
        //PERFORM INSERT FUNCTIONS
        //start the timer for these 100 elements
        high_resolution_clock::time_point start = high_resolution_clock::now();
        //loop goes for 100 to do 100 tracking nums at a time
        //cout<<"before insert loop"<<endl;
        for(int i = startingIndex; i<(startingIndex+99); i++){
            myList.insert(trackingNums[i]);
        }
        //end the clock
        high_resolution_clock::time_point end = high_resolution_clock::now();
        duration <float>  execTime = duration_cast<microseconds>(end - start);
        insert[timeIndex] = (execTime.count()/100);


        //NOW PERFORM SEARCH FUCTIONS
        //start the timer for these 100 elements
        start = high_resolution_clock::now();
        //loop goes from 0 to how many elements have been inserted
        //cout<<"before search loop"<<endl;
        for(int i = 0; i<(startingIndex+99); i++){
            int randIndex = (rand() % (startingIndex+99));
            //cout<<trackingNums[randIndex]<<endl;
            myList.search(trackingNums[randIndex]);
        }
        //end the clock
        end = high_resolution_clock::now();
        execTime = duration_cast<microseconds>(end - start);
        search[timeIndex] = (execTime.count()/100);

        //incriment starting index by 100
        startingIndex = startingIndex+100;
        timeIndex++;
    }


    //after all of those operations and recording time we need to write out to a file
    ofstream outfile;
    outfile.open("LLTimeDataSetA.csv");

    //go through every index in time arrays
    for(int i = 0; i<400; i++){
        outfile<< i << ", "<<insert[i]<< ", "<<search[i]<<endl;
    }

    outfile.close();
}