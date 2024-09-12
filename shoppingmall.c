#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_PRODUCTS 100

int main()
{
    int count;
    int stock[MAX_PRODUCTS];
    int id, sold, i;

    do {
        printf("��ǰ ����(����)�Է� (1 ~ 100): ");
        scanf("%d", &count);
    } while (count < 1 || count > 100);

    printf("��ǰ �� �԰���� �Է�: ");
    for (i = 0; i < count; i++) {
        scanf("%d", &stock[i]);
    }

    printf("��ǰ �� �Ǹż����� �Է�: ");
    for (i = 0; i < count; i++) {
        scanf("%d", &sold);
        if (sold <= stock[i]) {
            stock[i] -= sold;
        }
        else {
            printf("�Ǹ� ������ ����� ����. �ִ� �Ǹ� ���� ����: %d\n", stock[i]);
        }
    }

    while (1) {
        printf("��� ������ Ȯ���� ��ǰ ID�� �Է� (1 ~ %d, ����� 0): ", count);
        scanf("%d", &id);

        if (id == 0) {
            break;
        }
        else if (id > 0 && id <= count) {
            printf("��ǰ ID %d�� ���� ��� ����: %d\n", id, stock[id - 1]);
            printf("��� ��ǰ�� ��� ����: ");
            for (i = 0; i < count; i++) {
                printf("%d ", stock[i]);
            }
            printf("\n");
        }
        else {
            printf("�߸��� ID�Դϴ�. �ٽ� �Է�\n");
        }
    }



    return 0;
}