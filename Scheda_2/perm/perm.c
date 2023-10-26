#include <stdio.h>
#include <stdlib.h>

void    recursive_division(int n, int k, int *counter, int last_divisor)
{
    int j = last_divisor + 1;

    if (n == 1)
    {
        (*counter)++;
        return ;
    }
    while(--j > 0)
    {
        if (!(n % (j)) && k)
            recursive_division(n/j, k - 1, counter, j);
    }
}

int k_uple(int n, int k)
{
    int i = 0;
    recursive_division(n, k, &i, n);
    return (i);
}

int main(int argc, char **argv)
{
    printf("il numero di combinazioni è = %d\n", k_uple(atoi(argv[1]), atoi(argv[2])));
}