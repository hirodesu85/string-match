#include <stdlib.h>
#include <stdbool.h>

extern bool isVerbose;
extern int Ncmp;

bool cmp(char, char);

/**
 * 単純照合法による文字列照合．
 * @param text テキスト
 * @param pat 検索パターン
 * @return 照合に成功した位置．失敗した場合は -1．
 */
int naive(char* text, unsigned int textlen, char* pat, unsigned int patlen) {
  int i = 0;
  int j = 0;
  while (j < textlen) {
		if (!cmp(pat[i], text[j])) {
			j = j - i + 1;
			i = 0;
		} else {
			if (i == patlen - 1) {
				return j - patlen + 1;
			} else {
				i++;
				j++;
			}
		}
	}
	return -1;
}
