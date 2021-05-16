#include <iostream> 
using namespace std; 

struct Distance{
    int feet; 
    int inch; 
}; 

int main(){
    Distance d; 
    //pointer to distance variable 
    Distance* ptr; 
    d.feet = 8; 
    d.inch = 6; 

    //store address of d in p 
    ptr = &d; 
    cout << "Distance = " << ptr -> feet << " ft " << ptr -> inch << " inches." << endl; 
    return 0; 
}

//ouput 
//Distance = 8 ft 6 inches. 