#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 40
struct estab{
    char extsymname[max],csectname[max];
    int address,length;
}et[max];
int main(){
    char input[max];
    FILE *f1,*f2;
    int count=0;
    f1=fopen("linkinput.txt","r");
    f2=fopen("out.txt","w");
    int length;
    printf("Enter the starting address: \n");
    int csaddr;
    scanf("%d",&csaddr);
    fscanf(f1,"%s",input);
    while(strcmp(input,"END")!=0){
        if(strcmp(input,"H")==0){
            fscanf(f1,"%s",input);
            strcpy(et[count].csectname,input);
            strcpy(et[count].extsymname,"****");
            int add;
            fscanf(f1,"%d",&add);
            et[count].address=add+csaddr;
            fscanf(f1,"%d",&length);
            et[count].length=length;
            count++;

        }
        else if(strcmp(input,"D")==0){
            while(strcmp(input,"R")!=0&&strcmp(input,"T")!=0){
                fscanf(f1,"%s",input);
                strcpy(et[count].csectname,"****");
                strcpy(et[count].extsymname,input);
                int add;
                fscanf(f1,"%d",&add);
                et[count].address=csaddr+add;
                et[count].length=0;
                count++;
                fscanf(f1,"%s",input);
            }
            csaddr+=length;
        }
        fscanf(f1,"%s",input);
    }
    for(int i=0;i<count;i++){
        fprintf(f2,"%s\t%s\t%d\t%d\n",et[i].csectname,et[i].extsymname,et[i].address,et[i].length);
    }
}