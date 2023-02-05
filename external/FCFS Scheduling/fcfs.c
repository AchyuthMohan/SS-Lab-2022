#include<stdio.h>
#include<stdlib.h>
#define max 50
struct process{
    int pno,at,bt,ct,tat,wt;
}p[max];
int main(){
    int n,complete=0;
    printf("Enter the no of processes: \n");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter the arrival time, burst time for p[%d]: \n",i);
        scanf("%d%d",&p[i].at,&p[i].bt);
        p[i].pno=i;
        p[i].tat=0;
        p[i].wt=0;

    }
    
    struct process temp;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(p[i].at>p[j].at){
                temp=p[i];
                p[i]=p[j];
                p[j]=temp;
            }
        }
    }
    for(int i=0;i<n;i++){
        complete+=p[i].bt;
        p[i].ct=complete;
    }
    for(int i=0;i<n;i++){
        p[i].tat=p[i].ct-p[i].at;
    }
    for(int i=0;i<n;i++){
        p[i].wt=p[i].tat-p[i].bt;

    }
    printf("Final Answer: \n");
    for(int i=0;i<n;i++){
        printf("pno: %d\t tat: %d\t wt: %d\t ct:%d\n",p[i].pno,p[i].tat,p[i].wt,p[i].ct);
    }
    
}
