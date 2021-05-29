#include "sort.h"
#include <stdio.h>
#include <stdlib.h>



void printTable(data *arr, const int size)
{
	printf("+---------+------------------------------------------------+\n");
	printf("|   Ключ  |                    Значение                    |\n");
	printf("+---------+------------------------------------------------+\n");

	for (int i = 0; i < size; i++)
		printf("|%9ld|%48s|\n", arr[i]._key, arr[i]._str);

	printf("+---------+------------------------------------------------+\n");
}

void getRow(FILE *stream, char *str, const int size)
{
    int cnt = 0;
    char ch;
	while ((ch = getc(stream)) != '\n' && cnt < size - 1)
		str[cnt++] = ch;

	str[cnt] = '\0';
}

int binSearch(const data *arr, const int size, const long int key)
{
    int start = 0, end = size - 1, mid;

	if (size <= 0)
		return -1;

	while (start < end)
	{
		mid = start + (end - start) / 2;

		if (arr[mid]._key == key)
			return mid;
		else if (arr[mid]._key < key)
			start = mid + 1;
		else
			end = mid;
	}

	if (arr[end]._key == key)
		return end;

	return -1;
}

void Merg(data arr[], int begin, int end)
{
    int i = begin,
    t = 0,
    mid = begin + (end - begin) / 2,
    j = mid + 1,
    d[100];

    while (i <= mid && j <= end) {

    if (arr[i]._key <= arr[j]._key) {
        d[t] = arr[i]._key; 
        i++;
    }
    else {
        d[t] = arr[j]._key; 
        j++;
    }
    t++;
}

    while (i <= mid) {
        d[t] = arr[i]._key; 
        i++; 
        t++;
    }

while (j <= end){
    d[t] = arr[j]._key; 
    j++; 
    t++;
}

    for (i = 0; i < t; i++)
        arr[begin + i]._key = d[i];
    }

void MergSort(data *arr, int left, int right)
{
    int temp;
    if (left < right)
        if (right - left == 1) {
            if (arr[right]._key < arr[left]._key){
                temp = arr[left]._key;
                arr[left]._key = arr[right]._key;
                arr[right]._key = temp;
            }
        }
        else {
            MergSort(arr, left, left + (right - left) / 2);
            MergSort(arr, left + (right - left) / 2 + 1, right);
            Merg(arr, left, right);
        }

}

