#include "sorts.h"

void numberSort(int arr[], int l, int r) {
    int i = l,
    j = r,
    x = arr[(l + r) / 2],
    tmp;
    do {
        while(arr[i] < x) {
            i++;
        }
        while(arr[j] > x) {
            j--;
        }
        if(i <= j) {
            if(arr[i] > arr[j]) {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
            i++;
            j--;
        }
    } while(i <= j);

    if(i < r) {
        numberSort(arr, i, r);
    }
    if(l < j) {
        numberSort(arr, l, j);
    }
}

void rmassSort() {
    int len;
    while(true) {
        std::cout << "Number of sorted numbers: ";
        std::cin >> len;
        if(len > 0) {
            break;
        }
        std::cout << "Incorrect input" << std::endl;
    }

    int *arr = new int[len];

    for(int i = 0; i < len; i++) {
        std::cin >> arr[i];
    }

    numberSort(arr, 0, len - 1);

    std::cout << "Sorted array:" << std::endl;

    for(int i = len - 1; i > -1; i--) {
        std::cout << arr[i];
    }
}

void massSort() {
    int len;
    while(true) {
        std::cout << "Number of sorted numbers: ";
        std::cin >> len;
        if(len > 0) {
            break;
        }
        std::cout << "Incorrect input" << std::endl;
    }

    int *arr = new int[len];

    for(int i = 0; i < len; i++) {
        std::cin >> arr[i];
    }

    numberSort(arr, 0, len - 1);

    std::cout << "Sorted array:" << std::endl;

    for(int i = 0; i < len; i++) {
        std::cout << arr[i];
    }
}