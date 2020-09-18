#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 3000
#define TOKENS_SIZE 50

int main(int argc, char **argv){
    
    /* Single string & max number of characters for input */
    char buffer[BUFFER_SIZE];

    /* Array of strings & max number of characters for each token */
    char *tokens[TOKENS_SIZE];
    int num_tokens = 0;
    
    /* token pointer */
    char *token_ptr;
    
    /* Read user input */
    printf("Enter input: ");
    fgets(buffer, BUFFER_SIZE, stdin);
    
    /* Strip next line character from input */
    buffer[strcspn(buffer, "\n")] = 0;
    
    /* tokenize user input */
    token_ptr = strtok(buffer, " ");
    while(token_ptr != NULL){
        printf("%s\n", token_ptr);
        token_ptr = strtok(NULL, " ");
    }
    
    /* printf("%s\n",buffer); */
    
    return 0;
}