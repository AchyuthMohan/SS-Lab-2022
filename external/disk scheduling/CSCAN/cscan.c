#include <stdio.h>
#include <stdlib.h>
#define max 200
int main()
{
    int n, rq[200], intial, totalMoves = 0, i, j, temp, index, size;
    printf("Enter the number of requests..\n");
    scanf("%d", &n);
    printf("Enter the request sequence: \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &rq[i]);
    }
    printf("Enter the size of the disk: \n");
    scanf("%d", &size);
    printf("Enter the initial point header: \n");
    scanf("%d", &intial);
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j, n; j++)
        {
            if (rq[i] > rq[j])
            {
                temp = rq[i];
                rq[i] = rq[j];
                rq[j] = temp;
            }
        }
    }
    for(i=0;i<n;i++){
        if(intial<=rq[i]){
            index=i;
            break;
        }
    }
    printf("1. to high 2. to low..\n");
    int move;
    scanf("%d",&move);
    if(move==1){
        for(i=index;i<n;i++){
            totalMoves+=abs(rq[i]-intial);
            intial=rq[i];
        }
        totalMoves+=abs(size-rq[i-1]-1);
        totalMoves+=abs(size-1-0);
        intial=0;
        for(i=0;i<index;i++){
            totalMoves+=abs(rq[i]-intial);
            intial=rq[i];
        }
    }
    else{
        for(i=index-1;i>=0;i--){
            totalMoves+=abs(rq[i]-intial);
            intial=rq[i];
        }
        totalMoves+=abs(rq[i+1]-0);
        totalMoves+=abs(size-1-0);
        intial=size-1;
        for(i=size-1;i>=index;i--){
            totalMoves+=abs(rq[i]-intial);
            intial=rq[i];
        }
    }
}