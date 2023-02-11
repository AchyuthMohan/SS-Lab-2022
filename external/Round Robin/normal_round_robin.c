#include<stdio.h>
#include<stdlib.h>
#define max 100

struct process{
    int pno,at,bt,rbt,tat,ct,wt;
}p[max];
int main(){
    int n=0,m;
    printf("Enter the number of processes: \n");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter the arrival time of p[%d]: \n",i);
        scanf("%d",&p[i].at);
        printf("Enter the burst time of p[%d]: \n",i);
        scanf("%d",&p[i].bt);
        p[i].pno=i;
        p[i].rbt=p[i].bt;
        i++;
    }
    for(int i=0;i<n;i++){
        p[i].ct=0;
        p[i].tat=0;
    }
    int complete =0;
    int qt;
    printf("Enter the quantum time: \n");
    scanf("%d",&qt);
    int count=n;
    while(count!=0){
        for(int i=0;i<n;i++){
            if(p[i].rbt>qt){
                printf("%d----->",p[i].pno);
                p[i].rbt=p[i].rbt-qt;
                complete+=qt;
                continue;
            }
            else{
                complete+=p[i].rbt;
                p[i].rbt=0;
                p[i].ct=complete;
                count--;
            }
        }
    }
    printf("\n");
    for(int i=0;i<n;i++){
        p[i].tat=p[i].ct-p[i].at;
    }
    for(int i=0;i<n;i++){
        p[i].wt=p[i].tat-p[i].bt;
    }
    for(int i=0;i<n;i++){
        printf("pno: %d\tat: %d\tbt: %d\twt: %d\ttat:%d\tct: %d\n",p[i].pno,p[i].at,p[i].bt,p[i].wt,p[i].tat,p[i].ct);
    }
}
