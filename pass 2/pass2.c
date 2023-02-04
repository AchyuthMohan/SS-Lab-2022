#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 40
int main(){
    char address[max],label[max],opcode[max],operand[max],opc[max],oph[max],sym[max],syma[max];
    FILE *f1,*f2,*f3,*f4,*f5;
    f1=fopen("input.txt","r");
    f2=fopen("symtab.txt","r");
    f3=fopen("optab.txt","r");
    f4=fopen("length.txt","r");
    f5=fopen("ouput.txt","w");
    int length;
    fscanf(f4,"%d",&length);
    fscanf(f1,"%s%s%s%s",address,label,opcode,operand);
    fprintf(f5,"H^%s^%s^%d\nT^%s^",label,operand,length,operand);
    fscanf(f1,"%s%s%s%s",address,label,opcode,operand);
    while(strcmp(opcode,"END")!=0){
        fscanf(f3,"%s%s",opc,oph);
        while(!feof(f3)){
            if(strcmp(opc,opcode)==0){
                fclose(f3);
                fscanf(f2,"%s%s",sym,syma);
                while(!feof(f2)){
                    if(strcmp(label,sym)==0){
                        fprintf(f5,"%s%s^",oph,syma);
                        break;
                    }
                    else{
                        fscanf(f2,"%s%s",sym,syma);
                    }
                    break;
                }
            }
            else{
                fscanf(f3,"%s%s",opc,oph);
            }

            if(strcmp(opcode,"WORD")==0||strcmp(opcode,"BYTE")==0){
            if(strcmp(opcode,"WORD")==0){
                fprintf(f5,"%s^",operand);
            }
            else{
                int len=strlen(operand);
                for(int i=2;i<len;i++){
                    fprintf(f5,"0000%s^",operand[i]);
                }
            }
        }
        fscanf(f1,"%s%s%s%s",address,label,opcode,operand);
        f3=fopen("optab.txt","r");
        fseek(f3,SEEK_SET,0);
    }

        }
        
}