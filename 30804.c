#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_LEN 200000
int array[MAX_LEN];
int fruitSpecies[10];

int SpeciesCount(int N) {
    int count = 0;
    for (int i = 0; i < 10; i++) {
        if (fruitSpecies[i]>0) count++;
        //printf("%d Count :    %d\n", i, fruitSpecies[i]);
    }
    //printf("\n");
    return count;
}

int counting(int N) {
    int sum = 0;
    for (int i = 0; i < 10; i++) {
        sum += fruitSpecies[i];
    }

    return sum;
}

int onlyTwoSpecies(int N) {
    if (N == 1 || N == 2) {
        return N;
    }

    int left = 0;
    int right = 0;
    int max = 0;

    while (N--) {
        fruitSpecies[array[right++]]++;
        if (SpeciesCount(N) > 2) {
            if (counting(N) - 1 > max) {
                max = counting(N) - 1;
            }
            fruitSpecies[array[left++]]--;
        }
    }

    if (counting(N) > max) {
        max = counting(N);
    }
    return max;
}

int main(void) {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &array[i]);
    }

    int answer = onlyTwoSpecies(N);
    printf("%d", answer);

    return 0;
}