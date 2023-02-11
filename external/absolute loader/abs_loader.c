#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 100
int main()
{
    FILE *f1, *f2;
    int k = 0;
    char input[max], name[max];
    f1 = fopen("input.txt", "r");
    f2 = fopen("output.txt", "w");
    fscanf(f1, "%s", input);
    if (input[0] == 'H')
    {
        for (int i = 2; input[i] != '^'; i++)
        {
            name[k++] = input[i];
        }
    }
    fprintf(f2, "Name: %s\n", name);
    char start_addr[max];
    int start;
    fscanf(f1, "%s", input);
    while (!feof(f1))
    {
        while (input[0] == 'T')
        {
            int v = 0;
            for (int i = 2; input[i] != '^'; i++)
            {
                start_addr[v++] = input[i];
            }
            start = atoi(start_addr);
            int c = 12;
            while (input[c] != '$')
            {
                if (input[c] == '^')
                {
                    c++;
                }
                else
                {
                    fprintf(f2, "%d\t%c%c\n", start, input[c], input[c + 1]);
                    c += 2;
                    start++;
                }
            }
            fscanf(f1, "%s", input);
        }
        fscanf(f1, "%s", input);
    }
}
