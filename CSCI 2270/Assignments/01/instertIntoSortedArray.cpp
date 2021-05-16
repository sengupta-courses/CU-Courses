// 1A.​ ​Write a function called ​insertIntoSortedArray​.
// i. It should take ​three ​arguments -
// a. myArray[ ] :​ ​sorted​ array that should be able to hold at most 100 floats.
// b. numEntries : the number of elements inserted so far.
// c. newValue : the incoming value to be inserted into the sorted array (i.e.
// myArray[]).
// ii. The ​insertIntoSortedArray​ function should return a count of the elements inserted so far (i.e. the current size of the array)
// The function header will appear as follows:
// 1B. ​Write a ​complete program​ to do the following​ :
// i. Reading the file: ​Your program should take a single command line argument i.e. the name of the file where the numbers are present.
// a. This file needs to be stored in the same directory as your program.
// b. The file should store up to 100 numbers on separate lines. For testing you can
// use the file named​ “n​ umbers.txt​”​ on Moodle, or create your own if you prefer.

// ii. In the main function:
// a. Create an array of floats to store at most 100 floats.
// b. Open the file that was passed via the command line
// i. If there is any error in opening the file then print the below statement
// std::cout << “Failed to open the file.” << std::endl;
// c. Use the ​getline​ function to read the integers one by one.
// d. Store these integers in a sorted array by passing them to the
// insertIntoSortedArray​ function (you should use the code from part 1A).
// e. Each time a new number is read, print out the entire array after insertion.

#include <iostream> 
#include <fstream>
#include <sstream>

using namespace std; 

// Pass By Pointer
void swap_by_pointers(int *n1, int *n2) {
  // TODO Complete this function
  int *temp; 
  *temp = *n1; 
  *n1 = *n2; 
  *n2 = *temp; 
};

void sort(float array[], int array_size){
    int i = 0; 
    int j = 0; 
    for(i = 0; i < array_size; i++){
        float *ptr1 = array+i; 
        for(j = 0; j < array_size; j++){
            float *ptr2 = array + j; 
            if(*ptr1 > *ptr2){
                swap(ptr1, ptr2); 
            }
        }
    }
};

int insertIntoSortedArray(float myArray[], int numEntries, float newValue){
    int i = 0; 
    int j = 0; 

    for(i = 0; i < numEntries; i++){
        if(myArray[i] < newValue){
            break; 
        }
    }

    for(j = numEntries; j > i; j--){
        myArray[j] = myArray[j-1]; 
    }

    myArray[i] = newValue; 
    numEntries++; 
    return numEntries; 
}

int main(int argc, char *argv[]){
    string line = " "; 
    int count = 0; 
    float arr[100]; 
    int i = 0; 
    int j = 0; 
    
    for(i = 0; i < 100; i++){
        arr[i] = 0; 
    }
    
    ifstream myFile; 
    myFile.open(argv[1]); 
    
    if(!myFile.is_open()){
        cout << "Failed to open the file." << endl; 
    }
    
    else{
        while(getline(myFile, line)){
            if(line != ""){
                insertIntoSortedArray(arr, count, stof(line)); 
                count++; 
                for(j = 0; j < count; j++){
                    if( j > 0){
                        cout << ","; 
                    }
                    cout << arr[j]; 
                }
                cout << endl; 
            }
        }
    }
    myFile.close(); 
}