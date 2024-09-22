/*  INFO
    Name: Billy Leong
    Email: bleong@csu.fullerton.edu
    Course ID: CPSC223C
    Due Date: 09/22/2024 - 23:59:00
    Program Name:
    Purpose:
    OS: Windows 11
*/

#include "stdio.h"
#include "string.h"
#include "stdlib.h"

#define DEFAULT_TOKENS_SIZE 2048
#define DEFAULT_TOKENLIST_GROWTH 2048

/* Structure for containing a dynamically sized array of tokens
 *
 * contains elements:
 * - **tokens, a double pointer to type char
 * - maxTokens, the maximum number of tokens currently possible to contain
 * - tokenQty, the current number of tokens
 * 
 * Associated Functions:
 * Setup: TokenList_Construct()
 * Teardown: TokenList_Destruct()
 * Resize: TokenList_resize()
*/
struct TokenList
{
    char** tokens;
    int maxTokens;
    int tokenQty;
};

extern char* file2string(char*);

struct TokenList* tokenize(char*, char*);
void TokenList_Construct(struct TokenList*, int, int);
void TokenList_Destruct(struct TokenList*);

int main(int argc, char const *argv[])
{
    char* filename = (char*)malloc(101 * sizeof(char));
    char* buffer;
    char* delims = (char*)malloc(128 * sizeof(char));
    char charbuffer;
    struct TokenList* t;

    // startup
    printf("Welcome to Epic Software Systems, Inc. Head of Systems Lab: Billy Leong\n");
    
    // takes in the name of the file
    printf("Please input the file to be tokenized: ");
    scanf("%s", filename);
    scanf("%c", &charbuffer); /* gets rid of the extra newline */

    // repeat file name for confirmation
    printf("The file name is: %s\n", filename);
    
    buffer = file2string(filename);

    if (buffer == NULL) return 0; /* file2string has returned a null pointer, exit program */

    // prints out the return of file2string
    printf("The complete string taken from the file is: \n%s\n", buffer);

    // takes in the deliminator characters
    printf("Please enter the seperator characters: ");
    scanf("%s", delims);
    scanf("%c", &charbuffer);

    // repeat deliminators for confirmation
    printf("Confirmation: These are the seperator characters => %s\n", delims);

    // send string and delims to subfunction, returns a TokenList object 
    t = tokenize(buffer, delims);

    if(t->tokens[0] == NULL)
    {
        // tokenize has failed to work
        printf("There was an error in tokenizing. Please restart the program and try again.");
    }
    else
    {
        printf("Here is the complete list of tokens:\n");

        // prints out the tokens in order
        for (int i = 0; i < t->tokenQty; i++)
        {
            printf("[#%d] %s\n", i + 1, t->tokens[i]);
        }
        printf("The number of tokens is %d\n", t->tokenQty);
    }
    
    // deallocate memory
    free(filename);
    free(buffer);
    free(delims);
    return 0;
}

/* Sets up a new TokenList object
 * 
 * params: pointer to the TokenList to be set up, the initial size of the list, the current number of tokens
*/
void TokenList_Construct(struct TokenList* t, int TokenListSize, int curtokenQty)
{
    t->tokens = malloc(TokenListSize * sizeof(char*));
    t->maxTokens = TokenListSize;
    t->tokenQty = curtokenQty;
}

/* Resizes a TokenList
 * 
 * params: pointer to Tokenlist to be resized
 * returns: a new TokenList pointer and deletes the old one, make sure to set the pointer to this function's output
*/
struct TokenList* TokenList_resize(struct TokenList* t)
{
    struct TokenList* temp = (struct TokenList*)malloc(1 * sizeof(struct TokenList));

    TokenList_Construct(temp, t->maxTokens + DEFAULT_TOKENLIST_GROWTH, t->tokenQty);

    for (int i = 0; i < t->tokenQty; i++)
    {
        temp->tokens[i] = t->tokens[i];
    }
    TokenList_Destruct(t);
    return temp;
}

/* Teardown function for TokenList
 * frees the memory of a TokenList object
 *
 * params: pointer to the TokenList to teardown
*/
void TokenList_Destruct(struct TokenList* t)
{
    free(t->tokens);
    free(t);
}

/*
 * Subfuction to tokenize the string
 *
 * params: char* string buffer, char* deliminators
 * returns: a pointer to a TokenList struct
 * 
 * if there is nothing to tokenize or fails to tokenize, will return an empty TokenList
*/
struct TokenList* tokenize(char* buffer, char* delims)
{
    struct TokenList* t = (struct TokenList*)malloc(1 * sizeof(struct TokenList));

    TokenList_Construct(t, DEFAULT_TOKENS_SIZE, 0);

    t->tokens[t->tokenQty] = strtok(buffer, delims);
    if(t->tokens[t->tokenQty] == NULL) return t; /*if the first element is empty then immediately return an empty TokenList*/
    
    t->tokenQty++; 
    
    /*infinitely loops to tokenize the string*/
    while(1)
    {
        if(t->tokenQty >= t->maxTokens) t = TokenList_resize(t); /*of the number of tokens exceeds the current max size, resize */
        
        t->tokens[t->tokenQty] = strtok(NULL, delims);
        
        if(t->tokens[t->tokenQty] == NULL) break; /*if the most recent token is empty then break out of the loop */
        t->tokenQty++;
    }

    return t;
}