#include <stdio.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>

int main(){

	long int amma = syscall(333); 
	printf("System call sys_helloworld returned %d \n", amma); 
	return 0; 
}
