#include <stdlib.h>
#include "freq.h"

/* Calculate Character Frequency
 *
 * params: string;
 * returns: frequency array
*/
struct FREQ** calc_cfreq(char* string)
{
    int charbuf;
    struct FREQ** freq = malloc(256 * sizeof(struct FREQ*));
    int i;

    if (string == 0) return NULL;

    for (i = 0; i < 256; i++)
    {
        freq[i] = malloc(1 * sizeof(struct FREQ));
        freq[i]->code = i;
    }
        
    for (i = 0; string[i] != 0; ++i)
    {
        charbuf = string[i];
        ++(freq[charbuf]->freq);
    }
    return freq;
}