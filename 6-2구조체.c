/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <math.h>

struct point{
    int x;
    int y;
};

double dist(struct point p1, struct point p2){
    double distance;
    return sqrt(pow((p2.x - p1.x),2) + pow((p2.y - p1.y),2));
}

int main()
{
    struct point p1 = {10, 20};
    struct point p2;
  
    p1.x = 20;
    p2.x = 30;
    p2.y = 40;
  
    printf("p1.x = %d p1.y = %d\n", p1.x, p1.y);
    printf("p2.x = %d p2.y = %d\n", p2.x, p2.y);
   
    printf("distance of p1, p2 = %lf", dist(p1, p2) );

    return 0;
}
