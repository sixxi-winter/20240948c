/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <string.h>

int main()
{
    char src[100];
    char dest[100];
    int length;
    
    gets(src);
    
    length = strlen(src);
    printf("length of src = %d\n", length);
    strcpy(dest, src);
    printf("src = %s, dest = %s\n", src, dest);
    strcat(dest, src);
    printf("src = %s, dest = %s\n", src, dest);
    
    
    return 0;
}
