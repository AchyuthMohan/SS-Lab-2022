#include <stdio.h>
#include <stdlib.h>
#define max 100

int main()
{
    int f[max], n, bno, sta, length;
    for (int i = 0; i < max; i++)
    {
        f[i] = 0;
    }
    printf("Enter the number of blocks which are already allocated:\n");
    scanf("%d", &n);
    printf("Enter the blocks which are already allocated: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &bno);
        f[bno] = 1;
    }
    a:printf("Enter the start address and length: \n");
    scanf("%d", &sta);
    scanf("%d", &length);
    int k = length;
    if (f[sta] == 0)
    {
        for (int i = sta; i < (sta + k); i++)
        {
            if(f[i]==0){
                f[i]=1;
                printf("%d------->%d\n",i,f[i]);
            }
            else{
                k++;
                printf("already  allocated..\n");
            }
        }
    }
    else
    {
        printf("Starting address already allocated...\n");
    }
    b:printf("1. Add new file?  2.Exit: \n");
    int ch;
    scanf("%d",&ch);
    if(ch==1){
        goto a;
    }
    else if(ch==2){
        exit(0);
    }
    else{
        printf("Enter valid value..\n");
        goto b;
    }
}