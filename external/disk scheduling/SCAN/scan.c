#include<stdio.h>
#include<stdlib.h>
#define max 200
int main(){
    int n,rq[200],intial,totalMoves=0,i,j,temp,index,size;
    printf("Enter the number of requests..\n");
    scanf("%d",&n);
    printf("Enter the request sequence: \n");
    for(i=0;i<n;i++){
        scanf("%d",&rq[i]);
    }
    printf("Enter the size of the disk: \n");
    scanf("%d",&size);
    printf("Enter the initial point header: \n");
    scanf("%d",&intial);
    for(i=0;i<n;i++){
        for(j=i+1;j,n;j++){
            if(rq[i]>rq[j]){
                temp=rq[i];
                rq[i]=rq[j];
                rq[j]=temp;
            }
        }
    }
    for(i=0;i<n;i++){
        if(intial<=rq[i]){
            index=i;
            break;
        }
    }
    printf("1: To high 2: To low\n");
    int move;
    scanf("%d",&move);
    if(move==1){
        for(i=index;i<n;i++){
            totalMoves+=abs(intial-rq[i]);
            intial=rq[i];
        }
        totalMoves+=abs(rq[i-1]-1);
        intial=size-1;
        for(i=index-1;i<=0;i--){
            totalMoves+=abs(intial-rq[i]);
            intial=rq[i];
        }
    }
    else{
        for(i=index-1;i>=0;i--){
            totalMoves+=abs(intial-rq[i]);
            intial=rq[i];
        }
        totalMoves+=abs(rq[i+1]-0);
        intial=0;
        for(i=index;i<n;i++){
            totalMoves+=abs(intial-rq[i]);
            intial=rq[i];
        }
    }
    printf("Result: %d",totalMoves);
}