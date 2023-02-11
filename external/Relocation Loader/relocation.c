#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 100

int main()
{
    FILE *f1, *f2, *f3;
    char line[max], addr[max];
    int i, j;
    int start_addr, hexaddr;
    f1 = fopen("input.txt", "r");
    f3 = fopen("output.txt", "w");
    printf("Enter the actual start address: \n");
    scanf("%x", &start_addr);
    fscanf(f1, "%s", line);
    while (!feof(f1))
    {
        if (line[0] == 'T')
        {
            for (i = 1, j = 0; i < 7; i++, j++)
            {
                addr[j] = line[i];
            }
            f2 = fopen("temp.txt", "r+");
            fprintf(f2, "%s", addr);
            fscanf(f2, "%x", &hexaddr);
            fclose(f2);
            i = 9;
            while (line[i] != '\0')
            {
                fprintf(f3, "%x\t%c%c\n", hexaddr + start_addr, line[i], line[i + 1]);
                hexaddr++;
                i += 2;
            }
        }
        fscanf(f1, "%s", line);
    }
}