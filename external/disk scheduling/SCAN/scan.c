#include<stdio.h>
#include<stdlib.h>
int main(){
    int n,size,initial,totlamoves=0,rq[100],i,j,index;
    printf("Enter the number of requests: \n");
    scanf("%d",&n);
    printf("Enter the request sequence: \n");
    for(i=0;i<n;i++){
        scanf("%d",&rq[i]);
    }
    int temp;
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            temp=rq[i];
            rq[i]=rq[j];
            rq[j]=temp;
        }
    }
    printf("Enter the initail position of head: \n");
    scanf("%d",&initial);
    for(i=0;i<n;i++){
        if(initial<=rq[i]){
            index=i;
            break;
        }
    }
    printf("1: to high 2: to low: \n");
    int move;
    scanf("%d",&move);
    if(move==1){
        for(i=index;i<n;i++){
            totlamoves+=abs(rq[i]-initial);
            initial=rq[i];
        }
        totlamoves+=abs(size-rq[i-1]-1);
        totlamoves+=abs(size-1-0);
        initial=0;
        for(i=index-1;i>=0;i--){
            totlamoves+=abs(rq[i]-initial);
            initial=rq[i];
        }
    }
    else{
        for(i=index-1;i>=0;i--){
            totlamoves+=abs(rq[i]-initial);
            initial=rq[i];
        }
        totlamoves+=abs(rq[i+1]-0);
        totlamoves+=abs(size-1-0);
        for(i=index-1;i>=0;i--){
            totlamoves+=abs(rq[i]-initial);
            initial=rq[i];
        }
    }
    printf("Total moves: %d",totlamoves);
}