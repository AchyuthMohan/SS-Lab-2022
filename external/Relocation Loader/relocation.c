#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 100
int main(){
    FILE *f1,*f2;
    char line[max];
    f1=fopen("input.txt","r");
    f2=fopen("output.txt","w");
    fscanf(f1,"%s",line);
    char name[max];
    int k=0;
    for(int i=1;i<7;i++){
        name[k++]=line[i];
    }
    fprintf(f2,"Name: %s\n",name);
    fscanf(f1,"%s",line);
    printf("Enter the start address: \n");
    int addr;
    scanf("%d",&addr);
    char hexaddr[max];
    int hexaddr_val;
    int c,i;
    while(!feof(f1)){
        while(line[0]=='T'){
            c=0;
            for(i=1;i<7;i++){
                hexaddr[c++]=line[i];
            }
            hexaddr_val=atoi(hexaddr);
            i=12;
            while(line[i]!='\0'){
                fprintf(f2,"%d\t%c%c\n",hexaddr_val+addr,line[i],line[i+1]);
                i+=2;
                hexaddr_val++;

            }
            
            fscanf(f1,"%s",line);
        }
    }
}