#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 3000
#define TOKENS_SIZE 50

int main(int argc, char **argv){
    
    /*max number of characters for input */
    char buffer[BUFFER_SIZE];

    /*max number of characters for each token */
    char *tokens[TOKENS_SIZE];
    int num_tokens = 0;
    
    /*token pointer */
    char *token_ptr;
    
    /*Read user input */
    fgets(buffer, BUFFER_SIZE, stdin);
    buffer[strcspn(buffer, "\n")] = 0;
    printf("%s\n",buffer);
    
}