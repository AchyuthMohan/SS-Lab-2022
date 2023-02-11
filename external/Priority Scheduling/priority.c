#include<stdio.h>
#include<stdlib.h>
#define max 100
struct process{
    int pno,at,bt,ct,tat,wt,priority;
}p[max];
int main(){
    int n;
    printf("Enter the number of processes: \n");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        p[i].at=0;
        printf("Enter the burst time of p[%d]: \n",i);
        scanf("%d",&p[i].bt);
        printf("Enter the priority of p[%d]: \n",i);
        scanf("%d",&p[i].priority);
        p[i].pno=i;
    }
    struct process temp;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(p[i].priority<p[j].priority){
                temp=p[i];
                p[i]=p[j];
                p[j]=temp;
            }
        }
    }
    int complete=0;
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
    for(int i=0;i<n;i++){
        printf("pno: %d\tbt:%d\twt:%d\ttat:%d\tct:%d\tprio:%d\n",p[i].pno,p[i].bt,p[i].wt,p[i].tat,p[i].ct,p[i].priority);

    }
}