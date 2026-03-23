#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100000

int stack[MAX_SIZE];
int top = -1;
char string[MAX_SIZE * 2 + 1];
int stringCount = 0;

void push(int value) {
    stack[++top] = value;
    string[stringCount++] = '+';
}
int pop() {
    string[stringCount++] = '-';
    return stack[top--];
}

int main(void) {
    int N;
    scanf("%d", &N);

    int num;
    int count = 0;
    for (int i = 0; i < N; i++) {
        scanf("%d", &num);

        while (count < num) {
            push(++count);
        }
        if (stack[top] < num) {printf("NO"); return 0;}
        else {
            pop();
        }
    }

    for (int i =0;i<stringCount;i++) {
        printf("%c\n", string[i]);
    }

    return 0;
}