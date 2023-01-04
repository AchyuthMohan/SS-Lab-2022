#include<stdio.h>
#include<stdlib.h>
int main(){
    int p,f,size,pages[40];
    printf("Enter the number of pages: \n");
    scanf("%d",&p);
    printf("Enter the number of frames: \n");
    scanf("%d",&f);
    printf("Enter the page size: \n");
    scanf("%d",&size);
    for(int i=0;i<p;i++){
        pages[i]=-1;
    }
    
    for(int i=0;i<p;i++){
        printf("Enter the frame number of the page:%d or enter -1 else: \n",i+1);
        int val;
        scanf("%d",&val);
        pages[i]=val;
    }
    int state=0;
    while(state==0){
        printf("1. calculate logical address 2. exit: \n");
        int ch;
        scanf("%d",&ch);
        switch(ch){
            case 1:{
                printf("Enter the page number and offset value: \n");
                int offset,pno;
                scanf("%d",&offset);
                scanf("%d",&pno);
                int logical=pages[pno];
                if(logical==-1){
                    printf("Not allocated..\n");
                }
                else{
                    printf("Logical address: %d",logical);
                }
                break;
            }
            case 2:{
                state=1;
                break;
            }
        }
    }
}