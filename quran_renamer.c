#include <stdio.h>
#include <stdlib.h>
#include <dirent.h> 
#include <string.h>
#include <ctype.h>
#include <sys/types.h>


int main(){
    char dirName[] = "./";
    DIR *dir = opendir(dirName);
    struct dirent *ent;
    char * file_name = (char *)malloc(50*sizeof(char));
    while ((ent = readdir (dir)) != NULL) {
        if (!strcmp (ent->d_name, "."))
            continue;
        if (!strcmp (ent->d_name, ".."))    
            continue;

        file_name = ent->d_name;
        printf ("Fname: %s\n", file_name);
        int i=1;
        while (i<3){
            if (isdigit(file_name[i])){
                printf ("cont\n");
                ++i;
                continue;
            }else
            {
                printf ("break\n");
                break;
            }
        }
        char newName[3+strlen(file_name)];
        char zeros[3];
        int j=0;
        for (;i<3;i++){
            zeros[j++]='0';
        }

        zeros[j]='\0';

        
        printf ("o=%s\n\n", file_name);
        strcpy(newName,zeros);
        strcat(newName,file_name);
        strcat(newName,"\0");
        rename(file_name,newName);
        printf ("n=%s\n\n", newName);
    }
    closedir (dir);
    return 0;
}
