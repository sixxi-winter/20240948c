/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct point{
    int x;
    int y;
}POINT;

int inputMenu(void){
    int input;
    printf("메뉴입력(1. 구조체 만들기, 2. 구조체 출력하기) : ");
    scanf("%d", &input);
    return input;
}

int main()
{
    int menu;
    
    do{
        menu = inputMenu();
        if(menu == 1){
            //구조체 만들기
        }
        else if(menu == 2){
            //구조체 출력하기
        }
        else if(menu == -1){
            printf("프로그램을 종료합니다.\n");
        }
    }while(menu > 0);

    return 0;
}

/*
POINT* points;
    int count;
    scanf("%d", &count);
    
    points = (POINT*)malloc(sizeof(POINT) * count);
    
    for(int i=0; i < count; i++){
        points[i].x = rand() % 100;
        points[i].y = rand() % 100;
    }
    
    for(int i=0; i < count; i++){
        printf("x - %d, y - %d\n", points[i].x, points[i].y);
    }
    
    free(points);
    */
