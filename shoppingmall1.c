#include <stdio.h>

int main(){

    int type;
    int receive[5];
    int sale[5];
    int id;

    printf("상품 개수(종류) 입력: ");
    scanf_s("%d", &type);
    printf("상품 별 입고수량 입력: ");
    for (int i = 0; i < type; i++) {
        scanf_s("%d", &receive[i]);
    }
    printf("상품 별 판매수량 입력: ");
    for (int i = 0; i < type; i++) {
        scanf_s("%d", &sale[i]);
    }
    printf("ID 입력: ");
    scanf_s("%d", &id);
    printf("%d \n", receive[id] - sale[id]);
    for (int i = 0; i < type; i++) {
        printf("%d ", receive[i] - sale[i]);
    }
    return 0;
}