#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 100
int main(){
    FILE *f1,*f2,*f3,*f4,*f5;
    char label[max],opcode[max],operand[max],name[max],opcode1[max],operand1[max],arg[max];
    int pos=1,len;
    char pos1[max],pos2[max];
    f1=fopen("input.txt","r");
    f2=fopen("namtab.txt","w+");
    f3=fopen("deftab.txt","w+");
    f4=fopen("argtab.txt","w+");
    f5=fopen("output.txt","w+");
    fscanf(f1,"%s%s%s",label,opcode,operand);
    while(strcmp(opcode,"END")!=0){
        if(strcmp(opcode,"MACRO")==0){
            fprintf(f2,"%s",label);
            fseek(f2,SEEK_SET,0);
            fprintf(f3,"%s\t%s\n",label,operand);
            fscanf(f1,"%s%s%s",label,opcode,operand);
            while(strcmp(opcode,"MEND")!=0){
                if(operand[0]=='&'){
                    itoa(pos,pos1,5);
                    strcpy(pos2,"?");
                    strcpy(operand,strcat(pos2,pos1));
                    pos=pos+1;
                }
                fprintf(f3,"%s\t%s\n",opcode,operand);
                fscanf(f1,"%s%s%s",label,opcode,operand);
            }
            fprintf(f3,"%s",opcode);
        }
        else{
            fscanf(f2,"%s",name);
            if(strcmp(name,opcode)==0){
                len=strlen(operand);
                for(int i=0;i<len;i++){
                    if(operand[i]!=','){
                        fprintf(f4,"%c",operand[i]);
                    }
                    else{
                        fprintf(f4,"\n");
                    }
                }
                fseek(f3,SEEK_SET,0);
                fseek(f4,SEEK_SET,0);
                fscanf(f3,"%s%s",opcode1,operand1);
                fprintf(f5,".\t%s\t%s\n",opcode1,operand1);
                fscanf(f3,"%s%s",opcode1,operand1);
                while(strcmp(opcode1,"MEND")!=0){
                    if(operand1[0]=='?'){
                        fscanf(f4,"%s",arg);
                        fprintf(f5,"-\t%s\t%s",opcode1,arg);
                    }
                    else{
                        fprintf(f5,"-\t%s\t%s",opcode1,operand1);
                    }
                    fscanf(f3,"%s%s",opcode1,operand1);
                }

            }
            else{
                fprintf(f5,"%s\t%s\t%s\n",label,opcode,operand);
            }
        }
        fscanf(f1,"%s%s%s",label,opcode,operand);
    }
    fprintf(f5,"%s\t%s\t%s\n",label,opcode,operand);
}