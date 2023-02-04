#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char label[20], opcode[20], operand[20], length[20], start[20], address[20], opc[20], oph[20], syma[20], sym[20];
    FILE *f1, *f2, *f3, *f4, *f5;
    int len;
    f1 = fopen("input.txt", "r");
    f2 = fopen("symtab.txt", "r");
    f3 = fopen("optab.txt", "r");
    f4 = fopen("length.txt", "r");
    f5 = fopen("object_code.txt", "w");

    fscanf(f1, "%s%s%s%s", address, label, opcode, operand);

    if (strcmp(opcode, "START") == 0)
    {
        strcpy(start, operand);
        fscanf(f4, "%s", length);
        fprintf(f5, "H^%s^%s^%s\nT^", label, operand, length);
    }
    fscanf(f1, "%s%s%s%s", address, label, opcode, operand);
    while (strcmp(opcode, "END") != 0)
    {
        fscanf(f3, "%s%s", opc, oph);
        while (!(feof(f3)))
        {
            if (strcmp(opc, opcode) == 0)
            {
                fscanf(f2, "%s%s", syma, sym);
                while (!feof(f2))
                {
                    if (strcmp(operand, sym) == 0)
                    {
                        fprintf(f5, "%s%s", oph, syma);
                        break;
                    }
                    else
                    {
                        fscanf(f2, "%s%s", syma, sym);
                        break;
                    }
                }
                break;
            }
            else
            {
                fscanf(f3, "%s%s", opc, oph);
            }
        }
        if ((strcmp(opcode, "BYTE") == 0) || (strcmp(opcode, "WORD") == 0))
        {

            if (strcmp(opcode, "WORD") == 0)
                fprintf(f5, "0000%s^", operand);
            else
            {
                len = strlen(operand);
                for (int i = 2; i < len; i++)
                {
                    fprintf(f5, "%d", operand[i]);
                }
                fprintf(f5, "^");
            }
        }
        fscanf(f1, "%s%s%s%s", address, label, opcode, operand);
        f3 = fopen("optab.txt", "r");
        fseek(f3, SEEK_SET, 0);
    }

    fprintf(f5, "\nE^%s", start);
    return 0;
}