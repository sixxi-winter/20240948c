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
    printf("1. 만들기, 2. 출력하기, 3. 클리어, 4. 파일저장, 5. 파일로드, -1. 종료 : ");
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

int saveFile(POINT* p[], int count){
    FILE* fp;
    fp = fopen("points.bin", "ab");
    if(fp == NULL) return 0;
    for(int i = 0; i < count; i++)
        fwrite(p[i], sizeof(POINT), 1, fp);
    fclose(fp);
    return 1;
}

int lodeFile(POINT* p[], int max){
    FILE* fp;
    int fSize, fCount;
    fp = fopen("points.bin", "rb");
    if(fp == NULL) return 0;
    
    fseek(fp, 0, SEEK_END);
    fSize = ftell(fp);
    fCount = fSize / sizeof(POINT);
    rewind(fp);
    
    for(int i = 0; i < fCount; i++){
        if(i == max) break;
        p[i] = (POINT*)malloc(sizeof(POINT));
        fread(p[i], sizeof(POINT), 1, fp);
    }
    fclose(fp);
    return fCount;
}

int main()
{
    int menu;
    int count = 0;
    POINT* points[100];
    
    do{
        menu = inputMenu();
        switch(menu){
            case 1:
                points[count] = makePoint();
                count++;
                break;
            case 2:
                printPoint(points,count);
                break;
            case 3:
                system("clear"); //windows - system("cls")
                break;
            case 4: //file save
                if(!saveFile(points, count)) printf("file open error...\n");
                else printf("File writing success..\n");
                break;
            case 5: //load file
                count = lodeFile(points, 100);
                break;
            case -1:
                freePoints(points,count);
                printf("프로그램을 종료합니다.\n");
                break;
        }
        
    }while(menu > 0);
    
    return 0;
}
