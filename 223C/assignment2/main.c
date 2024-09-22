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

    printf("Welcome to the Tokenizer Program\n");
    printf("This program is maintained by: Billy Leong\n");
    printf("Please input the file to be tokenized: ");
    scanf("%s", filename);
    scanf("%c", &charbuffer); /* gets rid of the extra newline */

    
    printf("The file name is: %s\n", filename);
    
    buffer = file2string(filename);

    if (buffer == NULL) return 0;

    printf("The complete string taken from the file is: %s\n", buffer);

    printf("Please enter the seperator characters: ");
    scanf("%s", delims);
    scanf("%c", &charbuffer);

    t = tokenize(buffer, delims);

    printf("the number of tokens is %d\n", t->tokenQty);
    for (int i = 0; i < t->tokenQty; i++)
    {
        printf("[#%d] %s\n", i + 1, t->tokens[i]);
    }
    free(filename);
    free(buffer);
    free(delims);
    return 0;
}

void TokenList_Construct(struct TokenList* t, int TokenListSize, int curtokenQty)
{
    t->tokens = malloc(TokenListSize * sizeof(char*));
    t->maxTokens = TokenListSize;
    t->tokenQty = curtokenQty;
}

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

void TokenList_Destruct(struct TokenList* t)
{
    free(t->tokens);
    free(t);
}


struct TokenList* tokenize(char* buffer, char* delims)
{
    struct TokenList* t = (struct TokenList*)malloc(1 * sizeof(struct TokenList));

    TokenList_Construct(t, DEFAULT_TOKENS_SIZE, 0);

    t->tokens[t->tokenQty] = strtok(buffer, delims);
    if(t->tokens[t->tokenQty] == NULL) return t;
    t->tokenQty++; 
    while(1)
    {
        if(t->tokenQty >= t->maxTokens) t = TokenList_resize(t);
        t->tokens[t->tokenQty] = strtok(NULL, delims);
        if(t->tokens[t->tokenQty] == NULL) break;
        t->tokenQty++;
    }
    return t;
}