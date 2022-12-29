#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    FILE *fp,*fp1;
    char line[20],name[20],startaddr[20];

    fp=fopen("abssrc.txt","r");
    fp1=fopen("Output.txt","w");
    int i,j,sta;

    int k=0;
    fscanf(fp,"%s",line);
    for(i=2;line[i]!='^';i++){
        name[k++]=line[i];
    }
    printf("Name of the program is : %s\n",name);

    while(!feof(fp)){
        fscanf(fp,"%s",line);
        while(line[0]=='T'){
            for(i=2,j=0;line[i]!='^';i++,j++){
                startaddr[j]=line[i];

            }
            sta=atoi(startaddr);
            i=12;
            while(line[i]!='$'){
                if(line[i]!='^'){
                    fprintf(fp1,"00%d\t%c\t%c\t\n",sta,line[i],line[i+1]);
                    // printf("00%d\t%c\t%c\t\n",sta,line[i],line[i+1]);
                    // printf("")
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