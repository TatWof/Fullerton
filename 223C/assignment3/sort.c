

int sort(char** stringArr, int count)
{
    int strlen[count];
    int i, j, k;
    int min, max;
    
    for (k = 0; k < count; ++k)
    {
        for (i = 0; stringArr[k][i] != 0;) ++i;
        strlen[k] = i;
    }

    for(k = 0, j = count - 1; k < j; ++k, --j)
    {
        min = k, max = j;
        for (i = 0; i < count; ++i)
        {
            if (strlen[i] < strlen[min]) min = i;
            if (strlen[i] > strlen[max]) max = i; 
        }
        
        swap(&strlen[min], &strlen[j]);
        swap(&stringArr[min], &stringArr[j]);
        swap(&strlen[max], &strlen[k]);
        swap(&stringArr[max], &stringArr[k]);
    }
}

void swap(char** a, char** b)
{
    char* c = *a;
    *a = *b;
    *b = *c;
}

void swap(int* a, int* b)
{
    int* c = *a;
    *a = *b;
    *b = *c;
}