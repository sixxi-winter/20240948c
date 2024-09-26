#include <stdio.h>

int main()
{
    int type, receive, sale, ID;
    int total_receive[100];
    int total_sale[100];
    int total = 0;
    int proportion;
    int sum_receive = 0;
    int most = 0;
    int min = 0;
    int id;

    printf("상품 개수(종류)입력: ");
    scanf_s("%d", &type);
    printf("상품 별 입고수량 입력: ");
    for (int i = 0; i < type; i++)
    {
        scanf_s("%d", &receive);
        total_receive[i] = receive;
    }
    printf("상품 별 판매수량 입력: ");
    for (int j = 0; j < type; j++)
    {
        scanf_s("%d", &sale);
        total_sale[j] = sale;
    }

    printf("재고 수량: ");
    for (int k = 0; k < type; k++)
    {
        printf("%d ", total_receive[k] - total_sale[k]);
    }
    printf("\n총 판매량: ");
    for (int i = 0; i < type; i++)
    {
        total += total_sale[i];
        sum_receive += total_receive[i];
    }
    printf("%d (판매율 %.2f%%)\n", total, ((double)total / sum_receive) * 100);
    printf("가장 많이 판매된 상품: ID ");
    for (int i = 0; i < type; i++)
    {
        if (most < total_sale[i])
        {
            most = total_sale[i];
            id = i + 1;
        }
    }
    printf("%d, 판매량 %d\n", id, most);
    printf("가장 적게 판매된 상품: ID ");
    min = total_sale[0];
    for (int i = 0; i < type; i++)
    {
        if (min > total_sale[i])
        {
            min = total_sale[i];
            id = i + 1;
        }
    }
    printf("%d, 판매량 %d\n", id, min);
    for (int i = 0; i < type; i++)
    {
        if (total_receive[i] - total_sale[i] <= 2)
        {
            printf("상품 ID %d: 재고부족(%d)\n", i + 1, total_receive[i] - total_sale[i]);
        }
    }

    return 0;
}