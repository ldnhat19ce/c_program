#include <stdio.h>
#include <stdint.h>

int g_DefaultArraySize = 100;
enum State {WORKING = 1, FAILED = -1};


/**
 *  @param arraySize
 *  @return the size of array or -1 if condition is not satisfied
 */
int initArray(int arraySize) {
    if (arraySize > g_DefaultArraySize) {
        return FAILED;
    }
    return arraySize;
}

/**
 *  Input value from keyboard
 *  @param array
 *  @param arraySize
 *  @return 1 if function is working
 */
int inputArray(int array[], int arraySize) {
    printf("\nnhap %d phan tu vao mang: ", arraySize);
    for (int i = 0; i < arraySize; i++) {
        scanf("%d", &array[i]);
    }
    return WORKING;
}

/**
 *  Display all value of array
 *  @param array
 *  @param arraySize
 *  @return 1 if function is working
 */
int displayArray(int array[], int arraySize) {
    printf("\nHien thi mang: ");
    for (int i = 0; i < arraySize; i++) {
        printf("%d ", array[i]);
    }
    return WORKING;
}

/**
 *  Insert value to specific position of array
 *  @param array
 *  @param arraySize
 *  @param number
 *  @param position
 *  @return 1 if function is working
 */
int addElement(int array[], int *arraySize, int number, int position) {
    for (int i = *arraySize; i > position; i--) {
        array[i] = array[i - 1];
        printf("%d ", i);
    }
    array[position] = number;
    *arraySize = *arraySize + 1;
    return WORKING;
}

/**
 *  Delete value from specific position of array
 *  @param array
 *  @param arraySize
 *  @param position
 *  @return 1 if function is working
 */
int deleteElement(int array[], int *arraySize, int position) {
    for (int i = position; i < (*arraySize - 1); i++) {
        array[i] = array[i + 1];
    }
    *arraySize = *arraySize - 1;
    return WORKING;
}

/**
 *  Swap value between two value
 *  @param value1
 *  @param value2
 *  @return 1 if function is working
 */
int swap(int *value1, int *value2) {
    int temp = *value1;
    *value1 = *value2;
    *value2 = temp;
    return WORKING;
}

/**
 *  Sort elements in descending order
 *  @param array
 *  @param arraySize
 *  @return 1 if function is working
 */
int sortDescArray(int array[], int arraySize) {
    for (int i = 0; i < arraySize - 1; i++) {
        for (int j = i + 1; j < arraySize; j++) {
            if (array[i] < array[j]) {
                swap(&array[i], &array[j]);
            }
        }
    }
}

/**
 *  Sort elements in ascending order
 *  @param array
 *  @param arraySize
 *  @return 1 if function is working
 */
int sortAscArray(int array[], int arraySize) {
    for (int i = 0; i < arraySize - 1; i++) {
        for (int j = i + 1; j < arraySize; j++) {
            if (array[i] > array[j]) {
                swap(&array[i], &array[j]);
            }
        }
    }
}

/**
 *  Find specific value from array
 *  @param array
 *  @param arraySize
 *  @param value
 *  @return 1 if a element is found or -1 if element is not found
 */
int searchArray(int array[], int arraySize, int value) {
    for (int i = 0; i < arraySize; i++) {
        if (array[i] == value) {
            return WORKING;
        }
    }
    return FAILED;
}
