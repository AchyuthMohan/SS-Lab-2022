#include<stdio.h>
#include<stdlib.h>
#define max 100
int main(){
    int rq[max],i,j,n,initial,totlaMovement=0,size,index,move;
    printf("Enter the no of requests: \n");
    scanf("%d",&n);
    printf("Enter the request sequence: \n");
    for(i=0;i<n;i++){
        scanf("%d",&rq[i]);
    }
    printf("Enter the size of disk: \n");
    scanf("%d",&size);
    int temp;
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            temp=rq[i];
            rq[i]=rq[j];
            rq[j]=temp;
        }
    }
    printf("Enter the initial: \n");
    scanf("%d",&initial);
    for(i=0;i<n;i++){
        if(initial<=rq[i]){
            index=i;
            break;
        }
    }
    printf("Direction 1:to high 2: to low: \n");
    scanf("%d",&move);
    if(move==1){
        for(i=index;i<n;i++){
            totlaMovement+=abs(rq[i]-initial);
            initial=rq[i];
        }
        totlaMovement+=abs(rq[i-1]-1);
        initial=size-1;
        for(i=index-1;i>=0;i--){
            totlaMovement+=abs(rq[i]-initial);
            initial=rq[i];
        }
    }
    else{
        for(i=index-1;i>=0;i--){
            totlaMovement+=abs(rq[i]-initial);
            initial=rq[i];
        }
        totlaMovement+=abs(rq[i+1]-0);
        initial=0;
        for(i=index;i<n;i++){
            totlaMovement+=abs(rq[i]-initial);
            initial=rq[i];
        }
    }
    printf("%d",totlaMovement);
}