/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdlib.h>
#include <stdio.h>

typedef struct point{
    int x;
    int y;
}POINT;

int inputMenu(void){
    int input;
    printf("메뉴입력(1. 구조체 만들기, 2. 구조체 출력하기, -1. 종료 : ");
    scanf("%d", &input);
    return input;
}

POINT* makePoint(void){
    POINT* p = (POINT*)malloc(sizeof(POINT));
    p -> x = rand() % 100;
    p -> y = rand() % 100;
}

void printPoint(POINT* p[],int size){
    for(int i = 0; i < size; i++)
        printf("x: %d, y: %d\n", p[i] -> x, p[i] -> y);
}

void freePoints(POINT* p[],int size){
    for(int i = 0; i < size; i++)
        free(p[i]);
}

int main()
{
    int menu;
    int count = 0;
    POINT* points[100];
    
    do{
        menu = inputMenu();
        if(menu == 1){
            //구조체 만들기
            points[count] = makePoint();
            count++;
            printf("잘 만들었습니다.\n");
        }
        else if(menu ==2){
            //구조체 출력
            printPoint(points,count);
        }
        else if(menu == -1){
            freePoints(points,count);
            printf("프로그램을 종료합니다.\n");
        }
    }while(menu > 0);
    
    return 0;
}