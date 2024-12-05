#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

void mergeSort(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = malloc(n1 * sizeof(int));
    int *R = malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    free(L);
    free(R);
}

int main() {
    for (int size = 50000; size <= 500000; size += 50000) {
        printf("\nPara N = %d:\n", size);
        double insertionSortTime = 0;
        double mergeSortTime = 0;

        for (int nExecucoes = 0; nExecucoes < 3; nExecucoes++) {
            int *arr1 = malloc(size * sizeof(int));
            int *arr2 = malloc(size * sizeof(int));
            srand(time(NULL));

            for (int i = 0; i < size; i++) {
                int randomNumber = rand() % 10001;
                arr1[i] = randomNumber;
                arr2[i] = randomNumber;
            }

            clock_t t = clock();
            insertionSort(arr1, size);
            t = clock() - t;
            insertionSortTime += ((double)t) / CLOCKS_PER_SEC;

            clock_t t2 = clock();
            mergeSort(arr2, 0, size - 1);
            t2 = clock() - t2;
            mergeSortTime += ((double)t2) / CLOCKS_PER_SEC;

            free(arr1);
            free(arr2);

            printf("Execução %d:\n", nExecucoes + 1);
            printf(" - InsertionSort: %.6f s\n", ((double)t) / CLOCKS_PER_SEC);
            printf(" - MergeSort: %.6f s\n", ((double)t2) / CLOCKS_PER_SEC);
        }

        printf("\nMédia dos tempos:\n");
        printf(" - InsertionSort: %.6f s\n", insertionSortTime / 10.0);
        printf(" - MergeSort: %.6f s\n\n", mergeSortTime / 10.0);
    }

    return 0;
}
