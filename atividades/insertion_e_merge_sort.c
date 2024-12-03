#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort() {
    for (int i = 0; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j+1] = key;
    }
}

void mergeSort() {

}

void merge() {

}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

int main() {
    int arr1[10000];
    int arr2[10000];

    for (int i = 0; i < 10000; i++) {
        int randomNumber = random() % 10001;
        arr1[i] = randomNumber;
        arr2[i] = randomNumber;
    }

    printf("Array original: ");
    printArray(arr1, 10000);

    insertionSort(arr1, 10000);

    printf("Array ordenado: ");
    printArray(arr1, 10000);

}