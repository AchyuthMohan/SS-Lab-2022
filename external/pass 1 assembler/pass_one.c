#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 100
struct symtab
{
    char symbol[max];
    int addr;
} st[max];
struct optab
{
    char opcode[max], hexcode[max];
} op[max];
FILE *f1, *f2, *f3, *f4, *f5;
int o = 0, s = 0, start;
char label[max], opcode[max], operand[max], t1[max], t2[max], t3[max], opc[max], oph[max];

void read_optab()
{
    fscanf(f2, "%s%s", opc, oph);
    while (!feof(f2))
    {
        strcpy(op[o].opcode, opc);
        strcpy(op[o].hexcode, oph);
        o++;
        fscanf(f2, "%s%s", opc, oph);
    }
}
void read_line()
{
    fscanf(f1, "%s%s%s", t1, t2, t3);
    if (strcmp(t1, "") != 0 && strcmp(t2, "") != 0 && strcmp(t3, "") != 0)
    {
        strcpy(label, t1);
        strcpy(opcode, t2);
        strcpy(operand, t3);
    }
    else if (strcmp(t1, "") != 0 && strcmp(t2, "") != 0 && strcmp(t3, "") == 0)
    {
        strcpy(label, "");
        strcpy(opcode, t1);
        strcpy(operand, t2);
    }
    else if (strcmp(t1, "") != 0 && strcmp(t2, "") == 0 && strcmp(t3, "") == 0)
    {
        strcpy(label, "");
        strcpy(opcode, t1);
        strcpy(operand, "");
    }
}

int main()
{
    f1 = fopen("input.txt", "r");
    f2 = fopen("optab.txt", "r");
    f3 = fopen("symtab.txt", "w");
    f4 = fopen("output.txt", "w");
    f5 = fopen("length.txt", "w");
    int size = 0, locctr;
    fscanf(f1, "%s%s%s", label, opcode, operand);
    if (strcmp(opcode, "START") == 0)
    {
        start = atoi(operand);
        locctr = start;
    }
    else
    {
        locctr = 0;
    }
    read_optab();
    read_line();
    while (!feof(f1))
    {
        fprintf(f4, "%d\t%s\t%s\t%s\n", locctr, label, opcode, operand);
        if (strcmp(label, "") != 0)
        {
            for (int i = 0; i < s; i++)
            {
                if (strcmp(label, st[i].symbol) == 0)
                {
                    printf("Duplicate label..");
                    exit(0);
                }
            }
            strcpy(st[s].symbol, label);
            st[s].addr = locctr;
            s++;
        }
        int flag = 0;
        for (int i = 0; i < o; i++)
        {
            if (strcmp(op[i].opcode, opcode) == 0)
            {
                flag = 1;
                locctr += 0x3;
                size += 3;
                break;
            }
        }
        if (flag == 0)
        {
            if (strcmp(opcode, "RESB") == 0)
            {
                locctr += 0x1;
                size += 1;
            }
            else if (strcmp(opcode, "RESW") == 0)
            {
                locctr +=0x3;
                size += 3;
            }
            else if (strcmp(opcode, "BYTE") == 0)
            {
                locctr += 0x1;
                
            }
            else if (strcmp(opcode, "WORD") == 0)
            {
                locctr += 0x3;
                
            }
        }
        
        read_line();
    }

    for (int i = 0; i < s; i++)
    {
        fprintf(f3,"%s\t%d\n", st[i].symbol, st[i].addr);
    }
    fprintf(f5,"%d\t%d",size,size-locctr);
}
