#include <iostream>
using namespace std; 

void add2(int &num){
    num = num + 2; 
}

int main(){
    int a = 10; 
    add2(a); 
    cout << a << endl; 
}

//output 
//12