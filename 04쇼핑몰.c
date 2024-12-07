/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50

void input_stock(int num, int store[]);
void sell_products(int num, int store[], int sale[]);
void show_status(int num, int store[], int sale[], char product_names[][MAX_NAME_LENGTH]);
void input_product_names(int num, char product_names[][MAX_NAME_LENGTH]);

int main() {
    int store[MAX_PRODUCTS] = {0};
    int sale[MAX_PRODUCTS] = {0};
    char product_names[MAX_PRODUCTS][MAX_NAME_LENGTH] = {""};
    int num = 5; // 초기 상품 개수
    int choice;

    printf("[쇼핑몰 관리 프로그램]\n");

    while (1) {
        printf("\n> 원하는 메뉴를 선택하세요. (1. 입고, 2. 판매, 3. 상품현황, 4. 상품명 입력, 5. 종료): ");
        if (scanf("%d", &choice) != 1) {
            printf("잘못된 입력입니다. 프로그램을 종료합니다.\n");
            break;
        }

        switch (choice) {
            case 1:
                input_stock(num, store);
                break;
            case 2:
                sell_products(num, store, sale);
                break;
            case 3:
                show_status(num, store, sale, product_names);
                break;
            case 4:
                input_product_names(num, product_names);
                break;
            case 5:
                printf("프로그램을 종료합니다.\n");
                return 0;
            default:
                printf("잘못된 옵션입니다. 1에서 5 사이의 숫자를 선택하세요.\n");
        }
    }

    return 0;
}

void input_stock(int num, int store[]) {
    int option, id, quantity;
    printf("\n> 입고 옵션을 선택하세요. (1. 전체 상품, 2. 개별 상품): ");
    if (scanf("%d", &option) != 1) {
        printf("잘못된 입력입니다. 메뉴로 돌아갑니다.\n");
        return;
    }

    if (option == 1) {
        printf("전체 상품의 입고 수량을 입력하세요: ");
        for (int i = 0; i < num; i++) {
            if (scanf("%d", &store[i]) != 1) {
                printf("잘못된 입력입니다. 메뉴로 돌아갑니다.\n");
                return;
            }
        }
    } else if (option == 2) {
        printf("상품 ID를 입력하세요: ");
        if (scanf("%d", &id) != 1 || id < 1 || id > num) {
            printf("잘못된 상품 ID입니다. 메뉴로 돌아갑니다.\n");
            return;
        }
        printf("상품 ID %d의 입고 수량을 입력하세요: ", id);
        if (scanf("%d", &quantity) != 1 || quantity < 0) {
            printf("잘못된 수량입니다. 메뉴로 돌아갑니다.\n");
            return;
        }
        store[id - 1] += quantity;
    } else {
        printf("잘못된 옵션입니다. 메뉴로 돌아갑니다.\n");
    }
}

void sell_products(int num, int store[], int sale[]) {
    int option, id, quantity;
    printf("\n> 판매 옵션을 선택하세요. (1. 전체 상품, 2. 개별 상품): ");
    if (scanf("%d", &option) != 1) {
        printf("잘못된 입력입니다. 메뉴로 돌아갑니다.\n");
        return;
    }

    if (option == 1) {
        printf("전체 상품의 판매 수량을 입력하세요: ");
        for (int i = 0; i < num; i++) {
            if (scanf("%d", &quantity) != 1 || quantity < 0 || quantity > store[i]) {
                printf("상품 ID %d의 입력이 잘못되었거나 재고가 부족합니다. 메뉴로 돌아갑니다.\n", i + 1);
                return;
            }
            store[i] -= quantity;
            sale[i] += quantity;
        }
    } else if (option == 2) {
        printf("상품 ID를 입력하세요: ");
        if (scanf("%d", &id) != 1 || id < 1 || id > num) {
            printf("잘못된 상품 ID입니다. 메뉴로 돌아갑니다.\n");
            return;
        }
        printf("상품 ID %d의 판매 수량을 입력하세요: ", id);
        if (scanf("%d", &quantity) != 1 || quantity < 0 || quantity > store[id - 1]) {
            printf("잘못된 수량이거나 재고가 부족합니다. 메뉴로 돌아갑니다.\n");
            return;
        }
        store[id - 1] -= quantity;
        sale[id - 1] += quantity;
    } else {
        printf("잘못된 옵션입니다. 메뉴로 돌아갑니다.\n");
    }
}

void show_status(int num, int store[], int sale[], char product_names[][MAX_NAME_LENGTH]) {
    int total_sales = 0;
    float sales_rate;
    int max_sales = 0, max_sales_id = 0;
    int min_sales = 0, min_sales_id = 0;

    printf("\n재고 수량: ");
    for (int i = 0; i < num; i++) {
        printf("%d ", store[i]);
    }

    printf("\n총 판매량: ");
    for (int i = 0; i < num; i++) {
        total_sales += sale[i];
        if (i == 0 || sale[i] > max_sales) {
            max_sales = sale[i];
            max_sales_id = i + 1;
        }
        if (i == 0 || sale[i] < min_sales) {
            min_sales = sale[i];
            min_sales_id = i + 1;
        }
    }

    int total_stock = 0;
    for (int i = 0; i < num; i++) {
        total_stock += sale[i] + store[i];
    }

    sales_rate = (total_stock > 0) ? ((float)total_sales / total_stock) * 100 : 0;

    printf("\n총 판매량: %d (판매율: %.2f%%)\n", total_sales, sales_rate);
    printf("가장 많이 판매된 상품: ID %d, 상품명: %s, 판매량: %d\n", max_sales_id, product_names[max_sales_id - 1], max_sales);
    printf("가장 적게 판매된 상품: ID %d, 상품명: %s, 판매량: %d\n", min_sales_id, product_names[min_sales_id - 1], min_sales);

    for (int i = 0; i < num; i++) {
        if (store[i] <= 2) {
            printf("상품 ID %d, 상품명: %s 재고 부족 (%d)\n", i + 1, product_names[i], store[i]);
        }
    }
}

void input_product_names(int num, char product_names[][MAX_NAME_LENGTH]) {
    printf("\n상품명을 입력하세요:\n");
    for (int i = 0; i < num; i++) {
        printf("ID %d 상품명: ", i + 1);
        scanf("%s", product_names[i]);
    }
}

