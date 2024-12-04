/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#define SIZE 100
int main()
{
    char input[SIZE];
    FILE* fp = NULL;
    int i = 0;
    
    if((fp = fopen("output.bin", "rb")) == NULL){
        printf("error...");
        
        return 0;
    }
    
    while(!feof(fp)){
        fread(&input[i], sizeof(char), 1, fp);
        i++;
    }
    
    input[--i] = '\0';
    puts(input);
    
    fclose(fp);

    return 0;
}
