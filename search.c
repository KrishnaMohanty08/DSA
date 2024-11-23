#include <stdio.h>
#include <stdlib.h>

int linearSearch(int* arr, int key, int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int binarySearch(int* arr, int key, int size) {
    int start = 0, end = size - 1;

    while (start <= end) {
        int mid = (start + end) / 2;
        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return -1;
}

int main() {
    int *arr = (int*)malloc(20 * sizeof(int));
    int key;
    printf("Enter a key: ");
    scanf("%d", &key);
   
    for (int i = 0; i < 20; i++) {
        arr[i] = (rand() % 50) + 1;
    }
    linearSearch(arr, key, 20);
    binarySearch(arr, key,10);

    free(arr);
    return 0;
}
