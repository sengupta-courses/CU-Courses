#include <stdio.h>
#include <linux/kernel.h>
#include <syscall.h>
#include <unistd.h>

int main()
{

	int number1 = 5; 
	int number2 = 3; 
	int result; 
	
	syscall(334, number1, number2, &result); 

	printf("num1 + num2 = %d \n", result); 

	return 0; 
}
