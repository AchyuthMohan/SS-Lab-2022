#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct directory{
    char dname[20];
    int fcount;
    char fname[20][20];
};
int main(){
    struct directory dir;
    printf("Enter the directory name: \n");
    char name[20];
    scanf("%s",dir.dname);
    dir.fcount=0;
    int state=0;
    while(state==0){
        printf("1. Create file 2. search file 3. delete file 4. exit");
        int ch;
        scanf("%d",&ch);
        switch(ch){
            case 1:{
                printf("Enter the name of the file..");
                scanf("%s",dir.fname[dir.fcount]);
                dir.fcount++;
                break;
            }
            case 2:{
                if(dir.fcount==0){
                    printf("Empty..");
                }
                else{
                    printf("Enter the file name: ");
                    char name[20];
                    scanf("%s",name);
                    int flag=0;
                    for(int i=0;i<dir.fcount;i++){
                        if(strcmp(dir.fname[i],name)==0){
                            printf("Found file..");
                            flag=1;
                            break;
                        }
                    }
                    if(flag==0){
                        printf("Not found..");
                    }
                }
                break;
            }
            case 3:{
                if(dir.fcount==0){
                    printf("Empty..");
                }
                else{
                    printf("Enter the file name: ");
                    char name[30];
                    scanf("%s",name);
                    int target,flag=0;
                    for(int i=0;i<dir.fcount;i++){
                        if(strcmp(name,dir.fname[i])==0){
                            target=i;
                            flag=1;
                            break;
                        }
                    }
                    if(flag==0){
                        
                    }
                }
                break;  
            }
            case 4:{

            }
        }
    }
}