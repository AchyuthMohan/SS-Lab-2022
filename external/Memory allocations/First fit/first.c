#include<stdio.h>
#include<stdlib.h>
#define max 100
struct block{
    int pno,bno,b_size,is_alloc;
}blocks[max];
int main(){
    int n,p_sizes[max],m;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    printf("Enter the sizes of processes: \n");
    for(int i=0;i<n;i++){
        scanf("%d",&p_sizes[i]);
    }
    printf("Enter the number of blocks: \n");
    scanf("%d",&m);
    printf("Enter the sizes of blocks: \n");

    for(int i=0;i<m;i++){
        scanf("%d",&blocks[i].b_size);
        blocks[i].bno=i;
        blocks[i].is_alloc=0;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(blocks[j].is_alloc==0 && p_sizes[i]<=blocks[j].b_size){
                blocks[j].pno=i;
                blocks[j].is_alloc=1;
                break;
            }
            else{
                continue;
            }
        }
    }

    for(int i=0;i<m;i++){
        printf("bno: %d\tpno: %d\tis alloc: %d\t\n",blocks[i].bno,blocks[i].pno,blocks[i].is_alloc);
    }
}