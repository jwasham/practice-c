#include "assert.h"
#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

bool reverseWords(char str[]);

int main(int argc, char **argv) {
  char *s1 = "My kingdom for a horse.";
  reverseWords(s1);
  printf("%s\n", s1);

  return 0;
}

bool reverseWords(char str[]) {
  char *buffer;
  int slen, tokenReadPos, wordReadPos, wordEnd, writePos = 0;
  slen = strlen(str);
  /* Position of the last character is length - 1 */
  tokenReadPos = slen - 1;
  buffer = (char *)malloc(slen + 1);

  if (!buffer) return false; /* reverseWords failed */
  while (tokenReadPos >= 0) {
    if (str[tokenReadPos] == ' ') { /* Non-word characters */
                                    /* Write character */
      buffer[writePos++] = str[tokenReadPos--];
    } else { /* Word characters */
             /* Store position of end of word */
      wordEnd = tokenReadPos;
      /* Scan to next non-word character */
      while (tokenReadPos >= 0 && str[tokenReadPos] != ' ') tokenReadPos--;
      /* tokenReadPos went past the start of the word */
      wordReadPos = tokenReadPos + 1;
      /* Copy the characters of the word */
      while (wordReadPos <= wordEnd) {
        buffer[writePos++] = str[wordReadPos++];
      }
    }
  }
  /* null terminate buffer and copy over str */
  buffer[writePos] = '\0';
  strncpy(str, buffer, slen + 1);
  free(buffer);
  return true; /* ReverseWords successful */
}
