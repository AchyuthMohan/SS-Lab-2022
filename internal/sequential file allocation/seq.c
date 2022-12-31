#include<stdio.h>
#include<stdlib.h>
#define max 40
int main(){
    int blocks[max];
    int state=0;
    int start,n;
    for(int i=0;i<max;i++){
        blocks[i]=0;
    }
    while(state==0){
        printf("Enter the length of file and starting block: ");
        scanf("%d%d",&n,&start);
        if(blocks[start]==1){
            printf("already allocated...\n");
            goto x;
        }
        for(int i=start;i<(start+n);i++){
            if(blocks[i]==1){
                printf("Cannot allocate...");
                break;
            }
            else{
                blocks[i]=1;
                printf("%d-----%d\n",i,blocks[i]);
            }
        }
        
        x: printf("wanna add more files: 1. Yes 0.No\n");
        int ch;
        scanf("%d",&ch);

        if(ch==0){
            state=1;
            break;
        }
        else{
            continue;
        }
    }
}