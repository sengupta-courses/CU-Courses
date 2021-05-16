#include <iostream>
using namespace std; 

void add2(int *a, int len){
    for(int i = 0; i < len; i++){
        a[i] += 2; 
    }
}

int main(){
    int a[] = { 1, 2, 3}; 
    add2(&a[0], 3); 
    for(int j = 0; j < 3; j++){
        cout << a[j] << endl;
    }
}

//output 
//3
//4
//5