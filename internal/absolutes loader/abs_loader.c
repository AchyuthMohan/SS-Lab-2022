#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 30
int main(){
    FILE *fp,*fo;
    fp=fopen("abssrc.txt","r");
    fo=fopen("output.txt","w");
    char line[max],name[max];
    fscanf(fp,"%s",line);
    int k=0;
    if(line[0]=='H'){
        for(int i=2;line[i]!='^';i++){
            name[k++]=line[i];
        }
    }
    printf("Name is: %s",name);
    fscanf(fp,"%s",line);
    char startaddr[max];
    int sta;
    
    while(!feof(fp)){
        int i,j;
        while(line[0]=='T'){
            int v=0;
            for(i=2;line[i]!='^';i++){
                startaddr[v++]=line[i];
            }
            sta=atoi(startaddr);

            i=12;
            while(line[i]!='$'){
                if(line[i]!='^'){
                    fprintf(fo,"%d\t%c\t%c\n",sta,line[i],line[i+1]);
                    i+=2;
                    sta++;
                }
                else{
                    i++;
                }
            }
            fscanf(fp,"%s",line);

        }
    }
}