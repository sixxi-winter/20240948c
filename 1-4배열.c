/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 100
int main() 
{
	int number[SIZE];
	int temp;
	srand(time(NULL)); 
	
	for (int i = 0; i < SIZE; i++) {
		number[i] = (rand()%10000)+1;
	}
	
	for (int i = 0; i < SIZE-1; i++){
	    for (int j = 0; j < SIZE-i-1; j++){
    	    if (number[j]<number[j+1]){
	        temp = number[j];
	        number[j] = number[j+1];
	        number[j+1] = temp;
    	    }
	    }
	}

	for (int i = 0; i < SIZE; i++) {
		printf("%5d\t", number[i]);
		if((i+1)%10==0)printf("\n");
	}
		
	return 0;
}