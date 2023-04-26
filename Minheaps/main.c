#include <stdio.h>
#define LENGTH 5

void print(int array[], int length) {
    for (int i = 0; i < length; i++)
        printf("%d ", array[i]);
    printf("\n");
}


void heapify(int array[], int length, int i) {
    if (length == 1) {
        printf("The heap has only one element.\n");
        return;
    }

    int smallest = i;
    int left = (2 * i) + 1;
    int right = (2 * i) + 2;
    if (left < length && array[left] < array[i])
        smallest = left;
    if (right < length && array[right] < array[smallest])
        smallest = right;

    if (smallest != i) {
        int temp = array[i];
        array[i] = array[smallest];
        array[smallest] = temp;
        heapify(array, length, smallest);
    }
}

void insert(int array[], int length, int val) {
    if (length == 0) {
        array[0] = val;
        return;
    }

    array[length] = val;
    for (int i = (length / 2) - 1; i >= 0; i--) {
        heapify(array, length, i);
        print(array, length);
    }
}

int delete_min(int array[], int length) {
    if (length == 0)
        return 1;
    if (length == 1)
        return array[0];

    int root = array[0];
    array[0] = array[length - 1];
    length--;
    heapify(array, length, 0);

    return root;
}

int main() {
    int array[LENGTH];
    for (int i = 0; i < LENGTH; i++)
        insert(array, i, i - 500);

    print(array, LENGTH);

    printf("After deleting min:\n");
    delete_min(array, LENGTH);
    print(array, LENGTH);


    return 0;
}
