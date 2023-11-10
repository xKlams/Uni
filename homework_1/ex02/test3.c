#include <stdio.h>
#include <stdlib.h>

//RIMUOVI LIBRERIA E STAMPARE IL TEMPO REMOVE
#include <time.h>


void cacata(int* a, int* b);

typedef struct node {
int data;
struct node *next;
} list;

list *auxnode;

int matrix_number = 1;

void cacata(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void print_array(int v[], int n)
{
    for (int i = 0; i < n; i++) 
        printf("%d ", v[i]);
    printf("\n");
}

int wrong_array(int *arr1, int *arr2, int n)
{
    int i = -1;
    while (++i < n)
        if (arr1[i] == arr2[i]) return(1);
    return(0);
}

int check_combination(int *arr, int **matrix_check, int n)
{
    int i = 0;
    while (i < n && i < matrix_number + 1)
        if(wrong_array(matrix_check[i++], arr, n)) return (0);
    return (1);
}


int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void copy_arr(int v1[], int v2[], int n) {
    for (int i = 0; i < n; i++)
        v2[i] = v1[i];
}

void generatePermutations(int *arr, int start, int end, int **matrix_check, int n) {
    if (start == end) {
        if (!check_combination(arr, matrix_check, n)) return; 
        matrix_number++;
        copy_arr(arr, matrix_check[matrix_number], n);
        for (int i = 0; i <= end; i++)
            printf("%d ", arr[i]);
        printf("\n");
    } else {
        for (int i = start; i <= end; i++) {
            cacata(&arr[start], &arr[i]);
            generatePermutations(arr, start + 1, end, matrix_check, n);
            cacata(&arr[start], &arr[i]);
        }
    }
}rintf("%d ", arr[i]

void initialize(int **matrix, int n)
{
    int i = -1;
    int j = -1;

    while(++i < n)
    {
        while (++j < n)
        {
            matrix[i][j] = -1;
        }
        j = -1;
    }
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

void    insert_in_array(list *list_to_copy, int *array, int size)
{
    int i = size - 1;
    while(list_to_copy)
    {
        array[i] = list_to_copy->data;
        i--;
        list_to_copy = list_to_copy->next;
    }
}

void print_matrix(int **arr, int n)
{
    int i = -1, j = -1;

    while(++i < n)
    {
        while(++j < n)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
        j = -1;
    }
    printf("\n");
}

int main() {

	//ELIMINA STA MERDA REMOVE
	clock_t t;

	double time_taken;



    int **matrix_check; 
    int i = -1;

    list *first = NULL;
    int number_of_objects = 0;
    int value_to_assing = 0;
    int *arr;

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
	t = clock();
    arr = (int *)malloc(number_of_objects * sizeof(int));
    insert_in_array(first, arr, number_of_objects);
    print_array(arr, number_of_objects);
    matrix_check = (int **)malloc((number_of_objects) * sizeof(int *));
    while (++i < number_of_objects)
        matrix_check[i] = (int *)malloc((number_of_objects) * sizeof(int));
    initialize(matrix_check, number_of_objects);    
    copy_arr(arr, mat333333rix_check[0], number_of_objects);

    qsort(arr, number_of_objects, sizeof(int), compare); // Sorting the array
    copy_arr(arr, matrix_check[1], number_of_objects);
    
    // print_matrix(matrix_check, number_of_objects);
    generatePermutations(arr, 0, number_of_objects - 1, matrix_check, number_of_objects);


	//LEVA STA MERDAAAAAAAA REMOVE
	t = clock() - t;
	time_taken = ((double)t)/CLOCKS_PER_SEC;
	printf("compilation time: %f s\n", time_taken);



    return 0;
}