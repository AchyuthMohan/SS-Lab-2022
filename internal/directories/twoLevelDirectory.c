#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct directory{
    char dname[20];
    char fname[20][20];
    int fcount;

}d[20];
int main(){
    int state=0;
    int dcount=0;
    while(state==0){
        printf("1. Create directory 2. create file 3. serch file 4. delete file 5. Exit: ");
        int ch;
        scanf("%d",&ch);
        switch(ch){
            case 1:{
                printf("Enter the name of directory : \n");
                scanf("%s",d[dcount].dname);
                dcount++;
                break;
            }
            case 2:{
                printf("Enter the name of the directory: \n");
                char name[20];
                scanf("%s",name);
                int i;
                for(i=0;i<dcount;i++){
                    if(strcmp(d[i].dname,name)==0){
                        printf("Enter the name of file to be aded: \n");
                        scanf("%s",d[i].fname[d[i].fcount]);
                        d[i].fcount++;
                        printf("File Created...\n");
                        break;
                    }
                }
                if(i==dcount){
                    printf("Directory not found");
                    break;
                }
                break;
            }
            case 4:{
                printf("Enter the name of the directory: \n");
                char name[20];
                scanf("%s",name);
                for(int i=0;i<dcount;i++){
                    if(strcmp(d[i].dname,name)==0){
                        printf("Enter the file name: \n");
                        char name2[20];
                        scanf("%s",name2);
                        for(int k=0;k<d[i].fcount;k++){
                            if(strcmp(d[i].fname[k],name2)==0){
                                strcpy(d[i].fname[k],d[i].fname[d[i].fcount-1]);
                                printf("File deleted..");
                                d[i].fcount--;
                                goto jmp;
                            }
                        }
                        printf("File Not found..");
                        goto jmp;
                    }
                }
                jmp:break;
            }
            case 3:{
                printf("Enter the name of directory: \n");
                char name[20];
                scanf("%s",&name);
                for(int i=0;i<dcount;i++){
                    if(strcmp(d[i].dname,name)==0){
                        printf("Enter the name of the file: ");
                        char name2[20];
                        scanf("%s",name2);
                        for(int k=0;k<d[i].fcount;k++){
                            if(strcmp(d[i].fname[k],name2)==0){
                                printf("File found");
                                goto jmp2;
                            }
                        }
                     printf("File Not found..");
                     goto jmp2;
                    }
                }
                printf("Directory not found...");
                jmp2: break;
            }
            case 5:{
                state=1;
                break;
            }
        }
    }
}