
#include <stdio.h>

long long mergeComparisons = 0;
long long quickComparisons = 0;

void printArray(int array[], int size) {
    for (int index = 0; index < size; ++index) {
        printf("%d", array[index]);
        if (index + 1 == size) printf("\n");
        else printf(" ");
    }
}

void merge(int array[], int temp[], int left, int middle, int right) {
    int leftPartitionIndex = left;
    int rightPartitionIndex = middle + 1;
    int tempIndex = left;

    while (leftPartitionIndex <= middle && rightPartitionIndex <= right) {
        mergeComparisons++;
        if (array[leftPartitionIndex] <= array[rightPartitionIndex]) {
            temp[tempIndex++] = array[leftPartitionIndex++];
        } else {
            temp[tempIndex++] = array[rightPartitionIndex++];
        }
    }

    while (leftPartitionIndex <= middle) temp[tempIndex++] = array[leftPartitionIndex++];
    while (rightPartitionIndex <= right) temp[tempIndex++] = array[rightPartitionIndex++];

    for (int index = left; index <= right; ++index) {
        array[index] = temp[index];
    }
}

void mergeSort(int array[], int temp[], int left, int right) {
    if (left >= right) return;

    int middle = left + (right - left) / 2;

    mergeSort(array, temp, left, middle);
    mergeSort(array, temp, middle + 1, right);
    merge(array, temp, left, middle, right);
}

int partition(int array[], int low, int high) {
    int pivot = array[high];
    int smallerIndex = low - 1;

    for (int index = low; index < high; ++index) {
        quickComparisons++;
        if (array[index] <= pivot) {
            smallerIndex++;
            int swap = array[smallerIndex];
            array[smallerIndex] = array[index];
            array[index] = swap;
        }
    }

    int swap = array[smallerIndex + 1];
    array[smallerIndex + 1] = array[high];
    array[high] = swap;

    return smallerIndex + 1;
}

void quickSort(int array[], int low, int high) {
    if (low >= high) return;

    int pivotIndex = partition(array, low, high);

    quickSort(array, low, pivotIndex - 1);
    quickSort(array, pivotIndex + 1, high);
}

void mergeSortedBatch(int oldArray[], int oldSize, int newArray[], int newSize, int result[]) {
    int oldIndex = 0, newIndex = 0, resultIndex = 0;

    while (oldIndex < oldSize && newIndex < newSize) {
        if (oldArray[oldIndex] <= newArray[newIndex]) {
            result[resultIndex++] = oldArray[oldIndex++];
        } else {
            result[resultIndex++] = newArray[newIndex++];
        }
    }

    while (oldIndex < oldSize) result[resultIndex++] = oldArray[oldIndex++];
    while (newIndex < newSize) result[resultIndex++] = newArray[newIndex++];
}

int main(void) {
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("File not found\n");
        return 1;
    }

    int size, newSize;
    fscanf(file, "%d %d", &size, &newSize);

    int mergeArray[size], quickArray[size], temp[size];
    int newArray[newSize > 0 ? newSize : 1];
    int result[size + newSize];

    for (int index = 0; index < size; ++index) {
        fscanf(file, "%d", &mergeArray[index]);
        quickArray[index] = mergeArray[index];
    }

    for (int index = 0; index < newSize; ++index) {
        fscanf(file, "%d", &newArray[index]);
    }
    fclose(file);

    mergeSort(mergeArray, temp, 0, size - 1);
    quickSort(quickArray, 0, size - 1);

    printf("Merge Sort: ");
    printArray(mergeArray, size);
    printf("Quick Sort: ");
    printArray(quickArray, size);

    printf("Merge Comparisons: %lld\n", mergeComparisons);
    printf("Quick Comparisons: %lld\n", quickComparisons);

    mergeSortedBatch(mergeArray, size, newArray, newSize, result);

    printf("Updated Array: ");
    printArray(result, size + newSize);

    return 0;
}
