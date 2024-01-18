#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void compnext(char* pat, int* next) {
  int patlen = strlen(pat);

  for (int i = 0; i < patlen; i++) {
    next[i] = 0;
  }

  for (int i = 1; i < patlen; i++) {
    int len = 0;
    while (pat[len] == pat[i+len] && i+len < patlen) {
      len++;
    }

    if (i+len == patlen){
      continue;
    }

    if (next[i+len] < len+1) {
      next[i+len] = len+1;
    }
  }
}