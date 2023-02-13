#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define max 100
FILE *f1,*f2,*f3,*f4,*f5,*f6;
int main(){
    char address[max],label[max],opcode[max],operand[max],start_addr[max],opc[max],oph[max],sym[max],syma[max];
    int length,len,length_t=0;
    f1=fopen("intermediate.txt","r");
    f2=fopen("symtab.txt","r");
    f3=fopen("optab.txt","r");
    f4=fopen("length.txt","r");
    f5=fopen("object_code.txt","w");
    f6=fopen("intermediate.txt","r");
    fscanf(f6,"%s%s%s%s",address,label,opcode,operand);
    while(!feof(f6)){
        if(strcmp(opcode,"START")!=0 && strcmp(opcode,"END")!=0){
            length_t+=strlen(operand);
        }
        fscanf(f6,"%s%s%s%s",address,label,opcode,operand);
    }
    fscanf(f1,"%s%s%s%s",address,label,opcode,operand);
    strcpy(start_addr,operand);
    fscanf(f4,"%d",&length);
    fprintf(f5,"H^%s^%s^%d\nT^%s^%x^",label,operand,length,operand,length_t);
    fscanf(f1,"%s%s%s%s",address,label,opcode,operand);
    while(strcmp(opcode,"END")!=0){
        fscanf(f3,"%s%s",opc,oph);
        while(!feof(f3)){
            if(strcmp(opc,opcode)==0){
                fscanf(f2,"%s%s",sym,syma);
                while(!feof(f2)){
                    if(strcmp(sym,operand)==0){
                        fprintf(f5,"%s%s^",oph,syma);
                        break;
                    }
                    else{
                        fscanf(f2,"%s%s",sym,syma);
                        break;
                    }
                }
                break;
            }
            else{
                fscanf(f3,"%s%s",opc,oph);
            }
        }
        if(strcmp(opcode,"WORD")==0||strcmp(opcode,"BYTE")==0){
            if(strcmp(opcode,"WORD")==0){
                fprintf(f5,"0000%d^",operand);

            }
            else{
                len=strlen(operand);
                for(int i=2;i<len;i++){
                    fprintf(f5,"%c",operand[i]);
                }
                fprintf(f5,"^");
            }
        }

        fscanf(f1,"%s%s%s%s",address,label,opcode,operand);
    }
    fprintf(f5,"\nEND^%s",start_addr);
}