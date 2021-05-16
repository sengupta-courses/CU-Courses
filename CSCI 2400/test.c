#include <stdlib.h>

int main(void){
     struct {
        char c[5]; 
        double d[4]; 
        int i[4]; 
    }datum[6]; 


    printf("offset of c[4] is %d", (char *)&datum[4].c[4] - (char *)&datum); 
    printf("offset of d[2] is %d", (char *)&datum[4].d[2] - (char *)&datum); 
    printf("offset of i[3] is %d", (char *)&datum[4].i[1] - (char *)&datum); 
    return 0; 
}