#include<stdio.h>
#include<stdlib.h>
#define max 50
int main(){
    int f[max],i,j,a,sta,length;
    for(i=0;i<max;i++){
        f[i]=0;
    }
    printf("Enter the number of blocks which are already allocated: ");
    scanf("%d",&a);
    printf("Enter the blocks which are already allocated: \n");

    for(i=0;i<a;i++){
        int loc;
        scanf("%d",&loc);
        f[loc]=1;
    }
    x: printf("Enter the start address and length: \n");
    scanf("%d%d",&sta,&length);
    int k=length;
    if(f[sta]==0){
        for(int j=sta;j<(sta+k);j++){
            if(f[j]==0){
                f[j]=1;
                printf("%d----->%d\n",j,f[j]);
            }
            else{
                printf("Block is already allocated...\n");
                k++;
            }
        }
    }
    else{
        printf("Starting block is already allocated..\n");
        
    }
    y: printf("Add more files ? 1. yes 2. No\n");
    int ch;
    scanf("%d",&ch);
    if(ch==1){
        goto x;
    }
    else if(ch==2){
        return 0;
    }
    else{
        printf("Enter valid choice..");
        goto y;
    }
}