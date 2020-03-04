#include <stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
int main() {
    int size;
    int sum = 0;
    scanf("%d", &size);
    int* arr = (int*)malloc(sizeof(int) * size * size);
    for (int x = 0; x < size; x++) {
        scanf("%d", &arr[x]);
        sum += arr[x];
    }
    int min = 0;
    int TURNON = 0;
    while (TURNON <= sum / 2) {
        min++;
        for (int x = 0; x < size; x++)
            if (arr[x] != 0) {
                arr[x]--;
                TURNON++;
            }
        printf("%d", min);
        return 0;
    }
}