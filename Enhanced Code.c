#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void computeLPSArray(const char *pat, const size_t M, size_t *lps)
{
    size_t len = 0;
    lps[0] = 0;
    size_t i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMPSearch(const char *pat, const char *txt)
{
    const size_t M = strlen(pat);
    const size_t N = strlen(txt);
    size_t *lps = (size_t *) malloc(sizeof(size_t) * M);
    if (lps == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    size_t j = 0;
    computeLPSArray(pat, M, lps);
    size_t i = 0;
    while (i < N) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }
        if (j == M) {
            printf("Pattern found at index %zu\n", i - j);
            j = lps[j - 1];
        } else if (i < N && pat[j] != txt[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i = i + 1;
            }
        }
    }
    free(lps);
}

int main()
{
    char txt[100];
    char pat[100];
    printf("Enter the text: ");
    fgets_s(txt, sizeof(txt), stdin);
    txt[strcspn(txt, "\n")] = 0;
    printf("Enter the pattern: ");
    fgets_s(pat, sizeof(pat), stdin);
    pat[strcspn(pat, "\n")] = 0;
    KMPSearch(pat, txt

return 0;

}
