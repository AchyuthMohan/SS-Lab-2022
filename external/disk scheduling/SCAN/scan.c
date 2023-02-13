#include <stdio.h>
#include <stdlib.h>
int main()
{
    int RQ[100], totalheadmovement = 0, initial, n, move, size, i, j, temp;
    printf("Enter the number of requests: ");
    scanf("%d", &n);
    printf("Enter the request queue: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &RQ[i]);
    }

    printf("Enter the initial position of head: ");
    scanf("%d", &initial);
    printf("Enter total disk size: ");
    scanf("%d", &size);
    printf("Enter the direction 1 for high and 0 for low: ");
    scanf("%d", &move);

    for (i = 0; i < n; i++)
    {
        for (j = i; j < n; j++)
        {
            if (RQ[j] < RQ[i])
            {
                temp = RQ[i];
                RQ[i] = RQ[j];
                RQ[j] = temp;
            }
        }
    }
    int index;
    for (i = 0; i < n; i++)
    {
        if (initial < RQ[i])
        {
            index = i;
            break;
        }
    }
    if (move == 1)
    {
        for (i = index; i < n; i++)
        {
            totalheadmovement = totalheadmovement + abs(RQ[i] - initial);
            initial = RQ[i];
        }
        totalheadmovement = totalheadmovement + abs(RQ[i - 1] - 1);
        initial = size - 1;
        for (i = index - 1; i >= 0; i--)
        {
            totalheadmovement = totalheadmovement + abs(RQ[i] - initial);
            initial = RQ[i];
        }
    }
    else
    {
        for (i = index - 1; i >= 0; i--)
        {
            totalheadmovement = totalheadmovement + abs(RQ[i] - initial);
            initial = RQ[i];
        }
        totalheadmovement = totalheadmovement + abs(RQ[i + 1] - 0);
        initial = 0;
        for (i = index; i < n; i++)
        {
            totalheadmovement = totalheadmovement + abs(RQ[i] - initial);
            initial = RQ[i];
        }
    }
    printf("TOTAL HEAD MOVEMENT is: %d", totalheadmovement);
    return 0;
}