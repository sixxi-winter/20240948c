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

    printf("��ǰ ����(����)�Է�: ");
    scanf_s("%d", &type);
    printf("��ǰ �� �԰���� �Է�: ");
    for (int i = 0; i < type; i++)
    {
        scanf_s("%d", &receive);
        total_receive[i] = receive;
    }
    printf("��ǰ �� �Ǹż��� �Է�: ");
    for (int j = 0; j < type; j++)
    {
        scanf_s("%d", &sale);
        total_sale[j] = sale;
    }

    printf("��� ����: ");
    for (int k = 0; k < type; k++)
    {
        printf("%d ", total_receive[k] - total_sale[k]);
    }
    printf("\n�� �Ǹŷ�: ");
    for (int i = 0; i < type; i++)
    {
        total += total_sale[i];
        sum_receive += total_receive[i];
    }
    printf("%d (�Ǹ��� %.2f%%)\n", total, ((double)total / sum_receive) * 100);
    printf("���� ���� �Ǹŵ� ��ǰ: ID ");
    for (int i = 0; i < type; i++)
    {
        if (most < total_sale[i])
        {
            most = total_sale[i];
            id = i + 1;
        }
    }
    printf("%d, �Ǹŷ� %d\n", id, most);
    printf("���� ���� �Ǹŵ� ��ǰ: ID ");
    min = total_sale[0];
    for (int i = 0; i < type; i++)
    {
        if (min > total_sale[i])
        {
            min = total_sale[i];
            id = i + 1;
        }
    }
    printf("%d, �Ǹŷ� %d\n", id, min);
    for (int i = 0; i < type; i++)
    {
        if (total_receive[i] - total_sale[i] <= 2)
        {
            printf("��ǰ ID %d: ������(%d)\n", i + 1, total_receive[i] - total_sale[i]);
        }
    }

    return 0;
}