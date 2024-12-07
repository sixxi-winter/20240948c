/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

#define MAX_PRODUCTS 100

void input_stock(int num, int store[]);
void sell_products(int num, int store[], int sale[]);
void show_status(int num, int store[], int sale[]);

int main() {
    int store[MAX_PRODUCTS] = {0};
    int sale[MAX_PRODUCTS] = {0};
    int num = 5; // 초기 상품 개수
    int choice;

    printf("[쇼핑몰 관리 프로그램]\n");

    while (1) {
        printf("\n> 원하는 메뉴를 선택하세요 (1. 입고, 2. 판매, 3. 상품현황, 4. 종료): ");
        if (scanf("%d", &choice) != 1) {
            printf("잘못된 입력입니다. 종료합니다.\n");
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
                show_status(num, store, sale);
                break;
            case 4:
                printf("프로그램을 종료합니다.\n");
                return 0;
            default:
                printf("잘못된 선택입니다. 1에서 4 사이의 번호를 입력하세요.\n");
        }
    }

    return 0;
}

void input_stock(int num, int store[]) {
    int option, id, quantity;
    printf("\n> 입고 옵션을 선택하세요 (1. 전체 상품 입력, 2. 개별 상품 입력): ");
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
            printf("유효하지 않은 상품 ID입니다. 메뉴로 돌아갑니다.\n");
            return;
        }
        printf("상품 ID %d의 입고 수량을 입력하세요: ", id);
        if (scanf("%d", &quantity) != 1 || quantity < 0) {
            printf("유효하지 않은 수량입니다. 메뉴로 돌아갑니다.\n");
            return;
        }
        store[id - 1] += quantity;
    } else {
        printf("잘못된 선택입니다. 메뉴로 돌아갑니다.\n");
    }
}

void sell_products(int num, int store[], int sale[]) {
    int option, id, quantity;
    printf("\n> 판매 옵션을 선택하세요 (1. 전체 상품 입력, 2. 개별 상품 입력): ");
    if (scanf("%d", &option) != 1) {
        printf("잘못된 입력입니다. 메뉴로 돌아갑니다.\n");
        return;
    }

    if (option == 1) {
        printf("전체 상품의 판매 수량을 입력하세요: ");
        for (int i = 0; i < num; i++) {
            if (scanf("%d", &quantity) != 1 || quantity < 0 || quantity > store[i]) {
                printf("유효하지 않은 입력이거나 상품 ID %d의 재고 부족입니다. 메뉴로 돌아갑니다.\n", i + 1);
                return;
            }
            store[i] -= quantity;
            sale[i] += quantity;
        }
    } else if (option == 2) {
        printf("상품 ID를 입력하세요: ");
        if (scanf("%d", &id) != 1 || id < 1 || id > num) {
            printf("유효하지 않은 상품 ID입니다. 메뉴로 돌아갑니다.\n");
            return;
        }
        printf("상품 ID %d의 판매 수량을 입력하세요: ", id);
        if (scanf("%d", &quantity) != 1 || quantity < 0 || quantity > store[id - 1]) {
            printf("유효하지 않은 수량이거나 재고 부족입니다. 메뉴로 돌아갑니다.\n");
            return;
        }
        store[id - 1] -= quantity;
        sale[id - 1] += quantity;
    } else {
        printf("잘못된 선택입니다. 메뉴로 돌아갑니다.\n");
    }
}

void show_status(int num, int store[], int sale[]) {
    int total_sales = 0;
    float sales_rate;
    int max_sales = 0, max_sales_id = 0;
    int min_sales = 0, min_sales_id = 0;

    printf("\n현재 재고: ");
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
    printf("가장 많이 판매된 상품: ID %d, 판매량: %d\n", max_sales_id, max_sales);
    printf("가장 적게 판매된 상품: ID %d, 판매량: %d\n", min_sales_id, min_sales);

    for (int i = 0; i < num; i++) {
        if (store[i] <= 2) {
            printf("상품 ID %d: 재고 부족 (%d)\n", i + 1, store[i]);
        }
    }
}
