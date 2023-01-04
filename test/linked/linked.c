#include<stdio.h>
#include<stdlib.h>
#define max 40
int main(){
    int blocks[max];
    for(int i=0;i<max;i++){
        blocks[i]=0;
    }
    printf("Enter the number of blocks already allocated: \n");
    int n;
    scanf("%d",&n);
    printf("Enter the blocks which are already allocated: \n");
    for(int i=0;i<n;i++){
        int loc;
        scanf("%d",&loc);
        blocks[loc]=1;
    }
    int state=0;
    while(state==0){
       x: printf("1. Add more files  2. exit\n");
        int ch;
        scanf("%d",&ch);
        switch(ch){
            case 1:{
                printf("Enter the starting address.and length..\n");
                int start,len;
                scanf("%d%d",&start,&len);
                if(blocks[start]==1){
                    printf("already allocated.starting block.\n");
                    goto x;
                }
                for(int i=start;i<len;i++){
                    if(blocks[i]==0){
                        blocks[i]=1;
                        printf("block %d: allocated\n",i);
                    }
                    else{
                        len++;
                        printf("Block %d: already allocated\n",i);
                    }
                }
            }
            case 2:{
                state=1;
                break;
            }
        }
    }
}