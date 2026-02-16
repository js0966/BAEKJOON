#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_LEN 7

int squareOf2[MAX_LEN] = {0, 2, 4, 8, 16, 32, 64};

int main(void) {
    int n;
    scanf("%d", &n);

    if (n <= 2) {
        printf("%d\n", n);
        return 0;
    }

    for (int i = MAX_LEN - 1; i >= 0; i--) {
        if (squareOf2[i] <= n) {
            printf("%d\n", squareOf2[i]);
            break;
        }
    }

    return 0;
}
