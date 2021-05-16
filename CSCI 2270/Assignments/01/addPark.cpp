// Overview:​ In this question, you will write a program that:
// 1. Reads a ​“.csv” file with up to 100 lines and columns containing information on national
// parks.
// 2. Stores the information in an array of structs.
// 3. Writes the lines into the ​output ​.csv file where the area of the park is within a range
// specified by the lower bound and upper bound.
// 4. Prints the content of the entire array.

// Specifics:
// Create an array that holds the ​Park struct objects​. Use the following struct declaration:
// 2A​. Write a function named ​addPark:
// i. The ​addPark​ function has the following declaration:
// ii. Instantiate a struct and store the​ parkname, state​, and ​area ​values in it. iii. Add the struct to the ​parks ​array.

// 2B​. Write a function named ​printList:
// i. The​ printList​ function has the following signature:
// ii. Loop through the ​parks​ array.
// iii. Print out each element of the ​parks​ array in the following format.
// “<PARKNAME> [<STATE>] area: <AREA>” using the below cout statement std::​cout << park.parkname <<" [" << park.state << "] area: "<< park.area << std::endl;

// 2C​. ​Write a ​complete program​ which includes the following:​
// I. The ​park​ ​struct and the ​addPark, printList ​functions coded above.
// II. A ​main()​ function defined as below:
// 1. Your ​main() ​should handle ​four command line arguments​: the name of the
// input “​.csv” file​, the name of the ​output “​.csv” file​, a ​lower bound of area ​and
// an upper bound of area ​respectively​.
// 2. Input and output files need to be stored in the same directory as your program.
// 3. Read from the input file, “​park.csv​” :
// a. Each line of the file can be read using ​getline ​function.
// b. Parse each line using ​stringstream and convert each entry into its appropriate data type. ​parkname should be a string, ​state ​should be a string, and ​area ​should be an integer. ​(Hint: Use s​ toi, stof functions to
// convert from strings to numbers)
// c. Call ​addPark​ function to update the ​parks​ array.
// 4. Call the ​printList ​function after the array has been filled with data.
// 5. Writing out to external files in C++ can be done very similarly as reading in.
// Instead of using an object of the ​ifstream class, as is done with input streams, use an object of the ​ofstream c​ lass. A “csv” stands for comma separated values. Write into ​output​ ​“.csv”​ file:
// a. Write the <parkname>, <state>, <area> of the parks, whose
// <area> >= ​lower_bound and <area> <= ​upper_bound ​(read from command line) into the ​output “.csv”​ file.
// b. You should not sort them while writing to output file. The relative order will be same as input file. Only those park with area within the bound should be written in the output file.
// 6. Make sure your program closes the output file when it is finished writing.


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std; 

#define MAX 100 

struct Park{
    string parkname; 
    string state; 
    int area; 
}; 

void addPark(Park parks[], string parkname, string state, int area, int length); 
void printList(const Park parks[], int length); 


void addPark(Park parks[], string parkname, string state, int area, int length){
    Park park; 
    park.parkname = parkname; 
    park.state = state; 
    park.area = area; 
    parks[length] = park; 
    length++; 
}

void printList(const Park parks[], int length){
    int i = 0; 
    for (int i = 0; i < length-1; i++){
        cout << parks[i]. parkname << " [" << parks[i].state << "]" << " area: " << parks[i].area << endl; 
    }
}

int main(int argc, char *argv[]){
    if (argc != 5){
        return -1; 
    }

    int lower = atoi(argv[3]); 
    int upper = atoi(argv[4]); 

    Park parks[MAX]; 

    int area = 0; 
    int i = 0; 

    ifstream parkFile; 
    parkFile.open(argv[1]); 
    if(parkFile.is_open()){
      string line = " "; 
      string parkname = " "; 
      string state = " "; 
      string tempA = " "; 

      
      
      while(!parkFile.eof()){
          getline(parkFile, line); 
          istringstream ss(line); 

          getline(ss, parkname, ','); 
          getline(ss, state, ','); 
          getline(ss, tempA, ','); 

          area = stoi(tempA); 
          
          addPark(parks, parkname, state, area, i); 
          i++;
      }
    }
    else{
        cout << "Unable to open file" << endl; 
        return -1; 
    }
    parkFile.close(); 
    printList(parks, i); 

    ofstream output; 
    output.open(argv[2]); 
    for(int j = 0; j < i-1; j++){
        if(parks[j].area > lower && parks[j].area < upper){
            output << parks[j].parkname << "," << parks[j].state << "," << parks[j].area << endl; 
        }
    }
    output.close(); 
    return 0; 
}