#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX 2001

int naturalNum_array[MAX];
int max = 0;

int main(void) {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N + 1; i++) {
        naturalNum_array[i] = -1;
    }

    int a;
    int index = 0;
    int nn = 2 * N;

    for (int i = 0; i < nn; i++) {
        scanf("%d", &a);

        if (naturalNum_array[a] > -1) {
            index = i - naturalNum_array[a] - 1;
            if (max < index) max = index;
        }
        else {
            naturalNum_array[a] = i;
        }
    }

    printf("%d\n", max);
    return 0;
}