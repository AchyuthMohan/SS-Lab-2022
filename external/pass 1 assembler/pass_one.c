#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 100

FILE *f1,*f2,*f3,*f4,*f5;
char label[max],opcode[max],operand[max],t1[max],t2[max],t3[max],opcode_c[max],opcode_h[max];
int o=0,s=0,locctr,start,size=0;
struct optab{
    char opc[max],oph[max];
}ot[max];

struct symtab{
    int syma;
    char symbol[max];
}st[max];


void read_optab(){
    fscanf(f2,"%s%s",opcode_c,opcode_h);
    while(!feof(f2)){
        strcpy(ot[o].opc,opcode_c);
        strcpy(ot[o].oph,opcode_h);
        o++;
        fscanf(f2,"%s%s",opcode_c,opcode_h);
    }
}
void read_line(){
    fscanf(f1,"%s%s%s",t1,t2,t3);
    if(strcmp(t1,"")!=0 && strcmp(t2,"")!=0 && strcmp(t3,"")!=0){
        strcpy(label,t1);
        strcpy(opcode,t2);
        strcpy(operand,t3);
    }
    else if(strcmp(t1,"")!=0 && strcmp(t2,"")!=0 && strcmp(t3,"")==0){
        strcpy(label,"");
        strcpy(opcode,t1);
        strcpy(operand,t2);
    }
    else if(strcmp(t1,"")!=0 && strcmp(t2,"")==0 && strcmp(t3,"")==0){
        strcpy(label,"");
        strcpy(opcode,t1);
        strcpy(operand,"");
    }
}
int main(){
    f1=fopen("input.txt","r");
    f2=fopen("optab.txt","r");
    f3=fopen("symtab.txt","w");
    f4=fopen("output.txt","w");
    f5=fopen("length.txt","w");
    fscanf(f1,"%s%s%s",label,opcode,operand);
    if(strcmp(opcode,"START")==0){
        start=atoi(operand);
        locctr=start;
    }
    else{
        locctr=0;
        start=0;
    }
    read_optab();
    read_line();
    while(!feof(f1)){
        fprintf(f4,"%d\t%s\t%s\t%s\n",locctr,label,opcode,operand);
        if(strcmp(label,"")!=0){
            for(int i=0;i<s;i++){
                if(strcmp(label,st[i].symbol)==0){
                    printf("Error");
                    exit(0);
                }
            }
            st[s].syma=locctr;
            strcpy(st[s].symbol,label);
            s++;

        }
        int flag=0;
        for(int i=0;i<o;i++){
            if(strcmp(opcode,ot[i].opc)==0){
                size+=3;
                locctr+=0x3;
                flag=1;
            }
        }
        if(flag==0){
            if(strcmp(opcode,"RESB")==0){
                locctr+=0x1;
            }
            else if(strcmp(opcode,"RESW")==0){
                locctr+=0x3;
            }
            else if(strcmp(opcode,"WORD")==0){
                locctr+=0x3;
                size+=3;
            }
            else if(strcmp(opcode,"BYTE")==0){
                locctr+=0x1;
                size+=1;
            }
        }
        read_line();
    }
    for(int i=0;i<s;i++){
        fprintf(f3,"%s\t%d\n",st[i].symbol,st[i].syma);
    }

}