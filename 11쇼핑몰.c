/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <string.h>
#define MAX_PRODUCTS 5
#define MAX_NAME_LENGTH 50

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    int price;
    int stock;
    int sold;
    int total_sales;
} Product;

void input_stock(Product products[], int *product_count);
void sell_product(Product products[], int product_count);
void show_individual_status(Product products[], int product_count);
void show_all_status(Product products[], int product_count);
void save_product_info(Product products[], int product_count);
void load_product_info(Product products[], int *product_count);

int main() {
    Product products[MAX_PRODUCTS] = {0};
    int product_count = 0;
    int choice;

    printf("[쇼핑몰 관리 프로그램]\n");

    while (1) {
        printf("\n> 원하는 메뉴를 선택하세요. (1. 입고, 2. 판매, 3. 개별현황, 4. 전체현황, 5. 저장, 6. 불러오기, 7. 종료): ");
        if (scanf("%d", &choice) != 1) {
            printf("잘못된 입력입니다. 프로그램을 종료합니다.\n");
            break;
        }

        switch (choice) {
            case 1:
                input_stock(products, &product_count);
                break;
            case 2:
                sell_product(products, product_count);
                break;
            case 3:
                show_individual_status(products, product_count);
                break;
            case 4:
                show_all_status(products, product_count);
                break;
            case 5:
                save_product_info(products, product_count);
                break;
            case 6:
                load_product_info(products, &product_count);
                break;
            case 7:
                printf("프로그램을 종료합니다.\n");
                return 0;
            default:
                printf("잘못된 옵션입니다. 1에서 7 사이의 숫자를 선택하세요.\n");
        }
    }

    return 0;
}

void input_stock(Product products[], int *product_count) {
    if (*product_count >= MAX_PRODUCTS) {
        printf("상품의 최대 개수(%d)를 초과하였습니다.\n", MAX_PRODUCTS);
        return;
    }

    int id, stock, price;
    char name[MAX_NAME_LENGTH];

    printf("\n상품 ID를 입력하세요: ");
    scanf("%d", &id);

    for (int i = 0; i < *product_count; i++) {
        if (products[i].id == id) {
            printf("\n상품명: %s (기존 상품)\n", products[i].name);
            printf("입고량: ");
            scanf("%d", &stock);
            products[i].stock += stock;
            printf("입고가 완료되었습니다.\n");
            return;
        }
    }

    printf("\n상품명을 입력하세요: ");
    scanf("%s", name);
    printf("판매가격을 입력하세요: ");
    scanf("%d", &price);
    printf("입고량을 입력하세요: ");
    scanf("%d", &stock);

    products[*product_count].id = id;
    strcpy(products[*product_count].name, name);
    products[*product_count].price = price;
    products[*product_count].stock = stock;
    products[*product_count].sold = 0;
    products[*product_count].total_sales = 0;
    (*product_count)++;

    printf("상품이 추가되었습니다.\n");
}

void sell_product(Product products[], int product_count) {
    int id, quantity;

    printf("\n상품 ID를 입력하세요: ");
    scanf("%d", &id);

    for (int i = 0; i < product_count; i++) {
        if (products[i].id == id) {
            printf("\n판매량을 입력하세요: ");
            scanf("%d", &quantity);

            if (quantity > products[i].stock) {
                printf("재고가 부족합니다. 현재 재고: %d\n", products[i].stock);
                return;
            }

            products[i].stock -= quantity;
            products[i].sold += quantity;
            products[i].total_sales += quantity * products[i].price;
            printf("판매가 완료되었습니다.\n");
            return;
        }
    }

    printf("상품 ID를 찾을 수 없습니다.\n");
}

void show_individual_status(Product products[], int product_count) {
    int id;

    printf("\n상품 ID를 입력하세요: ");
    scanf("%d", &id);

    for (int i = 0; i < product_count; i++) {
        if (products[i].id == id) {
            printf("\n상품 ID: %d\n상품명: %s\n가격: %d\n재고: %d\n판매량: %d\n총 판매금액: %d\n",
                   products[i].id, products[i].name, products[i].price, products[i].stock, products[i].sold, products[i].total_sales);
            return;
        }
    }

    printf("상품 ID를 찾을 수 없습니다.\n");
}

void show_all_status(Product products[], int product_count) {
    int total_sales = 0, total_stock = 0, total_sold = 0;

    printf("\n전체 상품 정보:\n");
    for (int i = 0; i < product_count; i++) {
        printf("상품 ID: %d, 상품명: %s, 가격: %d, 재고: %d, 판매량: %d, 총 판매금액: %d\n",
               products[i].id, products[i].name, products[i].price, products[i].stock, products[i].sold, products[i].total_sales);
        total_sales += products[i].total_sales;
        total_stock += products[i].stock;
        total_sold += products[i].sold;
    }

    printf("\n전체 판매금액: %d\n전체 재고: %d\n전체 판매량: %d\n", total_sales, total_stock, total_sold);
}

void save_product_info(Product products[], int product_count) {
    FILE *file = fopen("products.dat", "wb");
    if (!file) {
        printf("상품 정보를 저장하는 데 실패했습니다.\n");
        return;
    }

    fwrite(&product_count, sizeof(int), 1, file);
    fwrite(products, sizeof(Product), product_count, file);

    fclose(file);
    printf("상품 정보가 저장되었습니다.\n");
}

void load_product_info(Product products[], int *product_count) {
    FILE *file = fopen("products.dat", "rb");
    if (!file) {
        printf("저장된 상품 정보를 찾을 수 없습니다.\n");
        return;
    }

    fread(product_count, sizeof(int), 1, file);
    fread(products, sizeof(Product), *product_count, file);

    fclose(file);
    printf("상품 정보를 불러왔습니다.\n");
}

