#include <stdlib.h>
#include <stdbool.h>

extern bool isVerbose;
extern int Ncmp;

bool cmp(char, char);
void compnext(char*, int*);

int kmp(char* text, unsigned int textlen, char* pat, unsigned int patlen) {
  int i = 0;
  int j = 0;
  int next[patlen];

  compnext(pat, next);

  while (j < textlen) {
    while (i >= 0 && !cmp(pat[i], text[j])) {
      i = next[i] - 1;
    }
    if (i != patlen - 1) {
      i++;
      j++;
    } else {
      return j - patlen + 1;
    }
  }

  return -1;
}