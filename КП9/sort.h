#include <stdio.h>

typedef struct _Data {
    long int _key;
    char _str[120];
} data;
void printTable(data *arr, const int size);
void getRow(FILE *stream, char *str, const int size);
int binSearch(const data *arr, const int size, const long int key);
void MergSort(data *arr, int left, int right);
void Merg(data arr[], int begin, int end);