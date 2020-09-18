#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 3000
#define TOKENS_SIZE 50

int main(int argc, char **argv){
    char buffer[BUFFER_SIZE];

    char *tokens[TOKENS_SIZE];
    int num_tokens = 0;

    char *token_ptr;
    
    fgets(tokens, TOKENS_SIZE, stdin);
    printf("%s\n",tokens);
    
}