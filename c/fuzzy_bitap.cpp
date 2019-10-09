//Code by : Somyajit Chakraborty(@Sam)
#include <stdlib.h>
#include <string.h>
#include <limits.h>
 
 const char *bitap_fuzzy_bitwise_search(const char *text, const char *pattern, int k)
 {
     const char *result = NULL;
     int m = strlen(pattern);
     unsigned long *R;
     unsigned long pattern_mask[CHAR_MAX+1];
     int i, d;
 
     if (pattern[0] == '\0') return text;
     if (m > 31) return "The pattern is too long!";
 
     /* Initialize the bit array R */
     R = malloc((k+1) * sizeof *R);
     for (i=0; i <= k; ++i)
         R[i] = ~1;
 
     /* Initialize the pattern bitmasks */
     for (i=0; i <= CHAR_MAX; ++i)
         pattern_mask[i] = ~0;
     for (i=0; i < m; ++i)
         pattern_mask[pattern[i]] &= ~(1UL << i);
 
     for (i=0; text[i] != '\0'; ++i) {
         /* Update the bit arrays */
         unsigned long old_Rd1 = R[0];
 
         R[0] |= pattern_mask[text[i]];
         R[0] <<= 1;
 
         for (d=1; d <= k; ++d) {
             unsigned long tmp = R[d];
             /* Substitution is all we care about */
             R[d] = (old_Rd1 & (R[d] | pattern_mask[text[i]])) << 1;
             old_Rd1 = tmp;
         }
 
         if (0 == (R[k] & (1UL << m))) {
             result = (text+i - m) + 1;
             break;
         }
     }
 
     free(R);
     return result;
 }
