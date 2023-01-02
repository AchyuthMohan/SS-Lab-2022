#include<stdio.h>
#include<stdlib.h>
#define max 45
int main(){
    int f,p,pages[max];
    printf("Enter the number of pages: \n");
    scanf("%d",&p);
    printf("Enter the number of frames: \n");
    scanf("%d",&f);
    for(int i=0;i<p;i++){
        pages[i]=-1;
    }
    printf("Enter the frame no associated with each page or else enter -1 for others: \n");
    for(int i=0;i<p;i++){
        printf("page %d\n",i);
        scanf("%d",&pages[i]);
    }
    int state=0;
    while(state==0){
        printf("1. Calculate logical address 2. exit: \n");
        int ch;
        scanf("%d",&ch);
        switch(ch){
            case 1:{
                printf("Enter the page number and offset..\n");
                int pno,offset;
                scanf("%d%d",&pno,&offset);
                if(pages[pno]==-1){
                    printf("Not allocated...");
                }
                else{
                    printf("Logical Address: %d, Offset: %d",pages[pno],offset);
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