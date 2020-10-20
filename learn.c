#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

// Constants
#define BUFFER_SIZE 3000
#define TOKENS_SIZE 50

//external methods
int ls(char *path);

int main(int argc, char **argv){
    while(1){
        // Initialize variable
        char buffer[BUFFER_SIZE];
        char *arguments[TOKENS_SIZE];
        char *token_ptr;

        // Show shell prompt
        char dir_buff[FILENAME_MAX];
        getcwd( dir_buff, FILENAME_MAX);
        printf("%s$$$ ", dir_buff);
        // Read Input
        fgets(buffer, BUFFER_SIZE, stdin);
        buffer[strcspn(buffer, "\n")] = 0;
        // Tokenize Input
        int num_arguments = 0;
        token_ptr = strtok(buffer, " ");
        while(token_ptr != NULL){
            arguments[num_arguments] = token_ptr;
            num_arguments++;
            token_ptr = strtok(NULL, " ");
        }
        arguments[num_arguments] = 0;

        // Parse Input
        char *command = arguments[0];
        if(strcmp("exit", command)==0){ // exit
            printf("Shell closed.\n");
            break;
        }
        else if(strcmp("echo", command)==0){ // echo
            for(int index = 1; index < num_arguments; index++){
                printf("%s ", arguments[index]);
            }
            printf("\n");
        }
        else if(strcmp("cd", command)==0){ // cd
            if (chdir(arguments[1]) != 0){
                printf("ERROR! Cannot change directory to %s: ", arguments[1]);
                perror("");
            }  
        }
        else if(strcmp("mkdir", command)==0){ // mkdir
            if (mkdir(arguments[1],0777) != 0){
                printf("ERROR! Cannot create \'%s\' directory : ", arguments[1]);
                perror("");
            }  
        }
        else if(strcmp("rmdir", command)==0){ // rmdir
            if (rmdir(arguments[1]) != 0){
                printf("ERROR! Cannot remove \'%s\' directory : ", arguments[1]);
                perror("");
            }  
        }
        else if(strcmp("ls", command)==0){ // ls
            if(num_arguments == 1){
                ls(".");
            }
            else{
                ls(arguments[1]);
            }
        }
        else{ // Command Not Found
            printf("ERROR: Command %s not found\n", command);
        }
    }
    
    
    return 0;
}

