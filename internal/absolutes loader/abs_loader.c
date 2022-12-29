#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    FILE *fp, *fp2;
    char line[50], name[50], startadd[50];
    int staddr1;
    fp = fopen("abssrc.txt", "r");
    fp2 = fopen("output.txt", "w");
    fscanf(fp, "%s", line);
    int k = 0;
    for (int i = 2; line[i] != '^'; i++)
    {
        name[k++] = line[i];
    }
    // int j;
    int i, j;
    printf("Name of the program: %s\n", name);
    while (!feof(fp))
    {
        fscanf(fp, "%s", line);
        while (line[0] == 'T')
        {
            for (i = 2, j = 0; line[i] != '^'; i++, j++)
            {
                startadd[j] = line[i];
            }
            startadd[j] = '\0';
            staddr1 = atoi(startadd);
            i = 12;
            while (line[i] != '$')
            {
                if (line[i] != '^')
                {
                    fprintf(fp2, "00%d\t%c%c\n", staddr1, line[i], line[i + 1]);
                    staddr1++;
                    i = i + 2;
                }
                else
                {
                    i++;
                }
            }
            fscanf(fp, "%s", line);
        }

        if (line[0] == 'E')
        {
            fclose(fp);
            fclose(fp2);
            exit(0);
        }
    }
    return 0;
}