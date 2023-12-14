#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct node {
int data;
struct node *next;
} list;

list *auxnode;

void print_array(int v[], int n)
{
    for (int i = 0; i < n; i++) 
        printf("%d ", v[i]);
    printf("\n");
}

int isEmpty(list *L) {
    return L == NULL;
}

void insertFirst(list **LS) {
    if (!isEmpty(*LS))
        auxnode->next = *LS;
    *LS = auxnode;
    return;
}

int not_in_list(list *list_to_check, int value)
{
    if (isEmpty(list_to_check)) return(1);
    while(list_to_check != NULL)
    {
        if(list_to_check->data == value)
            return(0);
        list_to_check = list_to_check->next;
    }
    return(1);
}

void displayForward(list *L, char *c) {
    printf("Lista%s: [ ",c);
    while(L) {
        printf("(%d) ", L->data);
        L = L->next;
    }
    printf("]\n");
    return;
}

void    insert_in_matrix(list *list_to_copy, int **array, int size)
{
    int i = size - 1;
    while(list_to_copy)
    {
        array[i%4][i/4] = list_to_copy->data;
        i--;
        list_to_copy = list_to_copy->next;
    }
}

void copy_arr(int v1[], int v2[], int n) {
    for (int i = 0; i < n; i++)
        v2[i] = v1[i];
}

int find_index(int v[], int to_find, int n)
{
  for (int i = 0; i < n; i++)
    if (v[i] == to_find) return i;
  return (-1);
}

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int check_already_seen(int *array, int *seen)
{

}

void    solve(int *starting_seq, int n)
{
    int passo = (int)(sqrt(n));
    int seen[passo];
    for (int i = 0; i < passo; i += 1)
    {
        for (int j = 0; j < n; j += passo)
        {
            
        }
    }
}

int main()
{
    list *first = NULL;
    int number_of_objects = 0;
    int value_to_assing = 0;
    int **arr;

    while(1)
    {
        scanf("%d", &value_to_assing);
        if(!not_in_list(first, value_to_assing)) break;
        number_of_objects++;
        auxnode = malloc(sizeof(list));
        auxnode->data = value_to_assing;
        auxnode->next = NULL;
        insertFirst(&first);
    }

    int lato = (int) sqrt(number_of_objects) + 1;


    arr = (int **)malloc(lato * sizeof(int *));
    for (int i = 0; i < lato; i++)
        arr[i] = (int *)malloc(lato * sizeof(int));

    insert_in_matrix(first, arr, lato);
    // print_array(arr[0], lato);
    // solve(arr, number_of_objects);
    printf("\n");
}