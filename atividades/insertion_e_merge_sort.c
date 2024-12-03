#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int size = 10;

void insertionSort(int arr[], int n) {
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
    int arr1[size];
    int arr2[size];
    clock_t t;

    srand((unsigned)time(NULL));

    for (int i = 0; i < size; i++) {
        int randomNumber = random() % 10001;
        arr1[i] = randomNumber;
        arr2[i] = randomNumber;
    }

    printf("Array original: ");
    printArray(arr1, size);

    t = clock();
    insertionSort(arr1, size);
    t = clock() - t;

    printf("Array ordenado: ");
    printArray(arr1, size);

    printf("Tempo de execucao: %lf ms\n", ((double)t)/((CLOCKS_PER_SEC/1000)));

}