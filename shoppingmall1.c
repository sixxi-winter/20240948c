#include <stdio.h>

int main(){

    int type;
    int receive[100];
    int sale[100];
    int id;

    printf("��ǰ ����(����) �Է�: ");
    scanf_s("%d", &type);
    printf("��ǰ �� �԰���� �Է�: ");
    for (int i = 0; i < type; i++) {
        scanf_s("%d", &receive[i]);
    }
    printf("��ǰ �� �Ǹż��� �Է�: ");
    for (int i = 0; i < type; i++) {
        scanf_s("%d", &sale[i]);
    }
    printf("ID �Է�: ");
    scanf_s("%d", &id);
    printf("�Է��� ID�� �ش��ϴ� ��ǰ�� ��� ����: %d \n", receive[id] - sale[id]);
    printf("��� ��ǰ�� ��� ����: ");
    for (int i = 0; i < type; i++) {
        printf("%d ", receive[i] - sale[i]);
    }
    return 0;
}