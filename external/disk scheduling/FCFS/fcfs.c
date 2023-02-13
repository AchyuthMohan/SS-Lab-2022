#include <stdio.h>
#include <stdlib.h>
#define max 100
int main()
{
    int n, rq[max], initial, result = 0;
    printf("Enter the number of requests: \n");
    scanf("%d", &n);
    printf("Enter the request queue: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &rq[i]);
    }
    printf("Enter the initial position: \n");
    scanf("%d", &initial);
    for (int i = 0; i < n; i++)
    {
        result += abs(rq[i] - initial);
        initial = rq[i];
    }
    printf("Result: %d", result);
}