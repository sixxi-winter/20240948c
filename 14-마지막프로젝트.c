/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define WORD    16

// 입력받은 10진수 문자열을 2진수로 변환하여 bin에 저장
void getBinary(char bin[], char str[], int n) {
    int num = atoi(str);  // 입력받은 문자열을 10진수 정수로 변환
    for (int i = n - 1; i >= 0; i--) {
        bin[i] = (num % 2) + '0';
        num /= 2;
    }
    bin[n] = '\0';  // 문자열 종료 문자 추가
}

// 2진수 보수화
void complement2(char bin[], int n) {
    // 2의 보수화를 위해 1의 보수를 구한 후 1을 더함
    int carry = 1;
    for (int i = n - 1; i >= 0; i--) {
        if (bin[i] == '1') {
            bin[i] = (carry == 1) ? '0' : '1';
        } else {
            bin[i] = (carry == 1) ? '1' : '0';
            carry = 0;
        }
    }
}

// 2진수를 10진수로 변환
int bin2dec(char bin[], int n) {
    int num = 0;
    int sign = 1;
    
    if (bin[0] == '1') {  // 음수인 경우
        sign = -1;
        complement2(bin, n);
    }

    for (int i = 0; i < n; i++) {
        num = num * 2 + (bin[i] - '0');
    }
    
    return sign * num;
}

int main() {
    char input1[100];
    char input2[100];
    char op[10];
    
    char binary1[WORD + 1] = {0};
    char binary2[WORD + 1] = {0};
    
    int result;
    int num1, num2;
    
    printf("<<<<<<input>>>>>>>");
    
    // 안전한 입력 처리를 위해 fgets 사용
    printf("첫 번째 숫자를 입력하세요: ");
    fgets(input1, sizeof(input1), stdin);
    input1[strcspn(input1, "\n")] = '\0'; // 개행 문자 제거

    printf("연산자를 입력하세요: ");
    fgets(op, sizeof(op), stdin);
    op[strcspn(op, "\n")] = '\0'; // 개행 문자 제거

    printf("두 번째 숫자를 입력하세요: ");
    fgets(input2, sizeof(input2), stdin);
    input2[strcspn(input2, "\n")] = '\0'; // 개행 문자 제거
    
    getBinary(binary1, input1, WORD);
    getBinary(binary2, input2, WORD);
    
    num1 = bin2dec(binary1, WORD);
    num2 = bin2dec(binary2, WORD);
    
    switch(op[0]) {
        case '+': result = num1 + num2; break;
        case '-': result = num1 - num2; break;
        case '*': result = num1 * num2; break;
        case '/': 
            if (num2 == 0) {
                printf("Division by zero is not allowed.\n");
                return 1;
            }
            result = num1 / num2; 
            break;
        case '%': 
            if (num2 == 0) {
                printf("Modulo by zero is not allowed.\n");
                return 1;
            }
            result = num1 % num2; 
            break;
        default: 
            printf("bad operator...\n"); 
            return 1;
    }
    
    printf("%s(%d) %c %s(%d) = %d\n", binary1, num1, op[0], binary2, num2, result);
    return 0;
}