#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void generateString(char *str, int n, const char *pat) {
  int patLen = strlen(pat);
  int i, j;

  // ランダムな文字列を生成する
  for (i = 0; i < n - patLen; ++i) {
    str[i] = 'a' + rand() % 5; // 'a' から 'e' までの文字を選択
  }

  // 文字列の末尾にパターンを付加
  for (j = 0; j < patLen; ++j) {
    str[i + j] = pat[j];
  }

  // 終端文字をセット
  str[n] = '\0';
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <length> <pattern>\n", argv[0]);
    return 1;
  }

  int n = atoi(argv[1]);
  const char *pat = argv[2];
  int patLen = strlen(pat);

  if (n <= patLen) {
    printf("Error: Length must be greater than the length of the pattern.\n");
    return 1;
  }

  // ランダムなシードを設定
  srand((unsigned)time(NULL));

  char *str = (char *)malloc(n + 1);
  if (str == NULL) {
    printf("Memory allocation failed.\n");
    return 1;
  }

  generateString(str, n, pat);

  // ファイルに結果を書き込む
  FILE *file = fopen("text", "w");
  if (file == NULL) {
    printf("File cannot be opened.\n");
    free(str);
    return 1;
  }

  fprintf(file, "%s\n", str);
  fclose(file);

  printf("Generated String has been written to text.txt\n");

  free(str);
  return 0;
}
