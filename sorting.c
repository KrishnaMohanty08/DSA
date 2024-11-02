#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int* arr) {
    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

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

void selectionSort(int* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        int min = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        if (arr[i] > arr[min]) {
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}

void insertionSort(int* arr, int size) {
    for (int i = 1; i < size; i++) {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

int partition(int* arr, int lb, int ub) {
    int pivot = arr[lb];
    int start = lb;
    int end = ub;
    while (start < end) {
        while (arr[start] <= pivot && start < ub) start++;
        while (arr[end] > pivot) end--;
        if (start < end) {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
        }
    }
    arr[lb] = arr[end];
    arr[end] = pivot;
    return end;
}

void quickSort(int* arr, int low, int high) {
    if (low < high) {
        int position = partition(arr, low, high);
        quickSort(arr, low, position - 1);
        quickSort(arr, position + 1, high);
    }
}

void CountSort(int* arr, int size, int max) {
    int count[max + 1];
    int sumArr[max + 1];
    int op[size];

    for (int i = 0; i <= max; i++) count[i] = 0;
    for (int i = 0; i < size; i++) count[arr[i]]++;

    sumArr[0] = count[0];
    for (int j = 1; j <= max; j++) sumArr[j] = count[j] + sumArr[j - 1];

    for (int k = size - 1; k >= 0; k--) {
        op[--sumArr[arr[k]]] = arr[k];
    }
    for (int i = 0; i < size; i++) arr[i] = op[i];
}

int main() {
    int *arr = (int*)malloc(20 * sizeof(int));
    int key;
    printf("Enter a key: ");
    scanf("%d", &key);
   
    for (int i = 0; i < 20; i++) {
        arr[i] = (rand() % 50) + 1;
    }

    CountSort(arr, 20, 50);
    for (int i = 0; i < 20; i++) {
        printf("%d, ", arr[i]);
    }

    free(arr);
    return 0;
}
