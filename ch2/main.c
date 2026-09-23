#include <stdio.h>
#include <string.h>
#include <math.h>
#include <assert.h>

int pow_16(int exponent) {
  return (int) pow(16.0, (double) exponent);
}

// convert hex given in string form to int
int htoi(char *s) {
  // may be some other nifty way where we utilize casting and type conversion

  int r = 0;
  int len = strlen(s);
  for (int i = len - 1; i >= 0; i--) {
    if (s[i] == 'x' || s[i] == 'X') {
      break;
    }

    int place = len - i - 1;
    if (s[i] >= '0' && s[i] <= '9') {
      r = r + pow_16(place) * (s[i] - '0');
    } else if (s[i] >= 'A' && s[i] <= 'F') {
      r = r + pow_16(place) * (s[i] - 'A' + 10);
    } else if (s[i] >= 'a' && s[i] <= 'f') {
      r = r + pow_16(place) * (s[i] - 'a' + 10);
    } else {
      printf("WARN: not a valid hex digit: %c", s[i]);
    }
  }

  return r;
}

int main(int argc, char **argv) {
  printf("chapter 2\n");

  char *t1 = "0x11";
  char *t2 = "0xff";
  char *t3 = "0xFF";
  
  int r = htoi(t1);
  assert(r == 17);
  r = htoi(t2);
  assert(r == 255);
  r = htoi(t3);
  assert(r == 255);
}
