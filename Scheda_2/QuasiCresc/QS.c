#include <stdio.h>
int maxSeqCresc(int *v, int n)
{
    int i, max, start_seq, l_seq, end_seq;
    i = -1;
    l_seq = 0;
    end_seq = 0;
    start_seq = 0;
    max = v[0];
    while (++i < n)
    {
        if (v[i] > max)
            l_seq++;
        else
        {
            l_seq = 0;
        }
        if (l_seq > end_seq - start_seq)
        {
            start_seq = i - 1 - l_seq;
            end_seq = i - 1;
        }
        max = v[i];
    }   
    return (end_seq - start_seq + 1);
}

int main()
{
    int v[6];
    v[0] = 2;
    v[1] = 1;
    v[2] = 1;
    v[3] = 2;
    v[4] = 3;
    v[5] = 4;

    printf("la massima sequenza crescente `e lunga: %d\n", maxSeqCresc(v, 6));
}