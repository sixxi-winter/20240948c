/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct point{
    int x;
    int y;
}POINT;

POINT makePoint(void){
    POINT p;
    scanf("%d %d", &p.x, &p.y);

    return p;
}

void makeRandomPoints(POINT p[], int size){
    srand(time(NULL));
    for (int i = 0; i < size; i){
        p[i].x = rand() % 100;
        p[i].y = rand() % 100;
    }
}

void printPoints(POINT p[], int size){
    for (int i = 0; i < 10; i++){
        printf("point[%d] = x : %d, y : %d\n", i, p[i].x, p[i].y);
    }
}

void saveFile(POINT p[], int size){
    FILE* fp;
    fp = fopen("struct.bin", "wb");
    if (fp == NULL) exit(-1);
    fwrite(p, sizeof(POINT), size, fp);
    fclose(fp);
}

void loadFile(POINT p[], int size){
    FILE* fp;
    fp = fopen("struct.bin", "rb");
    if (fp == NULL) exit(-1);
    fread(p, sizeof(POINT), size, fp);
    fclose(fp);
}

int main(){
    FILE* fp;
    POINT p[10];
    POINT p2;
    int pi;
    loadFile(p, 10);
    printPoints(p, 10);
    
    fp = fopen("struct.bin", "rb");
    if(fp == NULL) exit(-1);

    fseek(fp, sizeof(POINT)*3, SEEK_SET);
    pi = ftell(fp);
    printf("pi = %d\n", pi);
    fread(&p2, sizeof(POINT), 1, fp);
    printf("p2 -> x : %d, y : %d\n", p2.x, p2.y);
    
    fseek(fp, sizeof(POINT)*-2, SEEK_END);
    printf("pi = %d\n", ftell(fp));
    fread(&p2, sizeof(POINT), 1, fp);
    printf("p2 -> x : %d, y : %d\n", p2.x, p2.y);
    
    fseek(fp, 0, SEEK_END);
    printf("size = %ld\n", ftell(fp));
    
    fclose(fp);
    
    return 0;
}
