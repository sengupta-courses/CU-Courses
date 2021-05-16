#include <iostream> 

using namespace std; 

bool append(string* &str_arr, string s, int &numEntries, int &arraySize){
    bool dub = false; 
    int i = 0; 
    int newCap = 0; 
    if(numEntries>arraySize){
        newCap = 2*arraySize; 

        string* newArr; 
        newArr = new string[newCap]; 
        for(i = 0; i < arraySize; i++){
            newArr[i] = str_arr[i]; 
        }

        delete [] str_arr; 

        arraySize = newCap; 
        dub = true; 
    }
    else{
        s = *(str_arr + numEntries); 
        dub = false; 
    }
    
    return dub; 
}