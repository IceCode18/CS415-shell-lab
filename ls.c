#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>

int ls(char *path){

        // Initialize Variables
        DIR             *dip;
        struct dirent   *dit;
        int             i = 0;

        // Open Directory
        if ((dip = opendir(path)) == NULL){
                printf("ERROR! ");
                perror("opendir");
                return 0;
        }

        // List directory file names
        while ((dit = readdir(dip)) != NULL){
                i++;
                if (dit->d_type==DT_DIR){
                        printf("\n%s (Directory)", dit->d_name);
                }	
		else{
                        printf("\n%s", dit->d_name);
                }
        }
        printf("\n\nFound a total of %i files\n", i);

        // Close Directory
        if (closedir(dip) == -1){
                perror("closedir");
                return 0;
        }

        return 1;
}