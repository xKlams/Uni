#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int     in_array(int *array, int n, int value)
{
    for(int i = 0; i < n; i++)
        if(array[i] == value) return(i);
    return(-1);
}

void    fill_array(int *array, int n)
{
    for(int i = 0; i < n; i++)
        array[i] = i;
}
int    check_matrix(int n, int **matrix)
{
    int checked[n];
    int aux;
    for(int i = 0; i < n; i++)
    {
        fill_array(checked, n);
        for(int j = 0; j < n; j++)
        {
            aux = in_array(checked, n , matrix[i][j]);
            if(aux == -1) return 0;
            checked[aux] = -1;
        }
    }
    for(int i = 0; i < n; i++)
    {
        fill_array(checked, n);
        for(int j = 0; j < n; j++)
        {
            aux = in_array(checked, n , matrix[j][i]);
            if(aux == -1) return 0;
            checked[aux] = -1;
        }
    }
    return (1);
}

int main()
{
    int aux;
    int input_lenght = 0;
    int i;
    int lenght;
    int aux_len;
    int **matrix;
    char ans[4] = "NO\n";

    scanf("%d", &input_lenght);
    aux_len = input_lenght;
    matrix = (int **)malloc(input_lenght*sizeof(int*));
    for(int j = 0; j < input_lenght; j++)
        matrix[j] = (int *)malloc(input_lenght*sizeof(int));
    input_lenght *= input_lenght;
    lenght = input_lenght - 1;
    while(--input_lenght >= 0)
    {
        scanf("%d", &aux);
        matrix[(lenght - input_lenght)/aux_len][(lenght - input_lenght)%aux_len] = aux;
    }
    if(check_matrix(aux_len, matrix))
    {
        ans[0] = 'S';
        ans[1] = 'I';
    }
    printf("%s", ans);
    for(int j = 0; j < aux_len; j++)
        free(matrix[j]);
    free(matrix);
    return 0;
}