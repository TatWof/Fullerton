#include "freq.h"

void swap(struct FREQ**, struct FREQ**);

/* Sort by Character Frequency
 * sorts a frequency table by frequencies
 *
 * params: Frequecy table pointer array
 * requires: frequency table struct
 * returns: 1 if no table, 0 if successful
*/
int sort_bycfreq(struct FREQ** freq)
{
    int i, j;
    int min;

    if(freq == 0) return 1;

    for (i = 0; i < 256; i++)
    {
        min = i;
        for (j = i; j < 256; j++)
            if(freq[j]->freq < freq[min]->freq) min = j;

        swap(&freq[i], &freq[min]);
    }
    return 0;
}


void swap(struct FREQ** a, struct FREQ** b)
{
    struct FREQ* c = *a;
    *a = *b;
    *b = c; 
}