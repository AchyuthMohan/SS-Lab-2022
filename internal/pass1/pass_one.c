#include<stdio.h>
#include<stdlib.h>
#include<string.h>
FILE *fp1,*fp2,*fp3,*fp4,*fp5;
char opcode[20],operand[20],label[20],t1[20],t2[20],t3[20],s=0;

int o=-1,locctr,start,locctr,flag,size=0;

struct symtab{
    char label[20];
    int address;
}st[20];
struct optab{
    char opcode[10],hexcode[10];
}ot[20];

void read_line(){
    strcpy(t1,"");
    strcpy(t2,"");
    strcpy(t3,"");
    fscanf(fp1,"%s",t1);
    if(getc(fp1)!='\n'){
        fscanf(fp1,"%s",t2);
        if(getc(fp1)!='\n'){
            fscanf(fp1,"%s",t3);
        }
    }
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
    while(!feof(fp2)){
        o++;
        fscanf(fp2,"%s%s",ot[o].opcode,ot[o].hexcode);
    }
}
int main(){
    fp1=fopen("input.txt","r");
    fp2=fopen("optab.txt","r");
    fp3=fopen("symtab.txt","w");
    fp4=fopen("intermediate.txt","w");
    fp5=fopen("length.txt","w");

    read_optab();
    fscanf(fp1,"%s%s%d",label,opcode,&operand);
    if(strcmp(opcode,"START")==0){
        start=atoi(operand);
        locctr=start;
        read_line();
    }
    else{
        locctr=0;
    }
    while(strcmp(opcode,"END")!=0){
        fprintf(fp4,"%x\t%s\t%s\t%s\n",locctr,label,opcode,operand);
        if(strcmp(label,"")!=0){
            for(int i=0;i<s;i++){
                if(strcmp(st[i].label,label)==0){
                    printf("Error");
                    exit(0);
                }
            }
            strcpy(st[s].label,label);
            st[s].address=locctr;
            s++;
        }
        flag=0;
        for(int i=0;i<=o;i++){
            if(strcmp(ot[i].opcode,opcode)==0){
                locctr+=0x3;
                size+=3;
                flag=1;
                break;
            }
        }
        if(flag==0){
            if(strcmp(opcode,"WORD")==0){
                locctr+=0X3;
                size+=3;

            }
            else if(strcmp(opcode,"RESW")==0){
                locctr+=(0x3*(atoi(operand)));
            }
            else if(strcmp(opcode,"BYTE")==0){
                locctr+=0X1;
                size+=1;
            }
            else if(strcmp(opcode,"RESB")==0){
                locctr+=(atoi(operand));
            }
        }
        read_line();   //reads next Line
    }
    for(int i=0;i<s;i++){
        fprintf(fp3,"%s\t%x",st[i].label,st[i].address);
        if(i!=s){
            fprintf(fp3,"\n");
        }
    }
    fprintf(fp5,"%d %d",locctr-start,size);
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    fclose(fp4);
    fclose(fp5);
}