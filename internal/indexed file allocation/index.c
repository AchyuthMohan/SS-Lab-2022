#include<stdio.h>
#include<stdlib.h>
#define max 30
struct file{
    int start,length,no_of_blocks;
    int blocks[max];
}f[max];

int main(){
    int n;
    printf("Enter the number of files: \n");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter the starting block of %d: \n",i+1);
        scanf("%d",&f[i].start);
        printf("Enter the no of the file %d: ",i+1);
        scanf("%d",&f[i].no_of_blocks);
        printf("Enter the length of the file %d: ",i+1);
        scanf("%d",&f[i].length);
        printf("Enter the blocks : \n");
        for(int j=0;j<f[i].no_of_blocks;j++){
            scanf("%d",&f[i].blocks[j]);
        }
    }
    printf("\tfile\tlength\tno of blocks\n");
    for(int i=0;i<n;i++){
        printf("\t%d\t%d\t%d\n",i+1,f[i].length,f[i].no_of_blocks);
    }
    int state=0;
    while(state==0){
        printf("1. file blocks find 2. exit");
        int ch;
        scanf("%d",&ch);
        switch(ch){
            case 1:{
                 printf("Enter the file number: \n");
                 int fno;
                 scanf("%d",&fno);
                 for(int i=0;i<n;i++){
                    if(i==fno){
                        printf("Blocks: \n");
                        for(int j=0;j<f[i].no_of_blocks;j++){
                            printf("%d\t ",f[i].blocks[j]);
                        }
                    }
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