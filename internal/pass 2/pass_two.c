#include<stdio.h>
#include<stdlib.h>
#include<string.h>

FILE *fp1,*fp2,*fp3,*fp4,*fp5,*fp6;
int length,size,s=-1,o=-1;
char address[20],label[20],opcode[20],operand[20],start_addr[20],t1[20],t2[20],t3[20],t4[20];
struct optab{
    char opcode[20],hexcode[20];
}ot[30];

struct symtab{
    char label[20],address[20];
}st[30];

void read_line(){
    strcpy(t1,"");
    strcpy(t2,"");
    strcpy(t3,"");
    fscanf(fp1,"%s",t1);
    if(getc(fp1)!='\n'){
        fscanf(fp1,"%s",t2);
        if(getc(fp1)!='\n'){
            fscanf(fp1,"%s",t3);
            if(getc(fp1)!='\n'){
                fscanf(fp1,"%s",t4);
            }
        }
    }
    if(strcmp(t1,"")!=0&&strcmp(t2,"")!=0&&strcmp(t3,"")!=0&&strcmp(t4,"")!=0){
        strcpy(address,t1);
        strcpy(label,t2);
        strcpy(opcode,t3);
        strcpy(operand,t4);
    }
    else if(strcmp(t1,"")!=0&&strcmp(t2,"")!=0&&strcmp(t3,"")!=0&&strcmp(t4,"")==0){
        strcpy(address,t1);
        strcpy(label,"");
        strcpy(opcode,t2);
        strcpy(operand,t3);
    }
    else if(strcmp(t1,"")!=0&&strcmp(t2,"")!=0&&strcmp(t3,"")==0&&strcmp(t4,"")==0){
        if(strcmp(t1,"END")==0){
            strcpy(address,"");
            strcpy(label,"");
            strcpy(opcode,t1);
            strcpy(opcode,t2);

        }
        else{
            strcpy(address,t1);
            strcpy(label,"");
            strcpy(opcode,t2);
            strcpy(operand,"");
        }
    }
}
void read_optab(){
    while(1){
        o++;
        fscanf(fp3,"%s%s",ot[o].opcode,ot[o].hexcode);
        if(getc(fp3)==EOF){
            break;
        }
    }
}
void read_symtab(){
    while(1){
        o++;
        fscanf(fp2,"%s%s",st[s].label,st[o].address);
        if(getc(fp2)==EOF){
            break;
        }
    }
}
 int main(){
    fp1=fopen("intermediate.txt","r");
    fp2=fopen("symtab.txt","r");
    fp3=fopen("optab.txt","r");
    fp4=fopen("length.txt","r");
    fp5=fopen("assmlist.txt","w");
    fp6=fopen("objcode.txt","r");

    fscanf(fp4,"%d%d",length,size);
    read_optab();
    read_symtab();
    fscanf(fp1,"%s%s%s",label,opcode,operand);
    strcpy(start_addr,operand);
    if(strcmp(opcode,"START")==0){
        fprintf(fp5,"\t%s\t%s\t%s\n",label,opcode,operand);
        fprintf(fp6,"H^%s ^00%s^0000%s\n",label,operand,length);
        fprintf(fp6,"T^00%s",operand,size);
        read_line();
    }
    while(strcmp(opcode,"END")!=0){
        
    }
 }