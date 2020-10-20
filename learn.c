#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
// #include <direct.h>

// Constants
#define BUFFER_SIZE 3000
#define TOKENS_SIZE 50

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
        arguments[num_arguments] = 0

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
        else{ // Command Not Found
            printf("ERROR: Command %s not found\n", command);
        }
    }
    
    
    return 0;
}

