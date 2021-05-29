#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#define N 100

void printMenu()
{
    printf("Menu:\n");
    printf("1) Print the table\n");
    printf("2) Find a table element by key\n");
    printf("3) Sort the table by keys\n");
    printf("0) Finish the program\n");
}

int main(void)
{
	int i, cnt, action;
	long key;
	char ch;
	data array[N];
	FILE *file = fopen("text", "r");
    if (file == NULL)
        {
            printf("Ошибка при открытии файла\n");
            return 0;
        }
        i = 0;
        while (i < N && fscanf(file, "%ld", &array[i]._key) == 1)
        {
            fscanf(file, "%c", &ch);
            getRow(file, array[i]._str, sizeof(array[i]._str));
            i++;
        }
        fclose(file);
        cnt = i;
        printMenu();
        scanf("%d", &action);

            while (action != 0) {

                if (action == 1) {
                    printTable(array, cnt);
                } else if (action == 2) {
                        printf("Enter the key: ");
                        scanf("%ld", &key);
                        i = binSearch(array, cnt, key);
                        if(i > -1){
                            printf("Element by this key: %s\n", array[i]._str);
                        } else printf("There is no element with this key in the table!\n");
//else if (action == 3) {

                } else if (action == 3) {
                    MergSort(array, 0, i - 1);
                } else
                    printf("pls, write new integer");
                
                scanf("%d", &action);
            }

    return 0;
}