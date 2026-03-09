#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_LEN 128

int array[MAX_LEN][MAX_LEN];
int countZero = 0;
int countOne = 0;

void a(int y, int x, int N) {
    //printf("[%d][%d]  크기 : %d\n", y, x, N);
    int mapingValue = array[y][x];

    for (int i = y; i < y + N; i++) {
        for (int j = x; j < x + N; j++) {
            if (mapingValue != array[i][j]) {
                a(y, x, N / 2);
                a(y + N/2, x, N / 2);
                a(y, x + N/2, N / 2);
                a(y + N/2, x + N/2, N / 2);
                return;
            }
        }
    }

    if (mapingValue == 0) {
        countZero++;
    }
    else if (mapingValue == 1) {
        countOne++;
    }
    return;
}

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &array[i][j]);
        }
    }

    a(0, 0, N);

    printf("%d\n", countZero);
    printf("%d", countOne);

    return 0;
}
