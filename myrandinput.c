#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 50

int main() {
    srand(time(0));
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", rand() % 999);
    }
    return 0;
}