#include<stdio.h>
#include<stdlib.h>
#include<string.h>
FILE *f1,*f2,*f3,*f4,*f5;
struct optab{
    char opc[20],oph[20];
}ot[30];
int o=0,s=0;
struct symtab{
    char symbol[20];
    int address;
}st[40];
char opcode[20],operand[20],label[20],t1[20],t2[20],t3[20],start[20];
int locctr,size=0;

void read_line(){
    fscanf(f1,"%s%s%s",t1,t2,t3);
    if(strcmp(t1,"")!=0&&strcmp(t2,"")!=0&&strcmp(t3,"")!=0){
        strcpy(label,t1);
        strcpy(opcode,t2);
        strcpy(operand,t3);

    }
    else if(strcmp(t1,"")!=0&&strcmp(t2,"")!=0&&strcmp(t3,"")==0){
        strcpy(label,"");
        strcpy(opcode,t1);
        strcpy(operand,t2);
    }
    else if(strcmp(t1,"")!=0&&strcmp(t2,"")==0&&strcmp(t3,"")==0){
        strcpy(label,"");
        strcpy(opcode,t1);
        strcpy(operand,"");

    }
}
void read_optab(){
    while(!feof(f2)){
        fscanf(f2,"%s%s",ot[o].opc,ot[o].oph);
    o++;
 }
    

}
int main(){
    f1=fopen("input.txt","r");
    f2=fopen("optab.txt","r");
    f3=fopen("intermediate.txt","w");
    f4=fopen("symtyab.txt","w");
    f5=fopen("length.txt","w");
    fscanf(f1,"%s%s%s",label,opcode,operand);
    if(strcmp(opcode,"START")==0){
        strcpy(start,operand);
        locctr=atoi(start);

    }
    else{
        locctr=0;
    }
    read_optab();
    read_line();
    while(!feof(f1)){
        fprintf(f3,"%d\t%s\t%s\t%s\n",locctr,label,opcode,operand);
        if(strcmp(label,"")!=0){
            for(int i=0;i<s;i++){
            if(strcmp(label,st[i].symbol)==0){
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
            if(strcmp(ot[i].opc,opcode)==0){
                locctr+=0x3;
                size+=3;
                flag=1;
                break;
            }
        }
        if(flag!=0){
            if(strcmp(opcode,"RESB")==0){
                locctr+=0x1;
            }
            else if(strcmp(opcode,"RESW")==0){
                locctr+=0x3;
            }
            else if(strcmp(opcode,"BYTE")==0){
                locctr+=0x1;
                size+=1;
            }
            else if(strcmp(opcode,"WORD")==0){
                locctr+=0x3;
                size+=3;
            }
        }
        read_line();
        
    }
    for(int i=0;i<s;i++){
        fprintf(f4,"%s\t%d\n",st[i].symbol,st[i].address);
    }
    fprintf(f5,"%d\t%d",locctr-size,size);
}