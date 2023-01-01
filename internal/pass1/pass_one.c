#include<stdio.h>
#include<stdlib.h>
#include<string.h>
FILE *f1,*f2,*f3,*f4,*f5;
char opcode[20],label[20],operand[20],t1[20],t2[20],t3[20];
int s=0,o=0,size=0;
struct symtab{
    char symbol[20];
    int addr;
}st[20];

struct optab{
    char opcode[20],hexcode[20];
}ot[20];

void read_line(){
    strcpy(t1,"");
    strcpy(t2,"");
    strcpy(t3,"");
    fscanf(f1,"%s",t1);
    if(getc(f1)!='\n'){
        fscanf(f1,"%s",t2);
        if(getc(f1)!='\n'){
            fscanf(f1,"%s",t3);
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
    while(!feof(f2)){
        fscanf(f2,"%s%s",ot[o].opcode,ot[o].hexcode);
        o++;
    }
}
int main(){
   

    f1=fopen("input.txt","r");
    f2=fopen("optab.txt","r");
    f3=fopen("intermediate.txt","w");
    f4=fopen("symtab.txt","w");
    f5=fopen("length.txt","w");
    int locctr,start;
    read_optab();
    printf("OPTAB: ");
    for(int i=0;i<o;i++){
        printf("%s\t%s\n",ot[i].opcode,ot[i].hexcode);

    }
    fscanf(f1,"%s%s%s",label,opcode,operand);
    
    if(strcmp(opcode,"START")==0){
        start=atoi(operand);
        locctr=start;
        read_line();
    }
    else{
        locctr=0;
    }
    while(strcmp(opcode,"END")!=0){
        fprintf(f3,"%d\t%s\t%s\t%s\n",locctr,label,opcode,operand);
        if(strcmp(label,"")!=0){
            for(int i=0;i<s;i++){
                if(strcmp(st[i].symbol,label)==0){
                    printf("Error");
                    exit(0);
                }
            }
            strcpy(st[s].symbol,label);
            st[s].addr=locctr;
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
            if(strcmp(opcode,"RESW")==0){
                locctr+=0x3*(atoi(operand));
            }
            else if(strcmp(opcode,"RESB")==0){
                locctr+=atoi(operand);
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
        fprintf(f4,"%s\t%d\n",st[i].symbol,st[i].addr);
    }
    fprintf(f5,"%d\t%d",locctr-start,size);
    fclose(f1);
    fclose(f2);
    fclose(f3);
    fclose(f4);
    fclose(f5);

}