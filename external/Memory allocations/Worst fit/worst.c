#include <stdio.h>
#include <stdlib.h>
#define max 100
struct block
{
    int bno, size, pno, is_alloc;
} blocks[max];
int main()
{
    int n, p_sizes[max], m;
    printf("Enter the number of processes: \n");
    scanf("%d", &n);
    printf("Enter the process sizes: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &p_sizes[i]);
    }
    printf("Enter the number of blocks: \n");
    scanf("%d", &m);
    printf("Enter the block sizes: \n");
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &blocks[i].size);
        blocks[i].is_alloc = 0;
        blocks[i].bno = i;
    }
    struct block temp;
    for (int i = 0; i < m; i++)
    {
        for (int j = i + 1; j < m; j++)
        {
            if (blocks[j].size > blocks[i].size)
            {
                temp = blocks[i];
                blocks[i] = blocks[j];
                blocks[j] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (blocks[j].is_alloc == 0 && blocks[j].size >= p_sizes[i])
            {
                blocks[j].pno = i;
                blocks[j].is_alloc = 1;
                break;
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        if (blocks[i].is_alloc != 0)
        {
            printf("bno: %d\tpno: %d\tis alloc: %d\t\n", blocks[i].bno, blocks[i].pno, blocks[i].is_alloc);
        }
    }
}