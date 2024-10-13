
void swap_char_star(char**, char**);
void swap_int(int*, int*);

int sort(char** stringArr, int count)
{
    int strlen[count];
    int i, j, k;
    int min, max;

    if(count < 1) return 1;
    if(count == 1) return 0;
    if(stringArr == 0 || stringArr[0] == 0) return 1;
    
    for (k = 0; k < count; ++k)
    {
        for (i = 0; stringArr[k][i] != 0;) ++i;
        strlen[k] = i;
    }

    for(k = 0, j = count - 1; k < j; ++k, --j)
    {
        min = k, max = j;
        for (i = k; i <= j; ++i)
        {
            if (strlen[i] < strlen[min]) min = i;
            if (strlen[i] > strlen[max]) max = i; 
        }
        
        swap_int(&strlen[min], &strlen[k]);
        swap_char_star(&stringArr[min], &stringArr[k]);
        swap_int(&strlen[max], &strlen[j]);
        swap_char_star(&stringArr[max], &stringArr[j]);
    }
}

void swap_char_star(char** a, char** b)
{
    char* c = *a;
    *a = *b;
    *b = c;
}

void swap_int(int* a, int* b)
{
    int c = *a;
    *a = *b;
    *b = c;
}