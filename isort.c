#include <stdio.h>

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
    int arr[] = {5, 4, 3, 3, 1, 4, 11, 30, 1, 2, 99, 0, 3, 11, 4, 5, 1};
    int arr_size = sizeof(arr) / sizeof(int);
    printf("%d\n", arr_size);
    insertion_sort(arr, arr_size);
    for (int i = 0; i < arr_size; i++) {
        printf("%d ,", arr[i]);
    }
    printf("\n");
    return 0;
}