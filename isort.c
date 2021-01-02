#include <stdio.h>

#define ARR_SIZE 50

void shift_element(int *arr, int i) {
    if (arr == NULL) {
        return;
    }

    for (int j = i; j > 0; j--) {
        *(arr + j) = *(arr + j - 1);
    }
}

void insertion_sort(int *arr, int len) {
    if (arr == NULL) {
        return;
    }

    for (int i = 1; i < len; i++) {
        for (int j = 0; j < i; j++) {
            if (*(arr + i) < *(arr + j)) {
                int e = *(arr + i);
                shift_element(arr + j, i - j);
                *(arr + j) = e;
                break;
            }
        }
    }
}

int main() {
    int arr[ARR_SIZE];
    for (int i = 0; i < ARR_SIZE; i++) {
        if (scanf(" %d", arr + i) != 1) {
            char s[1000];
            scanf("%s", s);
            printf("Error wrong input %d : %s", i, s);
            return 1;
        }
    }

    insertion_sort(arr, ARR_SIZE);
    printf("%d", *arr);
    for (int i = 0; i < ARR_SIZE; i++) {
        printf(",%d", *(arr + i));
    }
    printf("\n");
    return 0;
}