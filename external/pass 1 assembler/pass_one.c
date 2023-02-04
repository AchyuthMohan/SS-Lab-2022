#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 30

struct optab{
    char opcode[max];
    char oph[max];
}ot[max];

struct symtab{
    char symbol[max];
    int address;
}st[max];
FILE *f1,*f2,*f3,*f4,*f5;
char label[max],opcode[max],operand[max],t1[max],t2[max],t3[max],start[max];
int locctr=0,o=0,s=0,size=0;
void read_line(){
    fscanf(f1,"%s%s%s",t1,t2,t3);
    if(strcmp(t1,"")!=0 && strcmp(t2,"")!=0 && strcmp(t3,"")!=0){
        strcpy(label,t1);
        strcpy(opcode,t2);
        strcpy(operand,t3);

    }else if(strcmp(t1,"")!=0 && strcmp(t2,"")!=0 && strcmp(t3,"")==0){
        strcpy(label,"");
        strcpy(opcode,t1);
        strcpy(operand,t2);
    }else if(strcmp(t1,"")!=0 &&strcmp(t2,"")==0 && strcmp(t3,"")==0){
        strcpy(label,"");
        strcpy(opcode,t1);
        strcpy(operand,"");
    }
}
void read_optab(){
    while(!feof(f2)){
fscanf(f2,"%s%s",ot[o].opcode,ot[o].oph);
    o++;
    }
    

}
int main(){
    f1=fopen("input.txt","r");
    f2=fopen("optab.txt","r");
    f3=fopen("intermediate.txt","w");
    f4=fopen("symtab.txt","w");
    f5=fopen("length.txt","w");

    fscanf(f1,"%s%s%s",label,opcode,operand);
    if(strcmp(opcode,"START")==0){
        strcpy(start,operand);
        locctr=atoi(start);
    }
    read_optab();
    read_line();
    while(!feof(f1)){
        fprintf(f3,"%d\t%s\t%s\t%s\n",locctr,label,opcode,operand);
        printf("%d\n",locctr);
        if(strcmp(label,"")!=0){
            for(int i=0;i<s;i++){
                if(strcmp(st[s].symbol,label)==0){
                    printf("Error");
                    exit(0);
                }
            }
            strcpy(st[s].symbol,label);
            st[s].address=locctr;
            s++;
        }
        int flag=0;
        for(int i=0;i<o;i++){
            if(strcmp(ot[i].opcode,opcode)==0){
                flag=1;
                locctr+=0x3;
                size+=3;
                break;
            }
        }
        if(flag!=0){
            if(opcode=="RESB"){
                locctr+=0x1;
                size+=1;
            }
            else if(opcode=="RESW"){
                locctr+=0x3;
                size+=3;

            }
            else if(opcode=="BYTE"){
                locctr+=0x1;
            }
            else if(opcode=="WORD"){
                locctr+=0x3;

            }
        }



        read_line();

    }
    for(int i=0;i<s;i++){
        fprintf(f4,"%s\t%d\n",st[i].symbol,st[i].address);

    }
    fprintf(f5,"%d\t%d",size,locctr-size);
}

