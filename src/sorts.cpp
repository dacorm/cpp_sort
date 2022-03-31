#include "sorts.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct DATE {
    int day;
    int month;
    int year;
} date;

int check_mass(int input[], int s) {
    int n = s,
    a[n];
    for (int i = 0; i < n; i++) {
        a[i] = input[i];
    }
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1])
        return 0;
    }
    return 1;
}

int string_to_int(char* string, int size) {
    if (size == 1 && *string == '-') {
        return -1;
    }
    if (size == 1) {
        return (*string - 0x30);
    }
    return string[size - 1] - 0x30
    + 10 * string_to_int(string, size - 1);
}

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

int vocabularySort() {
    char strings[line][column],
    str[column];
    FILE* f;
    int count = 0,
    i,
    j;
    if ((f = fopen("../thirdparty/testtext.txt", "r")) == NULL) {
        return 1;
    }
    /* Reading words from a file */
    while (feof(f) == 0 || count > 10) {
        fscanf(f, "%s", str);
        strcpy(strings[count++], str);
    }
    fclose(f);
    /* Outputting the lines */
    for (i = 0; i < count; i++) {
        std::cout << strings[i] << std::endl;
    }
    putchar('\n');
    /* Bubble sort */
    for (i = 1; i < count; i++)
    for (j = 0; j < count - i; j++)
    if (strcmp(strings[j], strings[j + 1]) > 0) {
        strcpy(str, strings[j]);
        strcpy(strings[j], strings[j + 1]);
        strcpy(strings[j + 1], str);
    }
    /* Output sorted rows */
    for (i = 0; i < count; i++) {
        std::cout << strings[i] << std::endl;
    }
    return 0;
}

int rvocabularySort() {
    char strings[line][column],
    str[column];
    FILE* f;
    int count = 0,
    i,
    j;
    if ((f = fopen("../thirdparty/testtext.txt", "r")) == NULL) {
        return 1;
    }
    /* Reading words from a file */
    while (feof(f) == 0 || count > 10) {
        fscanf(f, "%s", str);
        strcpy(strings[count++], str);
    }
    fclose(f);
    /* Outputting the lines */
    for (i = 0; i < count; i++) {
        std::cout << strings[i] << std::endl;
    }
    putchar('\n');
    /* Bubble sort */
    for (i = 1; i < count; i++) {
        for (j = 0; j < count - i; j++) {
            if (strcmp(strings[j], strings[j + 1]) > 0) {
                strcpy(str, strings[j]);
                strcpy(strings[j], strings[j + 1]);
                strcpy(strings[j + 1], str);
            }
        }
    }
    /* Output sorted rows */
    for (i = 0; i < count; i++) {
        std::cout << strings[i] << std::endl;
    }
    return 0;
}

int dateSort() {
    int i = 0;
    int j = 0;
    int size;
    FILE *f1,
    *f2;
    f1 = fopen("../thirdparty/datetest.txt", "r");
    fseek(f1, 0, SEEK_END);
    size = ftell(f1);
    fseek(f1, 0, SEEK_SET);
    char* file_dates = new char[size];
    date* arr = new date[size];
    if (f1 != NULL) {
        while (feof(f1) == 0) {
            fscanf(f1, "%c", &file_dates[i]);
            i++;
        }
        fclose(f1);
        size = size / 11;
        for (i = 0; i < size; i++) {
            arr[i].day = 0;
            arr[i].month = 0;
            arr[i].year = 0;
            int counter = 10;
            while (file_dates[j] != '-') {
                arr[i].day = string_to_int((file_dates + j), 1) * counter + arr[i].day;
                j++;
                counter = counter / 10;
            }
            j++;
            counter = 10;
            while (file_dates[j] != '-') {
                arr[i].month = string_to_int((file_dates + j), 1) * counter + arr[i].month;
                j++;
                counter = counter / 10;
            }
            j++;
            counter = 1000;
            while (file_dates[j] != ' ') {
                arr[i].year = string_to_int((file_dates + j), 1) * counter + arr[i].year;
                j++;
                counter = counter / 10;
            }
            j++;
        }
        std::cout << "Array, before sorting:";
        for (i = 0; i < size; i++) {
            std::cout << arr[i].day;
            std::cout << "-";
            std::cout << arr[i].month;
            std::cout << "-";
            std::cout << arr[i].year;
            std::cout << " ";
        }
        std::cout << std::endl;
        for (i = size - 1; i >= 0; i--) {
            for (j = 0; j < i; j++) {
                if ((arr[j].year * 10000) + (arr[j].month * 100) + (arr[j].day) > (arr[j + 1].year * 10000) + (arr[j + 1].month * 100) + (arr[j + 1].day)) {
                    date tmp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = tmp;
                }
            }
        }
        f2 = fopen("../thirdparty/dateres.txt", "w");
        std::cout << "Array written to file:";
        for (i = 0; i < size; i++) {
            fprintf(f2, "%d", arr[i].day);
            std::cout << arr[i].day;
            fprintf(f2, "-");
            std::cout << "-";
            fprintf(f2, "%d", arr[i].month);
            std::cout << arr[i].month;
            fprintf(f2, "-");
            std::cout << "-";
            fprintf(f2, "%d", arr[i].year);
            std::cout << arr[i].year;
            fprintf(f2, " ");
            std::cout << " ";
        }
    }
    return (0);
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

void textrmassSort() {
    FILE *f1,
    *f2;

    int i = 0;
    int file_numbers[N];
    f1 = fopen("../thirdparty/test.txt", "r");
    if (f1 != NULL) {
        while (feof(f1) == 0) {
            fscanf(f1, "%d ", &file_numbers[i]);
            i++;
        }
        fclose(f1);
        numberSort(file_numbers, 0, N - 1);
        if (check_mass(file_numbers, N) == 1) {
            f2 = fopen("../thirdparty/revres.txt", "w");
            std::cout << "Array written to file:";
            for (i = N - 1; i > -1; i--) {
                fprintf(f2, "%d ", file_numbers[i]);
                std::cout << file_numbers[i];
            }
            fclose(f2);
            std::cout << std::endl << "The array sorted from largest to smallest is written to revres.txt" << std::endl;
        } else {
            std::cout << "Sort error" << std::endl;
        }
    }
}

void textmassSort() {
    FILE *f1,
    *f2;

    int i = 0;
    int file_numbers[N];

    f1 = fopen("../thirdparty/test.txt", "r");

    if (f1 != NULL) {
        while (feof(f1) == 0) {
            fscanf(f1, "%d ", &file_numbers[i]);
            i++;
        }
        fclose(f1);
        numberSort(file_numbers, 0, N - 1);
        if (check_mass(file_numbers, N) == 1) {
            f2 = fopen("../thirdparty/res.txt",
                "w");
            std::cout << "Array written to file:";
            for (i = 0; i < N; i++) {
                fprintf(f2, "%d ", file_numbers[i]);
                printf("%d ", file_numbers[i]);
            }
            fclose(f2);
            std::cout << std::endl << "The array sorted from smallest to largest is written to res.txt" << std::endl;
        } else {
            std::cout << "Sort error" << std::endl;
        }
    }
}