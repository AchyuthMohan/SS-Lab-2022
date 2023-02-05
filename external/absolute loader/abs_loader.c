#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 100

FILE *f1, *f2;
char line[max], name[max], start_addr[max];
int i, start;
int main()
{
    f1 = fopen("input.txt", "r");
    f2 = fopen("output.txt", "w");
    fscanf(f1, "%s", line);
    if (line[0] == 'H')
    {
        int k = 0;
        for (i = 2; line[i] != '^'; i++)
        {
            name[k++] = line[i];
        }
    }
    fprintf(f2, "Name : %s\n", name);
    fscanf(f1, "%s", line);
    while (line[0] == 'T')
    {   int v=0;
        for(i=2;line[i]!='^';i++){
            start_addr[v++]=line[i];
        }
        start=atoi(start_addr);
        i=12;
        while(line[i]!='$'){
            
            if(line[i]!='^'){
                
                fprintf(f2,"%d\t%c   %c\n",start,line[i],line[i+1]);
                start++;
                i+=2;
            }
            else{
                i++;
            }
        }


        fscanf(f1, "%s", line);
    }
}