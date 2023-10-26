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
        {
            max = v[i];
            l_seq++;
        }
        else
        {
            if (l_seq > end_seq - start_seq)
            {
                start_seq = i - 1 - l_seq;
                end_seq = i - 1;
            }
            max = v[i];
            l_seq = 0;
        }
    }
    return (end_seq - start_seq);
}
#include <stdio.h>
int main()
{
    int v[6];
    v[0] = 2;
    v[1] = 1;
    v[2] = 2;
    v[3] = 2;
    v[4] = 3;
    v[5] = 4;

    printf("la massima sequenza crescente `e lunga: %d\n", maxSeqCresc(v, 6));
}