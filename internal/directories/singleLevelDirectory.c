#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct directory{
    char name[20];
    int fcount;
    char fname[20][20];
};
struct directory dir;
int main(){
    dir.fcount=-1;
    printf("Enter the name of tghe directory: ");
    scanf("%s",dir.name);
    int state=0;
    int ch;
    while(state==0){
        printf("1. Create File 2. Search 3. Delete 4.display 5.Exit");
        scanf("%d",&ch);
        switch(ch){
            case 1:{
                printf("Enter the name of the file: ");
                dir.fcount++;
                int x=dir.fcount;
                scanf("%s",dir.fname[dir.fcount]);
                break;
            }
            case 2:{
                printf("Enter the name of the file to be searched: ");
                char target_file[20];
                scanf("%s",target_file);
                if(dir.fcount==-1){
                    printf("Empty...");
                    break;
                }
                int found=0;
                for(int i=0;i<=dir.fcount;i++){
                    if(strcmp(dir.fname[i],target_file)==0){
                        printf("File Found..");
                        found=1;
                        break;
                    }
                }
                if(found==0){
                    printf("Not FOund");
                }
                break;
            }
            case 3:{
                printf("Enter the name of the file to be deleted: ");
                char target_file[20];
                scanf("%s",target_file);
                int found=0;
                for(int i=0;i<=dir.fcount;i++){
                    if(strcmp(dir.fname[i],target_file)==0){
                        strcpy(dir.fname[i],dir.fname[dir.fcount]);
                        dir.fcount--;
                        found=1;
                    }
                }
                if(found==0){
                    printf("File not found..");
                }
                break;
            }
            case 4:{
                if(dir.fcount==0){
                    printf("empty..");
                }
                else{
                     for(int i=0;i<=dir.fcount;i++){
                        printf("\nFile name: %s",dir.fname[i]);
                     }
                }
               break;
            }
            case 5:{
                state=1;
                break;
            }
        }
    }
}