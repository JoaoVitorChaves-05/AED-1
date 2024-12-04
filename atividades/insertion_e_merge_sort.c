#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int size = 10000;

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

// Função recursiva para dividir e ordenar
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2; // Encontra o meio

        mergeSort(arr, left, mid);        // Ordena a primeira metade
        mergeSort(arr, mid + 1, right);  // Ordena a segunda metade

        merge(arr, left, mid, right);    // Mescla as duas metades
    }
}

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1; // Tamanho do primeiro subarray
    int n2 = right - mid;    // Tamanho do segundo subarray

    int L[n1], R[n2]; // Arrays temporários

    // Copia os dados para os arrays temporários
    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    // Mescla os arrays temporários de volta em arr[]
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

    // Copia os elementos restantes de L[], se houver
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copia os elementos restantes de R[], se houver
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

int main() {
    for (int nExecucoes = 0; nExecucoes < 10; nExecucoes++) {
        int arr1[size];
        int arr2[size];
        clock_t t;
        clock_t t2;

        srand((unsigned)time(NULL));

        for (int i = 0; i < size; i++) {
            int randomNumber = random() % 10001;
            arr1[i] = randomNumber;
            arr2[i] = randomNumber;
        }

        //printf("Array original: ");
        //printArray(arr1, size);

        t = clock();
        insertionSort(arr1, size);
        t = clock() - t;

        //printf("Array ordenado: ");
        //printArray(arr1, size);

        //printf("Array original: ");
        //printArray(arr2, size);

        t2 = clock();
        mergeSort(arr2, 0, size - 1);
        t2 = clock() - t2;

        //printf("Array ordenado: ");
        //printArray(arr2, size);

        printf("EXECUÇÃO %i\n", nExecucoes + 1);
        printf("Tempo de execucao do InsertionSort: %lf ms\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
        printf("Tempo de execucao do MergeSort: %lf ms\n\n", ((double)t2)/((CLOCKS_PER_SEC/1000)));
    }

}