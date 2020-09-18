#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 3000
#define TOKENS_SIZE 50

int main(int argc, char **argv){
    
    /* Single string & max number of characters for input */
    char buffer[BUFFER_SIZE];

    /* Array of tokens & max number of tokens */
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
        /* store token into a specific index in array */
        tokens[num_tokens] = token_ptr;
        /* increment tokens counter to keep track of total number of tokens */
        num_tokens++;
        /* printf("%s\n", tokens[num_tokens]); */
        token_ptr = strtok(NULL, " ");
    }
    
    /* print elements of token array */
    for(int i = 0; i < num_tokens; i++){
        printf("%s\n", tokens[i]); 
    }
    /* printf("%s\n",buffer); */
    
    return 0;
}