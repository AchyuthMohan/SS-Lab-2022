#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 300
struct estab
{
    char csectname[max], extsymbol_name[max];
    int address, length;
} et[max];
FILE *f1, *f2;
int main()
{
    int ctr = 0, cs_addr, length;
    char input[max];
    printf("Enter the starting address: \n");
    scanf("%d", &cs_addr);
    f1 = fopen("input.txt", "r");
    f2 = fopen("output.txt", "w");
    fscanf(f1, "%s", input);
    while (strcmp(input, "END") != 0)
    {
        if (strcmp(input, "H") == 0)
        {
            int add;
            fscanf(f1, "%s", input);
            strcpy(et[ctr].csectname, input);
            strcpy(et[ctr].extsymbol_name, "****");
            fscanf(f1, "%s", input);
            add=atoi(input);
            et[ctr].address = cs_addr + add;
            fscanf(f1, "%d", &length);
            et[ctr].length = length;
            ctr++;
        }
        else if (strcmp(input, "D") == 0)
        {
            while (strcmp(input, "R") != 0 && strcmp(input, "T") != 0)
            {
                fscanf(f1, "%s", input);
                strcpy(et[ctr].csectname, "****");
                strcpy(et[ctr].extsymbol_name, input);
                int add;
                fscanf(f1, "%d", &add);
                et[ctr].address = cs_addr+add;
                et[ctr].length = 0;
                ctr++;
                fscanf(f1, "%s", input);
            }
            cs_addr += length;
        }
        fscanf(f1, "%s", input);
    }

    for (int i = 0; i < ctr; i++)
    {
        fprintf(f2, "%s\t%s\t%d\t%d\n", et[i].csectname, et[i].extsymbol_name, et[i].address, et[i].length);
    }
}