/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
   int array[1000];
   FILE* fp;
   int i = 0;
   
   fp = fopen("array.bin", "rb");
   
   if(fp == NULL) return -1;
   
   fread(array, sizeof(int), 100, fp);
  
   for(int i = 0; i < 100; i++) printf("%d ", array[i]);
   
   fclose(fp);

    return 0;
}
