#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define MAXLEN 100001

int main(void) {
  const char *capitals = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char buf[MAXLEN];

  fgets(buf, MAXLEN, stdin); // Normally do dynamic allocation, but the input length is guarenteed

  char *nextCapital = buf;
  uint32_t word_count = 1;
  while ((nextCapital = strpbrk(nextCapital+1, capitals)) != NULL)
    word_count++;

  printf("%d\n", word_count);
}
