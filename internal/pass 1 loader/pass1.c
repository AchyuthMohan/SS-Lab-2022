#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    int csaddr,progaddr;
    FILE *fp,*fo;
    printf("Enter the staring address...\n");
    scanf("%d",&progaddr);
    csaddr=progaddr;
    fp=fopen("input.txt","r");
    fo=fopen("ouput.txt","w");
    
}