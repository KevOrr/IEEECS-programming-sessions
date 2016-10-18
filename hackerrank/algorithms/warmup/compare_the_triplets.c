#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

#define MAX_SCORES 3
#define MAX_SCORE_DEC_WIDTH 3
// up to 3 chars per num * 3 nums + (3-1) spaces + '\0'
#define MAXLEN MAX_SCORES * (1 + MAX_SCORE_DEC_WIDTH)

const char * DELIM = " ";

int main(void) {
  char alice_in[MAXLEN];
  char bob_in[MAXLEN];

  unsigned int alice_scores[3];
  unsigned int bob_scores[3];

  unsigned int alice_comparison_score;
  unsigned int bob_comparison_score;

  // Get input
  fgets(alice_in, MAXLEN, stdin);
  fgets(bob_in, MAXLEN, stdin);

  // Strip trailing '\n'
  alice_in[strcspn(alice_in, "\n")] = '\0';
  bob_in[strcspn(bob_in, "\n")] = '\0';

  // atoi() alice
  alice_scores[0] = atoi(strtok(alice_in, DELIM));
  unsigned int i;
  for (i = 1; i < MAX_SCORES; i++) {
    alice_scores[i] = atoi(strtok(NULL, DELIM));
  }

  // atoi() bob
  bob_scores[0] = atoi(strtok(bob_in, DELIM));
  for (i = 1; i < MAX_SCORES; i++) {
    bob_scores[i] = atoi(strtok(NULL, DELIM));
  }

  // Get comparison scores
  for (i = 0; i < MAX_SCORES; i++) {
    alice_comparison_score += alice_scores[i] > bob_scores[i];
    bob_comparison_score += bob_scores[i] > alice_scores[i];
  }

  printf("%d %d\n", alice_comparison_score, bob_comparison_score);
}
