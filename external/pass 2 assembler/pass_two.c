#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 100

FILE *f1, *f2, *f3, *f4, *f5;
int len;
char start_addr[max], address[max], label[max], opcode[max], operand[max], length[max], opc[max], oph[max], sym[max], syma[max];

int main()
{
    f1 = fopen("intermediate.txt", "r");
    f2 = fopen("optab.txt", "r");
    f3 = fopen("symtab.txt", "r");
    f4 = fopen("length.txt", "r");
    f5 = fopen("object_code.txt", "w");
    fscanf(f1, "%s%s%s%s", address, label, opcode, operand);
    fscanf(f4, "%s", length);
    strcpy(start_addr,operand);
    fprintf(f5, "H^%s^%s^%s\nT^%s^", label, operand, length, operand);
    fscanf(f1, "%s%s%s%s", address, label, opcode, operand);
    while (strcmp(opcode,"END")!=0)
    {
        fscanf(f2,"%s%s",opc,oph);
        while(!feof(f2)){
            if(strcmp(opc,opcode)==0){
                fscanf(f3,"%s%s",sym,syma);
                while(!feof(f3)){
                    if(strcmp(sym,operand)==0){
                        fprintf(f5,"%s%s^",oph,syma);
                        break;
                    }
                    else{
                        fscanf(f3,"%s%s",sym,syma);
                        break;
                    }
                }
                break;
            }
            else{
                fscanf(f2,"%s%s",opc,oph);
            }
        }
        if(strcmp(opcode,"BYTE")==0 || strcmp(opcode,"WORD")==0){
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
        fscanf(f1, "%s%s%s%s", address, label, opcode, operand);
    }
    fprintf(f5,"\nE^%s",start_addr);

}