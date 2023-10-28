#include <stdio.h>
#include <stdlib.h>

//RIMUOVI LIBRERIA E STAMPARE IL TEMPO REMOVE
#include <time.h>

typedef struct node {
int data;
struct node *next;
} list;

list *auxnode;

int matrix_number = 1;

int find_max_min(int *arr, int value, int value_index, int n)
{
    int min = n + 2;
    int min_index;
    while (value_index < n)
    {
        if (arr[value_index] < min && arr[value_index] > value)
        {
            min = arr[value_index];
            min_index = value_index;
        }
            value_index++;
    }
    return (value_index);
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void invert_from(int *arr, int n, int start)
{
    start--;
    int j = n;
    while (++start < --j)
        swap(&arr[i], &arr[j]);
}

void next_permiutation(int *arr, int n)
{
    int i, j;
    while (arr[--i] > = arr[i - 1] && i > 0);
    j = find_max_min(arr, arr[i - 1], i - 1, n);
    swap(&arr[i - 1], &arr[j]);
    invert(arr, n, i);
}
