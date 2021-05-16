#include <iostream>
using namespace std; 

int main(){
    int a = 10; 

    //p is a pointer variable 
    int *p = &a; 
    cout << a << endl; 
    cout << p << endl; 

    //* is used to dereference p 
    cout << *p << endl; 
    return 0; 
}

//output 
//10 
//0x7ffccbbcd804
//10