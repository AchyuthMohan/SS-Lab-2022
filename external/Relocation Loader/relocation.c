#include<stdio.h>
#include<stdlib.h>
#define max 100
int main(){
    FILE *f1,*f2,*f3;
    f1=fopen("input.txt","r");
    f2=fopen("output.txt","w");

    int start_addr;
    printf("Enter the new starting address: \n");
    scanf("%x",&start_addr);
    char line[max];
    char addr[max];
    int k;
    int hexaddr;
    fscanf(f1,"%s",line);
    while(!feof(f1)){

        if(line[0]=='T'){
            k=0;
            for(int i=1;i<7;i++){
                addr[k++]=line[i];
            }
            f3=fopen("temp.txt","r+");
            fprintf(f3,"%s",addr);
            fscanf(f3,"%x",&hexaddr);
            k=9;
            while(line[k]!='\0'){
                fprintf(f2,"%x\t%c%c\n",hexaddr+start_addr,line[k],line[k+1]);
                k+=2;
                hexaddr++;
            }
        }

        fscanf(f1,"%s",line);
    }
}