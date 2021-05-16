// #include<iostream> 

// struct Distance {
//     int feet; 
//     int inch; 
// }; 

// int main() {
//     Distance d; 
//     d.feet = 10; 
//     d.inch = 5; 

//     Distance* ptr2; 
//     ptr2 = &d; 

//     std::cout << "Distance = " << (*ptr2).feet << " ft" << std:: endl; 

//     return 0; 
// }

// #include <iostream> 
// using namespace std; 
// void swap0(int* ptr1, int* ptr2){
//     int *temp; 
//     temp = ptr1; 
//     ptr1 = ptr2; 
//     ptr2 = temp; 
// }

// void swap1(int ptr1, int ptr2){
//     int temp; 
//     temp = ptr1; 
//     ptr1 = ptr2; 
//     ptr2 = temp; 
// }

// void swap2(int *&ptr1, int *&ptr2){
//     int* temp; 
//     temp = ptr1; 
//     ptr1 = ptr2; 
//     ptr2 = temp; 
// }

// void swap3(int &ptr1, int &ptr2){
//     int temp; 
//     temp = ptr1; 
//     ptr1 = ptr2; 
//     ptr2 = temp;
// }

// int main(){
    
//     int *ptr1 = new int[5]; 
//     int *ptr2 = new int[5]; 

//     for(int i = 0; i < 5; i++){
//         ptr1[i] = i; 
//     }
    
//     for (int i = 0; i < 5; i++){
//         ptr2[i] = 4 - i; 
//     }

//     for(int i = 0; i < 5; i++){
//         cout << ptr1[i] << " "; 
//     }
//     cout << endl; 

//     swap0(ptr1, ptr2);
//     swap1(*ptr1, *ptr2);
//     swap2(ptr1, ptr2);
//     swap3(*ptr1, *ptr2);

//     for(int i = 0; i < 5; i++){
//         cout << ptr1[i] << " "; 
//     }
//     return 0; 
// }

// #include<iostream> 

// using namespace std; 

// int main(){
//     int x = 5; 
//     int &y = x; 
//     int *z = &y; 

//     x = 20; 
//     y = 15; 
//     *z = 10; 

//     cout << x << ", " << y << endl; 
// }

#include <iostream> 

using namespace std; 

int main(){
    int a[] = {5, 4, 3, 2, 1}; 

    int* ptr = (int*)(a+4); 
    cout << *a+1 << ", " << *(ptr-1) << endl; 
}