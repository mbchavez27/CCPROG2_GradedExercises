#include <stdio.h>
#include <string.h>

#define MAX 15

typedef char string[MAX + 3];

int isCheckLowerCase(char letter) {
  int yes = 0;
  if (letter >= 97 && letter <= 122) {
    yes = 1;
  }
  return yes;
}

void toJejemon(string str) {
  int i = 0;
  int strlength = strlen(str);
  int switchLowerCase = 0;

  if (str[strlength - 1] == 'o' || str[strlength - 1] == 'O') {
    strcat(str, "wz");
  }
  strlength = strlen(str);

  for (i = 0; i < strlength; i++) {
    switch (str[i]) {
    case 'o':
    case 'O':
      str[i] = '0';
      break;

    case 'e':
    case 'E':
      str[i] = '3';
      break;
    }
  }

  if (str[strlength - 1] == 's' || str[strlength - 1] == 'S') {
    strcpy(&str[strlength - 1], "es");
  }
  strlength = strlen(str);

  for (i = 0; i < strlength; i++) {
    if (switchLowerCase % 2 == 0) {
      if (!(str[i] >= 48 && str[i] <= 57)) {
        if (!isCheckLowerCase(str[i])) {
          str[i] += 32;
        }
      }
    } else {
      if (!(str[i] >= 48 && str[i] <= 57)) {
        if (isCheckLowerCase(str[i])) {
          str[i] -= 32;
        }
      }
    }
    switchLowerCase++;
  }
}
