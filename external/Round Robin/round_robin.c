#include <stdio.h>
#include <stdlib.h>
#define max 50
struct process
{
    int pno, at, bt, tat, ct, rbt, wt;
} p[max];

int main()
{
    int n, qt, complete = 0;
    printf("Enter the number of processes: \n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter the arrival time and burst time pf p[%d]: \n", i);
        scanf("%d%d", &p[i].at, &p[i].bt);
        p[i].pno = i;
        p[i].tat = p[i].wt = 0;
    }
    for (int i = 0; i < n; i++)
    {
        p[i].rbt = p[i].bt;
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
    printf("Enter the quantum time: \n");
    scanf("%d",&qt);
    int completed_pros = 0;

    while (completed_pros != n - 1)
    {

        for (int i = 0; i < n; i++)
        {
            if(p[i].rbt!=0){

           
            if (p[i].rbt > qt)
            {
                p[i].rbt = p[i].rbt - qt;
                complete += qt;
                printf("processing: %d\n", p[i].pno);
            }
            else
            {
                complete += p[i].rbt;
                p[i].rbt = 0;
                p[i].ct = complete;
                completed_pros += 1;
                printf("Completed: %d\n", p[i].pno);
                break;
            }
        }
         }
    }

    printf("Final Answer: \n");
    for (int i = 0; i < n; i++)
    {
        printf("pno: %d\tBT: %d\t CT: %d\n", p[i].pno, p[i].bt, p[i].ct);
    }
}